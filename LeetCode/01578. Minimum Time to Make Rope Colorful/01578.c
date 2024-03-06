int minCost(char * colors, int *neededTime, int neededTimeSize) {
    int count = 0;
    int i, head, maxOfSame, sumOfSame;
    
    for (i = 1, head = 0, maxOfSame = sumOfSame = neededTime[0]; i < neededTimeSize; ++i) {
        if (colors[i-1] == colors[i]) {
            maxOfSame = (maxOfSame > neededTime[i]) ? maxOfSame : neededTime[i];
            sumOfSame += neededTime[i];
        } else {
            if (i-1 > head) {
                count += sumOfSame - maxOfSame;
            }
            
            head = i;
            maxOfSame = sumOfSame = neededTime[i];
        }
    }
    
    if (i-1 > head) {
        count += sumOfSame - maxOfSame;
    }
    
    return count;
}
