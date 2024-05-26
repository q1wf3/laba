#include <iostream>

struct Node {
    double data;
    Node* next;

    Node(double value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(double value) {
        if (head == nullptr) {
            head = new Node(value);
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);
        }
    }

    void insertBefore22(double value, double newValue) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != 22) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            Node* newNode = new Node(newValue);
            newNode->next = current;
            if (prev != nullptr) {
                prev->next = newNode;
            }
            else {
                head = newNode;
            }
        }
        else {
            std::cout << "Элемент со значением 22 не найден\n";
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    LinkedList list;

    list.insert(10);
    list.insert(22);
    list.insert(30);
    list.insert(40);

    std::cout << "Список до вставки:\n";
    list.display();

    list.insertBefore22(22, 0.99);

    std::cout << "Список после вставки:\n";
    list.display();

    return 0;
}
