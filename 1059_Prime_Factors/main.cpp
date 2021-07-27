#include <iostream>
#include <cstring>
#include <math.h>

const int maxn = 10010;

int main() {
    long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    int p[maxn];
    int P[maxn];
    int tail = -1;
    memset(p, 0, sizeof(int) * maxn);
    for (long int i = 2; i <= maxn; i++) {
        if (p[i] == 0) {
            P[++tail] = i;
        }
        for (long int j = 0; j <= tail; ++j) {
            if (i * P[j] > maxn) break;
            p[i * P[j]] = 1;
            if ((i % P[j]) == 0)
                break;
        }
    }
    //欧拉筛获取素数表
    int pk[20];
    int ak[20];
    memset(pk, 0, sizeof(int) * 20);
    memset(ak, 0, sizeof(int) * 20);
    int cnt = 0;
    for (int k = 0; k < maxn && n > 1; k++) {
        if ((n % P[k]) == 0) {
            pk[cnt] = P[k];
            while ((n % P[k]) == 0) {
                n /= P[k];
                ak[cnt]++;
            }
            cnt++;
        }
    }
    for (int l = 0; l < cnt; ++l) {
        if (ak[l] == 1) {
            printf("%d", pk[l]);
        } else {
            printf("%d^%d", pk[l], ak[l]);
        }
        if (l < cnt - 1)
            printf("*");
    }
    if (cnt == 0) {
        printf("1");
    }
    return 0;
}
