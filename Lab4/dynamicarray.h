#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>

// Структура для представления динамического массива
struct DynamicArray {
    int* data; // Указатель на массив данных
    size_t capacity; // Емкость массива
    size_t length; // Текущая длина массива
};

// Создание динамического массива с указанной начальной емкостью
DynamicArray createDynamicArrayWithCapacity(size_t capacity);

// Создание динамического массива с емкостью по умолчанию
DynamicArray createDynamicArray();

// Добавление элемента в конец динамического массива
void addElementToArray(DynamicArray* arr, int element);

// Получение элемента по индексу из динамического массива
int getElementAtIndex(const DynamicArray* arr, size_t index);

// Освобождение памяти, занятой динамическим массивом
void destroyDynamicArray(DynamicArray* arr);

#endif // DYNAMIC_ARRAY_H
