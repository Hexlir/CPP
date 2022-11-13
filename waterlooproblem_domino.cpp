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

//return sum all divisors
int divisorFunction(int n)
{
  int ans = 1;
  int power = 0;
  while (n % 2 == 0)power++, n /= 2;
  //sum of GP
  ans *= (pow(2, power + 1) - 1);
  for (int i = 3; i * i <= n; i += 2) {
    power = 0;
    while (n % i == 0) {
      power++;
      n /= i;
    }
    ans *= (pow(i, power + 1) - 1) / (i - 1);
  }
  return ans;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    
    cout << divisorFunction(t) << endl;

    return 0;
}