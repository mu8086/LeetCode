int lengthOfLastWord(char * s) {
    int count=0, flag=0;
    
    for (int i=strlen(s)-1; i>=0; i--) {
        if (s[i] != ' ') {
            flag = 1;
        } else {
            if (flag == 1) {
                break;
            }
        }
        if (flag == 1) {
            count++;
        }
    }
    
    return count;
}
