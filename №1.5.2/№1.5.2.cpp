#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    void removeMultiplesOfThree() {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data % 3 == 0) {
                if (current == head) {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    void insert88AfterEqualPairs() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* newNode = new Node(88);
                newNode->next = current->next;
                current->next = newNode;
                current = newNode->next;
            }
            else {
                current = current->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(6);
    list.append(6);
    list.append(7);
    list.append(8);
    list.append(9);
    list.append(9);
    list.append(9);

    std::cout << "Исходный список: ";
    list.display();

    list.removeMultiplesOfThree();
    std::cout << "Список после удаления элементов, кратных трём: ";
    list.display();

    list.insert88AfterEqualPairs();
    std::cout << "Список после вставки 88 после каждой пары равных рядом стоящих чисел: ";
    list.display();

    return 0;
}
