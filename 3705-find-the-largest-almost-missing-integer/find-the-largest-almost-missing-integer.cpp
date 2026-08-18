class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // If the whole array itself is the only subarray
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // For k = 1, an element must occur exactly once
        if (k == 1) {
            unordered_map<int, int> freq;
            for (int x : nums) freq[x]++;

            int ans = -1;
            for (auto &[x, count] : freq) {
                if (count == 1) ans = max(ans, x);
            }
            return ans;
        }

        // For 1 < k < n, only first or last element
        // can belong to exactly one subarray of size k.
        int ans = -1;

        if (count(nums.begin(), nums.end(), nums[0]) == 1)
            ans = max(ans, nums[0]);

        if (count(nums.begin(), nums.end(), nums[n - 1]) == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};