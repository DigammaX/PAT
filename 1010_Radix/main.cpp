#include <iostream>
#include <algorithm>

using namespace std;

int translate(char a){
    if('0' <= a && a <= '9')
        return a-'0';
    else
        return a-'a'+10;
}

long long strToInt(string a,long long radix){
    long long res = 0;
    for(auto it = a.begin();it != a.end();it++)
        res = res*radix + translate(*it);
    return res;
}

long long find_radix(string N1,string N2,long long radix){
    long long RES = strToInt(N2,radix);
    char a = *max_element(N1.begin(),N1.end());
    long long low = translate(a)+1,high = max(RES,low);
    while(low <= high){
        long long mid = (low + high)/2;
        long long res = strToInt(N1,mid);
        if(res < 0 || res > RES){
            high = mid-1;
        }else if(RES == res){
            return mid;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    string N1;
    string N2;
    int tag;
    long long radix;
    cin >> N1 >> N2 >> tag >> radix;
    long long R = find_radix(tag == 2?N1:N2,tag == 2?N2:N1,radix);
    if(R == -1)
        cout << "Impossible";
    else
        cout << R;
    return 0;
}
