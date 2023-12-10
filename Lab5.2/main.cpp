#include <iostream>
#include <vector>

// Структура для представления нода графа
struct GraphNode {
    int value;
    std::vector<GraphNode*> neighbors; // Динамический буфер для соседних нодов

    // Конструктор для удобного создания нода с заданным значением
    GraphNode(int val) : value(val) {}
};

// Функция для вычисления суммы значений соседних нодов заданного нода
int sumNeighbors(const GraphNode* node) {
    int sum = 0;
    for (const GraphNode* neighbor : node->neighbors) {
        sum += neighbor->value;
    }
    return sum;
}

int main() {
    // Создание графа с указанной конфигурацией
    GraphNode* node1 = new GraphNode(1);
    GraphNode* node2 = new GraphNode(2);
    GraphNode* node3 = new GraphNode(3);
    GraphNode* node4 = new GraphNode(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node3);
    node1->neighbors.push_back(node4);

    node2->neighbors.push_back(node3);

    node3->neighbors.push_back(node4);

    node4->neighbors.push_back(node1);

    // Пример использования функции для вычисления суммы значений соседних нодов
    std::cout << "Sum of neighbors for node1: " << sumNeighbors(node1) << std::endl;
    std::cout << "Sum of neighbors for node2: " << sumNeighbors(node2) << std::endl;
    std::cout << "Sum of neighbors for node3: " << sumNeighbors(node3) << std::endl;
    std::cout << "Sum of neighbors for node4: " << sumNeighbors(node4) << std::endl;

    // Освобождение выделенной памяти
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
