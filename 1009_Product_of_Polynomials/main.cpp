#include <iostream>

int main() {
    int N1,N2;
    scanf("%d",&N1);
    int a[N1];
    double A[N1];
    for (int i = 0; i < N1; ++i) {
        scanf("%d %lf",&a[i],&A[i]);
    }
    scanf("%d",&N2);
    int b[N2];
    double B[N2];
    for (int j = 0; j < N2; ++j) {
        scanf("%d %lf",&b[j],&B[j]);
    }
    //输入

    int N = a[0]+b[0];
    double C[N+1];
    for (int l = 0; l < N+1; ++l) {
        C[l]=0;
    }
    for (int i = 0; i < N1; ++i)
        for (int j = 0; j < N2 ; ++j) {
            C[a[i]+b[j]]+=A[i]*B[j];
        }
    int cnt = 0;
    int flag[N+1];
    for (int k = 0; k < N+1; ++k) {
        if(C[k]>0.01 | C[k]<-0.01){
            cnt++;
            flag[k]=1;
        }
        else{
            flag[k]=0;
        }
    }
    printf("%d",cnt);
    for (int m = N; m > -1; --m) {
        if(flag[m])
        printf(" %d %.1lf",m,C[m]);
    }
    return 0;
}
