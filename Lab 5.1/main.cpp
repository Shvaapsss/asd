#include <iostream>
#include <cassert>

// Односвязный список
struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* first;  // Указатель на первый узел списка
    Node* last;   // Указатель на последний узел списка
    int length;   // Текущая длина списка
};

struct FindNodeResult {
    Node* node;     // Узел с искомым значением
    Node* prevNode; // Узел перед искомым значением
};

// Вставка нового узла после заданного узла или в начало списка
Node* insertAfter(LinkedList* list, Node* node, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!list->first) {
        // Список пуст
        list->first = newNode;
        list->last = newNode;
    } else if (!node) {
        // Вставка в начало списка
        newNode->next = list->first;
        list->first = newNode;
    } else {
        // Вставка после заданного узла
        newNode->next = node->next;
        node->next = newNode;

        if (node == list->last) {
            // Обновление указателя на последний узел
            list->last = newNode;
        }
    }

    list->length++;
    return newNode;
}

// Поиск узла по значению в списке
FindNodeResult find(LinkedList* list, int value) {
    FindNodeResult result;
    result.node = nullptr;
    result.prevNode = nullptr;

    Node* current = list->first;

    while (current) {
        if (current->data == value) {
            result.node = current;
            break;
        }

        result.prevNode = current;
        current = current->next;
    }

    return result;
}

// Удаление узла после заданного узла или первого узла списка
void removeAfter(LinkedList* list, Node* node) {
    if (!list->first || !node) {
        // Список пуст или узел не задан
        return;
    }

    Node* toRemove = node->next;

    if (!toRemove) {
        // Узел после заданного отсутствует
        return;
    }

    node->next = toRemove->next;

    if (toRemove == list->last) {
        // Обновление указателя на последний узел
        list->last = node;
    }

    delete toRemove;
    list->length--;
}

// Проверка отсутствия циклов в списке
void assertNoCycles(LinkedList* list) {
    int count = 0;
    Node* current = list->first;

    while (current) {
        count++;
        if (count > list->length) {
            // Найден цикл
            assert(false);
        }

        current = current->next;
    }
}

// Двусвязный список
struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;
};

struct DoublyLinkedList {
    DoublyNode* first;  // Указатель на первый узел списка
    DoublyNode* last;   // Указатель на последний узел списка
    int length;         // Текущая длина списка
};

// Вставка нового узла после заданного узла или в начало списка
DoublyNode* insertAfter(DoublyLinkedList* list, DoublyNode* node, int value) {
    DoublyNode* newNode = new DoublyNode{value, nullptr, nullptr};

    if (!list->first) {
        // Список пуст
        list->first = newNode;
        list->last = newNode;
    } else if (!node) {
        // Вставка в начало списка
        newNode->next = list->first;
        list->first->prev = newNode;
        list->first = newNode;
    } else {
        // Вставка после заданного узла
        newNode->prev = node;
        newNode->next = node->next;

        if (node->next) {
            node->next->prev = newNode;
        } else {
            // Обновление указателя на последний узел
            list->last = newNode;
        }

        node->next = newNode;
    }

    list->length++;
    return newNode;
}

// Вставка нового узла перед заданным узлом или в конец списка
DoublyNode* insertBefore(DoublyLinkedList* list, DoublyNode* node, int value) {
    DoublyNode* newNode = new DoublyNode{value, nullptr, nullptr};

    if (!list->first) {
        // Список пуст
        list->first = newNode;
        list->last = newNode;
    } else if (!node) {
        // Вставка в конец списка
        newNode->prev = list->last;
        list->last->next = newNode;
        list->last = newNode;
    } else {
        // Вставка перед заданным узлом
        newNode->prev = node->prev;
        newNode->next = node;

        if (node->prev) {
            node->prev->next = newNode;
        } else {
            // Обновление указателя на первый узел
            list->first = newNode;
        }

        node->prev = newNode;
    }

    list->length++;
    return newNode;
}

// Поиск узла по значению в списке
DoublyNode* find(DoublyLinkedList* list, int value) {
    DoublyNode* current = list->first;

    while (current) {
        if (current->data == value) {
            return current;
        }

        current = current->next;
    }

    return nullptr;
}

// Удаление заданного узла из списка
void remove(DoublyLinkedList* list, DoublyNode* node) {
    if (!list->first || !node) {
        // Список пуст или узел не задан
        return;
    }

    if (node->prev) {
        node->prev->next = node->next;
    } else {
        // Обновление указателя на первый узел
        list->first = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        // Обновление указателя на последний узел
        list->last = node->prev;
    }

    delete node;
    list->length--;
}

// Проверка отсутствия циклов в списке
void assertNoCycles(DoublyLinkedList* list) {
    int count = 0;
    DoublyNode* current = list->first;

    while (current) {
        count++;
        if (count > list->length) {
            // Найден цикл
            assert(false);
        }

        current = current->next;
    }
}

// Очередь
struct Queue {
    Node* first;  // Указатель на первый узел в очереди
    Node* last;   // Указатель на последний узел в очереди
};

// Добавление элемента в конец очереди
void enqueue(Queue* queue, int value) {
    Node* newNode = new Node{value, nullptr};

    if (!queue->first) {
        // Очередь пуста
        queue->first = newNode;
        queue->last = newNode;
    } else {
        // Добавление в конец очереди
        queue->last->next = newNode;
        queue->last = newNode;
    }
}

// Удаление элемента из начала очереди
int dequeue(Queue* queue) {
    if (!queue->first) {
        // Очередь пуста
        assert(false);
        return -1; // или выбросить исключение
    }

    Node* toRemove = queue->first;
    int value = toRemove->data;

    queue->first = toRemove->next;

    if (!queue->first) {
        // Очередь теперь пуста
        queue->last = nullptr;
    }

    delete toRemove;
    return value;
}

// Проверка, пуста ли очередь
bool isEmpty(Queue* queue) {
    return !queue->first;
}

// Функции тестирования
void testLinkedList() {
    LinkedList list = {nullptr, nullptr, 0};

    Node* node1 = insertAfter(&list, nullptr, 1);
    Node* node2 = insertAfter(&list, node1, 2);
    Node* node3 = insertAfter(&list, node2, 3);

    FindNodeResult result = find(&list, 2);
    assert(result.node == node2 && result.prevNode == node1);

    removeAfter(&list, node2);

    assertNoCycles(&list);

    // Освобождение памяти
    Node* current = list.first;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void testDoublyLinkedList() {
    DoublyLinkedList list = {nullptr, nullptr, 0};

    DoublyNode* node1 = insertAfter(&list, nullptr, 1);
    DoublyNode* node2 = insertAfter(&list, node1, 2);
    DoublyNode* node3 = insertAfter(&list, node2, 3);

    DoublyNode* foundNode = find(&list, 2);
    assert(foundNode == node2);

    remove(&list, node2);

    assertNoCycles(&list);

    // Освобождение памяти
    DoublyNode* current = list.first;
    while (current) {
        DoublyNode* next = current->next;
        delete current;
        current = next;
    }
}

void testQueue() {
    Queue queue = {nullptr, nullptr};

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    assert(dequeue(&queue) == 1);
    assert(dequeue(&queue) == 2);
    assert(dequeue(&queue) == 3);
    assert(isEmpty(&queue));
}

int main() {
    testLinkedList();
    testDoublyLinkedList();
    testQueue();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
