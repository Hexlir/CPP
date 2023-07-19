#include "iostream"

int main(){
    short n,d;
    std::cin >> n >> d;
    if (d>1){
        std::cout << "YES" << std::endl;
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}