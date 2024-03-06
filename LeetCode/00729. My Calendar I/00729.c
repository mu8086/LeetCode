#define MAX_SIZE    1000

#define MIN_VAL     0
#define MAX_VAL     1000000000

typedef struct {
    int schedule[MAX_SIZE][2];
    int scheduleSize;
    int min;
    int max;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar* ret = (MyCalendar*) malloc(sizeof(MyCalendar));
    ret->scheduleSize = 0;
    ret->min = MAX_VAL;
    ret->max = MIN_VAL;
        
    return ret;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    int size = obj->scheduleSize;
    
    if (end > obj->min && start < obj->max) {
        for (int i=0, schedule_start, schedule_end; i<size; i++) {
            schedule_start  = obj->schedule[i][0];
            schedule_end    = obj->schedule[i][1];
            if (end > schedule_start && start < schedule_end) {
                return false;
            }
        }
    }
    
    obj->schedule[size][0] = start;
    obj->schedule[size][1] = end;
    (obj->scheduleSize)++;
    obj->min = (start < obj->min) ? start : obj->min;
    obj->max = (end   > obj->max) ? end   : obj->max;
    
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    free(obj);
}
