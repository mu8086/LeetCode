#define DONE 1

int** int2dArray(int m, int n) {
    int** ret = (int**) malloc(sizeof(int*) * m + sizeof(int) * m * n);

    int* first_int = (int*)(ret + m);
    for (int i=0; i<m; i++) {
        ret[i] = first_int + i * n;
    }
    memset(first_int, 0, sizeof(int) * m * n);
    
    return ret;
}

int getProduct(int** product, int* nums, int size_1, int index, int* ret, int k, int* max) {
    //printf("get [%d][%d]: %d\n", size_1, index, product[size_1][index]);
    if (max[index] != 0) {
        if (max[index] < size_1) {
            product[size_1][index] = k;
        }
    } else if (product[size_1][index] == 0) {
        int tmp = getProduct(product, nums, size_1-1, index+1, ret, k, max);
        product[size_1][index] = (tmp < k) ? nums[index] * tmp : k;
        if (product[size_1][index] < k) {
            //printf("ret: %d -> %d\n", *ret, (*ret)+1);
            (*ret)++;
        } else if (max[index] == 0) {
            max[index] = size_1;
        }
    }
    
    //printf("    end [%d][%d]: %d\n", size_1, index, product[size_1][index]);
    return product[size_1][index];
}

int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    int ret = 0;
    
    if (k == 0) {
        return 0;
    }
    
    int** product = int2dArray(numsSize, numsSize);
    memcpy(product[0], nums, sizeof(int) * numsSize);
    
    int* max = (int*) malloc(sizeof(int) * numsSize);
    memset(max, 0, sizeof(int) * numsSize);

    for (int i=0; i<numsSize; i++) {
        if (nums[i] < k) {
            ret++;
        }
    }
    
    int i, max_size_of_last_i, max_size_of_this_i, size;
    
    for (i=0, max_size_of_last_i=1, size; i<numsSize; i++) {        // for all index
        max_size_of_this_i = numsSize-i-1;
        for (size=max_size_of_last_i; size<=max_size_of_this_i; size++) {   // for all size
            if (getProduct(product, nums, size, i, &ret, k, max) >= k) {    // not less than k, try another i
                break;
            }
            max_size_of_last_i = size;  // record max available size of index i, then index i+1 start from this size to try
        }
        max_size_of_last_i = (max_size_of_last_i > 2) ? max_size_of_last_i-1 : 1;
    }
    
    free(product);
    return ret;
}
