//
// Created by Rutvik Patel on 2026-05-17.
//

use std::collections::HashMap;

// solution

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut complement_idx: HashMap<i32, i32> = HashMap::new();
        for (idx, &n) in nums.iter().enumerate() {
            if let Some(&prev_idx) = complement_idx.get(&n) {
                return vec![prev_idx, idx as i32];
            }
            complement_idx.insert(target - n, idx as i32);
        }
        vec![]
    }
}

// main

fn main() {
    let test_cases: Vec<(Vec<i32>, i32, Vec<i32>)> = vec![
        (vec![2, 7, 11, 15], 9, vec![0, 1]),
        (vec![3, 2, 4], 6, vec![1, 2]),
        (vec![3, 3], 6, vec![0, 1]),
    ];

    for (nums, target, expected) in test_cases {
        let got = Solution::two_sum(nums.clone(), target);
        assert_eq!(got, expected, "Failed for nums={:?}, target={}", nums, target);
    }

    println!("[INFO]: All test cases passed!");
}
