class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i, subarray, n = nums.size();
        int prefix[n];
        
        for (i = 1, prefix[0] = nums[0]; i < n; ++i) {
            prefix[i] = nums[i] + prefix[i-1];
        }
        
        unordered_map<int, int> umap;
        
        for (i = 0, subarray = 0; i < n; ++i) {
            if (prefix[i] == k) {
                ++subarray;
            }
            
            if (umap.find(prefix[i] - k) != umap.end()) {
                subarray += umap[prefix[i] - k];
            }
            
            ++umap[prefix[i]];
        }
        
        return subarray;
    }
};
