bool isValid(char * s){
    int i, len = strlen(s), stack_index;
    char stack[10001] = {};
    
    if (len & 1) {  // odd str-length
        return false;
    }
    
    for (i=stack_index=0; i<len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[stack_index++] = s[i];
        } else {
            if (stack_index < 1) {
                return false;
            }
            if (s[i] == ')') {
                if (stack[--stack_index] != '(') {
                    return false;
                }
            } else if (s[i] == ']') {
                if (stack[--stack_index] != '[') {
                    return false;
                }
            } else if (s[i] == '}') {
                if (stack[--stack_index] != '{') {
                    return false;
                }
            }
        }
    }
    
    return stack_index == 0;
}
