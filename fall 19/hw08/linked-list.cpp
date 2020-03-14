/*
  linked-list.cpp
  Sec B
  19F
 */
#include <iostream>
using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// void listDisplay(Node* headPtr) {
//     //while (headPtr->next != nullptr) {
//     while (headPtr != nullptr) {
//         cout << headPtr->data << ' ';
//         headPtr = headPtr->next; // bump
//     }
//     cout << endl;
// }

//void listDisplay(const Node* headPtr) {
void listDisplay(Node* headPtr) {
    //const Node* p = headPtr;
    Node* p = headPtr;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next; // bump
    }
    cout << endl;
}

Node* listFindTail(Node* headPtr) {
    if (headPtr == nullptr) return nullptr; 
    Node* p = headPtr;
    while (p->next != nullptr) {
        p = p->next; // bump
    }
    return p;
}

void listAddTail(Node*& headPtr, int data) {
    //void listAddTail(Node*& headPtr, int data) {
    if (headPtr == nullptr) {
        headPtr = new Node(data);
    }
    else {
        Node* last = listFindTail(headPtr);
        last->next = new Node(data);
    }
}

void listAddHead(Node*& headPtr, int data) {
    // // 1. creat a node for the data
    // Node* nodeToInsert = new Node(data);

    // // 2. make the node "point" to the old head node
    // nodeToInsert->next = headPtr;
    // Node* nodeToInsert = new Node(data, headPtr);

    // // 3. set the head pointer to point to the new node
    // headPtr = nodeToInsert;

    headPtr = new Node(data, headPtr);
}
 
//void listAdd(Node* prior, Node* after, int data) {
void listAdd(Node* prior, int data) {
    prior->next = new Node(data, prior->next);
}

void listRemoveHead(Node*& headPtr) {
    if (headPtr == nullptr) return;

    // 0. remember the ...
    Node* victim = headPtr;

    // 2. make the head pointer point to the old secod node
    headPtr = headPtr->next;

    // 1. free up the head node
    //delete headPtr;
    delete victim;
}

void listRemove(Node* prior) {
    Node* victim = prior->next;
    //prior->next = victim->next;
    prior->next = prior->next->next;
    delete victim;
}

void listClearRecursive(Node*& headPtr) {
    if (headPtr == nullptr) return;
    listClearRecursive(headPtr->next);
    delete headPtr;
    headPtr = nullptr;
}

void listClear(Node*& headPtr) {
    while (headPtr != nullptr) {
        listRemoveHead(headPtr);
    }
}

Node* listDup(Node* headPtr) {
    if (headPtr == nullptr) return nullptr;
    Node* result = new Node(headPtr->data);
    Node* p = headPtr->next;
    Node* last = result;

    while (p != nullptr) {
        last->next = new Node(p->data);
        last = last->next;
        p = p->next;
    }
    return result;
}

int main() {
    Node* myList = nullptr;
    cout << "Displaying empty list: ";
    listDisplay(myList);
    cerr << "===========\n";

    //    myList = new Node(17);
    listAddTail(myList, 17);

    //myList->next = new Node(28);
    listAddTail(myList, 28);

    cout << myList->data << ' ' << myList->next->data << endl;
    cout << "Displaying two node list: ";
    listDisplay(myList);
    cerr << "===========\n";

    listClear(myList);
    cout << "Displaying empty list: ";
    listDisplay(myList);
    cerr << "===========\n";
}
