#include "iostream"
#include "vector"
#include "algorithm"
#include "math.h"

#define endl '\n'
#define ll long long

using std::cin;
using std::cout;
using std::vector;
using std::sort;
using std::abs;

ll n, m;
ll h[100000009];

struct node 
{
    ll u, v;
    ll hp;
};

vector<node> edges;

int main()
{
    cin >> n >> m;

    for (ll i = 0; i < n; i++)
        cin >> h[i];
    
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        ll hp = abs(h[u-1] - h[v-1]);
    }

    
}