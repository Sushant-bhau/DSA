#include<iostream>
using namespace std;
 class Linkedlist{
    class Node{
        public:
        int data;
        Node* next;
        Node(int data,Node* next=NULL){
            this->data=data;
            this->next=next;
        }
    };
    Node* head;
    
    public:
    Linkedlist(){
        head=nullptr;
        
    }
    void insertathead(int data){
        if(head==nullptr){
            head=new Node(data);
            return;
        }
        Node* newnode= new Node(data,head);
        
        head=newnode;
        
    }
    void insertatlast(int data){
        if(head==nullptr){
            insertathead(data);
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* newnode=new Node(data);
        temp->next=newnode;
    }
    void insertatindex(int data,int index){
        if(index==0){
            insertathead(data);
            return;
        }
        Node* temp=head;
        int i=0;
        while(i<index-1){
            temp=temp->next;
            i++;
        }
        Node* newnode=new Node(data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void deleteathead(){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    void deleteatlast(){
        Node* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        Node* todelete=temp->next;
        temp->next=nullptr;
        delete todelete;
    }
    void deleteatindex(int index){
        if(index==0){
            deleteathead();
            return;
        }
        Node* temp=head;
        int i=0;
        while(i<index-1){
            temp=temp->next;
            i++;
        }
        Node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
    int length(){
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    int get(int index){
        Node* temp=head;
        int i=0;
        while(i<index){
            temp=temp->next;
            i++;
        }
        return temp->data;
    }
    bool search(int key){
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    Node* getHead() const {
        return head;
    }
 };

 int main(){
     Linkedlist l;
     l.insertathead(1);
     l.insertathead(2);
     l.insertathead(3);
     l.print();
     cout<<endl;
     cout<<l.getHead()->data;
     return 0;
 }