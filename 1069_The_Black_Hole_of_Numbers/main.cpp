#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a > b;
}

int int4toint(int a[]){
    return 1000*a[0] + 100*a[1] + 10*a[2] + a[3];
}

void inttoint4(int a,int b[]){
    for (int i = 0; i < 4; ++i) {
        b[3-i] = a%10;
        a = a/10;
    }
}

int main() {
    int a,b[4];
    scanf("%d",&a);
    inttoint4(a,b);
    sort(b,b+4);
    if(b[0] == b[3]){
        printf("%d%d%d%d - %d%d%d%d = 0000",b[0],b[0],b[0],b[0],b[0],b[0],b[0],b[0]);
        return 0;
    }

    int max,min;
    inttoint4(a,b);
    do {
        sort(b,b+4,cmp);
        max = int4toint(b);
        printf("%d%d%d%d - ",b[0],b[1],b[2],b[3]);
        sort(b,b+4);
        min = int4toint(b);
        printf("%d%d%d%d = ",b[0],b[1],b[2],b[3]);
        a = max-min;
        inttoint4(a,b);
        printf("%d%d%d%d\n",b[0],b[1],b[2],b[3]);
    }while(a != 6174);
    return 0;
}
