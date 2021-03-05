#pragma once
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class LinkedList {
private:
    class Node {
        T item;
        Node* next;
    }
    Node* head;
    int size;
public:
    LinkedList() {
        head = new Node();
        head->next = tail;
        size = 0;
    }
    ~LinkedList() {
        for(Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            delete ptr;
        }
    }
    void insertHead(T value) {
        // If the head has no item, then the list is empty.
        if (head.item == NULL) {
            head.item = value;
            ++size;
            return;
        }
        // Check for duplicates.
        for(Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == T) {
                return;
            }
        }
        // Otherwise, create a new head Node.
        Node* newHead = new Node;
        newHead.item = value;
        newHead.next = head;
        head = newHead;
        ++size;
    }
    void insertTail(T value) {
        // If the head has no item, then the list is empty.
        // Also, the head would be the tail.
        if (head.item == NULL) {
            head.item = value;
            ++size;
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
                ++size;
                return;
            }
        }
    }
    void insertAfter(T value, T insertionNode) {
        if (value == insertionNode) {
            return;
        }
        for (Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->item == insertionNode) {
                Node* newNode = new node();
                newNode->item = value;
                newNode->next = ptr->next;
                ptr->next = newNode;
                ++size;
            }
        }
        // If we reach this point, the insertionNode did not exist.
    }
    void remove(T value) {
        for (Node* ptr = head; ptr != NULL; ptr=ptr->next) {
            if (ptr->next->item == value) {
                Node* nextnext = ptr->next->next;
                delete ptr->next;
                ptr->next = ptr-> nextnext;
                --size;
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
        head = noew Node();
        size = 0;
    }
    T at (int index) {
        if (index >= size || index < 0) {
            // TODO: Throw an out of range exception.
            return;
        }
        Node* ptr = head;
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        return ptr->item;
    }
    int size() {
        return size;
    }
    string toString() {
        stringstream ss;
        Node* ptr = head;
        while (ptr->next != NULL) {
            ss << ptr->item << '';
        }
        if (ptr->item != NULL) {
            ss << ptr->item;
        return ss.str();
    }
}