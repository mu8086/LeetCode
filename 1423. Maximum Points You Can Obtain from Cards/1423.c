#define MAX_VAL 10001

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int i, sum, min, total;
    int otherCardsSize = cardPointsSize - k;
    
    for (i = 0, sum = 0, total = 0; i < cardPointsSize; ++i) {
        total += cardPoints[i];
        
        if (i < otherCardsSize) {
            sum = total;
            min = total;
        } else {
            sum += cardPoints[i] - cardPoints[i-otherCardsSize];
            min = (sum < min) ? sum : min;
        }
    }
    
    return total - min;
}
