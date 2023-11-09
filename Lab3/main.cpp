#include <iostream>
using namespace std;
int hello(int num) {
    return num * 2;
}

int main() {
    int result = hello(5);
    cout << "Result: " << result << std::endl;
    return 0;
}
