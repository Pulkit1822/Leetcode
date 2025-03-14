/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
class Solution {
    long long func(vector<int>& arr, int mid, long long k) {
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++)
            if (mid > 0) ans += (arr[i] / mid);
        return ans >= k;
    }

public:
    long long maximumCandies(vector<int>& candies, long long k) {
        long long l = 1;
        long long h = *max_element(candies.begin(), candies.end());
        while (l <= h) {
            long long mid = (h + l) / 2;
            if (func(candies, mid, k)) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return h;
    }
};
// @lc code=end

