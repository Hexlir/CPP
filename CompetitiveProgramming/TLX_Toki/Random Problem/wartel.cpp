#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<pair<string, int>> v;
    for (int i = 0; i < N; i++){
        string s;
        int x;
        cin >> s >> x;
        v.push_back(make_pair(s, x));
    }
    for (int i = 0; i < Q; i++){
        l = 0;
        r = N-1;
        temp = 0;
        string x;
        cin >> x;
        while (l <= r){
            int mid = (l+r)/2;
            if (v[mid].first == x){
                cout << v[mid].second << endl;
                break;
            }
            else if (v[mid].first < x){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if (l > r){
            cout << "NIHIL" << endl;
        }
    }
}