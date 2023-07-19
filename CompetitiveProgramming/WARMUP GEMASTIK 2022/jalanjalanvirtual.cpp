#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t-- > 0) {
        int step, x = 0, y = 0, temp = 1, temp2 = 1, direction = 0;

        cin >> step;

        for(int i = 1; i <= step; i++){
            if(direction == 0){
                x++;
            }
            else if(direction == 1){
                y++;
            }
            else if(direction == 2){
                x--;
            }
            else if(direction == 3){
                y--;
            }

            temp2--;

            if(temp2 == 0){
                temp++;
                temp2 = temp;
                if(direction + 1 == 4){
                    direction = 0;
                }
                else{
                    direction++;
                }
            }

        }

        cout << x << " " << y << endl;
    }
}