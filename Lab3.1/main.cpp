// main.cpp
#include <iostream>

int hello(int x) {
    //принятие int x и название функции hello

    int zxc = x * 2;
    return zxc;
    //возвращается значение типа int
}

int main() {
    std::cout << "Result: " << hello(3) << std::endl;
    //вызов этой функции в main, никакой ошибки не выдало результат 6
    return 0;
}
