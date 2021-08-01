#include <bits/stdc++.h>

using namespace std;

const int N = 40010;
const int M = 26*26*26*10+10;

vector<int> Course[M];

int getID(char name[]){  //hash
    int id = 0;
    for (int i = 0; i < 3; ++i) {
        id = id * 26 + name[i] - 'A';
    }
    id = id * 10 + name[3] - '0';
    return id;
}

int main() {
    int n,m;
    char name[5]; //char用scanf更方便（需要效率）
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        int Cid,count;
        scanf("%d%d",&Cid,&count);
        while(count--){
            scanf("%s",name);
            Course[getID(name)].push_back(Cid);
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s",name);
        int id = getID(name);
        sort(Course[id].begin(),Course[id].end());
        printf("%s %d",name,Course[id].size());
        for(auto i : Course[id]){
            printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}

