int trap(int *height, int heightSize) {
    int i, carrySum, headIdx;
    int water = 0;
    
    for (i = 1, headIdx = 0, carrySum = 0; i < heightSize; ++i) {
        if (height[i] >= height[headIdx]) {
            water += (i-headIdx-1) * fmin(height[i], height[headIdx]) - carrySum;

            headIdx = i;
            carrySum = 0;
        } else {
            carrySum += height[i];
        }
    }
    
    for (i = heightSize-2, headIdx = heightSize-1, carrySum = 0; i >= 0; --i) {
        // Only the larger ones are counted, preventing double-counting the equal case
        if (height[i] > height[headIdx]) {
            water += (headIdx-i-1) * fmin(height[i], height[headIdx]) - carrySum;

            headIdx = i;
            carrySum = 0;
        } else {
            carrySum += height[i];
        }
    }
    
    return water;
}
