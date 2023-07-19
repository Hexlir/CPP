#include <iostream>
#define ull unsigned long long

using namespace std;

ull step;

void clearscreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // DEBUG
}

void hanoi(int n, char from, char to, char temp)
{
    if (n == 1)
    {
        cout << "Pindahkan cakram 1 dari " << from << " ke " << to << endl;
        step++;
    }
    else
    {
        hanoi(n - 1, from, temp, to);
        cout << "Pindahkan cakram " << n << " dari " << from << " ke " << to << endl;
        hanoi(n - 1, temp, to, from);
        step++;
    }
}

int main()
{
    clearscreen();

    int n;

    cin >> n; cout << endl;


    hanoi(n, 'A', 'C', 'B');

    cout << "\nJumlah langkah: " << step << endl;

    cin.get();cin.get();

    clearscreen();

    return 0;
}