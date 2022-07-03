double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income) {
    int i, tmp, lastBase;
    double tax;
    

    for (i = 0, lastBase = 0, tax = 0.0; i < bracketsSize; ++i) {
        tmp = (income <= brackets[i][0]) ? income : brackets[i][0];
        
        tax += (tmp - lastBase) * brackets[i][1] / 100.0;
        
        lastBase = brackets[i][0];
        
        if (tmp == income) {
            break;
        }
    }
    
    return tax;
}
