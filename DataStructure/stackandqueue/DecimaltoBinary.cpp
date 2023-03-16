// Decimal to Binary using Stack

#include "iostream"
#include "string"

using namespace std;

template <class T> class Stack {
    private:
        T *data;
        int top;
        int size;
    public:
        Stack(int size) {
            this->size = size;
            data = new T[size];
            top = -1;
        }
        ~Stack() {
            delete [] data;
        }
        bool isEmpty() {
            return top == -1;
        }
        bool isFull() {
            return top == size - 1;
        }
        void push(T value) {
            if (!isFull()) {
                top++;
                data[top] = value;
            }
        }
        T pop() {
            if (!isEmpty()) {
                T value = data[top];
                top--;
                return value;
            }
        }
        T peek() {
            if (!isEmpty()) {
                return data[top];
            }
        }
};

class DecimalToBinary {
    private:
        int decimal;
        Stack<int> *stack;
    public:
        DecimalToBinary(int decimal) {
            this->decimal = decimal;
            stack = new Stack<int>(decimal);
        }
        ~DecimalToBinary() {
            delete stack;
        }
        void convert() {
            while (decimal > 0) {
                stack->push(decimal % 2);
                decimal /= 2;
            }
        }
        void print() {
            while (!stack->isEmpty()) {
                cout << stack->pop();
            }
            cout << endl;
        }
};

int main() {
    int decimal;
    cout << "Enter decimal number: ";
    cin >> decimal;
    DecimalToBinary *decimalToBinary = new DecimalToBinary(decimal);
    decimalToBinary->convert();
    cout << "Binary number: ";
    decimalToBinary->print();
    delete decimalToBinary;
}
