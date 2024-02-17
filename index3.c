#include<stdio.h>

void sort(int n, int arr[]) {
    int i = 0;
    int j = 0;
    int tmp = 0;
    for (i = 0; i <= n - 1; i++) {
        for (j = 0; j <= n - i - 1; j++) {
            if (arr[j] <= arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// 返回名次，如果找不到名次则返回0
int lookup(int n, int need, int arr[]) {
    int i = 0;
    while (i < n) {
        if (need == arr[i]) {
            return i + 1;
        }
        i++;
    }
    return 0;
}

int main() {
    int i = 0;
    int j = 0;
    int n = 0;
    int arr[50];
    int need = 0;
    int r;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i <= n - 1; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &need);
        sort(n, arr);
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
            ++j;
            if (j >= 10) {
                printf("\n");
                j = 0;
            }
            if (i + 1 == n) {
                printf("\n");
            }
        }
        r = lookup(n, need, arr);
        if (r != 0) {
            printf("%d\n", r);
        } else {
            printf("no this score\n");
        }
    }
    return 0;
}