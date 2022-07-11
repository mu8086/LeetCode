#define VALUE_RANGE     100002
#define INVALID         -1
#define PQ_TOP_INDEX    1

typedef struct {
    int size;
    int (*heap)[2];
} PriorityQueue;

int pqSize(PriorityQueue pq) {
    return pq.size;
}

int * pqTop(PriorityQueue pq) {
    if (pqSize(pq) > 0) {
        return pq.heap[PQ_TOP_INDEX];
    }
    return NULL;
}

bool pqLess(PriorityQueue pq, int indexA, int indexB) {
    return pq.heap[indexA][0] < pq.heap[indexB][0];
}

void pqSwap(PriorityQueue *pq, int src, int dest) {
    int tmp[2] = { pq->heap[src][0], pq->heap[src][1] };
    pq->heap[src][0]    = pq->heap[dest][0],    pq->heap[src][1]    = pq->heap[dest][1];
    pq->heap[dest][0]   = tmp[0],               pq->heap[dest][1]   = tmp[1];
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
    
    int parentIndex = index / 2;
    while (index > PQ_TOP_INDEX && pqLess(*pq, parentIndex, index)) {
        pqSwap(pq, parentIndex, index);
        index = parentIndex;
        parentIndex /= 2;
    }
}

void pqPush(PriorityQueue *pq, int value, int counter) {
    pq->heap[++(pq->size)][0] = value;
    pq->heap[   pq->size ][1] = counter;
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

int * pqPop(PriorityQueue *pq) {
    if (pqSize <= 0) {
        return INVALID;
    }
    static int ret[2] = {};
    int *tmp = pqTop(*pq);
    ret[0] = tmp[0], ret[1] = tmp[1];
    
    pqSwap(pq, 1, pqSize(*pq));
    --(pq->size);
    pqSink(pq, 1);
    return ret;
}

void setDelta(int delta[], int *nums1, int *nums2, int size) {
    for (int i = 0, tmp; i < size; ++i) {
        tmp = nums1[i] - nums2[i];
        tmp = (tmp >= 0) ? tmp : -tmp;
        ++delta[tmp];
    }
}

PriorityQueue getPQ(int *nums1, int *nums2, int size) {
    static int heap[VALUE_RANGE][2], heapSize = sizeof(int) * VALUE_RANGE * 2;
    memset(heap, 0, heapSize);
    PriorityQueue pq = { .size = 0, .heap = heap };

    int delta[VALUE_RANGE] = {};
    setDelta(delta, nums1, nums2, size);

    for (int i = VALUE_RANGE-1; i > 0; --i) {
        if (delta[i] != 0) {
            pqPush(&pq, i, delta[i]);
        }
    }
    pqPush(&pq, 0, delta[0]);

    return pq;
}

long long getSum(PriorityQueue pq) {
    int *top = NULL;
    long long sum = 0, val;
    
    while (pq.size > 0) {
        top = pqPop(&pq);
        val = top[0];
        if (val == 0) {
            break;
        }
        sum += val * val * top[1];
    }
    
    return sum;
}

long long minSumSquareDiff(int *nums1, int nums1Size, int *nums2, int nums2Size, int k1, int k2) {
    PriorityQueue pq = getPQ(nums1, nums2, nums1Size);
    
    int k = k1 + k2;
    int diffToMax, maxVal, maxValSize;
    int *max = NULL, *top = NULL;
    
    while (k > 0 && pq.size > 0) {
        max = pqPop(&pq);
        maxVal      = max[0];
        maxValSize  = max[1];
        if (maxVal == 0) {
            break;
        }
        
        top = pqTop(pq);
        diffToMax = maxVal - top[0];
        
        if (k >= diffToMax * maxValSize) {
            k -= diffToMax * maxValSize;
            top[1] += maxValSize;
        } else {
            int q = k / maxValSize;
            int r = k % maxValSize;

            // Both 'maxVal - q' and 'maxVal - q - 1' have a chance to generate the second node with an existing value;
            // therefore, the MACRO VALUE_RANGE is 100002, not 100001
            pqPush(&pq, maxVal - q,     maxValSize - r);
            pqPush(&pq, maxVal - q - 1, r);
            break;
        }
    }
    
    long long sum = getSum(pq);
    return sum;
}
