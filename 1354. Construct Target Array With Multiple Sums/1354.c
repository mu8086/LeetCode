#define MAX_SIZE        50001
#define INVALID         -1
#define PQ_TOP_INDEX    1

typedef struct {
    int size;
    int *heap;
} PriorityQueue;

int pqSize(PriorityQueue pq) {
    return pq.size;
}

int pqTop(PriorityQueue pq) {
    if (pqSize(pq) > 0) {
        return pq.heap[PQ_TOP_INDEX];
    }
    return INVALID;
}

bool pqLess(PriorityQueue pq, int a, int b) {
    return pq.heap[a] < pq.heap[b]; // greater value means less priority
}

void pqSwap(PriorityQueue *pq, int src, int dest) {
    int tmp         = pq->heap[src];
    pq->heap[src]   = pq->heap[dest];
    pq->heap[dest]  = tmp;
}

int pqLeftIndex(PriorityQueue pq, int index) {
    int size = pqSize(pq);
    if (index == 0 || index > size) {
        return INVALID;
    }
    
    int left = index << 1;      // index = index*2
    return (left <= size) ? left : INVALID;
}

int pqRightIndex(PriorityQueue pq, int index) {
    int size = pqSize(pq);
    if (index == 0 || index > size) {
        return INVALID;
    }
    
    int right = index << 1 | 1; // index = index*2+1
    return (right <= size) ? right : INVALID;
}

void pqSwin(PriorityQueue *pq, int index) {
    if (pqSize(*pq) <= 0) {
        return;
    }
    
    int parent = index / 2;
    while (index > PQ_TOP_INDEX && pqLess(*pq, parent, index)) {
        pqSwap(pq, parent, index);
        index = parent;
        parent /= 2;
    }
}

void pqPush(PriorityQueue *pq, int value) {
    pq->heap[++(pq->size)] = value;
    pqSwin(pq, pq->size);
}

void pqSink(PriorityQueue *pq, int index) {
    int leftIndex, rightIndex;
    
    if (pqSize(*pq) < 2 || index < PQ_TOP_INDEX) {
        return;
    }
    
    while ((leftIndex = pqLeftIndex(*pq, index)) != INVALID) {
        rightIndex = pqRightIndex(*pq, index);
        
        if (rightIndex != INVALID) {
            if (!pqLess(*pq, leftIndex, rightIndex)) {    // left >= right
                if (pqLess(*pq, index, leftIndex)) {
                    pqSwap(pq, index, leftIndex);
                    index = leftIndex;
                } else {
                    break;
                }
            } else {    // left < right
                if (pqLess(*pq, index, rightIndex)) {
                    pqSwap(pq, index, rightIndex);
                    index = rightIndex;
                } else {
                    break;
                }
            }
        } else {
            if (pqLess(*pq, index, leftIndex)) {
                pqSwap(pq, index, leftIndex);
                index = leftIndex;
            } else {
                break;
            }
        }
    }
}

int pqPop(PriorityQueue *pq) {
    if (pqSize <= 0) {
        return INVALID;
    }

    int ret = pqTop(*pq);
    pqSwap(pq, 1, pqSize(*pq));
    (pq->size)--;
    pqSink(pq, 1);
    return ret;
}

bool isPossible(int* target, int targetSize) {
    if (targetSize == 1) {
        return target[0] == 1;
    } else if (targetSize == 2 && (target[0] == 1 || target[1] == 1)) {
        return true;
    }

    static int heap[MAX_SIZE], heapSize = sizeof(int) * MAX_SIZE;
    memset(heap, 0, heapSize);
    PriorityQueue pq = { .size = 0, .heap = heap };
    
    long long i, num, diff, top, sum;
    
    for (i = 0, sum = 0; i < targetSize; ++i) {
        sum += target[i];
        pqPush(&pq, target[i]);
    }
    
    for (num = pqPop(&pq); num > 1; num = pqPop(&pq)) {
        sum -= num;
        if (num <= sum) {
            return false;
        }
        
        top = pqTop(pq);
        if (num - top > sum) {
            // speed up num decrement
            diff = (num - top) % sum + top;
        } else {
            diff = num - sum;
        }

        sum += diff;
        pqPush(&pq, diff);
    }

    return num == 1;
}
