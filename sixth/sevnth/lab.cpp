
//1. Modify the above program to insert a new node in the middle of list (take a node data from user, search the node and insert new node after this node).
//2. Modify the above program to include an operation for searching a value from the linked list.
//3. Write a function to delete a matching node (by search) from a linked list of integers. You can use the example given above to develop your solution. In your answer, provide only the required function.
/*
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *link;
};

Node *temp = NULL, *cur = NULL, *head = NULL, *tail = NULL;

void InsertFront() {
    temp = new Node;
    cout << "Enter Integer Data:\n";
    cin >> temp->info;
    temp->link = nullptr;

    if (head == NULL) {
        head = tail = temp;
    } else {
        temp->link = head;
        head = temp;
    }
}

void InsertRear() {
    temp = new Node;
    cout << "Enter Integer Data:\n";
    cin >> temp->info;
    temp->link = nullptr;

    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->link = temp;
        tail = temp;
    }
}

void DeleteFront() {
    temp = head;
    if (head == NULL) {
        cout << "List is Empty!!\n";
    } else {
        if (temp->link == NULL) {
            head = tail = nullptr;
        } else {
            head = head->link;
        }
        cout << "Deleted: " << temp->info << "\n";
        delete temp;
    }
}

void DeleteRear() {
    cur = head;

    if (head == NULL) {
        cout << "List is Empty!!\n";
    } else {
        if (cur->link == NULL) {
            head = tail = nullptr;
        } else {
            while (cur->link != tail) {
                cur = cur->link;
            }
            tail = cur;
            cur->link = nullptr;
        }
        cout << "Deleted: " << temp->info << "\n";
        delete temp;
    }
}

void PrintForward() {
    cur = head;

    if (head == NULL) {
        cout << "List is Empty!!\n";
    } else {
        cout << "List display:\n";
        while (cur != NULL) {
            cout << cur->info << "\t";
            cur = cur->link;
        }
        cout << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1: Insert item at front\n";
        cout << "2: Insert item at rear\n";
        cout << "3: Delete item from front\n";
        cout << "4: Delete item from rear\n";
        cout << "5: Print List in forward direction\n";
        cout << "6: Exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
            case 1:
                InsertFront();
                break;
            case 2:
                InsertRear();
                break;
            case 3:
                DeleteFront();
                break;
            case 4:
                DeleteRear();
                break;
            case 5:
                PrintForward();
                break;
            case 6:
                cout << "Exiting Program\n";
                break;
            default:
                cout << "Error! wrong choice\n";
        }
    } while (choice != 6);

    return 0;
}
*/
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *link;
};

Node *temp = NULL, *cur = NULL, *head = NULL, *tail = NULL;

void InsertFront() {
    temp = new Node;
    cout << "Enter Integer Data:\n";
    cin >> temp->info;
    temp->link = nullptr;

    if (head == NULL) {
        head = tail = temp;
    } else {
        temp->link = head;
        head = temp;
    }
}

void InsertRear() {
    temp = new Node;
    cout << "Enter Integer Data:\n";
    cin >> temp->info;
    temp->link = nullptr;

    if (head == NULL) {
        head = tail = temp;
    } else {
        tail->link = temp;
        tail = temp;
    }
}

void DeleteFront() {
    temp = head;
    if (head == NULL) {
        cout << "List is Empty!!\n";
    } else {
        if (temp->link == NULL) {
            head = tail = nullptr;
        } else {
            head = head->link;
        }
        cout << "Deleted: " << temp->info << "\n";
        delete temp;
    }
}

void DeleteRear() {
    cur = head;

    if (head == NULL) {
        cout << "List is Empty!!\n";
    } else {
        if (cur->link == NULL) {
            head = tail = nullptr;
        } else {
            while (cur->link != tail) {
                cur = cur->link;
            }
            tail = cur;
            cur->link = nullptr;
        }
        cout << "Deleted: " << temp->info << "\n";
        delete temp;
    }
}

void PrintForward() {
    cur = head;

    if (head == NULL) {
        cout << "List is Empty!!\n";
    } else {
        cout << "List display:\n";
        while (cur != NULL) {
            cout << cur->info << "\t";
            cur = cur->link;
        }
        cout << endl;
    }
}

void InsertMiddle(int after, int value) {
    temp = new Node;
    temp->info = value;
    temp->link = nullptr;

    if (head == NULL) {
        head = tail = temp;
    } else {
        Node *p = head;
        while (p != NULL && p->info != after) {
            p = p->link;
        }
        if (p != NULL) {
            temp->link = p->link;
            p->link = temp;
        } else {
            cout << "Node with value " << after << " not found!\n";
        }
    }
}

bool SearchValue(int value) {
    cur = head;
    while (cur != NULL && cur->info != value) {
        cur = cur->link;
    }
    if (cur != NULL) {
        cout << "Value " << value << " found in the list!\n";
        return true;
    } else {
        cout << "Value " << value << " not found in the list!\n";
        return false;
    }
}

void DeleteNode(int value) {
    if (head == NULL) {
        cout << "List is Empty!!\n";
        return;
    }

    if (head->info == value) {
        temp = head;
        head = head->link;
        cout << "Deleted: " << temp->info << "\n";
        delete temp;
        return;
    }

    cur = head;
    while (cur != NULL && cur->link != NULL && cur->link->info != value) {
        cur = cur->link;
    }

    if (cur != NULL && cur->link != NULL) {
        temp = cur->link;
        cur->link = cur->link->link;
        cout << "Deleted: " << temp->info << "\n";
        delete temp;
    } else {
        cout << "Value " << value << " not found in the list!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "1: Insert item at front\n";
        cout << "2: Insert item at rear\n";
        cout << "3: Delete item from front\n";
        cout << "4: Delete item from rear\n";
        cout << "5: Print List in forward direction\n";
        cout << "6: Search a value\n";
        cout << "7: Insert middle\n";
        cout << "8: Delete by value\n";
        cout << "9: Exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
            case 1:
                InsertFront();
                break;
            case 2:
                InsertRear();
                break;
            case 3:
                DeleteFront();
                break;
            case 4:
                DeleteRear();
                break;
            case 5:
                PrintForward();
                break;
            case 6:
                {
                    int value;
                    cout << "Enter the value to search: ";
                    cin >> value;
                    SearchValue(value);
                }
                break;
            case 7:
                {
                    int after, value;
                    cout << "Enter the value to insert after and the value to insert: ";
                    cin >> after >> value;
                    InsertMiddle(after, value);
                }
                break;
            case 8:
                {
                    int value;
                    cout << "Enter the value to delete: ";
                    cin >> value;
                    DeleteNode(value);
                }
                break;
            case 9:
                exit(0);
                break;
            default:
                cout << "Invalid choice! Please choose a number between 1 and 9.\n";
        }

    } while (choice != 9);

    return 0;
}
