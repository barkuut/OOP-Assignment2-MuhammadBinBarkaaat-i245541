#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = nullptr; }
};

class LinkedListStack {
    Node* top;
public:
    LinkedListStack() { top = nullptr; }
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == nullptr) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek() {
        if (top == nullptr) return -1;
        return top->data;
    }
    bool isEmpty() { return top == nullptr; }
};

class ArrayStack {
    int* arr;
    int capacity;
    int top;
public:
    ArrayStack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    void push(int val) {
        if (top == capacity - 1) {
            int* newArr = new int[capacity * 2];
            for (int i = 0; i < capacity; i++) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            capacity *= 2;
        }
        arr[++top] = val;
    }
    void pop() {
        if (top >= 0) top--;
    }
    int peek() {
        if (top < 0) return -1;
        return arr[top];
    }
    bool isEmpty() { return top < 0; }
};

int iterativeFibonacciLinked(int n) {
    LinkedListStack s;
    s.push(n);
    int a = 0, b = 1, c = 0;
    while (!s.isEmpty()) {
        int num = s.peek();
        s.pop();
        if (num == 0) c = 0;
        else if (num == 1) c = 1;
        else {
            s.push(num - 1);
            s.push(num - 2);
        }
        a = b;
        b = c;
    }
    return c;
}

int iterativeFibonacciArray(int n) {
    ArrayStack s(10);
    s.push(n);
    int a = 0, b = 1, c = 0;
    while (!s.isEmpty()) {
        int num = s.peek();
        s.pop();
        if (num == 0) c = 0;
        else if (num == 1) c = 1;
        else {
            s.push(num - 1);
            s.push(num - 2);
        }
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << "LinkedList Stack Fibonacci: " << iterativeFibonacciLinked(n) << endl;
    cout << "Array Stack Fibonacci: " << iterativeFibonacciArray(n) << endl;
    return 0;
}

