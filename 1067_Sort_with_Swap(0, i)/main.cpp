#include <iostream>
#include <vector>
using namespace std;

typedef struct _node{
    int a;
    bool visited;
    _node(){
        visited = false;
    }
}node;

int main() {
    int n;
    cin >> n;
    node A[n];
    int nr = 0; //排列无误的个数
    for (int i = 0; i < n; ++i) {
        cin >> A[i].a;
        if(A[i].a == i){
            A[i].visited = true;
            nr++;
        }
    }
    bool flag = false;
    int nc = 0; //遍历环的个数
    for (int j = 0; j < n; ++j) {
        if (!A[j].visited) {
            nc++;
            A[j].visited = true;
            int temp;
            temp = A[j].a;
            if(temp == 0){
                flag = true;
            } //看看0在不在环里
            while (temp != j) {
                A[temp].visited = true;
                temp = A[temp].a;
                if(temp == 0){
                    flag = true;
                } //看看0在不在环里
            }
        }
    }

    if(flag){
        printf("%d",n-nr+nc-2);
    }else{
        printf("%d",n-nr+nc);
    }
    return 0;
}
