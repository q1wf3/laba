#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Стек пуст!" << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    void printStack() {
        Node* current = top;
        cout << "Содержимое стека: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int countNumbersGreaterThan(int threshold) {
        int count = 0;
        Node* current = top;
        while (current != nullptr) {
            if (current->data > threshold) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    Stack stack;

    stack.push(1);
    stack.push(4);
    stack.push(2);

    stack.printStack();

    stack.push(4);

    stack.printStack();

    int count = stack.countNumbersGreaterThan(3);
    cout << "Количество чисел, больших 3: " << count << endl;

    return 0;
}
