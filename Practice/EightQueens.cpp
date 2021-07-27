#include <iostream>

const int maxn = 11;

int n,hashTab[maxn],P[maxn],count = 0;
void generateP(int index){
    if(index >= n){
        bool flag = true;
        for (int j = 0; j < n; ++j)
            for (int k = j+1; k < n; ++k) {
                if(abs(j-k) == abs(P[j]-P[k])) {
                    flag = false;
                }
            }
        if(flag) count++;
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
    n = 8;
    generateP(0);
    printf("%d",count);
    return 0;
}