// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> m;
        unordered_map <int, int>::iterator it;

        for (int i = 0; i < nums.size(); ++i) {
            it = m.find(nums[i]);
            if (it == m.end()) {
                m.insert({nums[i], i});
            } else {
                if (i - it->second <= k) {
                    return true;
                }

                it->second = i;
            }
        }

        return false;
    }
};
