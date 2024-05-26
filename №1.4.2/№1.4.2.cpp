#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;

    Node(const std::string& d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(const std::string& data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    int countLatinLetters() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            for (char c : current->data) {
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    count++;
                }
            }
            current = current->next;
        }
        return count;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    LinkedList list;
    list.append("Hello, world!");
    list.append("aBc");
    list.append("12345");

    int latinCount = list.countLatinLetters();
    std::cout << "Общее количество латинских букв: " << latinCount << std::endl;

    return 0;
}
