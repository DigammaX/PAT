#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _frac{
    long long up,down;
}frac;

long long gcd(long long ,long long );
frac sub(frac,frac);
frac add(frac,frac);
frac mul(frac,frac);
frac div(frac,frac);
frac reduce(frac);
void show(frac);

int main() {
    frac f1,f2;
    f1.up = 2;
    f1.down = 3;
    f2.up = 1;
    f2.down = 6;
    show(div(f1,f2));
    return 0;
}

long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}

frac reduce(frac res){
    if(res.down < 0){
        res.down = -res.down;
        res.up = - res.up;
    }
    if(res.up == 0){
        res.down = 1;
    }else{
        int d = gcd(res.up,res.down);
        res.up /= d;
        res.down /= d;
    }
    return res;
}

frac add(frac f1,frac f2){
    frac res;
    res.down = f1.down*f2.down;
    res.up = f1.down*f2.up + f2.down*f1.up;
    return reduce(res);
}

frac sub(frac f1,frac f2){
    frac res;
    res.down = f1.down*f2.down;
    res.up = f1.up*f2.down - f2.up*f1.down;
    return reduce(res);
}

frac mul(frac f1,frac f2){
    frac res;
    res.down = f1.down*f2.down;
    res.up = f1.up*f2.up;
    return reduce(res);
}

frac div(frac f1,frac f2){
    frac res;
    res.down = f1.down*f2.up;
    res.up =  f2.down*f1.up;
    return reduce(res);
}

void show(frac f){
    f = reduce(f);
    if(f.down == 1){
        printf("%lld\n",f.up);
    }else if(abs(f.up) > f.down){
        printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
    }else{
        printf("%lld/%lld",f.up,f.down);
    }
}