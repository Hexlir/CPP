#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "masukkan nilai : ";
    
    int nilai;

    cin >> nilai;

    if (nilai > 80)
    {
        cout << "nilai anda A" << endl;
    }
    else if (nilai > 70)
    {
        cout << "nilai anda B" << endl;
    }
    else if (nilai > 60)
    {
        cout << "nilai anda C" << endl;
    }
    else if (nilai > 50)
    {
        cout << "nilai anda D" << endl;
    }
    else
    {
        cout << "nilai anda E" << endl;
    }

    return 0;
}
