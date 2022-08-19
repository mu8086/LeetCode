class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int index1 = 0, index2 = 0, num = 0, lastNum = 0;
        
        for (int i = 0, steps = (nums1.length + nums2.length) / 2; i <= steps; ++i) {
            lastNum = num;
            
            if (index1 == nums1.length) {
                num = nums2[index2++];
            } else if (index2 == nums2.length) {
                num = nums1[index1++];
            } else if (nums1[index1] < nums2[index2]) {
                num = nums1[index1++];
            } else {
                num = nums2[index2++];
            }
        }
        
        if ((nums1.length + nums2.length) % 2 == 1) {
            return num;
        } else {
            return (num + lastNum) / 2.0;
        }
    }
}
