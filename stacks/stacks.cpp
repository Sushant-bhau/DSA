#include<iostream>
using namespace std;

class stack{
      
      int arr[100];
      int top;
      public:
      stack(){
          top=-1;
      }
      void push(int x){
          top++;
          arr[top]=x;
      }
      void pop(){
          top--;

      }
      int gettop(){
          return arr[top];
      }
      int size(){
          return top+1; 
      }

   void display(){
       for(int i=top;i>=0;i--){
           cout<<arr[i]<<" ";
       }
       cout<<endl;
   }


};



int main(){

    stack s ;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
   
    cout<<s.gettop()<<endl;
    s.pop();
    cout<<s.gettop()<<endl;
    cout<<s.size()<<endl;
    s.display();
    cout<<endl;


    return 0;
}
