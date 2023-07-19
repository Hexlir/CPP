#include "iostream"
#include "algorithm"
#include "cmath"

#define endl '\n'
#define fastIO \
    cin.tie(NULL); \
    cout.tie(NULL); \
    std::ios::sync_with_stdio(false);

using std::cin;
using std::cout;

int main(){
    int m, n;
    cin >> m;
    int bebek[m];
    for (int i = 0; i < m; i++)
    {
        cin >> bebek[i];
    }
    cin >> n; n -= 1;

    std::sort(bebek, bebek + m);

    int mid = std::floor((double)m / (double)n) - 1;

    for (int i = mid; i < m; i+=mid)
    {
        cout << bebek[i] - 1 << endl;
    }
}