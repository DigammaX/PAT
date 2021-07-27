#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int randPartition(int A[],int left,int right){
    int p = round(1.0*rand()/RAND_MAX*(right-left)+left);
    swap(A[p],A[left]);
    int temp = A[left];
    while(left < right){
        while(left < right && A[right] > temp)
            right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp)
            left++;
        A[right] = A[left];   //从右往左找，找到一个小于等于temp的位置，送到左边，从左往右找，找到大的送到右边,由于temp值记录下来了，不必交换值
        //由于temp值已经存下来了，虽然中间值消失了，最后还原即可
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[],int left,int right){
    if(left < right){
        int pos = randPartition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}

int main() {
    srand((unsigned)time(NULL));
    int A[5] = {4,6,8,2,3};
    quickSort(A,0,4);
    for (int i : A) {
        printf("%d",i);
    }
    return 0;
}

/*
#include <iostream>

int Partition(int A[],int left,int right){
    int temp = A[left];
    while(left < right){
        while(left < right && A[right] > temp)
            right--;
        A[left] = A[right];
        while(left < right && A[left] <= temp)
            left++;
        A[right] = A[left];   //从右往左找，找到一个小于等于temp的位置，送到左边，从左往右找，找到大的送到右边,由于temp值记录下来了，不必交换值
                              //由于temp值已经存下来了，虽然中间值消失了，最后还原即可
    }
    A[left] = temp;
    return left;
}

void quickSort(int A[],int left,int right){
    if(left < right){
        int pos = Partition(A,left,right);
        quickSort(A,left,pos-1);
        quickSort(A,pos+1,right);
    }
}

int main() {
    int A[5] = {4,6,8,2,3};
    quickSort(A,0,4);
    for (int i : A) {
        printf("%d",i);
    }
    return 0;
}
*/
