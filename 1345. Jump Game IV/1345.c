#include <stdarg.h>

#define NEVER_SEEN              0
#define OK                      1
#define MEET_ANOTHER_QUEUE      2
#define FIRST_INDEX_NEVER_SEEN  -1
#define LAST_INDEX_NEVER_SEEN   -2

typedef struct {
    int arrIndex;
    int arrValue;
    int farFromFirstIndexOfSameValue;
    int farFromLastIndexOfSameValue;
} Node;

int * intArray(int size) {
    int *array = (int *) malloc(sizeof(int) * size);
    memset(array, NEVER_SEEN, sizeof(int) * size);
    return array;
}

int compare(const void *aa, const void *bb) {
    Node a = *(Node *)aa, b = *(Node *)bb;
    
    if (a.arrValue != b.arrValue) {
        return a.arrValue - b.arrValue;
    } else {
        return a.arrIndex - b.arrIndex;
    }
}

Node * sortedByValueList(int *arr, int arrSize) {
    int i, lastIndex = arrSize-1, count;
    Node *list = (Node *) malloc(sizeof(Node) * arrSize);
    
    for (i=0; i<=lastIndex; ++i) {
        list[i].arrValue = arr[i];
        list[i].arrIndex = i;
    }
    
    qsort(list, arrSize, sizeof(Node), compare);
    
    for (i=1, count=0; i<=lastIndex; ++i) {
        list[i-1].farFromFirstIndexOfSameValue = count++;
        
        if (list[i-1].arrValue != list[i].arrValue) {
            count = 0;
        }
    }
    list[i-1].farFromFirstIndexOfSameValue = count;
    
    for (i=lastIndex-1, count=0; i>=0; --i) {
        list[i+1].farFromLastIndexOfSameValue = count++;
        
        if (list[i+1].arrValue != list[i].arrValue) {
            count = 0;
        }
    }
    list[i+1].farFromLastIndexOfSameValue = count;
    
    return list;
}

int getIndexInSortedOfValue(int target, Node *sorted, int lastIndex) {
    int value, half, min = 0, max = lastIndex;
    
    while (true) {
        half = (max + min) / 2;
        value = sorted[half].arrValue;
        if (value == target) {
            break;
        } else if (max == min) {
            break;
        } else if (value > target) {
            max = half-1;
        } else {
            min = half+1;
        }
    }
    
    return half;
}

int getFirstIndexInSortedOfValue(int value, Node *sorted, int size) {
    int randomIndexInSortedOfValue = getIndexInSortedOfValue(value, sorted, size);
    return randomIndexInSortedOfValue - sorted[randomIndexInSortedOfValue].farFromFirstIndexOfSameValue;
}

int getLastIndexInSortedOfValue(int value, Node *sorted, int size) {
    int randomIndexInSortedOfValue = getIndexInSortedOfValue(value, sorted, size);
    return randomIndexInSortedOfValue + sorted[randomIndexInSortedOfValue].farFromLastIndexOfSameValue;
}

bool isEmptyQueue(int index, int size) {
    return index == size;
}

void _enQueue(int *queue, int *queueSize, int arrIndex, int step, int *steps) {
    queue[(*queueSize)++] = arrIndex;
    steps[arrIndex] = step;
}

bool meetAnotherQueue(int arrIndex, int newStep, int *steps) {
    return (steps[arrIndex] + newStep) % 2 != 0;
}

bool meetLastIndex(int lastArrIndex, int *steps) {
    return steps[lastArrIndex] != LAST_INDEX_NEVER_SEEN;
}

int enQueue(int *queue, int *queueSize, int lastArrIndex, int arrIndex, int newStep, int *steps) {
    if (steps[arrIndex] == NEVER_SEEN) {
        _enQueue(queue, queueSize, arrIndex, newStep, steps);
    } else if (meetAnotherQueue(arrIndex, newStep, steps)) {
        steps[lastArrIndex] = (steps[arrIndex] + newStep) / 2 + 1;
        return MEET_ANOTHER_QUEUE;
    }
    return OK;
}

bool isFromLeftQueue(int newStep) {
    return newStep % 2 == 1;
}

void deQueueAll(int *queue, int *queueIndex, int *queueSize, int *arr, int lastArrIndex, int newStep, int *steps, Node *sorted) {
    static bool tmp[200000001] = {}, *valueScaned = &tmp[100000000];
    
    int i, j, jBegin, jAfterEnd, jIncrement;
    int arrIndexInQueue, arrValueInQueue, oldQueueSize = *queueSize;
    
    for (i=*queueIndex; i<oldQueueSize && !meetLastIndex(lastArrIndex, steps); ++i) {
        arrIndexInQueue = queue[i];
        arrValueInQueue = arr[arrIndexInQueue];

        if (arrIndexInQueue > 0) {
            if (enQueue(queue, queueSize, lastArrIndex, arrIndexInQueue-1, newStep, steps) == MEET_ANOTHER_QUEUE) {
                break;
            }
        }
        if (arrIndexInQueue < lastArrIndex) {
            if (enQueue(queue, queueSize, lastArrIndex, arrIndexInQueue+1, newStep, steps) == MEET_ANOTHER_QUEUE) {
                break;
            }
        }
        
        if (valueScaned[arrValueInQueue] == false) {
            valueScaned[arrValueInQueue] = true;
            
            if (isFromLeftQueue(newStep)) {
                jBegin      = getLastIndexInSortedOfValue(arrValueInQueue, sorted, lastArrIndex);
                jAfterEnd   = -1;
                jIncrement  = -1;
            } else {
                jBegin      = getFirstIndexInSortedOfValue(arrValueInQueue, sorted, lastArrIndex);
                jAfterEnd   = lastArrIndex+1;
                jIncrement  = 1;
            }

            for (j = jBegin; j != jAfterEnd && sorted[j].arrValue == arrValueInQueue; j += jIncrement) {
                if (enQueue(queue, queueSize, lastArrIndex, sorted[j].arrIndex, newStep, steps) == MEET_ANOTHER_QUEUE) {
                    break;
                }
            }
        }
        
        ++(*queueIndex);
    }
    
    if (meetLastIndex(lastArrIndex, steps)) {
        memset(tmp, 0, sizeof(tmp));
    }
}

void doFree(void * allocate, ...) {
    void *target = allocate;
    
    va_list args;
    
    va_start(args, allocate);
    while (target != NULL) {
        free(target);
        target = va_arg(args, void *);
    }
    va_end(args);
}

int minJumps(int* arr, int arrSize) {
    if (arrSize == 1) {
        return 0;
    }

    Node *sortedList = sortedByValueList(arr, arrSize);
    int ret, lastArrIndex= arrSize-1, *steps = intArray(arrSize);

    int fromLeftQueueInitArrIndex = 0, fromLeftQueueStep = FIRST_INDEX_NEVER_SEEN;
    int fromLeftQueueIndex  = 0, fromLeftQueueSize  = 0, *fromLeftQueue = intArray(arrSize);
    enQueue(fromLeftQueue, &fromLeftQueueSize, lastArrIndex, fromLeftQueueInitArrIndex, fromLeftQueueStep, steps);
    fromLeftQueueStep = 1;

    int fromRightQueueInitArrIndex = lastArrIndex, fromRightQueueStep = LAST_INDEX_NEVER_SEEN;
    int fromRightQueueIndex = 0, fromRightQueueSize = 0, *fromRightQueue = intArray(arrSize);
    enQueue(fromRightQueue, &fromRightQueueSize, lastArrIndex, fromRightQueueInitArrIndex, fromRightQueueStep, steps);
    fromRightQueueStep = 2;
    
    while (!meetLastIndex(lastArrIndex, steps)) {
        deQueueAll(fromLeftQueue,  &fromLeftQueueIndex, &fromLeftQueueSize, arr, lastArrIndex, fromLeftQueueStep, steps, sortedList);
        fromLeftQueueStep += 2;

        if (!meetLastIndex(lastArrIndex, steps)) {
            deQueueAll(fromRightQueue, &fromRightQueueIndex, &fromRightQueueSize, arr, lastArrIndex, fromRightQueueStep, steps, sortedList);
            fromRightQueueStep += 2;
        }
    }

    ret = steps[lastArrIndex];
    
    doFree(sortedList, steps, fromLeftQueue, fromRightQueue, NULL);
    return ret;
}
