#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <functional>
#include <random>

// Функция для создания и заполнения массива случайными числами
int* createAndFillArray(int size) {
    int* array = new int[size];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    for (int i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }

    return array;
}

// Функция для измерения времени выполнения функции
template <typename Func>
long long measureExecutionTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Алгоритмы сортировки
void selectionSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(array[i], array[minIndex]);
    }
}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void merge(int* array, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    for (int i = 0; i < n1; ++i) {
        leftArray[i] = array[low + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            ++i;
        } else {
            array[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = rightArray[j];
        ++j;
        ++k;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int* array, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (array[j] < pivot) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return i + 1;
}

void quickSort(int* array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

// Алгоритмы поиска
int linearSearch(const int* array, int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int* array, int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    srand(time(nullptr));

    const int arraySize = 10000; // Размер массива
    int* array = createAndFillArray(arraySize);

    // Тестирование Selection Sort
    std::cout << "Testing Selection Sort..." << std::endl;
    long long selectionSortTime = measureExecutionTime([&]() {
        selectionSort(array, arraySize);
    });
    std::cout << "Selection Sort Execution Time: " << selectionSortTime << " microseconds" << std::endl;

    // Тестирование Bubble Sort
    std::cout << "Testing Bubble Sort..." << std::endl;
    long long bubbleSortTime = measureExecutionTime([&]() {
        bubbleSort(array, arraySize);
    });
    std::cout << "Bubble Sort Execution Time: " << bubbleSortTime << " microseconds" << std::endl;

    // Тестирование Merge Sort
    std::cout << "Testing Merge Sort..." << std::endl;
    long long mergeSortTime = measureExecutionTime([&]() {
        mergeSort(array, 0, arraySize - 1);
    });
    std::cout << "Merge Sort Execution Time: " << mergeSortTime << " microseconds" << std::endl;

    // Тестирование Quick Sort
    std::cout << "Testing Quick Sort..." << std::endl;
    long long quickSortTime = measureExecutionTime([&]() {
        quickSort(array, 0, arraySize - 1);
    });
    std::cout << "Quick Sort Execution Time: " << quickSortTime << " microseconds" << std::endl;

    // Тестирование Linear Search
    std::cout << "Testing Linear Search..." << std::endl;
    int linearSearchTarget = array[rand() % arraySize]; // Выбираем случайный элемент для поиска
    long long linearSearchTime = measureExecutionTime([&]() {
        int result = linearSearch(array, arraySize, linearSearchTarget);
        // Добавим вывод результата, чтобы компилятор не оптимизировал поиск
        std::cout << "Linear Search Result: " << result << std::endl;
    });
    std::cout << "Linear Search Execution Time: " << linearSearchTime << " microseconds" << std::endl;

    // Тестирование Binary Search
    std::cout << "Testing Binary Search..." << std::endl;
    // Перед бинарным поиском нужно убедиться, что массив отсортирован
    std::sort(array, array + arraySize);
    int binarySearchTarget = array[rand() % arraySize]; // Выбираем случайный элемент для поиска
    long long binarySearchTime = measureExecutionTime([&]() {
        int result = binarySearch(array, arraySize, binarySearchTarget);
        // Добавим вывод результата, чтобы компилятор не оптимизировал поиск
        std::cout << "Binary Search Result: " << result << std::endl;
    });
    std::cout << "Binary Search Execution Time: " << binarySearchTime << " microseconds" << std::endl;

    delete[] array;
    return 0;
}
