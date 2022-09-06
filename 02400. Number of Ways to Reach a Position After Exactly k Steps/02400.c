#define MAX_LEVEL   1001
#define MODULO      1000000007

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int combination(int n, int r) {
    static bool once = false;
    static int table[MAX_LEVEL][MAX_LEVEL] = {};

    if (once == false) {
        once = true;

        // use Pascal’s Triangle to precompute the nCr
        for (int i = 1, j; i < MAX_LEVEL; ++i) {
            table[i][1] = i;
            for (j = 2; j <= i; ++j) {
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % MODULO;
            }
        }
    }

    return table[n][r];
}

int numberOfWays(int startPos, int endPos, int k) {
    if (startPos > endPos) {
        swap(&startPos, &endPos);
    }

    int diff = endPos - startPos;

    if (diff == k) {
        return 1;
    } else if (diff > k || ((k - diff) & 1) != 0) {
        return 0;
    }

    // divide the left and right step into two parts
    int part1 = (k - diff) / 2, part2 = k - part1;
    if (part1 > part2) {
        part1 = part2;
    }

    return combination(k, part1);
}
