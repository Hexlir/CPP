#include <bits/stdc++.h>
    using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main()
{
    fastio();
    ll p,l;
    cin >> p;
    cin >> l;

    char arr[p][l];
    ll x,y;

    for(ll i=0;i<p;i++){
        for(ll j=0;j<l;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='D'){
                x=i;
                y=j;
            }
        }
    }

    ll flag=0;
    for(ll i=0;i<p;i++){
        for(ll j=0;j<l;j++){
            if(arr[i][j]=='C'){
                if(i==x){
                    if(j>y){
                        for(ll k=y;k<j;k++){
                            if(arr[i][k]=='-'){
                                flag=1;
                                break;
                            }
                        }
                    }
                    else{
                        for(ll k=j;k<y;k++){
                            if(arr[i][k]=='-'){
                                flag=1;
                                break;
                            }
                        }
                    }
                }
                else if(j==y){
                    if(i>x){
                        for(ll k=x;k<i;k++){
                            if(arr[k][j]=='|'){
                                flag=1;
                                break;
                            }
                        }
                    }
                    else{
                        for(ll k=i;k<x;k++){
                            if(arr[k][j]=='|'){
                                flag=1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    if(flag==1){
        cout << "Dawala bertemu Cepot" << endl;
    }
    else{
        cout << "Dawala tidak bertemu Cepot" << endl;
    }

    ll flag2=0;

    for(ll i=0;i<p;i++){
        for(ll j=0;j<l;j++){
            if(arr[i][j]=='C'){
                if(i==0){
                    if(arr[i+1][j]==' '){
                        flag2=1;
                        break;
                    }
                }
                else if(i==p-1){
                    if(arr[i-1][j]==' '){
                        flag2=1;
                        break;
                    }
                }
                else if(j==0){
                    if(arr[i][j+1]==' '){
                        flag2=1;
                        break;
                    }
                }
                else if(j==l-1){
                    if(arr[i][j-1]==' '){
                        flag2=1;
                        break;
                    }
                }
                else{
                    if(arr[i+1][j]==' ' || arr[i-1][j]==' ' || arr[i][j+1]==' ' || arr[i][j-1]==' '){
                        flag2=1;
                        break;
                    }
                }
            }
        }
    }

    if(flag2==1){
        cout << "Ada jalan bagi Cepot untuk lumpat" << endl;
    }
    else{
        cout << "Tidak ada jalan bagi Cepot untuk lumpat" << endl;
    }

    return 0;
}