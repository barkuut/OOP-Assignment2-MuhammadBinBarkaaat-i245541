#include <iostream>
using namespace std;

class Node {
public:
    int BookID;
    string Title;
    string Author;
    Node* prev;
    Node* next;

    Node(int id, string t, string a) {
        BookID = id;
        Title = t;
        Author = a;
        prev = nullptr;
        next = nullptr;
    }
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

    void addAtBeginning(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void addAtEnd(int id, string title, string author) {
        Node* newNode = new Node(id, title, author);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void addAtPosition(int pos, int id, string title, string author) {
        if (pos <= 1) {
            addAtBeginning(id, title, author);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;
        if (temp == nullptr || temp->next == nullptr) {
            addAtEnd(id, title, author);
            return;
        }
        Node* newNode = new Node(id, title, author);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteByID(int id) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr && temp->BookID != id)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Book ID " << id << " not found.\n";
            return;
        }
        if (temp == head)
            head = head->next;
        if (temp == tail)
            tail = tail->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Book ID " << id << " deleted.\n";
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "No books in list.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->BookID << " | " << temp->Title << " | " << temp->Author << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "No books in list.\n";
            return;
        }
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->BookID << " | " << temp->Title << " | " << temp->Author << endl;
            temp = temp->prev;
        }
    }

    class Iterator {
        Node* current;
    public:
        Iterator(Node* ptr) : current(ptr) {}
        bool operator!=(const Iterator& other) const { return current != other.current; }
        Iterator& operator++() { current = current->next; return *this; }
        Iterator& operator--() { current = current->prev; return *this; }
        Node& operator*() { return *current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    Iterator rbegin() { return Iterator(tail); }
    Iterator rend() { return Iterator(nullptr); }

    ~DoublyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DoublyLinkedList library;
    library.addAtEnd(1, "1984", "George Orwell");
    library.addAtEnd(2, "The Alchemist", "Paulo Coelho");
    library.addAtBeginning(3, "Pride and Prejudice", "Jane Austen");
    library.addAtPosition(2, 4, "Moby Dick", "Herman Melville");

    cout << "\n--- Books in Order ---\n";
    library.displayForward();

    cout << "\n--- Books in Reverse Order ---\n";
    library.displayBackward();

    cout << "\n--- Delete Book with ID 2 ---\n";
    library.deleteByID(2);
    library.displayForward();

    cout << "\n--- Traversing Forward with Iterator ---\n";
    for (auto it = library.begin(); it != library.end(); ++it)
        cout << (*it).BookID << " | " << (*it).Title << " | " << (*it).Author << endl;

    cout << "\n--- Traversing Backward with Iterator ---\n";
    for (auto it = library.rbegin(); it != library.rend(); --it)
        cout << (*it).BookID << " | " << (*it).Title << " | " << (*it).Author << endl;

    return 0;
}

