void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, *ans = nums1;
    --m, --n;
    
    for (i = nums1Size - 1; i >= 0; --i) {
        if (m >= 0 && n >= 0) {
            if (nums1[m] >= nums2[n]) {
                ans[i] = nums1[m--];
            } else {
                ans[i] = nums2[n--];
            }
        } else if (m >= 0) {
            ans[i] = nums1[m--];
        } else {
            ans[i] = nums2[n--];
        }
    }
}
