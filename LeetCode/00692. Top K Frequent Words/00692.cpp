// https://leetcode.com/problems/top-k-frequent-words

struct Compare {
    bool operator() (pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> m;

        for (int i = 0; i < words.size(); ++i) {
            ++m[words[i]];
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> q;
        for (auto pair : m) {
            q.push({pair.first, pair.second});
        }

        while (k--) {
            ans.push_back(q.top().first);
            q.pop();
        }

        return ans;
    }
};
