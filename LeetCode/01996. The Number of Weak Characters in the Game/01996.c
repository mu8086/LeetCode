int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa, *b = *(int **)bb;

    if (a[0] != b[0]) {
        return b[0] - a[0];
    }
    return a[1] - b[1];
}

int numberOfWeakCharacters(int **properties, int propertiesSize, int *propertiesColSize) {
    int count = 0;

    qsort(properties, propertiesSize, sizeof(int) * 2, compare);

    for (int i = 0, max = 0; i < propertiesSize; ++i) {
        if (max > properties[i][1]) {
            ++count;
        }
        
        max = (max > properties[i][1]) ? max : properties[i][1];
    }

    return count;
}
