#include <iostream>
using namespace std;

class Feature {
public:
    string Name;
    Feature(string n) : Name(n) {}
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(string n) : Feature(n) {}
    void analyze() override {
        cout << "Land Feature Detected: " << Name << " — Land area detected.\n";
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) : Feature(n) {}
    void analyze() override {
        cout << "Water Feature Detected: " << Name << " — Water body detected.\n";
    }
};

class Node {
public:
    int FeatureID;
    Feature* feature;
    Node* next;
    Node(int id, Feature* f) {
        FeatureID = id;
        feature = f;
        next = nullptr;
    }
    ~Node() {
        delete feature;
    }
};

class SinglyLinkedList {
private:
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtEnd(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteByID(int featureID) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->FeatureID == featureID) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Feature ID " << featureID << " deleted.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->FeatureID != featureID)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Feature ID " << featureID << " not found.\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Feature ID " << featureID << " deleted.\n";
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "No features in the list.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Feature ID: " << temp->FeatureID << " -> ";
            temp->feature->analyze();
            temp = temp->next;
        }
        cout << endl;
    }

    void reverseList() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "List reversed successfully.\n";
    }

    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(1, new LandFeature("Forest"));
    list.insertAtEnd(2, new WaterFeature("River"));
    list.insertAtEnd(3, new LandFeature("Mountain"));
    list.insertAtEnd(4, new WaterFeature("Ocean"));

    cout << "\n--- All Features ---\n";
    list.displayAll();

    cout << "\n--- Delete Feature with ID 2 ---\n";
    list.deleteByID(2);
    list.displayAll();

    cout << "\n--- Reverse List ---\n";
    list.reverseList();
    list.displayAll();

    return 0;
}


