int getContinuationSize(int byte) {
    static int flag[4]   = {128, 224, 240, 248};
    static int target[4] = {  0, 192, 224, 240};

    for (int i = 0; i < 4; ++i) {
        if ((byte & flag[i]) == target[i]) {
            return i;
        }
    }

    return -1;
}

bool verifyContinuation(int byte) {
    return (byte & 192) == 128;
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
