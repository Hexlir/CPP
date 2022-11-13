#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B;
    char op;
    cin >> A >> op >> B;

    if (op == '+')
    {
        cout << A + B << endl;
    }
    else if (op == '-')
    {
        cout << A - B << endl;
    }
    else if (op == '*')
    {
        cout << A * B << endl;
    }
    else if (op == '>' && A > B)
    {
        cout << "benar" << endl;
    }
    else if (op == '<' && A < B)
    {
        cout << "benar" << endl;
    }
    else if (op == '=' && A == B)
    {
        cout << "benar" << endl;
    }
    else
    {
        cout << "salah" << endl;
    }
    return 0;
}
