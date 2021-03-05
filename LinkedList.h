#include <string>
#include <iostream>
#include <sstream>
using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T item;
        Node* next;
    };
    Node* head;
    int numItems;
public:
    LinkedList() {
        cout << "Start constructor" << endl;
        numItems = 0;
        cout << "End constructor" << endl;
    }
    ~LinkedList() {
        cout << "Starting destructor " << endl;
        clear();
        cout << "End destructor" << endl;
    }
    void insertHead(T value) {
        cout << "Start insertHead" << endl;
        // If the size is 0, we need a new head.
        if (numItems == 0) {
            head = new Node();
            head->item = value;
            ++numItems;
            cout << "End inserhead (at head)" << endl;
            return;
        }
        // Check for duplicates.
        for(Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == value) {
                cout << "End insertHead (found dup)" << endl;
                return;
            }
        }
        // Otherwise, create a new head Node.
        Node* newHead = new Node;
        newHead->item = value;
        newHead->next = head;
        head = newHead;
        ++numItems;
        cout << "End insertHead (success)" << endl;
    }
    void insertTail(T value) {
        cout << "Start insertTail" << endl;
        // If the head has no item, then the list is empty.
        // Also, the head would be the tail.
        if (numItems == 0) {
            head = new Node();
            head->item = value;
            ++numItems;
            cout << "End insertTail (at head)" << endl;
            return;
        }
        // Check for duplcates, while searching for tail.
        for (Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == value) {
                cout << "End insertTaile (found duplicate)" << endl;
                return;
            }
            if (ptr->next == NULL) {
                Node* newTail = new Node();
                newTail->item = value;
                ptr->next = newTail;
                ++numItems;
                cout << "End insertTail (success)" << endl;
                return;
            }
        }
        cout << "End insertail how???" << endl;
    }
    void insertAfter(T value, T insertionNode) {
        cout << "Start insertAfter" << endl;
        if (value == insertionNode) {
            cout << "End inserafter (value = insert) " << endl;
            return;
        }
        for (Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == insertionNode) {
                Node* newNode = new Node();
                newNode->item = value;
                newNode->next = ptr->next;
                ptr->next = newNode;
                ++numItems;
                cout << "End InsertAfter (found spot)" << endl;
                return;
            }
        }
        // If we reach this point, the insertionNode did not exist.
        cout << "End InsertAfter (no insertionNode)" << endl;
    }
    void remove(T value) {
        cout << "Start removing " << value << endl;
        cout << toString() << endl;
        if (numItems == 0) {
            cout << "End remove (no values)" << endl;
            return;
        }
        if (head->item == value) {
            Node* newHead = head->next;
            delete head;
            head = newHead;
            --numItems;
            cout << "End remove (first value)" << endl;
            return;
        }
        for (Node* ptr = head; ptr->next != NULL; ptr=ptr->next) {
            cout << ptr->item << ' ';
            if (ptr->next->item == value) {
                Node* nextnext = ptr->next->next;
                delete ptr->next;
                ptr->next = nextnext;
                --numItems;
                cout << toString() << endl;
                cout << "End remove (some value)" << endl;
                return;
            }
        }
        cout << "End Remove (item not found)" << endl;
        // If we reach this point, the value did not exist.
    }
    void clear () {
        cout << "starting clear " << endl;
        cout << toString() << endl;
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->item << ' ';
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
        numItems = 0;
        head = NULL;
        cout << "end clear" << endl;
    }
    T at (int index) {
        cout << "Starting at" << endl;
        if (index >= numItems || index < 0) {
            throw std::out_of_range ("index was out of range");
        }
        Node* ptr = head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        cout << "End at (success)" << endl;
        return ptr->item;
    }
    int size() {
        cout << "Start size" << endl;
        return numItems;
        cout << "end size" << endl;
    }
    string toString() {
        cout << "Start toString" << endl;
        stringstream ss;
        if (numItems == 0) {
            cout << "there are no items, no string generated" << endl;
            return "";
        }
        Node* ptr = head;
        while (ptr->next != NULL) {
            ss << ptr->item << ' ';
            ptr = ptr->next;
        }
        ss << ptr->item;
        cout << "End toString" << endl;
        return ss.str();
    }
};