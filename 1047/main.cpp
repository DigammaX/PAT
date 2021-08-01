#include <bits/stdc++.h>
using namespace std;

vector<int> Course[2500];
char Student[40010][5];

bool compare(int a,int b){
    return strcmp(Student[a],Student[b])<0;
}

int main() {
    int n,m;
    int cnt;
    int Cid;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d",Student[i],&cnt);
        while(cnt--){
            scanf("%d",&Cid);
            Course[Cid].push_back(i);
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d %d\n",i,Course[i].size());
        sort(Course[i].begin(),Course[i].end(), compare);
        for(auto j:Course[i]){
            printf("%s\n",Student[j]);
        }
    }
    return 0;
}
