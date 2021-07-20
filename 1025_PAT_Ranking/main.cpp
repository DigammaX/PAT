#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct _Student{
    char id[13];
    int score;
    int location_number;
    int local_rank;
} Student;

bool cmp(Student a,Student b){
    if(a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id,b.id)<0;
}
int main() {
    Student A[30010];
    int n,k;
    int num = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        for (int j = 0; j < k; ++j) {
            scanf("%s %d",A[num].id,&A[num].score);
            A[num].location_number = i+1;
            num++;
        }
        sort(A+num-k,A+num,cmp);
        A[num-k].local_rank = 1;
        for(int j = num-k+1 ; j<num;++j){
            if(A[j].score == A[j-1].score)
                A[j].local_rank = A[j-1].local_rank;
            else
                A[j].local_rank = j-(num-k)+1;
        }
    }
    //输入所有数据，并完成内部排序、
    sort(A,A+num,cmp);
    printf("%d\n",num);
    int rank = 1;
    for (int l = 0; l < num; ++l) {
        if( l > 0 && A[l].score == A[l-1].score){
            printf("%s %d %d %d\n",A[l].id,rank,A[l].location_number,A[l].local_rank);
        } else {
            rank = l+1;
            printf("%s %d %d %d\n", A[l].id, rank, A[l].location_number, A[l].local_rank);
        }
    }
}
