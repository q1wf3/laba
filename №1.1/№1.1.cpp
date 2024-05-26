#include <iostream>
#include <stack>


class IntStack {
private:
	std::stack<int> data_stack;

public:
	void push(int value) {
		data_stack.push(value);
	}

	int pop() {
		if (data_stack.empty()) {
			std::cerr << "Стек пуст!" << std::endl;
			return 0;
		}
		int top_value = data_stack.top();
		data_stack.pop();
		return top_value;
	}

	void display() {
		std::stack<int> temp_stack = data_stack;
		std::cout << "Данные стека: ";
		while (!temp_stack.empty()) {
			std::cout << temp_stack.top() << " ";
			temp_stack.pop();
		}
		std::cout << std::endl;
	}

	double averageOfEven() {
		if (data_stack.empty()) {
			std::cerr << "Стек пуст!" << std::endl;
			return 0.0;
		}

		int sum = 0;
		int count = 0;
		std::stack<int> temp_stack = data_stack;

		while (!temp_stack.empty()) {
			int top_value = temp_stack.top();
			temp_stack.pop();

			if (top_value % 2 == 0) {
				sum += top_value;
				count++;
			}
		}

		if (count == 0) {
			std::cerr << "Стек не содержит чётных чисел!" << std::endl;
			return 0.0;
		}

		return static_cast<double>(sum) / count;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	IntStack stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.push(7);
	stack.push(8);
	stack.push(9);
	stack.push(10);

	stack.display();

	double average = stack.averageOfEven();
	if (average != 0.0) {
		std::cout << "Среднее арифметическое чётных значений элементов стека: " << average << std::endl;
	}

	return 0;
}
