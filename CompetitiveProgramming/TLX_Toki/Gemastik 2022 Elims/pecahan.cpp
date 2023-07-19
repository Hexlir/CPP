#include "iostream"
#include "string"

#define endl '\n'
#define l long

using std::cin;
using std::cout;
using std::string;

l a,b,c,d;

inline string solve (l *a, l *b, l *c, l *d)
{
    double x = (double) *a / (double) *b;
    double y = (double) *c / (double) *d;

    if (x == y) return "sama";
    if (x > y) return "lebih besar";
    if (x < y) return "lebih kecil";
}

int main()
{
    cin >> a >> b;
    cin >> c >> d;

    cout << solve (&a, &b, &c, &d) << endl;
}