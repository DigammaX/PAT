#include <iostream>
const int p = 1000000007;
using namespace std;

int main() {
    string A;
    int countP=0,countPA =0,countPAT =0;
    cin >> A;
    for (auto i : A) {
        if( i == 'A'){
            countPA = (countPA + countP)%p;
        } else if(i == 'T'){
            countPAT = (countPAT + countPA)%p;
        }else{
            countP = (countP+1)%p;
        }
    }
    printf("%d",countPAT);
    return 0;
}
