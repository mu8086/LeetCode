#define MAX 46341

int mySqrt(int x) {
    static bool once = false;
    static unsigned int i, square[MAX];
    
    if (!once) {
        once = true;
        for (i=0; i<MAX; ++i) {
            square[i] = i * i;
        }
    }

    for (i=0; i<MAX; ++i) {
        if (square[i] > x) {
            break;
        }
    }
    
    return i-1;
}
