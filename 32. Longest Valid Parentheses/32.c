#define FRONT   '('
#define END     ')'
#define MATCHED 0
#define MAX_LEN 30000

int longestValidParentheses(char * s){
    int len_s = strlen(s);
    int i, count, max;
    int stack[MAX_LEN] = {}, stack_size = 0;

    for (i=0; i<len_s; i++) {
        if (s[i] == FRONT) {
            stack[stack_size++] = i;
        } else if (stack_size > 0) {
            s[i] = MATCHED;
            s[stack[stack_size-1]] = MATCHED;
            stack_size--;
        }
    }
    
    for (i=0, count=0, max=0; i<len_s; i++) {
        if (s[i] == MATCHED) {
            count++;
        } else {
            if (count != 0) {
                if (count % 2 == 1) {
                    count--;
                }
                max = (count > max) ? count : max;
                count = 0;
            }
        }
    }
    
    if (count != 0) {
        if (count % 2 == 1) {
            count--;
        }
        max = (count > max) ? count : max;
    }

    return max;
}
