// main.cpp
#include <iostream>

static int hello(int x) {
    //принятие int x и название функции hello добавление модификатора static

    int zxc = x * 2;
    return zxc;
    //возвращается значение типа int
}

int main() {
    std::cout << "Result: " << hello(4) << std::endl;
    //вызов этой функции в main, никакой ошибки не выдало результат 6
    return 0;
}
