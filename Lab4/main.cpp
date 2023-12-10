#include "dynamicarray.h"
#include <iostream>

int main() {
    // Тестирование функций
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 10);
    addElementToArray(&arr, 15);

    // Вывод элементов массива на экран
    for (size_t i = 0; i < arr.data.size(); ++i) {
        std::cout << "Element at index " << i << ": " << getElementAtIndex(&arr, i) << std::endl;
    }

    // Освобождение памяти, занятой динамическим массивом
    destroyDynamicArray(&arr);

    return 0;
}
