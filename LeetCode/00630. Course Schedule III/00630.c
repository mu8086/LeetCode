#define MAX_SIZE        10001
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
    return pq.heap[a] < pq.heap[b];
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

void pqPrint(PriorityQueue pq) {
    int i, size = pq.size, left, right;
    
    printf("[pqPrint] size: %d\n", size);
    for (i = 1; i <= size; ++i) {
        if (i == 1) {
            printf("[");
        }
        printf("%d,", pq.heap[i]);
        if (i == size) {
            printf("]\n");
        }
    }
    
    for (i = 1; i <= size; ++i) {
        printf("[%d]:%d  ", i, pq.heap[i]);
        if ((left = pqLeftIndex(pq, i)) != INVALID) {
            printf("left[%d]:%d  ", left, pq.heap[left]);
        }
        if ((right = pqRightIndex(pq, i)) != INVALID) {
            printf("right[%d]:%d  ", right, pq.heap[right]);
        }
        printf("\n");
    }
}

int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa, *b = *(int **)bb;
    return a[1] - b[1];
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    qsort(courses, coursesSize, sizeof(int **), compare);

    static int heap[MAX_SIZE], heapSize = sizeof(int) * MAX_SIZE;
    memset(heap, 0, heapSize);
    PriorityQueue pq = { .size = 0, .heap = heap };
    
    for (int i = 0, time = 0; i < coursesSize; ++i) {
        time += courses[i][0];
        pqPush(&pq, courses[i][0]);
        
        if (time > courses[i][1]) {
            time -= pqPop(&pq);
        }
    }
    
    //pqPrint(pq);
    
    return pq.size;
}
