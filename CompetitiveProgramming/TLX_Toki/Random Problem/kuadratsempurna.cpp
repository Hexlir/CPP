#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    long num;

    cin >> num;

    double result = sqrt(num);
    
    if(result != int(result)){
        cout << 0 << endl;
        return 0;
    }


    cout << result << endl;
    return 0;
}