#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int N;

    cin >> N;

    vector <int> B;

    for (int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        B[i] = temp;
    }

    cout << *max_element(B.begin(), B.end()) << " " << *min_element(B.begin(), B.end()) << endl;
    return 0;
}
