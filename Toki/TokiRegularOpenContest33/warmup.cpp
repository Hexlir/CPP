#include "bits/stdc++.h"

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using std::cin;
using std::cout;
#define endl '\n'

struct teman{
    int s;
    int d;
};

bool cmp(teman a, teman b){
    return a.s < b.s;
}

int main(){
    int n;
    cin >> n;

    std::vector<teman> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].s >> v[i].d;
        v[i].d += v[i].s;
    }

    std::sort(v.begin(), v.end(), cmp);
    int now = 0, ans = 1;

    for(int i = 0; i < n; i++){
        if(v[i].s >= now){
            ans++;
            now = v[i].d;
        }
    }

    cout << ans << endl;
}