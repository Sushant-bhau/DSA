#include<bits/stdc++.h>

using namespace std;
// implementing stack using linked list

 class stackl{
       class Node {
    public:
        int data;
        Node* next;

        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node* top;
    public:
     stackl() : top(nullptr) {}

    void push(int data) {
        Node* newnode = new Node(data, top);
        top = newnode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
   int gettop() const {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1; // Return an invalid value to indicate the stack is empty
        }
        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void print() const {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
 };

 int main(){
     stackl s;
     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);
     s.print();
     cout<<s.gettop()<<endl;
     s.pop();
     s.print();
     return 0;
 }