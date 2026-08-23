#!/usr/bin/env bash
# Usage: run.sh <lang> <problem-num>
#   lang: cpp | python | javascript | rust   (also accepts py / js / rs)
#   problem-num: e.g. 1, 11, 42
#
# Looks up the matching source file in the repo and runs it. Called by the
# VS Code tasks "Run current file" and "Run problem (pick lang + #)".

set -e
shopt -s nullglob

LANG_ID="${1:?usage: $0 <lang> <num>}"
PROB_NUM="${2:?usage: $0 <lang> <num>}"

case "$LANG_ID" in
  cpp)
    src=("cpp/${PROB_NUM}. "*.cpp)
    if [ ${#src[@]} -eq 0 ]; then
      echo "No cpp file for problem ${PROB_NUM} (no cpp/${PROB_NUM}. *.cpp)"
      exit 1
    fi
    if ! grep -qE "^[^#]*add_executable\([^)]*_${PROB_NUM}\b" CMakeLists.txt; then
      echo "${src[0]} exists but is not registered (or is commented out) in CMakeLists.txt."
      echo "Add or uncomment:  add_executable(\${PROJECT_NAME}_${PROB_NUM} \"${src[0]}\")"
      exit 1
    fi
    target="1337_c0d3_${PROB_NUM}"
    # Heal a build/ that was configured by a CMake which no longer exists. This
    # happens routinely with snap's cmake: an auto-update garbage-collects the old
    # revision that build/ has baked into its Makefiles, and every build then dies
    # with "cmake: No such file or directory". Detect the dead path and start clean.
    cached_cmake=$(sed -n 's/^CMAKE_COMMAND:INTERNAL=//p' build/CMakeCache.txt 2>/dev/null)
    if [ -n "$cached_cmake" ] && [ ! -x "$cached_cmake" ]; then
      echo "Cached CMake ($cached_cmake) no longer exists — reconfiguring build/ from scratch."
      rm -rf build
    fi
    [ -d build ] || cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build -j"$(nproc)" --target "$target"
    "./build/$target"
    ;;
  python|py)
    f=("python/${PROB_NUM}. "*.py)
    if [ ${#f[@]} -eq 0 ]; then
      echo "No python file for problem ${PROB_NUM} (no python/${PROB_NUM}. *.py)"
      exit 1
    fi
    if ! command -v uv >/dev/null 2>&1; then
      echo "uv is not installed. Install it with:  curl -LsSf https://astral.sh/uv/install.sh | sh"
      echo "(see https://docs.astral.sh/uv/ ). It manages the python/.venv used to run solutions."
      exit 1
    fi
    # uv auto-creates/syncs python/.venv (per python/pyproject.toml) on first run,
    # then runs the file from that environment.
    uv run --project python --quiet python "${f[0]}"
    ;;
  javascript|js)
    f=("javascript/${PROB_NUM}. "*.js)
    if [ ${#f[@]} -eq 0 ]; then
      echo "No javascript file for problem ${PROB_NUM} (no javascript/${PROB_NUM}. *.js)"
      exit 1
    fi
    node "${f[0]}"
    ;;
  rust|rs)
    f=("rust/${PROB_NUM}. "*.rs)
    if [ ${#f[@]} -eq 0 ]; then
      echo "No rust file for problem ${PROB_NUM} (no rust/${PROB_NUM}. *.rs)"
      exit 1
    fi
    if ! grep -qE "^[[:space:]]*name[[:space:]]*=[[:space:]]*\"p${PROB_NUM}\"" rust/Cargo.toml; then
      echo "${f[0]} exists but has no [[bin]] in rust/Cargo.toml."
      echo "Add:"
      echo "  [[bin]]"
      echo "  name = \"p${PROB_NUM}\""
      echo "  path = \"${PROB_NUM}. $(basename "${f[0]}" .rs | sed "s/^${PROB_NUM}\. //").rs\""
      exit 1
    fi
    cargo run --release --quiet --manifest-path rust/Cargo.toml --bin "p${PROB_NUM}"
    ;;
  *)
    echo "Unknown lang: $LANG_ID (use cpp/python/javascript/rust)"
    exit 1
    ;;
esac
