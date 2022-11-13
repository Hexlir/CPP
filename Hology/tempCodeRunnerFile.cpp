#include <iostream>
using namespace std;

int main()
{
    int jml, total = 0, kolom, baris, temp;
    int bil[][5]={ 
		{1, 2, 35, 7, 10}, 
		{6, 7, 4, 1, 0} 
	};


    for (baris = 0; baris < 2; baris++)
        for (kolom = 0; kolom < 5; kolom++)
            cin >> temp;
            total += temp;
            
            bil[baris][kolom] = temp;

    cout << "Hasil penjumlahan 2 array tsb adalah = " << total;
}
