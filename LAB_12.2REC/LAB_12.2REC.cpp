#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countElementsWithValueRecursive(Node* current, int value) {
    if (current == nullptr) {
        return 0;
    }

    int count = countElementsWithValueRecursive(current->next, value);

    if (current->data == value) {
        return count + 1;
    }

    return count;
}

void createListRecursive(Node*& head, Node*& tail, int values[], int size, int index = 0) {
    if (index == size) {
        return;
    }

    Node* newNode = new Node();
    newNode->data = values[index];
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    createListRecursive(head, tail, values, size, index + 1);
}

void printListRecursive(Node* current) {
    if (current == nullptr) {
        cout << endl;
        return;
    }

    cout << current->data << " ";
    printListRecursive(current->next);
}

int main() {
    int values[] = { 1, 2, 3, 4, 5, 2 };
    int size = sizeof(values) / sizeof(values[0]);

    Node* head = nullptr;
    Node* tail = nullptr;

    createListRecursive(head, tail, values, size);

    cout << "Список елементів:" << endl;
    printListRecursive(head);

    int valueToCount = 2;
    int count = countElementsWithValueRecursive(head, valueToCount);

    cout << "Кількість елементів зі значенням " << valueToCount << ": " << count << endl;

    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
