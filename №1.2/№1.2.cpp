#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(string value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Стек пуст" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void printStack() {
        if (top == nullptr) {
            cout << "Стек пуст" << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    string findMinLengthString() {
        if (top == nullptr) {
            return "";
        }
        Node* current = top;
        string minLengthString = current->data;
        while (current != nullptr) {
            if (current->data.length() < minLengthString.length()) {
                minLengthString = current->data;
            }
            current = current->next;
        }
        return minLengthString;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    Stack stack;
    stack.push("sdf");
    stack.push("2");
    stack.push("ssd4");
    stack.push("hello");

    cout << "Содержимое стека после добавления элементов:" << endl;
    stack.printStack();

    stack.pop();
    stack.pop();

    cout << "Содержимое стека после удаления двух элементов:" << endl;
    stack.printStack();

    string minLengthString = stack.findMinLengthString();
    if (minLengthString != "") {
        cout << "Строка минимальной длины в стеке: " << minLengthString << endl;
    }
    else {
        cout << "Стек пуст, нет строк для поиска минимальной длины." << endl;
    }

    return 0;
}
