public class linkedlist {
    class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    Node head;

    public linkedlist() {
        head = null;
    }

    public void insertAtHead(int data) {
        Node newnode = new Node(data);
        newnode.next = head;
        head = newnode;
    }
    public void insertattail(int data){
        Node newnode = new Node(data);
        if (head==null){
           head=new Node(data);
        }
      
        Node temp = head;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=newnode;

    }
    public void insertatindex(int data,int index){
        Node newnode = new Node(data);
        Node temp = head;
        
        while(index-->1){
            temp=temp.next;
        }
        newnode.next=temp.next;
        temp.next=newnode;
    }
    
    public void deleteathead(){
        if(head==null){
            return;
        }
        Node temp = head;
        head = head.next;
        temp = null;
    }
    public void deleteattail(){
        if(head==null){
            return;
        }
        Node temp = head;
        while(temp.next.next!=null){
            temp=temp.next;
        }
        temp.next=null;
    
    }
    public void deleteatindex(int index){
      if(head==null){
          return;
      }
      Node temp =head;
      while(index-->1){
        temp=temp.next;
      }
      Node temp2=temp.next;
      temp.next=temp.next.next;
      temp2=null;

    }
    public int length(){
        Node temp = head;

        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        return count;

    }
    public int getHead(){
        return head.data;
    }
    public int get(int index){
        Node temp = head;
        while(index-->0){
            temp=temp.next;
        }
        return temp.data;
    }
    public boolean search(int key){
        Node temp = head;
        while(temp!=null){
            if(temp.data==key){
                return true;
            }
            temp=temp.next;
        }
        return false;
    }

    public void print() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        linkedlist list = new linkedlist();
        list.insertAtHead(1);
        list.insertAtHead(2);
        list.insertAtHead(3);
        list.insertattail(0);
        list.insertatindex(4,2);
        list.insertattail(7);
        list.insertattail(8);
        list.print();
        list.deleteathead();
        list.print();
        list.deleteattail();
        list.print();
        list.deleteatindex(2);
        list.print();

        System.out.println(list.length());
        System.out.println(list.getHead());
        System.out.println(list.get(2));
        System.out.println(list.search(4));
        System.out.println(list.search(9));
    }
}