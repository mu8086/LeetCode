double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int sum = nums1Size + nums2Size;
    int index1 = sum >> 1;
    int index2 = index1 + (sum & 1) - 1;
    int i=0, j=0;
    int a, b;
    
    for (int count=0; count <= index2; count++) {
        if (i == nums1Size) {
            a = nums2[j];
            j++;
        } else if (j == nums2Size) {
            a = nums1[i];
            i++;
        } else {
            if (nums1[i] <= nums2[j]) {
                a = nums1[i];
                i++;
            } else {
                a = nums2[j];
                j++;
            }
        }
    }

    if (index1 == index2)
        return (double) a;

    if (i == nums1Size) {
        b = nums2[j];
    } else if (j == nums2Size) {
        b = nums1[i];
    } else {
        if (nums1[i] < nums2[j])
            b = nums1[i];
        else
            b = nums2[j];
    }
    
    return (a + b)/2.0;
}
