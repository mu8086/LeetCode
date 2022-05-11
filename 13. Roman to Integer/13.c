int getValue(char c) {
    switch (c) {
        case 'I':   return 1;
        case 'V':   return 5;
        case 'X':   return 10;
        case 'L':   return 50;
        case 'C':   return 100;
        case 'D':   return 500;
        case 'M':   return 1000;
    }
    return 0;
}

int romanToInt(char * s){
    int i, sum, curr, last, len = strlen(s);
    
    for (i=len-1, sum=curr=last=0; i>=0; i--) {
        curr = getValue(s[i]);
        sum += (curr >= last) ? curr : -curr;
        last = curr;
    }
    
    return sum;
}
