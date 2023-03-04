#include "iostream"
#include "iomanip"

int main(){
    double n;
    std::cin >> n;
    
    std::cout << std::setprecision(4) << n/4 << "\n";
}