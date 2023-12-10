#include "dynamicarray.h"

// Создание динамического массива с указанной начальной емкостью
DynamicArray createDynamicArrayWithCapacity(size_t capacity) {
    DynamicArray arr;
    // Резервирование памяти в векторе для указанной емкости
    arr.data.reserve(capacity);
    return arr;
}

// Создание динамического массива с емкостью по умолчанию
DynamicArray createDynamicArray() {
    return createDynamicArrayWithCapacity(4); // Задаем емкость по умолчанию равной 4
}

// Добавление элемента в конец динамического массива
void addElementToArray(DynamicArray* arr, int element) {
    arr->data.push_back(element); // Добавление элемента в конец вектора
}

// Получение элемента по индексу из динамического массива
int getElementAtIndex(const DynamicArray* arr, size_t index) {
    // Проверка наличия элемента по индексу
    if (index < arr->data.size()) {
        return arr->data[index];
    } else {
        return 0; // Возвращаем 0 в случае некорректного индекса
    }
}

// Освобождение памяти, занятой динамическим массивом
void destroyDynamicArray(DynamicArray* arr) {
    // Ничего не нужно удалять, так как вектор сам управляет своей памятью
    arr->data.clear(); // Очистка вектора
}
