#include <iostream>

const int maxn = 11;

int n,hashTab[maxn],P[maxn];
void generateP(int index){
    if(index >= n){
        for (int i = 0; i < n; ++i) {
            printf("%d",P[i]);
        }
        printf("\n");
        return;
    }
    //完成递归
    for (int j = 0; j < n; ++j) {
        if(hashTab[j] == false){
            P[index] = j+1;
            hashTab[j] = true;
            generateP(index+1);
            hashTab[j] = false;
        }
    }
}
int main(){
    n = 5;
    generateP(0);
    return 0;
}