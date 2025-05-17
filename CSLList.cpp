#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val=0,Node* n=nullptr) : data(val), next(n) {}
};

// Circular Singly Linked List class
class CSLList 
{
public:
    Node* head;

    CSLList() : head(nullptr) {}

    // Function to insert a new node at the end (in a circular way)
    void insertAtHead(int val) {
        Node* newNode=new Node(val);
        if(!head) {
        head=newNode;
        head->next=head;
        return;
        }
        if(head->next==head)
        {
            newNode->next=head;
            head->next=newNode;
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=head;
    }

    // Function to delete a node with a specific value
    void delete_at_val(int val) {
        if (!head) {
            std::cout << "List is empty!" << std::endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == val) {
            if (head->next == head) { // Only one node in the list
                delete head;
                head = nullptr;
                return;
            }

            Node* temp=head;
            head=head->next;
            Node* last=head;
            while(last->next!=temp)
            {
             last=last->next;  
            }
            last->next=head;
            delete temp;
    }
    Node* curr=head->next;
    Node* prev=head;
    while(curr!=head)
    {
        if(curr->data==val)
        {
            prev->next=curr->next;
            delete curr;
            return;
        }
        prev=curr;
        curr=curr->next;
    }
  
}

    // Function to print the list (for testing purposes)
 void print() {
        if (!head) {
            cout<< "List is empty!" << std::endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << std::endl;
    }
    void insertAtTail(int val)
    {
        Node* newNode=new Node(val);
       if(!head)
       {
        head=newNode;
        head->next=head;
        return;
       }
       if(head->next==head)
       {
        head->next=newNode;
        newNode->next=head;
        return;
       }
       Node* temp{head->next};
       while(temp->next!=head)
       {
        temp=temp->next;
       }
       temp->next=newNode;
       newNode->next=head;
    }
    void clear()
    {
        if(!head) return;
        Node* temp{head->next};
        while(temp!=head)
        {
            Node* temp2{temp};
            temp=temp->next;
            delete temp2;
        }
        delete head;
        head=nullptr;
    }
    CSLList& operator=(CSLList & obj)
    {
       if(this==&obj) return * this;
       if(!obj.head){
        clear();
        return *this;
       }
       clear();
       Node* temp=obj.head;
       while(temp->next!=obj.head)
       {
         insertAtHead(temp->data);
         temp=temp->next;
       }
       insertAtHead(temp->data);
       return * this;
    }
    CSLList(const CSLList& obj)
    {
        head=nullptr;
       if(!obj.head){
        return;
       }
       else{ 
       Node* temp=obj.head;
       while(temp->next!=obj.head)
       {
         this->insertAtTail(temp->data);
         temp=temp->next;
       }
       this->insertAtTail(temp->data);
    }

    }
    int deleteHead()
    {
        if(!head) {
              throw" Empty list";
             }
             Node* temp=head;
             head=head->next;
             Node* Last=head;
             while(Last->next!=temp)
             {
                Last=Last->next;
             }
             Last->next=head;
             return temp->data;
             delete temp;

    }
    void insertSorted(int val)
    {
        Node* newNode=new Node(val);
        if(!head)
        {
             head=newNode;
             head->next=head;
             return;
        }
        if(head->next==head)
        {
            if(head->data<val)
            {
                head->next=newNode;
                newNode->next=head;
                return;
            }
            else{
                newNode->next=head;
                head->next=newNode;
                head=newNode;
                return;
            }
        }
        if(val<=head->data){ 
        Node* last{head};
        while(last->next!=head)
        {
            last=last->next;
        }
        newNode->next=head;
        head=newNode;
        last->next=head;
    }
        Node* curr{head->next},* prev{head};
            while(curr!=head&&curr->data<val)
            { 
               prev=curr;
               curr=curr->next;
            }
            prev->next=newNode;
            newNode->next=curr;

    }
};

// Testing the delete_at_val function
int main() {
    CSLList intSLL;
for (int i{1}; i < 10; ++i)
{
intSLL.insertAtHead(i*5);
intSLL.insertAtTail(i*10);
}
intSLL.print();
CSLList intSLL2 {intSLL};
try{ 
cout << intSLL2.deleteHead()<<endl; }
catch(const char* str){
    cout<<str;
}
intSLL2.print();
CSLList intSLL3;
intSLL3 = intSLL2;
cout<<intSLL3.deleteHead()<<endl;
intSLL2.insertSorted(32);
intSLL2.print();
}
