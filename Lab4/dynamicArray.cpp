#include "dynamicarray.h"
#include <iostream>

// Создание динамического массива с указанной начальной емкостью
DynamicArray createDynamicArrayWithCapacity(size_t capacity) {
    DynamicArray arr;
    arr.data = new int[capacity]; // Выделение памяти для массива данных
    arr.capacity = capacity;
    arr.length = 0;
    return arr;
}

// Создание динамического массива с емкостью по умолчанию
DynamicArray createDynamicArray() {
    return createDynamicArrayWithCapacity(4); // Задаем емкость по умолчанию равной 4
}

// Добавление элемента в конец динамического массива
void addElementToArray(DynamicArray* arr, int element) {
    // Проверка наличия свободного места
    if (arr->length == arr->capacity) {
        // Если массив полный, увеличиваем его размер вдвое
        size_t newCapacity = arr->capacity * 2;
        int* newData = new int[newCapacity];
        // Копирование данных из старого массива в новый
        for (size_t i = 0; i < arr->length; ++i) {
            newData[i] = arr->data[i];
        }
        // Освобождение памяти старого массива
        delete[] arr->data;
        // Обновление данных структуры
        arr->data = newData;
        arr->capacity = newCapacity;
    }
    // Добавление элемента в конец массива
    arr->data[arr->length++] = element;
}

// Получение элемента по индексу из динамического массива
int getElementAtIndex(const DynamicArray* arr, size_t index) {
    // Проверка наличия элемента по индексу
    if (index < arr->length) {
        return arr->data[index];
    } else {
        return 0; // Возвращаем 0 в случае некорректного индекса
    }
}

// Освобождение памяти, занятой динамическим массивом
void destroyDynamicArray(DynamicArray* arr) {
    // Освобождение памяти массива данных
    delete[] arr->data;
    // Обнуление данных структуры
    arr->data = nullptr;
    arr->capacity = 0;
    arr->length = 0;
}
