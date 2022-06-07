void getCandy(int index, int *candys, int *ratings, int ratingsSize) {
    if (candys[index] != 0) {
        return ;
    }
    
    int left = 0, right = 0;

    if (index > 0 && ratings[index] > ratings[index-1]) {
        getCandy(index-1, candys, ratings, ratingsSize);
        left = candys[index-1];
    }
    if (index < ratingsSize-1 && ratings[index] > ratings[index+1]) {
        getCandy(index+1, candys, ratings, ratingsSize);
        right = candys[index+1];
    }
    
    candys[index] = (left > right) ? left+1 : right+1;
}

int candy(int* ratings, int ratingsSize) {
    int i, sum;
    int *candys = (int *) malloc(sizeof(int) * ratingsSize);
    memset(candys, 0, sizeof(int) * ratingsSize);
    
    for (i=0, sum=0; i<ratingsSize; ++i) {
        getCandy(i, candys, ratings, ratingsSize);
        sum += candys[i];
    }
    
    free(candys);
    return sum;
}
