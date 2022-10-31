#include "bits/stdc++.h"
#include "algorithm"

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, C;
    bool K;

    cin >> A >> B >> C >> K;
    
    array<int, 3> arr = {A, B, C};
    if (K == true)
    {
        cout << sort(arr) << endl;
    }

    return 0;
}
