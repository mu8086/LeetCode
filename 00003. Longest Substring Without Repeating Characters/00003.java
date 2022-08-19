class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> pos = new HashMap<>();
        int i, head, maxLen;
        
        for (i = 0, head = 0, maxLen = 0; i < s.length(); ++i) {
            if (pos.containsKey(s.charAt(i))) {
                head = Math.max(head, pos.get(s.charAt(i))+1);
            }
            
            pos.put(s.charAt(i), i);
            maxLen = Math.max(maxLen, i-head+1);
        }
        
        return maxLen;
    }
}
