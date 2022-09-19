#define NOT_FOUND           -1
#define SAME_STRING         0
#define MAX_FILENAME_COUNT  20000

int getDelimiterIdx(char *s, int beginIdx, char delimiter) {
    for (int i = beginIdx; s[i] != '\0'; ++i) {
        if (s[i] == delimiter) {
            return i;
        }
    }

    return NOT_FOUND;
}

// return mapSize
int setMap(char *map[MAX_FILENAME_COUNT][2], char **paths, int pathsSize) {
    int i, delimiterIdx, mapIdx;
    int path_len, prefix_len, filename_len;
    char *s         = NULL;
    char *prefix    = NULL;
    char *filename  = NULL;
    char *content   = NULL;
    char *fullname  = NULL;

    for (i = 0, mapIdx = 0; i < pathsSize; ++i) {
        s = paths[i];
        path_len = strlen(paths[i]);

        // [prefix]
        prefix = s;
        delimiterIdx = getDelimiterIdx(s, 0, ' ');
        s[delimiterIdx] = '\0';

        while (delimiterIdx < path_len) {
            // [filename]
            filename = s + delimiterIdx + 1;
            delimiterIdx = getDelimiterIdx(s, delimiterIdx+1, '(');
            s[delimiterIdx] = '\0';

            // [content]
            content = s + delimiterIdx + 1;
            delimiterIdx = getDelimiterIdx(s, delimiterIdx+1, ')');
            s[delimiterIdx++] = '\0';   // use '++' to bypass the space character between filenames

            // [fullname]
            prefix_len = strlen(prefix);
            filename_len = strlen(filename);
            fullname = (char *) malloc(sizeof(char) * (prefix_len + filename_len + 2)); // +2: 1 for '/' between prefix & filename, 1 for ending '\0'
            memcpy(fullname, prefix, prefix_len);
            fullname[prefix_len] = '/';
            memcpy(fullname+prefix_len+1, filename, filename_len+1);

            // [set to map]
            map[mapIdx][0] = content, map[mapIdx][1] = fullname;
            ++mapIdx;
        }
    }

    return mapIdx;
}

int compare(const void *aa, const void *bb) {
    char **a = *(char ***)aa, **b = *(char ***)bb;
    return strcmp(a, b);
}

void setReturnValues(char ***ret, int row, int *columnSize, char **stringList, int stringCount) {
    columnSize[row] = stringCount;

    ret[row] = (char **) malloc(sizeof(char *) * stringCount);
    memcpy(ret[row], stringList, sizeof(char *) * stringCount);
}

void classifyFullnameAndSetReturnValues(char ***ret, int *returnSize, int **returnColumnSizes, char *map[MAX_FILENAME_COUNT][2], int mapSize) {
    int i, count;
    char *last = "";
    char **fullname_list_of_same_content = (char **) malloc(sizeof(char *) * mapSize);

    for (i = 0, count = 0; i < mapSize; ++i) {
        if (strcmp(last, map[i][0])) {
            last = map[i][0];

            if (count > 1) {
                setReturnValues(ret, *returnSize, *returnColumnSizes, fullname_list_of_same_content, count);
                ++(*returnSize);
            }

            count = 0;
        }

        fullname_list_of_same_content[count++] = map[i][1];
    }
    if (count > 1) {
        setReturnValues(ret, *returnSize, *returnColumnSizes, fullname_list_of_same_content, count);
        ++(*returnSize);
    }

    free(fullname_list_of_same_content);
}

char *** findDuplicate(char ** paths, int pathsSize, int *returnSize, int **returnColumnSizes) {
    // map[][0] -> content, map[][1] -> fullname
    char *map[MAX_FILENAME_COUNT][2] = {};

    int mapSize = setMap(map, paths, pathsSize);

    // sort map by content
    qsort(map, mapSize, sizeof(char **) * 2, compare);


    *returnSize = 0;
    char ***ret = (char ***) malloc(sizeof(char **) * mapSize);
    *returnColumnSizes = (int *) malloc(sizeof(int) * mapSize);
    classifyFullnameAndSetReturnValues(ret, returnSize, returnColumnSizes, map, mapSize);

    return ret;
}
