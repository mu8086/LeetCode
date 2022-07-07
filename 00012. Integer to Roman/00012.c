char * intToRoman(int num){
    char* ret = (char*) malloc(sizeof(char) * 20);
    memset(ret, 0, sizeof(char) * 20);
    
    for (int i=0; num > 0; i++) {
        if (num >= 1000) {
            num -= 1000;
            ret[i] = 'M';
        } else if (num >= 900) {
            num -= 900;
            ret[i] = 'C';
            i++, ret[i] = 'M';
        } else if (num >= 500) {
            num -= 500;
            ret[i] = 'D';
        } else if (num >= 400) {
            num -= 400;
            ret[i] = 'C';
            i++, ret[i] = 'D';
        } else if (num >= 100) {
            num -= 100;
            ret[i] = 'C';
        } else if (num >= 90) {
            num -= 90;
            ret[i] = 'X';
            i++, ret[i] = 'C';
        } else if (num >= 50) {
            num -= 50;
            ret[i] = 'L';
        } else if (num >= 40) {
            num -= 40;
            ret[i] = 'X';
            i++, ret[i] = 'L';
        } else if (num >= 10) {
            num -= 10;
            ret[i] = 'X';
        } else if (num >= 9) {
            num -= 9;
            ret[i] = 'I';
            i++, ret[i] = 'X';
        } else if (num >= 5) {
            num -= 5;
            ret[i] = 'V';
        } else if (num >= 4) {
            num -= 4;
            ret[i] = 'I';
            i++, ret[i] = 'V';
        } else if (num >= 1) {
            num -= 1;
            ret[i] = 'I';
        }
    }
    
    return ret;
}
