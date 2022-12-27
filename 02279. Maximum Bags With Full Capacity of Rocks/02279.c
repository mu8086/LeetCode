// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maximumBags(int *capacity, int capacitySize, int *rocks, int rocksSize, int additionalRocks) {
    int i, ans = 0;
    int *diff = capacity;

    for (i = 0; i < capacitySize; ++i) {
        diff[i] = capacity[i] - rocks[i];
    }

    qsort(diff, capacitySize, sizeof(int), compare);

    for (i = 0; i < capacitySize; ++i) {
        if (additionalRocks < diff[i]) {
            break;
        }

        additionalRocks -= diff[i];
        ++ans;
    }

    return ans;
}
