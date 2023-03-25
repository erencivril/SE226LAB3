#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x, Node* n) {
        data = x;
        next = n;
    }
};

class Queue {
private:
    Node* front;
    Node* back;
    int length;
public:
    Queue() {
        front = NULL;
        back = NULL;
        length = 0;
    };
    void enqueue(int x) {
        Node* temp = new Node(x, NULL);
        if (back == NULL) {
            front = back = temp;
        } else {
            back->next = temp;
            back = temp;
        }
        length++;
    };
    void dequeue() {
        if (front == NULL) {
            return;
        };
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            back = NULL;
        };
        delete temp;
        length--;
    };
    int top() {
        if (front == NULL) {
            return -1;
        };
        return front->data;
    };
    bool isEmpty() {
        if (front == NULL && back == NULL) {
            return true;
        } else {
            return false;
        }
    };
    int size() {
        return length;
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(16);
    q.enqueue(34);
    q.enqueue(78);
    cout << "Top element of the queue " << q.top() << endl;
    q.dequeue();
    cout << "Top element of the queue " << q.top() << endl;
    cout << "Is the queue empty? " << q.isEmpty() << endl;
    cout << "Size of the queue: " << q.size() << endl;
    return 0;
}
