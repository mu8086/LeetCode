int minAddToMakeValid(char * s){
    int index, len=strlen(s);
    int local=0, total=0;
    
    for (index=0; index<len; index++) {
        if (s[index] == '(') {
            if (local < 0) {
                total -= local;
                local = 1;
            } else {
                local++;
            }
        } else {
            local--;
        }
    }
    
    if (local < 0) {
        local = -local;
    }
    
    return total + local;
}
