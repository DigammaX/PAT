#include <bits/stdc++.h>

using namespace std;

set<int> A[55];

void compare(int x,int y){
    int n = A[x].size()+A[y].size();
    int nc = 0;
    for(auto i : A[x]){
        if(A[y].find(i) != A[y].end()){ //find方法，查找位置
            nc++;
        }
    }
    printf("%.1lf%\n",((double)nc*100)/(n-nc));
}//比较A[x]和A[y]

int main() {
    int N,K;
    int cnt,temp;
    scanf("%d",&N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d",&cnt);
        while(cnt--){
            scanf("%d",&temp);
            A[i].insert(temp);
        }
    }
    scanf("%d",&K);
    int x,y;
    for (int i = 0; i < K; ++i) {
        scanf("%d%d",&x,&y);
        compare(x,y);
    }
    return 0;
}
