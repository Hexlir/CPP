#include "algorithm"
#include "iostream"
#include "numeric"
#include "cstdlib"
#include "cassert"
#include "iomanip"
#include "cstdio"
#include "limits"
#include "string"
#include "vector"
#include "cmath"
#include "cmath"
#include "deque"
#include "queue"
#include "stack"
#include "map"
#include "set"
using namespace std;

typedef long long ll;
typedef long long LL;
typedef string str;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<int,int> PII;
typedef pair<ll,ll> pll;
typedef pair<ll,ll> PLL;

#define elif else if
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>b;--i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define popf pop_front
#define popb pop_back
#define pf push_front
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define i16 short
#define i32 int
#define i64 long
#define i128 long long
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long
#define u128 unsigned long long
#define f32 float
#define f64 double
#define f80 long double

#define endl '\n'
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; }

const double EPS = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const ll LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const double PI = acos(-1);
const ll MOD = 998244353;
const int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
const char DCH[4] = {'D', 'U', 'R', 'L'};
const char dch[4] = {'d', 'u', 'r', 'l'};
const str ds[8] = {"E", "W", "S", "N", "SE", "NW", "SW", "NE"};

// macros
template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return b > a ? a = b, 1 : 0;}
template<class T> T gcd(T a, T b) {return b ? gcd(b, a % b) : a;}
template<class T> T lcm(T a, T b) {return a / gcd(a, b) * b;}
template<class T> T sqr(T a) {return a * a;}
template<class T> int sgn(T a) {return (a > 0) - (a < 0);}
template<class T> T abs(T a) {return a >= 0 ? a : -a;}
template<class T> T pow(T a, int b) {return b ? (b & 1 ? a * pow(a, --b) : sqr(pow(a, b >> 1))) : 1;}
template<class T> void remdup(vector<T> &v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
template<class T> void read(T &x) {cin >> x;}
template<class H, class... T> void read(H &h, T &...t) {read(h); read(t...);}
template<class T> void read(vector<T> &v) {for (auto &x : v) read(x);}
template<class T> void read(T v[], int n) {rep(i, 0, n) read(v[i]);}
template<class T> void readln(T &x) {getline(cin, x);}
template<class H, class... T> void read(vector<H> &h, vector<T> &...t) {read(h); read(t...);}
template<class T> void write(T x) {cout << x;}
template<class H, class... T> void write(H h, T... t) {write(h); write(t...);}
template<class T> void write(vector<T> &v) {for (auto &x : v) write(x);}
template<class T> void write(T v[], int n) {rep(i, 0, n) write(v[i]);}
template<class H, class... T> void write(vector<H> &h, vector<T> &...t) {write(h); write(t...);}
template<class T> void writeln(T x) {cout << x << endl;}
template<class H, class... T> void writeln(H h, T... t) {write(h); writeln(t...);}
template<class T> void writeln(vector<T> &v) {for (auto &x : v) writeln(x);}
template<class T> void writeln(T v[], int n) {rep(i, 0, n) writeln(v[i]);}
template<class H, class... T> void writeln(vector<H> &h, vector<T> &...t) {write(h); writeln(t...);}
template<class T> void debug(T x) {cerr << x << endl;}
template<class H, class... T> void debug(H h, T... t) {debug(h); debug(t...);}
template<class T> void debug(vector<T> &v) {for (auto &x : v) debug(x);}
template<class T> void debug(T v[], int n) {rep(i, 0, n) debug(v[i]);}
template<class H, class... T> void debug(vector<H> &h, vector<T> &...t) {debug(h); debug(t...);}

inline void open(string a) {
#ifndef LOCAL
    freopen((a + ".in").c_str(), "r", stdin);
    freopen((a + ".out").c_str(), "w", stdout);
#endif
}

inline void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

inline void setIO(string a = "") {
    fastio();
#ifdef LOCAL
    open(a);
#endif
}

bool isVisited[101][101];
i32 grid[101][101];
i32 counter = 0;

void jawbreaker(i32 x, i32 y, i32 c){
    if(x >= 0 && y >= 0){
        if(grid[x][y] == c && !isVisited[x][y]){
            isVisited[x][y] = true;
            counter++;
            jawbreaker(x+1, y, c);
            jawbreaker(x-1, y, c);
            jawbreaker(x, y+1, c);
            jawbreaker(x, y-1, c);
        }
    }
}

inline void solve() {
    i32 n, m; read(n); read(m);

    rep(i, 0, n){
        rep(j, 0, m){
            read(grid[i][j]);
        }
    }

    i32 x, y; read(x); read(y);
    i32 c = grid[x][y];

    jawbreaker(x, y, c);

    if(x >= n || y >= m){
        counter = 0;
    }
    else{
        writeln(counter*(counter-1));
    }
}

int main() {
    setIO();
    solve();
    return 0;
}