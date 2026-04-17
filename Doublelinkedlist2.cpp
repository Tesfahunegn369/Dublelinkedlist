#include <iostream>
using namespace std;

/*
    Node structure for Doubly Linked List
    Each node contains:
    - data: integer value
    - prev: pointer to previous node
    - next: pointer to next node
*/
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

/*
    DoublyLinkedList class
    Manages all operations on the list
*/
class DoublyLinkedList {
private:
    Node* head; // Pointer to first node
    Node* tail; // Pointer to last node

public:
    // Constructor initializes empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /*
        Insert a node at the beginning
    */
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            // If list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    /*
        Insert a node at the end
    */
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (!tail) {
            // If list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /*
        Insert a node after a given value
        If value not found, nothing is inserted
    */
    void insertAfter(int target, int value) {
        Node* temp = head;

        // Search for target value
        while (temp && temp->data != target) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value " << target << " not found in list\n";
            return;
        }

        Node* newNode = new Node(value);

        // Insert after temp
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next) {
            temp->next->prev = newNode;
        } else {
            // If inserting at the end
            tail = newNode;
        }

        temp->next = newNode;
    }

    /*
        Delete node from beginning
    */
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        if (head == tail) {
            // Only one node
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    /*
        Delete node from end
    */
    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            // Only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    /*
        Delete a node with specific value
    */
    void deleteValue(int value) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Search for the node
        while (temp && temp->data != value) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value not found\n";
            return;
        }

        if (temp == head) {
            deleteFromBeginning();
            return;
        }

        if (temp == tail) {
            deleteFromEnd();
            return;
        }

        // Middle node deletion
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    /*
        Display all elements in the list
    */
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        cout << "List: ";

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /*
        Destructor to free memory when object is destroyed
    */
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

/*
    Main function:
    Provides menu-driven interface
*/
int main() {
    DoublyLinkedList list;
    int choice, value, target;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after value\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete specific value\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertEnd(value);
                break;

            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAfter(target, value);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;

            case 7:
                list.display();
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
