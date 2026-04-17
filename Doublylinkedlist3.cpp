#include <iostream>
using namespace std;

/*
    Template Node for Doubly Linked List
    Works with any data type (int, float, string, etc.)
*/
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

/*
    Generic Doubly Linked List Class
*/
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count; // Keeps track of number of nodes

public:
    /*
        Constructor: initialize empty list
    */
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    /*
        Insert at beginning
    */
    void insertBeginning(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    /*
        Insert at end
    */
    void insertEnd(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    /*
        Insert after a specific value
    */
    void insertAfter(T target, T value) {
        Node<T>* temp = head;

        while (temp && temp->data != target) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Value not found\n";
            return;
        }

        Node<T>* newNode = new Node<T>(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
        count++;
    }

    /*
        Delete from beginning
    */
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        count--;
    }

    /*
        Delete from end
    */
    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        count--;
    }

    /*
        Delete a specific value
    */
    void deleteValue(T value) {
        Node<T>* temp = head;

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

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        count--;
    }

    /*
        Display list from head to tail (forward traversal)
    */
    void displayForward() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp = head;
        cout << "Forward: ";

        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    /*
        Display list from tail to head (reverse traversal)
    */
    void displayReverse() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }

        Node<T>* temp = tail;
        cout << "Reverse: ";

        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    /*
        Search for a value in the list
        Returns true if found, false otherwise
    */
    bool search(T value) {
        Node<T>* temp = head;

        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }

        return false;
    }

    /*
        Return size of the list
    */
    int size() {
        return count;
    }

    /*
        Destructor: free all allocated memory
    */
    ~DoublyLinkedList() {
        Node<T>* temp = head;

        while (temp) {
            Node<T>* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

/*
    Main function to test the generic list
*/
int main() {
    DoublyLinkedList<int> list;

    list.insertBeginning(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertAfter(20, 25);

    list.displayForward();   // 10 20 25 30
    list.displayReverse();   // 30 25 20 10

    cout << "Size: " << list.size() << endl;

    cout << "Search 25: " << (list.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not Found") << endl;

    list.deleteValue(25);
    list.displayForward();

    return 0;
}
