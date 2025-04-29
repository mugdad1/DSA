/*
Part 2: Lab Tasks (10 points)
Note: Copy this section into a new word file then save it. You will only submit this section of the lab manual.

    •  Implement a Circular Singly Linked List. Providing the following operations:
        a. Insert at front
        b. Insert at rear.
        c. Delete from front.
        d. Delete from rear.
        e. Print the list in forward direction.

*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularSinglyLinkedList {
private:
    Node* head;

public:
    CircularSinglyLinkedList() : head(nullptr) {}

    // a. Insert at front
    void insertAtFront(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // b. Insert at rear
    void insertAtRear(int data) {
        Node* newNode = new Node{data, nullptr};
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // c. Delete from front
    void deleteFromFront() {
        if (head == nullptr) return; // List is empty

        Node* temp = head;
        if (head->next == head) { // Only one node in the list
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        }

        delete temp;
    }

    // d. Delete from rear
    void deleteFromRear() {
        if (head == nullptr) return; // List is empty

        Node* temp = head, * prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        if (prev == nullptr) { // Only one node in the list
            head = nullptr;
        } else {
            prev->next = head;
        }

        delete temp;
    }

    // e. Print the list in forward direction
    void printList() const {
        if (head == nullptr) return; // List is empty

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
