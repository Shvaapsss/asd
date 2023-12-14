#include "dynamicarray.h"
#include <iostream>
#include <cassert>

// Тестирование функций

void test1() {
    DynamicArray arr = createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
}

void test2() {
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    addElementToArray(&arr, 5);
    assert(arr.length == 1);
}

void test3() {
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4);
}

void test4() {
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5);
}

void test5() {
    DynamicArray arr{};
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    // Проверка через указатель на массив
    int* ptr = arr.data;
    assert(ptr[0] == 5);
    assert(ptr[1] == 6);
    assert(ptr[2] == 7);

    // Попытка доступа через getCurrentSpan должна привести к ошибке,
    // так как эта функция должна инвалидировать указатель на массив
    // std::span<int> span = getCurrentSpan(&arr);
}

int main() {
    // Вызов тестовых функций
    test1();
    test2();
    test3();
    test4();
    test5();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
