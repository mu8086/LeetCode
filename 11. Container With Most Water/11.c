int bruteCalArea(int* height, int heightSize) {
    int result=0, local=0;
    
    for (int i=1; i<heightSize; i++) {
        local = calArea(getLowerHeight(height[0], height[i]), i);
        result = result > local ? result : local;
    }
    
    return result;
}

int calArea(int height, int width) {
    return height * width;
}

int getLowerHeight(int a, int b)
{
    return a<b ? a : b ;
}

int maxArea(int* height, int heightSize){
    if (heightSize == 2) {
        return calArea(getLowerHeight(height[0], height[1]), 1);
    } else {
        int subResult = maxArea(&height[1], heightSize-1);
        int bruteResult = 0;
        if (height[0] * (heightSize-1) > subResult) {
            bruteResult = bruteCalArea(height, heightSize);
        }
        return subResult>bruteResult ? subResult : bruteResult ;
    }
}
