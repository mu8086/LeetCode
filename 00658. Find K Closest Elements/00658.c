// https://leetcode.com/problems/find-k-closest-elements

int x;

int compare(const void *aa, const void *bb) {
    int a = *(int *)aa, b = *(int *)bb;
    a = (a > x) ? a-x : x-a;
    b = (b > x) ? b-x : x-b;

    if (a == b) {
        return *(int *)aa - *(int *)bb;
    }
    return a - b;
}

int compare2(const void *aa, const void *bb) {
    return *(int *)aa - *(int *)bb;
}

int * findClosestElements(int *arr, int arrSize, int k, int target, int *returnSize) {
    x = target;
    *returnSize = k;
    int *ret = (int *) malloc(sizeof(int) * k);

    qsort(arr, arrSize, sizeof(int), compare);

    memcpy(ret, arr, sizeof(int) * k);
    qsort(ret, k, sizeof(int), compare2);

    return ret;
}
