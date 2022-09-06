#define MAX_STEP    45

int climbStairs(int n) {
    static int once = false, ans[MAX_STEP] = {1, 2};
    
    if (once == false) {
        once = true;
        
        for (int i = 2; i < MAX_STEP; ++i) {
            ans[i] = ans[i-2] + ans[i-1];
        }
    }
    
    return ans[n-1];
}
