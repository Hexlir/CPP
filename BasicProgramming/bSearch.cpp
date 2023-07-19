#include <bits/stdc++.h>

using namespace std;

void binarySearch(arr list ; int item){
    int low = 0;
    int high = length(list) - 1;

    while (low <= high){
        int mid = (low + high) / 2;
        int guess = list[mid];
        if (guess == item){
            return mid;
        }
        if (guess > item){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}

int main(){
    int my_list[] = {1,3,5,7,9};
    cout << binarySearch(my_list, 3);
    cout << binarySearch(my_list, -1);

}