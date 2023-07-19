#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)cin>>v[i];
    ll ans=0;
    priority_queue<ll>pq;
    for(ll i=0;i<n;i++){
        if(v[i]==0 || pq.empty())ans+=v[i];
        else{
            ll top=pq.top();
            pq.pop();
            if(top>v[i]){
                ans+=top;
                pq.push(v[i]);
            }
            else{
                ans+=v[i];
                pq.push(top);
            }
        }
        if(v[i]!=0)pq.push(v[i]);
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}