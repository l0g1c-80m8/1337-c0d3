cmake_minimum_required(VERSION 3.26)

set(PROJECT_NAME "1337_c0d3")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}_7 "cpp/7. reverse-integer.cpp")
add_executable(${PROJECT_NAME}_8 "cpp/8. string-to-integer.cpp")
add_executable(${PROJECT_NAME}_9 "cpp/9. palindrome-number.cpp")
add_executable(${PROJECT_NAME}_11 "cpp/11. container-with-most-water.cpp")
add_executable(${PROJECT_NAME}_12 "cpp/12. integer-to-roman.cpp")
add_executable(${PROJECT_NAME}_13 "cpp/13. roman-to-integer.cpp")
add_executable(${PROJECT_NAME}_14 "cpp/14. longest-common-prefix.cpp")
add_executable(${PROJECT_NAME}_15 "cpp/15. 3-sum.cpp")
add_executable(${PROJECT_NAME}_16 "cpp/16. 3-sum-closest.cpp")
add_executable(${PROJECT_NAME}_17 "cpp/17. letter-combinations-of-a-phone-number.cpp")
