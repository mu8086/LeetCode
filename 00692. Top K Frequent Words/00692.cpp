// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }

    vector<pair<string, int>> sort(map<string, int>& m) {
        vector<pair<string, int>> v;

        for (auto& it : m) {
            v.push_back(it);
        }

        std::sort(v.begin(), v.end(), cmp);

        return v;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        std::map<std::string, int> m;
        std::map<std::string, int>::iterator it;

        for (auto & word : words) {
            if ((it = m.find(word)) == m.end()) {
                // not found;
                m.insert(std::pair<std::string, int>(word, 1));
            } else {
                ++(it->second);
            }
        }

        auto v = sort(m);
        vector<string> ans;

        for (auto it2 = v.rbegin(); k > 0 && it2 != v.rend(); --k, ++it2) {
            ans.push_back(it2->first);
        }

        return ans;
    }
};
