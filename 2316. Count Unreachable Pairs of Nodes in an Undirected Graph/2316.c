#define MAX_N   100001

long long sum1toN(long long N) {
    return (1+N)*N/2;
}

int compare(const void *aa, const void *bb) {
    int *a = *(int **)aa;
    int *b = *(int **)bb;
    return a[0] - b[0];
}

bool isEmpty(int size, int index) {
    return size == index;
}

void enqueue(int *queue, int *size, int val, int *num, int *numAdd) {
    queue[(*size)++] = val;
    
    if (num[val] == 0) {
        ++(*numAdd);
        num[val] = 1;
    }
}

void dequeueAll(int *queue, int * qsize, int *qindex, int *num, int **edges, int *startI, int *endI, int *numAdd) {
    int oldSize = *qsize;
    int node, i, j, end, sec;
    
    for (i = *qindex; i < oldSize; ++i) {
        node = queue[i];
        for (j = startI[node], end = endI[node]; j <= end && end != -1; ++j) {
            sec = edges[j][1];
            if (num[sec] == 0) {
                enqueue(queue, qsize, sec, num, numAdd);
            }
        }
    }
    
    *qindex = i;
}

int** int2dArray(int m, int n) {
    int** ret = (int**) malloc(sizeof(int*) * m + sizeof(int) * m * n);

    int* first_int = (int*)(ret + m);
    for (int i=0; i<m; i++) {
        ret[i] = first_int + i * n;
    }
    
    return ret;
}

long long countPairs(int n, int** edges, int edgesSize, int* edgesColSize) {
    long long total = sum1toN(n-1), sumEdge;
    
    int i, tmp, lastI;
    int node, qsize, qindex, numAdd;

    int **doub = int2dArray(edgesSize * 2, 2);
    
    int *allocate = (int *) malloc(sizeof(int) * n * 4);
    int *startI = allocate;
    int *endI   = allocate + n;
    int *nums   = allocate + n*2;
    int *queue  = allocate + n*3;
    
    memset(allocate, -1, sizeof(int) * n * 4);
 
    for (i = 0; i < edgesSize; ++i) {
        doub[i][0] = doub[i+edgesSize][1] = edges[i][0];
        doub[i][1] = doub[i+edgesSize][0] = edges[i][1];
    }
    
    edges = doub;
    edgesSize *= 2;
    
    qsort(edges, edgesSize, sizeof(int *), compare);
    
    for (i = 0, lastI = edgesSize-1; i <= lastI; ++i) {
        tmp = edges[i][0];
        
        if (startI[tmp] == -1) {
            startI[tmp] = i;
            nums[tmp] = 0;
        }
        
        if (i == lastI || tmp != edges[i+1][0]) {
            endI[tmp] = i;
        }
    }
    
    for (node = 0, sumEdge = 0; node < n; ++node) {
        if (nums[node] == 0) {
            qsize = 0, qindex = 0, numAdd = 0;
            enqueue(queue, &qsize, node, nums, &numAdd);
            while (!isEmpty(qsize, qindex)) {
                dequeueAll(queue, &qsize, &qindex, nums, edges, startI, endI, &numAdd);
            }

            sumEdge += sum1toN(numAdd-1);
        }
    }

    free(doub);
    free(allocate);
    return total-sumEdge;
}
