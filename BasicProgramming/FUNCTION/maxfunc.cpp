#include "iostream"

using namespace std;

void max(auto a, auto b)
{
    return (a > b) ? a : b;
}

int main(){
    int a, b;

    cin >> a >> b;

    cout << max(a, b);
}