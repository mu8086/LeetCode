#define MAX 46341

bool isPerfectSquare(int num){
    static bool once = false;
    static unsigned int i, square[MAX];
    
    if (!once) {
        once = true;
        for (i=0; i<MAX; ++i) {
            square[i] = i * i;
        }
    }

    for (i=0; i<MAX; ++i) {
        if (square[i] == num) {
            return true;
        } else if (square[i] > num) {
            break;
        }
    }
    
    return false;
}
