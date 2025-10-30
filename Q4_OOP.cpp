#include <iostream>
using namespace std;

class Customer {
public:
    int ID;
    string Name;
    int Tickets;
    Customer* next;
    Customer(int id, string n, int t) {
        ID = id;
        Name = n;
        Tickets = t;
        next = nullptr;
    }
};

class Queue {
private:
    Customer* front;
    Customer* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int id, string name, int tickets) {
        Customer* newCustomer = new Customer(id, name, tickets);
        if (rear == nullptr) {
            front = rear = newCustomer;
            return;
        }
        rear->next = newCustomer;
        rear = newCustomer;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Customer* temp = front;
        cout << "Serving Customer: " << temp->Name << " (" << temp->Tickets << " tickets)\n";
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "No customers in queue.\n";
            return;
        }
        Customer* temp = front;
        cout << "\nCurrent Queue:\n";
        while (temp != nullptr) {
            cout << temp->ID << " | " << temp->Name << " | Tickets: " << temp->Tickets << endl;
            temp = temp->next;
        }
    }

    ~Queue() {
        while (front != nullptr) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

class PriorityQueue {
private:
    Customer* front;

public:
    PriorityQueue() { front = nullptr; }

    void enqueue(int id, string name, int tickets) {
        Customer* newCustomer = new Customer(id, name, tickets);
        if (front == nullptr || tickets > front->Tickets) {
            newCustomer->next = front;
            front = newCustomer;
            return;
        }
        Customer* temp = front;
        while (temp->next != nullptr && temp->next->Tickets >= tickets)
            temp = temp->next;
        newCustomer->next = temp->next;
        temp->next = newCustomer;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Priority Queue is empty.\n";
            return;
        }
        Customer* temp = front;
        cout << "Serving (Priority) Customer: " << temp->Name << " (" << temp->Tickets << " tickets)\n";
        front = front->next;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "No customers in priority queue.\n";
            return;
        }
        Customer* temp = front;
        cout << "\nPriority Queue:\n";
        while (temp != nullptr) {
            cout << temp->ID << " | " << temp->Name << " | Tickets: " << temp->Tickets << endl;
            temp = temp->next;
        }
    }

    ~PriorityQueue() {
        while (front != nullptr) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(1, "Ali", 2);
    q.enqueue(2, "Sara", 4);
    q.enqueue(3, "Ahmed", 1);

    cout << "\n--- Regular Queue ---\n";
    q.display();
    q.dequeue();
    q.display();

    PriorityQueue pq;
    pq.enqueue(1, "Ali", 2);
    pq.enqueue(2, "Sara", 4);
    pq.enqueue(3, "Ahmed", 1);

    cout << "\n--- Priority Queue ---\n";
    pq.display();
    pq.dequeue();
    pq.display();

    return 0;
}

