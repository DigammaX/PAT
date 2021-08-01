#include <iostream>
#include <cstring>

void mod3(char[]);
void mod3_1(char[]);
void mod3_2(char[]);

int main() {
    char A[100];
    scanf("%s",A);
    int n = strlen(A);
    void (*pfunc[3])(char[]);
    pfunc[0] = mod3;
    pfunc[1] = mod3_1;
    pfunc[2] = mod3_2;
    int d = n % 3;
    pfunc[d](A);
    return 0;
}

void mod3(char A[]){
    int n = strlen(A);
    int x = n/3;
    for (int i = 0; i < x-1; ++i) {
        printf("%c",A[i]);
        for (int j = 0; j < x; ++j) {
            printf(" ");
        }
        printf("%c\n",A[n-1-i]);
    }
    for (int k = x-1; k < 2*x+1; ++k) {
        printf("%c",A[k]);
    }
}

void mod3_1(char A[]){
    int n = strlen(A);
    int x = n/3;
    for (int i = 0; i < x; ++i) {
        printf("%c",A[i]);
        for (int j = 0; j < x-1; ++j) {
            printf(" ");
        }
        printf("%c\n",A[n-1-i]);
    }
    for (int k = x; k < 2*x+1; ++k) {
        printf("%c",A[k]);
    }
}

void mod3_2(char A[]){
    int n = strlen(A);
    int x = n/3;
    for (int i = 0; i < x; ++i) {
        printf("%c",A[i]);
        for (int j = 0; j < x; ++j) {
            printf(" ");
        }
        printf("%c\n",A[n-1-i]);
    }
    for (int k = x; k < 2*x+2; ++k) {
        printf("%c",A[k]);
    }
}