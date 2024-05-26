#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insert66AfterNegatives() {
        Node* current = head;

        while (current != nullptr) {
            if (current->data < 0) {
                Node* newNode = new Node();
                newNode->data = 66;

                newNode->prev = current;
                newNode->next = current->next;

                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                else {
                    tail = newNode;
                }

                current->next = newNode;
                current = newNode->next;
            }
            else {
                current = current->next;
            }
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

    DoublyLinkedList list;

    list.insert(-5);
    list.insert(10);
    list.insert(-8);
    list.insert(20);
    list.insert(-15);

    std::cout << "Исходный список: ";
    list.display();

    list.insert66AfterNegatives();

    std::cout << "Список после вставки числа 66: ";
    list.display();

    return 0;
}
