int myAtoi(char * str){
    int res = 0;
    int flag = 0;
    int sign = 1;
    
    for (int i=0; str[i] != '\0'; i++) {
        if (flag != 2) {
            if (str[i] == ' ' && flag == 0) {
                continue;
            } else if (str[i] == '+' && flag == 0) {
                flag = 1;
            } else if (str[i] == '-' && flag == 0) {
                flag = 1;
                sign = -1;
            } else if (isdigit(str[i])) {
                flag = 2;
                res = (str[i] - '0') * sign;
            } else {
                break;
            }
        } else {
            if (!isdigit(str[i])) {
                break;
            }
            
            if (res >= 214748365) {
                return INT_MAX;
            } else if (res <= -214748365) {
                return INT_MIN;
            }
            
            res *= 10;
            if (sign == 1) {
                if (INT_MAX - res >= str[i] - '0')
                    res += str[i] - '0';
                else
                    return INT_MAX;
            } else {
                if (INT_MIN - res <= '0' - str[i])
                    res -= str[i] - '0';
                else
                    return INT_MIN;
            }
        }
    }
    
    return res;
}
