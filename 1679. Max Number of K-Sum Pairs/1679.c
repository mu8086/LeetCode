int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maxOperations(int* nums, int numsSize, int k){
    int front, end, ret, req;
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (front=0, end=numsSize-1, ret=0; front<end; front++) {
        for (req=k-nums[front]; nums[end]>req && front<end; end--) {
            ;
        }
        if (front == end) {
            break;
        } else if (nums[end] == req) {
            ret++;
            end--;
        }
    }
    
    return ret;
}
