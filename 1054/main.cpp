#include <bits/stdc++.h>

using namespace std;

map<int,int> A;

int main() {
    int M,N;
    int pixel;
    scanf("%d%d",&M,&N);
    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j) {
            scanf("%d",&pixel);
            if(A.find(pixel) != A.end()){
                A[pixel]++;
            }else{
                A[pixel] = 1;
            }
        }
    }
    int MaxPixel,max = 0;
    for(auto i = A.begin();i!=A.end();i++){
        if(i->second > max){
            max = i->second;
            MaxPixel = i->first;
        }
    }
    printf("%d",MaxPixel);
    return 0;
}
