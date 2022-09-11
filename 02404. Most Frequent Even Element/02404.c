#define MAX_SIZE    100001

int mostFrequentEven(int *nums, int numsSize) {
    int i, ans = -1, max = -1;
    int freq[MAX_SIZE] = {};
    
    for (i = 0; i < numsSize; ++i) {
        if (nums[i] % 2 == 0) {
            ++freq[nums[i]];
            max = (max > freq[nums[i]]) ? max : freq[nums[i]];
        }
    }
    
    for (i = 0; i < MAX_SIZE; i += 2) {
        if (freq[i] == max) {
            ans = i;
            break;
        }
    }

    return ans;
}
