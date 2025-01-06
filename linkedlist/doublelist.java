public class doublelist{
    class Node{
        int data;
        Node next;
        Node prev;
        Node(int data){
            this.data=data;
            this.next=null; 
            this.prev=null;
        }
    }
    Node head;
    public doublelist(){
        head=null;
    }
    public void insertAtHead(int data){
       
        Node newnode=new Node(data);
        newnode.next=head;
        newnode.prev=null;
        if(head!=null){
            head.prev=newnode;
        }
        head=newnode;
    }
    public void insertAtTail(int data){
        Node newnode=new Node(data);
        Node temp=head;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=newnode;
        newnode.prev=temp;
        newnode.next=null;
    }
    public void insertatindex(int data,int index){
        Node newnode=new Node(data);
        Node temp=head;
        while(index-->1){
            temp=temp.next;
        }
        
        newnode.next=temp.next;
        newnode.prev=temp;
        temp.next.prev=newnode;
        temp.next=newnode;
    }
    public void deleteathead(){
        if(head==null){
            return;
        }
        Node temp = head;
        head=head.next;
        head.prev=null;
        temp=null;
    }
    public void deleteattail(){
        if(head==null){
            return;
        }
        Node temp=head;
        while(temp.next.next!=null){
            temp=temp.next;
        }
        temp.next=null;
    }
    public void deleteatindex(int index){
        if(head==null){
            return;
        }
        Node temp=head;
        while(index-->1){
            temp=temp.next;
        }
        temp.next=temp.next.next;
        temp.next.prev=temp;
    }
    public void length(){
        Node temp=head;
        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        System.out.println(count);
    }
    public int getHead(){
        return head.data;
    }
    public int get(int index){
        Node temp=head;
        while(index-->0){
            temp=temp.next;
        }
        return temp.data;
    }
    public boolean search(int key){
        Node temp=head;
        while(temp!=null){
            if(temp.data==key){
                return true;
            }
            temp=temp.next;
        }
        return false;
    }
    
    public void print(){
        Node temp=head;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
        System.out.println();
    }


    public static void main(String[] args) {
        doublelist l=new doublelist();
        l.insertAtHead(10);
        l.insertAtHead(20);
        l.insertAtHead(30);
        l.insertAtTail(40);
        l.insertatindex(50,2);
        l.print();
    }
}
