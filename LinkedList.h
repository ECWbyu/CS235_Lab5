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
        numItems = 0;
    }
    ~LinkedList() {
        clear();
    }
    void insertHead(T value) {
        // If the size is 0, we need a new head.
        if (numItems == 0) {
            head = new Node();
            head->item = value;
            ++numItems;
            return;
        }
        // Check for duplicates.
        for(Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == value) {
                return;
            }
        }
        // Otherwise, create a new head Node.
        Node* newHead = new Node;
        newHead->item = value;
        newHead->next = head;
        head = newHead;
        ++numItems;
    }
    void insertTail(T value) {
        // If the head has no item, then the list is empty.
        // Also, the head would be the tail.
        if (numItems == 0) {
            head = new Node();
            head->item = value;
            ++numItems;
            return;
        }
        // Check for duplcates, while searching for tail.
        for (Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == value) {
                return;
            }
            if (ptr->next == NULL) {
                Node* newTail = new Node();
                newTail->item = value;
                ptr->next = newTail;
                ++numItems;
                return;
            }
        }
    }
    void insertAfter(T value, T insertionNode) {
        if (value == insertionNode) {
            return;
        }
        Node* insertSpot = NULL;
        for (Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == value) {
                // Found a duplicate, quit
                return;
            }
            if (ptr->item == insertionNode) {
                insertSpot = ptr;
            }
        }
        if (insertSpot != NULL) {
            Node* newNode = new Node();
            newNode->item = value;
            newNode->next = insertSpot->next;
            insertSpot->next = newNode;
            ++numItems;
        }
        // If we reach this point, the insertionNode did not exist.
    }
    void remove(T value) {
        if (numItems == 0) {
            return;
        }
        if (head->item == value) {
            Node* newHead = head->next;
            delete head;
            head = newHead;
            --numItems;
            return;
        }
        for (Node* ptr = head; ptr->next != NULL; ptr=ptr->next) {
            if (ptr->next->item == value) {
                Node* nextnext = ptr->next->next;
                delete ptr->next;
                ptr->next = nextnext;
                --numItems;
                return;
            }
        }
        // If we reach this point, the value did not exist.
    }
    void clear () {
        Node* ptr = head;
        while (ptr != NULL) {
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
        numItems = 0;
        head = NULL;
    }
    T at (int index) {
        if (index >= numItems || index < 0) {
            throw std::out_of_range ("index was out of range");
        }
        Node* ptr = head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr->item;
    }
    int size() {
        return numItems;
    }
    string toString() {
        stringstream ss;
        if (numItems == 0) {
            return "";
        }
        Node* ptr = head;
        while (ptr->next != NULL) {
            ss << ptr->item << ' ';
            ptr = ptr->next;
        }
        ss << ptr->item;
        return ss.str();
    }
};