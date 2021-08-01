#include <bits/stdc++.h>

using namespace std;

map<string,set<int>> Title,Author,Key,Publisher,Year;

void query(map<string,set<int>>& mp,string& temp){
    if(mp.find(temp) != mp.end()){
        for(auto i : mp[temp]){
            printf("%07d\n",i);
        }
    }else{
        cout << "Not Found" << endl;
    }
}
int main() {
    int N;
    cin >> N;
    string title,author,key,publisher,year;
    int bID;
    char c;
    while(N--){
        cin >> bID;
        getchar();//吸收掉换行符
        getline(cin,title);
        Title[title].insert(bID);
        getline(cin,author);
        Author[author].insert(bID);
        while(cin >> key){
            Key[key].insert(bID);
            c = getchar();
            if(c == '\n') break;
        }
        getline(cin,publisher);
        Publisher[publisher].insert(bID);
        getline(cin,year);
        Year[year].insert(bID);
    }
    int M;
    cin >> M;
    string temp;
    int type;
    for (int i = 1; i <= M ; ++i) {
        cin >> type >> c; //后面一个：
        getchar();
        getline(cin,temp);
        cout << type << ": " << temp <<endl;
        if(type == 1) query(Title,temp);
        else if(type == 2) query(Author,temp);
        else if(type == 3) query(Key,temp);
        else if(type == 4) query(Publisher,temp);
        else query(Year,temp);
    }
    return 0;
}
