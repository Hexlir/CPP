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
    string s; cin >> s;
    for(int i = 0; i < s.length();i++){
        if (i == 0){
            continue;
        }
        if(s[i] == '_'){
            s.erase(i,1);
            s[i] = toupper(s[i]);
        }
        // detect are there any uppercase letter
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            s.insert(i, "_");
            s[i+1] = tolower(s[i+1]);
        }
    }
    cout << s << endl;

    return 0;
}