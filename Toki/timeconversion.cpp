// Given a time in -hour AM/PM format, convert it to military (24-hour) time.

// Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
// - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

#include <bits/stdc++.h>
#include "string"
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
    string s;
    cin >> s;
    
    string hour = s.substr(0, 2);
    string min = s.substr(3, 2);
    string sec = s.substr(6, 2);
    string ampm = s.substr(8, 2);

    if (ampm == "PM")
    {
        if (hour == "12")
        {
            cout << hour << ":" << min << ":" << sec << endl;
        }
        else
        {
            int h = stoi(hour);
            h += 12;
            cout << h << ":" << min << ":" << sec << endl;
        }
    }
    else
    {
        if (hour == "12")
        {
            cout << "00" << ":" << min << ":" << sec << endl;
        }
        else
        {
            cout << hour << ":" << min << ":" << sec << endl;
        }
    }
    return 0;
}