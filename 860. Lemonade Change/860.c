bool lemonadeChange(int* bills, int billsSize) {
    int i, five, ten, twenty;
    
    for (i=0, five=0, ten=0, twenty=0; i<billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five >= 1) {
                five--;
                ten++;
            } else {
                return false;
            }
        } else {
            if (ten >= 1 && five >= 1) {
                five--;
                ten--;
                twenty++;
            } else if (five >= 3) {
                five -= 3;
                twenty++;
            } else {
                return false;
            }
        }
    }
        
    return true;
}
