int getNextBarIndex(char *s, int index) {
    int i;
    
    for (i = index+1; s[i] != '\0'; ++i) {
        if (s[i] == '|') {
            break;
        }
    }
    
    return (s[i] == '|') ? i : -1;
}

int countS(char *s, int *index) {
    int count, i;
    
    for (i = *index, count = 0; s[i] != '\0' && s[i] != '|'; ++i) {
        if (s[i] == '*') {
            ++count;
        }
    }
    *index = i;
    return count;
}

int countAsterisks(char * s) {
    int index, len_s = strlen(s);
    int count = 0;
    
    index = 0;
    while (index < len_s && index != -1) {
        count += countS(s, &index);
        if (index >= len_s || index == -1) {
            break;
        }
        index = getNextBarIndex(s, index)+1;
    }
    
    return count;
}
