#define MAX_LADDER_SIZE 100000

int searchIndex(int list[], int size, int value) {
    if (size == 0) {
        return 0;
    }
    
    int ret;
    int left = 0, right = size-1;
    int half, f_half, halfIndex;
    
    while (true) {
        halfIndex = (left + right) / 2;
        half = list[halfIndex];
        if (left == right) {
            ret = (value < list[halfIndex]) ? halfIndex : halfIndex+1;
            break;
        }
        f_half = list[halfIndex-1];
        
        if (f_half <= value && value < half) {
            ret = halfIndex;
            break;
        } else if (half > value) {
            right = halfIndex-1;
        } else if (half <= value) {
            left = halfIndex+1;
        }
    }
    
    return ret;
}

void popAndInsert(int list[], int size, int value) {
    if (size == 1 || value < list[1]) {
        list[0] = value;
        return;
    }
    
    static int tmp[MAX_LADDER_SIZE];
    int index = searchIndex(&list[1], size-1, value);
    int copySize = sizeof(int) * index;
    
    memcpy(tmp, &list[1], copySize);
    memcpy(list, tmp, copySize);
    
    list[index] = value;
}

void insertValueToListInIndex(int list[], int size, int index, int value) {
    static int tmp[MAX_LADDER_SIZE];
    
    if (size != index) {
        int copySize = sizeof(int) * (size - index);

        memcpy(tmp, &list[index], copySize);
        memcpy(&list[index+1], tmp, copySize);
    }
    
    list[index] = value;
}

void insert(int list[], int size, int value) {
    int index = searchIndex(list, size, value);
    insertValueToListInIndex(list, size, index, value);
}

int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    int i, diff;
    static int inListSize = 0, listSize = sizeof(int) * MAX_LADDER_SIZE;
    static int list[MAX_LADDER_SIZE];

    if (ladders != 0) {
        int min;
        inListSize = 0;
        memset(list, 0, listSize);
        
        for (i = 1; i < heightsSize; ++i) {
            if (heights[i] > heights[i-1]) {
                diff = heights[i] - heights[i-1];
                if (ladders > 0) {
                    --ladders;
                    insert(list, inListSize, diff);
                    ++inListSize;
                    continue;
                }
                
                min = list[0];
                if (diff > min) {
                    popAndInsert(list, inListSize, diff);
                    bricks -= min;
                } else {
                    bricks -= diff;
                }
                
                if (bricks < 0) {
                    --i;
                    break;
                }
            }
        }
    } else {
        for (i = 1; i < heightsSize; ++i) {
            if (heights[i] > heights[i-1]) {
                diff = heights[i] - heights[i-1];
                bricks -= diff;
                if (bricks < 0) {
                    --i;
                    break;
                }
            }
        }
    }

    return (i != heightsSize) ? i : heightsSize-1;
}
