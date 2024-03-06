// https://leetcode.com/problems/maximum-ice-cream-bars

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxIceCream(int *costs, int costsSize, int coins) {
    int i;

    qsort(costs, costsSize, sizeof(int), compare);

    for (i=0; i<costsSize; ++i) {
        if (coins < costs[i]) {
            return i;
        }
        coins -= costs[i];
    }

    return costsSize;
}
