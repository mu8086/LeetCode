// https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; !pq.empty(); ++i, pq.pop()) {
            nums[i] = pq.top();
        }
        return nums;
    }
};
