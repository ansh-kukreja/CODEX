public class code02 {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        list.insertAtEnd(4);
        list.insertAtEnd(5);
        list.insertAtEnd(6);
        list.insertAtEnd(7);

        list.insertAtStart(3);
        list.insertAtStart(2);
        list.insertAtStart(1);

        System.out.print("\nLinked List\n");
        list.display();

        list.deleteFromStart();
        list.deleteFromEnd();

        System.out.print("\nAfter deleting\n");
        list.display();
    }
}

class Node{
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList{
    Node head = null;

    void insertAtEnd(int data) {
        Node newNode = new Node(data);

        if(head == null) {
            head = newNode;
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    void insertAtStart(int data) {
        Node newNode = new Node(data);

        if(head == null) {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;
    }

    void deleteFromEnd() {
        if(head == null) {
            System.out.println("List is empty");
            return;
        }

        if(head.next == null) {
            head = null;
            return;
        }

        Node temp = head;
        while(temp.next.next != null){
            temp = temp.next;
        }
        temp.next = null;
    }

    void deleteFromStart() {
        if(head == null) {
            System.out.println("List is empty");
        }
        else{
            head = head.next;
        }
    }

    void display() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println("\n");
    }
}