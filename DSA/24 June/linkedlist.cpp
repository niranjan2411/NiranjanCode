// Design a Singly Linked List and write functions to
// ○ Insert at beginning
// ○ Insert at end
// ○ Insert at any index
// ○ Delete at beginning
// ○ Delete at end
// ○ Delete at index

// ○ Delete first occurrence of node with given value
// ○ Write at least 2 test cases for each operation

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Print the list
    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }

    // Insert at any index
    void insertAtIndex(int index, int val) {
        if (index == 0) {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* curr = head;
        int i = 0;
        while (curr && i < index - 1) {
            curr = curr->next;
            i++;
        }
        if (!curr) {
            cout << "Index out of bounds\n";
            delete newNode;
            return;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->next) curr = curr->next;
        delete curr->next;
        curr->next = nullptr;
    }

    // Delete at index
    void deleteAtIndex(int index) {
        if (!head) return;
        if (index == 0) {
            deleteAtBeginning();
            return;
        }
        Node* curr = head;
        int i = 0;
        while (curr->next && i < index - 1) {
            curr = curr->next;
            i++;
        }
        if (!curr->next) {
            cout << "Index out of bounds\n";
            return;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    // Delete first occurrence of node with given value
    void deleteByValue(int val) {
        if (!head) return;
        if (head->data == val) {
            deleteAtBeginning();
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) curr = curr->next;
        if (!curr->next) {
            cout << "Value not found\n";
            return;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
};

int main() {
    SinglyLinkedList list;

    cout << "=== Insert at beginning ===\n";
    list.insertAtBeginning(10); list.printList(); // TC1
    list.insertAtBeginning(20); list.printList(); // TC2

    cout << "\n=== Insert at end ===\n";
    list.insertAtEnd(30); list.printList(); // TC1
    list.insertAtEnd(40); list.printList(); // TC2

    cout << "\n=== Insert at index ===\n";
    list.insertAtIndex(2, 25); list.printList(); // TC1
    list.insertAtIndex(0, 5); list.printList();  // TC2

    cout << "\n=== Delete at beginning ===\n";
    list.deleteAtBeginning(); list.printList(); // TC1
    list.deleteAtBeginning(); list.printList(); // TC2

    cout << "\n=== Delete at end ===\n";
    list.deleteAtEnd(); list.printList(); // TC1
    list.deleteAtEnd(); list.printList(); // TC2

    cout << "\n=== Delete at index ===\n";
    list.insertAtEnd(50); list.insertAtEnd(60); list.insertAtEnd(70); list.printList();
    list.deleteAtIndex(1); list.printList(); // TC1
    list.deleteAtIndex(5); list.printList(); // TC2 (out of bounds)

    cout << "\n=== Delete by value ===\n";
    list.deleteByValue(50); list.printList(); // TC1
    list.deleteByValue(999); list.printList(); // TC2 (not found)

    return 0;
}
