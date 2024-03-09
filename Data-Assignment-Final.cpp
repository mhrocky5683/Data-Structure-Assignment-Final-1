#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* _front = NULL;
Node* _rear = NULL;

Node* createNode (int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty () {
    if (_front == NULL && _rear == NULL)
        return true;
    else
        return false;
}

void pushFront (int x) {
    Node* newNode = createNode(x);
    if (isEmpty()) {
        _front = newNode;
        _rear = newNode;
    }
    newNode->next = _front;
    _front->prev = newNode;
    _front = newNode;
}

void pushRear (int x) {
    Node* newNode = createNode(x);
    if (isEmpty()) {
        _front = newNode;
        _rear = newNode;
    }
    newNode->prev = _rear;
    _rear->next = newNode;
    _rear = newNode;
}

void popFront () {
    if (isEmpty()) {
        cout << "Queue is already empty!";
        return;
    }
    Node* temp = _front;
    if (_front == _rear) {
        _front = _rear = NULL;
    }
    else {
        _front  = _front->next;
        _front->prev = NULL;
    }
    delete temp;
}

void popRear () {
    if (isEmpty()) {
        cout << "Queue is already empty!";
        return;
    }
    Node* temp = _rear;
    if (_front == _rear) {
        _front = _rear = NULL;
    }
    else {
        _rear  = _rear->prev;
        _rear->next = NULL;
    }
    delete temp;
}

int frontElement () {
    if (isEmpty()) {
        cout << "Nothing in queue!" << endl;
        return -1;
    }
    return _front->data;
}

int rearElement () {
    if (isEmpty()) {
        cout << "Nothing in queue!" << endl;
        return -1;
    }
    return _rear->data;
}

void printQueue() {
    Node* temp = _front;
    cout << "The queue is: ";
    while (temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    pushFront(17);
    pushRear(9);
    pushFront(7);
    pushRear(15);
    pushRear(10);
    pushFront(20);
    printQueue();
    cout << "Front: " << frontElement() << endl;
    cout << "Rear: " << rearElement() << endl;
    popFront();
    printQueue();
    cout << "Front: " << frontElement() << endl;
    popRear();
    printQueue();
    cout << "Rear: " << rearElement() << endl;
    popFront();
    popRear();

    return 0;
}
