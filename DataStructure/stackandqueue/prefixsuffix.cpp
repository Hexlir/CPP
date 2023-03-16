//  konversi dari notasi bentuk infix menjadi bentuk postfix dan prefix menggunakan stack

#include <iostream>
#include <string>

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

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

bool isOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

bool isOperand(char op) {
    return (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z');
}

string infixToPostfix(string infix) {
    Stack<char> stack(infix.length());
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        if (isOperand(infix[i])) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop();
        } else if (isOperator(infix[i])) {
            while (!stack.isEmpty() && precedence(infix[i]) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    return postfix;
}

string infixToPrefix(string infix) {
    Stack<char> stack(infix.length());
    string prefix = "";
    for (int i = infix.length() - 1; i >= 0; i--) {
        if (isOperand(infix[i])) {
            prefix += infix[i];
        } else if (infix[i] == ')') {
            stack.push(infix[i]);
        } else if (infix[i] == '(') {
            while (!stack.isEmpty() && stack.peek() != ')') {
                prefix += stack.pop();
            }
            stack.pop();
        } else if (isOperator(infix[i])) {
            while (!stack.isEmpty() && precedence(infix[i]) < precedence(stack.peek())) {
                prefix += stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    while (!stack.isEmpty()) {
        prefix += stack.pop();
    }
    string temp = "";
    for (int i = prefix.length() - 1; i >= 0; i--) {
        temp += prefix[i];
    }
    return temp;
}

int main() {
    string infix = "A + B / C -  D *E";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    cout << "Prefix: " << infixToPrefix(infix) << endl;
    return 0;
}