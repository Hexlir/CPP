#include "bits/stdc++.h"

#define str string
#define endl "\n"

using namespace std;

int grid[128][128];

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void quadtree(int r, int c, int k, str s){
    if(s.length() == 1 && s[0] == '1'){
        for(int i = r; i < r+k; i++){
            for(int j = c; j < c+k; j++){
                grid[i][j] = 1;
            }
        }
    }
    else{
        if(s[1] == '0'){
            quadtree(r, c, k/2, s.erase(1,1));
        }
        else if(s[1] == '1'){
            quadtree(r, c+(k/2), k/2, s.erase(1,1));
        }
        else if(s[1] == '2'){
            quadtree(r+(k/2), c, k/2, s.erase(1,1));
        }
        else if(s[1] == '3'){
            quadtree(r+(k/2), c+(k/2), k/2, s.erase(1,1));
        }
    }
}

int main(){
    fastIO();

    int n; cin >> n;

    str ans[n];
    for(int i = 0; i < n; i++){
        cin >> ans[i];
    }
    
    int r, c; cin >> r >> c;

    int maxRc = max(r,c);
    int poww = 1;
    
    while(poww < maxRc){
        poww *= 2;
    }

    for(int i = 0; i < n; i++){
        quadtree(0,0,poww,ans[i]);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

