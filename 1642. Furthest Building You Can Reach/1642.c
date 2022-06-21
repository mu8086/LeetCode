#define MAX_LADDER_SIZE 100000

void popAndInsert(int list[], int size, int value) {
    int left = 0, right = size-1;
    int half, f_half, halfIndex;
    static int tmp[MAX_LADDER_SIZE];
    
    list[0] = 0;    // reset to 0 for while-loop
    
    if (size == 1 || value < list[1]) {
        list[0] = value;
        return;
    }
    
    if (value > list[size-1]) {
        memcpy(tmp, &list[1], sizeof(int) * (size-1));
        memcpy(list, tmp, sizeof(int) * (size-1));
        list[size] = value;
        return;
    }
    
    if (left <= right) {
        while (true) {
            halfIndex = (left + right) / 2;
            half    = list[halfIndex];
            f_half  = (halfIndex > 0) ? list[halfIndex-1] : 0;

            if (f_half <= value && value < half) {
                memcpy(tmp, &list[1], sizeof(int) * (halfIndex-1));
                memcpy(list, tmp, sizeof(int) * (halfIndex-1));
                list[halfIndex-1] = value;
                break;
            } else if (left == right) {
                memcpy(tmp, &list[1], sizeof(int) * halfIndex);
                memcpy(list, tmp, sizeof(int) * halfIndex);
                list[halfIndex] = value;
                break;
            } else if (half <= value) {
                left = halfIndex+1;
            } else if (half > value) {
                right = halfIndex-1;
            }
        }
    }
}

void insert(int list[], int size, int value) {
    int left = 0, right = size-1;
    int half, f_half, halfIndex;
    static int tmp[MAX_LADDER_SIZE];

    if (size == 0 || value < list[0]) {
        for (int i = size-1; i >= 0; i--) {
            list[i+1] = list[i];
        }
        list[0] = value;
        return;
    }
    
    if (value > list[size-1]) {
        list[size] = value;
        return;
    }
    
    while (true) {
        halfIndex = (left + right) / 2;
        half    = list[halfIndex];
        f_half  = (halfIndex > 0) ? list[halfIndex-1] : 0;

        if (f_half <= value && value < half) {
            memcpy(tmp, &list[halfIndex], sizeof(int) * (size-halfIndex));
            memcpy(&list[halfIndex+1], tmp, sizeof(int) * (size-halfIndex));
            list[halfIndex] = value;
            break;
        } else if (left == right) {
            memcpy(tmp, &list[1], sizeof(int) * halfIndex);
            memcpy(list, tmp, sizeof(int) * halfIndex);
            list[halfIndex] = value;
            break;
        } else if (half <= value) {
            left = halfIndex+1;
        } else if (half > value) {
            right = halfIndex-1;
        }
    }
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
