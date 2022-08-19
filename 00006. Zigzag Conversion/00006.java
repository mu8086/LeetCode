class Solution {
    public String convert(String s, int numRows) {
        int i = 0, j = 0, len = s.length();
        char[] c_array = s.toCharArray();
        
        StringBuffer[] bufs = new StringBuffer[numRows];
        for (i = 0; i < numRows; i++) {
            bufs[i] = new StringBuffer();
        }
        
        for (i = 0; i < len; ) {
            for (j = 0; j < numRows && i < len; j++) {
                bufs[j].append(c_array[i++]);
            }
            for (j = numRows-2; j > 0 && i < len; j--) {
                bufs[j].append(c_array[i++]);
            }
        }
        
        for (i = 1; i < numRows; i++) {
            bufs[0].append(bufs[i]);
        }
        
        return bufs[0].toString();
    }
}
