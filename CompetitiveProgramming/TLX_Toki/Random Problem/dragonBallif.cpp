#include "iostream"
#include "string"

#define endl '\n'
#define fastIO \
    cin.tie(NULL); \
    cout.tie(NULL); \
    std::ios::sync_with_stdio(false);

using std::cin;
using std::cout;
using std::string;

int main(){
    fastIO;
    string S = "kamehameha";
    
    int n;
    cin >> n;

    while(n--){
        int p;
        cin >> p;

        if (p == 1) 
        {
            cout << S << endl;
            continue;
        }
 
        for(int i = 0; i < S.length(); i++){
            if (i == 0) cout << S.at(i);
            else if ((S.at(i) == 'h') or (S.at(i) == 'm')) cout << S.at(i);
            else
            {
                for (int j = 0; j < p; j++)
                {
                    cout << S.at(i);
                }
            }

        }
        cout << endl;
    }
}