// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int pair = 0, dup_letter = 0;

        unordered_map<string, int> m;
        unordered_map<string, int>::iterator m_it;

        for (string word : words) {
            string rev = string(&word[1], 1) + string(&word[0], 1);
            if (word == rev) {
                ++dup_letter;
            }

            m_it = m.find(rev);
            if (m_it == m.end() || m_it->second == 0) {    // not found matched partner
                ++m[word];
            } else {
                ++pair;
                --m[rev];

                if (word == rev) {
                    dup_letter -= 2;
                }
            }
        }

        if (dup_letter > 1) {
            dup_letter = 1; // only use one set in ans
        }
        return pair * 4 + dup_letter * 2;
    }
};
