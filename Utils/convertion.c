/*
** value type convertion functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
/**
 * @name intToStr
 * @function change the given int to a string
 * @param m: the given integer
 * @return the string
 */
char *intToStr(int m) {
    char temp[20], *result;
    //由于int型表示的范围负数比正数多1，故在这里处理
    if (m == INT_MIN) {
        char *s = intToStr(INT_MIN + 1);
        s[strlen(s) - 1] += 1;
        return s;
    }
    int i = 0, flag = 0;
    if (m < 0 && m > INT_MIN) {
        flag = 1;
        m = -m;
    }
    while (m > 0) {
        temp[i++] = (char) (m % 10 + '0');
        m /= 10;
    }
    if (flag) {
        temp[i++] = '-';
    }
    temp[i] = '\0';
    i--;
    int j = 0;
    result = (char *) malloc(sizeof(char) * (strlen(temp) + 1));
    for (j = 0; i >= 0; j++, i--) {
        result[j] = temp[i];
    }
    result[j] = '\0';
    return result;
}

/**
 * @name myAtoi
 * @function convert a string to integer
 * @param str: the given string
 * @return the integer
 */
int myAtoi(const char *str) {
    int result = 0, i = 0, flag = 0;
    while (str[i] == ' ') //处理前面空格
        i++;
    if (str[i] == '-') { //判断是否为负数
        i++;
        flag = 1;
    } else if (str[i] == '+')
        i++;
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9')) {
            if (result >= (INT_MAX / 10 - (str[i] - '0') + 7)) { //判断是否超出int型最大
                if (flag && result > (INT_MAX / 10 - (str[i] - '0') + 7)) {
                    return INT_MIN;
                }
                return flag ? -INT_MAX : INT_MAX;
            }
            result *= 10;
            result += str[i++] - '0';
        } else {
            return flag ? -result : result;
        }
    }
    return flag ? -result : result;
}