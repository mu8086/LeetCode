void setAns(int *ans, int prefix, int leftDigits, int k, int *returnSize) {
    if (leftDigits > 0) {
        int unit = prefix % 10;
        
        if (0 <= unit - k) {
            setAns(ans, prefix * 10 + unit - k, leftDigits-1, k, returnSize);
        }
        
        if (k != 0 && unit + k <= 9) {
            setAns(ans, prefix * 10 + unit + k, leftDigits-1, k, returnSize);
        }
    } else {
        ans[(*returnSize)++] = prefix;
    }
}

int * numsSameConsecDiff(int n, int k, int *returnSize) {
    int leading;
    int *ans = (int *) malloc(sizeof(int) * 1556);
    
    *returnSize = 0;
    for (leading = 1; leading <= 9; ++leading) {
        setAns(ans, leading, n-1, k, returnSize);
    }
    
    return ans;
}
