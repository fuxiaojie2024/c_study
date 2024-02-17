#include <stdio.h>
#include <string.h>

void encrypt(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if ('a' <= str[i] && str[i] <= 'y') {
            str[i] = str[i] + 1;
        } else if ('A' <= str[i] && str[i] <= 'Y') {
            str[i] = str[i] + 1;
        } else if (str[i] == 'z') {
            str[i] = 'a';
        } else if (str[i] == 'Z') {
            str[i] = 'A';
        }
    }
}

int checkStrHasSpace(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[79];
    printf("请输入字符串：");
    scanf("%[^\n]", str);
    if (checkStrHasSpace(str) == 1) {
        printf("字符中不能包含空");
        return 0;
    }
    if (strlen(str) >= 80 || strlen(str) < 1) {
        printf("字符长度不能大于79或小于1");
        return 0;
    }
    encrypt(str);
    printf("加密后的字符串为：%s\n", str);
}