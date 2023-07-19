#include "iostream"

#define endl '\n'
#define l long

using std::cin;
using std::cout;

#define fastIO \
    cin.tie(NULL); \
    cout.tie(NULL); \
    std::ios::sync_with_stdio(false);

l binSearch(l arr[], l low, l high, l key)
{
    while (low <= high)
    {
        l mid = (low + high) / l(2);

        if (arr[mid] <= key)
        {
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return low;
}

int main()
{
    fastIO;
    l n, k;
    cin >> n >> k;

    l a[n + 3];
    l total = 0;

    for (l i = 0; i < n; i  ++)
    {
        cin >> a[i];
        total += a[i];
        a[i] = total;
    }

    for (l i = 0; i < k; i++)
    {
        l b;
        cin >> b;

        cout << binSearch(a, 0, n - 1, b) << endl;
    }
}