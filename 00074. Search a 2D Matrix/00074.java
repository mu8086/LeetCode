class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;
        int begin = 0, end = row * col - 1, half, halfValue;
        
        while (begin <= end) {
            half = (begin + end) / 2;
            halfValue = matrix[half / col][half % col];
                
            if (target == halfValue) {
                return true;
            } else if (target > halfValue) {
                begin = half+1;
            } else {
                end = half-1;
            }
        }
        
        return false;
    }
}
