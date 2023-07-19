#include <iostream>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastio();

    string s;
    cin >> s;

    int cUpper = 0, cLower = 0, cNumber = 0, cSymbol = 0;

    for (char c : s) {
        if (isupper(c)) {
            cUpper++;
        } else if (islower(c)) {
            cLower++;
        } else if (isdigit(c)) {
            cNumber++;
        } else {
            cSymbol++;
        }
    }

    if (cUpper > 0 && cLower > 0 && cNumber > 0 && cSymbol > 0 && (cUpper + cLower + cNumber + cSymbol) > 8) {
        cout << "Kuat\n";
    } else if ((cUpper + cLower) > 12) {
        cout << "AgakKuat\n";
    } else {
        cout << "Lemah\n";
    }

    return 0;
}
