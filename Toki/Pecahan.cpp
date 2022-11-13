#include <bits/stdc++.h>
#define standar using namespace std
#define ull unsigned long long

standar;

ull fpb(ull a, ull b) {
    if (a%b == 0) return b;
    return fpb(b, a % b);
}

main(){
    ull a,b,c,d,e,f,pembagi;
    
    cin>>a>>b;
    cin>>c>>d;

    e = a*d + b*c;
    f = b*d;

    if (e > f) pembagi = fpb(e,f);
    else pembagi = fpb(f,e);

    cout<<e/pembagi<<" "<<f/pembagi<<endl;

}