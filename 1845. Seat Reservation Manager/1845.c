#define INVALID     100001
#define MIN_SIZE    100

typedef struct {
    int minAvailable[MIN_SIZE];
    int size;
    bool *seat;
} SeatManager;

SeatManager* seatManagerCreate(int n) {
    int seatSize = sizeof(bool) * (n + 1);
    SeatManager *ret = (SeatManager *) malloc(sizeof(SeatManager) + seatSize);
    *ret = (SeatManager){ .minAvailable = { INVALID }, .size = n, .seat = (bool *)(ret + 1) };
    memset(ret->seat, 0, seatSize);
    
    return ret;
}

int getMin(SeatManager *obj) {
    int i, size, minIndex, ret; 
    
    if (obj->minAvailable[0] == INVALID) {
        for (i = 1, size = obj->size, minIndex = 0; i <= size && minIndex < MIN_SIZE; ++i) {
            if (obj->seat[i] == false) {
                obj->minAvailable[minIndex++] = i;
            }
        }

        while (minIndex < MIN_SIZE) {
            obj->minAvailable[minIndex] = INVALID;
            ++minIndex;
        }
    }
    
    ret = obj->minAvailable[0];
    for (i = 1; i < MIN_SIZE; ++i) {
        obj->minAvailable[i-1] = obj->minAvailable[i];
    }
    obj->minAvailable[MIN_SIZE-1] = INVALID;

    return ret;
}

int seatManagerReserve(SeatManager* obj) { 
    int ret = getMin(obj);
    obj->seat[ret] = true;
    
    return ret;
}

void setMin(SeatManager *obj, int seatNumber) {
    for (int i = 0, j; i < MIN_SIZE && obj->minAvailable[i] != INVALID; ++i) {
        if (seatNumber < obj->minAvailable[i]) {
            for (j = MIN_SIZE-1; j > i; j--) {
                obj->minAvailable[j] = obj->minAvailable[j-1];
            }
            obj->minAvailable[i] = seatNumber;
            break;
        }
    }
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    obj->seat[seatNumber] = false;
    setMin(obj, seatNumber);
}

void seatManagerFree(SeatManager* obj) {
    free(obj);
}
