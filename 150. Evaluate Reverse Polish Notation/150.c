bool isAdd(char c) {
    return c == '+';
}

bool isSub(char c) {
    return c == '-';
}

bool isMul(char c) {
    return c == '*';
}

bool isDiv(char c) {
    return c == '/';
}

bool isOperator(char * token) {
    if (token[1] == '\0') {
        if (isAdd(token[0]) || isSub(token[0]) || \
            isMul(token[0]) || isDiv(token[0])) {
            return true;
        }
    }
    return false;
}

int evalRPN(char ** tokens, int tokensSize){
    int stack[5000] = {}, top = -1;
    
    for (int i=0; i<tokensSize; i++) {
        if (isOperator(tokens[i])) {
            if (isAdd(tokens[i][0])) {
                stack[top-1] += stack[top];
            } else if (isSub(tokens[i][0])) {
                stack[top-1] -= stack[top];
            } else if (isMul(tokens[i][0])) {
                stack[top-1] *= stack[top];
            } else if (isDiv(tokens[i][0])) {
                stack[top-1] /= stack[top];
            }
            top--;
        } else {
            stack[++top] = atoi(tokens[i]);
        }
    }
    
    return stack[top];
}
