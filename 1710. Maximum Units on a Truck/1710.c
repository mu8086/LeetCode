int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa, *b = *(int **)bb;
    return b[1] - a[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    int sum, i, tmp;
    
    qsort(boxTypes, boxTypesSize, sizeof(int *), compare);
    
    for (i = 0, sum = 0; i < boxTypesSize && truckSize > 0; ++i) {
        tmp = (truckSize >= boxTypes[i][0]) ? boxTypes[i][0] : truckSize;
        truckSize -= tmp;
        sum += tmp * boxTypes[i][1];
    }
    
    return sum;
}
