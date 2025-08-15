// Longest Increasing Subsequence of an array

// dp solution
// O(n^2)

#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    std::vector<int> dp(nums.size(), 1);

    for (size_t i = 1; i < nums.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int length : dp) {
        maxLength = std::max(maxLength, length);
    }

    return maxLength;
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "Length of LIS is " << lengthOfLIS(nums) << std::endl; // Output: 4
    return 0;
}

// optimal solution
// O(nlog(n))

#include <iostream>
#include <vector>
#include <algorithm>

int lengthOfLIS_binary_search(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    std::vector<int> tails;
    for (int num : nums) {
        auto it = std::lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }

    return tails.size();
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "Length of LIS is " << lengthOfLIS_binary_search(nums) << std::endl; // Output: 4
    return 0;
}