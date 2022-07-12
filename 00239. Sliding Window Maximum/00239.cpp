#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 1 || k == 1) {
            return nums;
        }
        
        vector<int> ret;
        ret.reserve(nums.size() - k + 1);
        
        deque<int> dq;

        for (int i = 0, numSize = nums.size(); i < numSize; ++i) {
            if (i > k-2) {
                while (!dq.empty() && dq.front() <= i-k) {
                    dq.pop_front();
                }
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            if (i >= k-1) {
                ret.push_back(nums[dq.front()]);
            }
        }
        
        return ret;
    }
};
