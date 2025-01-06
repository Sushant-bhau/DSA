#include<iostream>
using namespace std;
class queue{
    int* arr;
    int front;
    int back;
    int size;
    public:
    queue(int s){
        arr=new int[s];
        front=-1;
        back=-1;
        size=s;
    }
    void enqueue(int data){
        if(back==size-1){
            cout<<"Queue is full"<<endl;
            return;
        }
        back++;
        arr[back]=data;
        if(front==-1){
            front=0;
        }
    }
    void dequeue(){
        if(front==-1 || front>back){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front]<<" is dequeued"<<endl;
        front++;
    }
    void print(){
        if(front==-1 || front>back){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=front;i<=back;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};  
int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}