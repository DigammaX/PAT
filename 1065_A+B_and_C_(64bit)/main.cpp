#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

typedef struct bigN{
    int d[1000];
    int len;
    bool sign;
    bigN(){
        memset(d,0,sizeof(d));
        len = 0;
        sign = true;
    }
}bigN;

bigN change(char str[]);
bigN uadd(bigN a,bigN b);
bigN usub(bigN a,bigN b);
int ucompare(bigN a,bigN b);
bigN add(bigN a,bigN b);
bigN sub(bigN a,bigN b);
void reduce(bigN &a); //0的唯一表达
int compare(bigN a,bigN b);
void show(bigN a);

int main() {
    int n;
    scanf("%d",&n);
    char res[n][50];
    for (int i = 1; i <= n; ++i) {
        char a[50], b[50], c[50];
        scanf("%s", a);
        scanf("%s", b);
        scanf("%s", c);
        bigN A = change(a);
        bigN B = change(b);
        bigN C = change(c);
        if (compare(add(A, B), C) == 1)
            sprintf(res[i-1],"Case #%d: true\n", i);
        else
            sprintf(res[i-1],"Case #%d: false\n", i);
    }
    for (int j = 0; j < n; ++j) {
        printf("%s",res[j]);
    }
    return 0;
}


bigN change(char str[]){
    bigN a;
    a.len = strlen(str);
    int offset = 0;
    if(str[0] == '-') {
        offset = 1;
        a.sign = false;
    }
    for (int i = 0; i < (a.len - offset); ++i) {
        a.d[i] = str[a.len-i-1]-'0';
    }
    return a;
}

bigN uadd(bigN a,bigN b){
    bigN c;
    int carry = 0;//进位
    for (int i = 0; i < a.len || i < b.len ; ++i) {
        int temp = a.d[i] + b.d[i] + carry;  //高位全部是0,无需对此进行判断
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0){
        c.d[c.len++] = 0;
    }
    return c;
}

bigN usub(bigN a,bigN b){
    bigN c;
    int flag = ucompare(a,b);
    if( flag < 0 ){
        return usub(b,a);
    }
    for (int i = 0; i < a.len || i < b.len ; ++i) {
        if(a.d[i] < b.d[i]) {
            a.d[i + 1]--;
            a.d[i]+=10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len > 1 && c.d[c.len-1] == 0)
        c.len--;
    return c;
}
int ucompare(bigN a,bigN b){
    if(a.len == b.len) {
        for (int i = a.len - 1; i >= 0; i--) {
            if (a.d[i] != b.d[i])
                return (a.d[i]>b.d[i])? 1 : -1;
        }
        return 0; //
    }else{
        return (a.len>b.len)? 1 : -1;
    }
}

void show(bigN a){
    if(!a.sign)
        printf("-");
    for (int i = 0; i < a.len; ++i) {
        printf("%d",a.d[a.len-i-1]);
    }
    printf("\n");
}

bigN add(bigN a,bigN b){
    bigN c;
    if(a.sign == b.sign ){
        c = uadd(a,b);
        c.sign = a.sign;
    }else{
        c = usub(a,b);
        c.sign = (a.sign && (ucompare(a,b)==1)) || (b.sign && (ucompare(a,b)== -1));
    }
    reduce(c);
    return c;
}

void reduce(bigN &a){
    if (a.len == 1 && a.d[0] == 0)
        a.sign = true;
}


int compare(bigN a,bigN b){
    if(a.sign && b.sign){
        return ucompare(a,b);
    }else if(!a.sign && !b.sign){
        return -ucompare(a,b);
    }else{
        return a.sign? 1 : -1;
    }
}