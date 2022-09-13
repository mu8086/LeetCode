int getContinuationSize(int byte) {
    static int flag[4]   = { 0b10000000, 0b11100000, 0b11110000, 0b11111000 };
    static int target[4] = { 0b00000000, 0b11000000, 0b11100000, 0b11110000 };
    
    for (int i = 0; i < 4; ++i) {
        if ((byte & flag[i]) == target[i]) {
            return i;
        }
    }
    
    return -1;
}

bool verifyContinuation(int byte) {
    return (byte & 0b11000000) == 0b10000000;
}

bool validUtf8(int *data, int dataSize) {
    for (int i = 0, j, n = 0; i < dataSize; i += n+1) {
        if ((n = getContinuationSize(data[i])) == -1 || i + n >= dataSize) {
            return false;
        }
        
        for (j = i+1; j <= i+n; ++j) {
            if (verifyContinuation(data[j]) == false) {
                return false;
            }
        }
    }
    
    return true;
}
