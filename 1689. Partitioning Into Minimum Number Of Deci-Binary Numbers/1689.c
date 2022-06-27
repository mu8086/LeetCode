int minPartitions(char * n) {
    char c, maxDigit = '\0';
    
    while ((c = *n) != '\0') {
        maxDigit = (maxDigit > c) ? maxDigit : c;
        ++n;
    }

    return maxDigit - '0';
}
