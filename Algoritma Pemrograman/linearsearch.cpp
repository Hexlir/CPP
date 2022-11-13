#include "bits/stdc++.h"

using namespace std;

int linearSearch(int array[], int size, int userinput){

    for (int i = 0; i < size; i++){
        if ( userinput == array[i]){
            cout << i << endl;
        }
    }

    return -1;

}

int main(int argc, char const *argv[])
{
    int a[] = {15,23,7,45,87,16};

    int userVal;

    cin >> userVal;

    linearSearch(a, 6, userVal);


    return 0;
}
