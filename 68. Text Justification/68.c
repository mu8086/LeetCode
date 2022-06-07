#define MAX_LINE    300

char ** char2dArray(int length, int width) {
    // ret[width][length]
    char **ret = (char **) malloc(sizeof(char *) * width + sizeof(char) * width * length);
    
    char *first = (char *)(ret + width);
    memset(first, ' ', sizeof(char) * width * length);
    
    for (int i=0; i<width; ++i) {
        ret[i] = first + i * length;
        ret[i][length-1] = '\0';
    }
    
    return ret;
}

int fillIndexRange(char **words, int wordsSize, int maxWidth, int indexRange[MAX_LINE][2], int spaceSize[MAX_LINE]) {
    int indexRangeSize, leftWordsIndex, wordLen, lineLeftSpace;
    
    for (indexRangeSize = 0, leftWordsIndex = 0; leftWordsIndex < wordsSize; ++indexRangeSize) {
        indexRange[indexRangeSize][0]   = leftWordsIndex;
        indexRange[indexRangeSize][1]   = leftWordsIndex;
        
        wordLen = strlen(words[leftWordsIndex]);
        lineLeftSpace                   = maxWidth - wordLen;
        spaceSize[indexRangeSize]       = maxWidth - wordLen;
        
        for (++leftWordsIndex; leftWordsIndex < wordsSize && lineLeftSpace > 0; lineLeftSpace -= wordLen) {
            --lineLeftSpace;    // the space char ' '

            wordLen = strlen(words[leftWordsIndex]);
            if (lineLeftSpace >= wordLen) {
                spaceSize[indexRangeSize] -= wordLen;
                indexRange[indexRangeSize][1] = leftWordsIndex;
                ++leftWordsIndex;
            }
        }
    }
    
    return indexRangeSize;
}

void fillAns(char **ans, char **words, int maxWidth, int indexRange[MAX_LINE][2], int indexRangeSize, int spaceSize[MAX_LINE]) {
    int i, line, wordLen, tmp;
    int spaceLen, spaceExt, spaceDelimiters;
    int last1Line = indexRangeSize - 1, last2Line = indexRangeSize - 2;

    for (line = 0; line <= last1Line; ++line) {
        spaceDelimiters = indexRange[line][1] - indexRange[line][0];

        if (spaceDelimiters > 0) {
            spaceLen = spaceSize[line] / spaceDelimiters;
            spaceExt = spaceSize[line] % spaceDelimiters;
        }
        if (line == last1Line) {
            spaceLen = 1;
            spaceExt = 0;
        }
        
        // first word in line
        wordLen = strlen(words[indexRange[line][0]]);
        memcpy(&ans[line][0], words[indexRange[line][0]], wordLen);
        tmp = wordLen;

        // left words and space
        for (i = indexRange[line][0] + 1; i <= indexRange[line][1]; ++i) {
            tmp += spaceLen;
            if (spaceExt > 0) {
                ++tmp;
                --spaceExt;
            }
            wordLen = strlen(words[i]);
            memcpy(&ans[line][tmp], words[i], wordLen);
            tmp += wordLen;
        }
    }
}

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize) {
    int indexRange[MAX_LINE][2], spaceSize[MAX_LINE];
    
    *returnSize = fillIndexRange(words, wordsSize, maxWidth, indexRange, spaceSize);
    
    char **ans = char2dArray(maxWidth+1, *returnSize);
    
    fillAns(ans, words, maxWidth, indexRange, *returnSize, spaceSize);

    return ans;
}
