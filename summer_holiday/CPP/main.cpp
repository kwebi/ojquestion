#include <iostream>

int main() {
    int a = 1;
    int b = (a = 0 + 2);
    std::cout << a << std::endl << b << std::endl;
    return 0;
}