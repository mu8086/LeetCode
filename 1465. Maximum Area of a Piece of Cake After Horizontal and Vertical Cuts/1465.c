int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize) {
    int i, tmp;
    long long maxDiffH, maxDiffW;
    
    qsort(horizontalCuts, horizontalCutsSize, sizeof(int), compare);
    qsort(verticalCuts, verticalCutsSize, sizeof(int), compare);
    
    for (i = horizontalCutsSize-2, maxDiffH = h-horizontalCuts[horizontalCutsSize-1]; i >= 0; --i) {
        tmp = horizontalCuts[i+1] - horizontalCuts[i];
        maxDiffH = (maxDiffH >= tmp) ? maxDiffH : tmp;
    }
    maxDiffH = (maxDiffH >= horizontalCuts[0]) ? maxDiffH : horizontalCuts[0];
    
    for (i = verticalCutsSize-2, maxDiffW = w-verticalCuts[verticalCutsSize-1]; i >= 0; --i) {
        tmp = verticalCuts[i+1] - verticalCuts[i];
        
        maxDiffW = (maxDiffW >= tmp) ? maxDiffW : tmp;
    }
    maxDiffW = (maxDiffW >= verticalCuts[0]) ? maxDiffW : verticalCuts[0];

    return maxDiffH * maxDiffW % 1000000007;
}
