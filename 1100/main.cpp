#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
//垃圾题，打表都行
string Mars[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string Marsh[13] = {"tret","tam","hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map <string,int> strToNum;

string numToStr(int N){
    if(N<13){
        return Mars[N];
    }else if(N%13 == 0){
        return Marsh[N/13];
    }else{
        return Marsh[N/13] + " " + Mars[N%13];
    }
}


void init(){
    for (int i = 0; i < 13; ++i) {
        strToNum[Mars[i]] = i;
        strToNum[Marsh[i]] = i*13;
    }
    for (int i = 1; i < 13; ++i) {
        for (int j = 1; j < 13; ++j) {
            strToNum[Marsh[i]+" "+Mars[j]] = i*13+j;
        }
    }
}

int main() {
    init();
    int N;
    vector<string> res;
    scanf("%d%*c",&N);
    while(N--) {
        string str;
        getline(cin,str);
        if(str[0]>='0' && str[0]<='9'){
            int num = 0;
            for(auto i : str){
                num = num*10 + (i-'0');
            }
            res.push_back(numToStr(num));
        }else{
            res.push_back(to_string(strToNum[str])); //万能std
        }
    }
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
