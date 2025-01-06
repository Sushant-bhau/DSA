#include <iostream>
using namespace std;

class Queue {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int data) {
        Node* newnode = new Node(data);
        if (rear == nullptr) {
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int getfront() const {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1; // Return an invalid value to indicate the queue is empty
        }
        return front->data;
    }
    int getback() const {
        if (rear == nullptr) {
            cout << "Queue is empty" << endl;
            return -1; // Return an invalid value to indicate the queue is empty
        }
        return rear->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void print() const {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print(); // Output: 1 2 3
    cout << "Front element is " << q.getfront() << endl; // Output: Front element is 1
    q.dequeue();
    q.print(); // Output: 2 3
    cout << "Front element is " << q.getback() << endl; // Output: Front element is 2
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Output: Queue underflow
    return 0;
}