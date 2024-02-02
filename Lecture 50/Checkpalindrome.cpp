#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data = "<<this->data<<endl;
    }
};
void InsertAtHead(int d,Node* &head){
    if(head==NULL){
        Node* temp = new Node(d);
        head=temp;
        return;
    }
    Node*temp = new Node(d);
    temp->next = head;
    head = temp;
}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* findMiddle(Node* head){                  //Index of middle = (n/2)+1, where n is the number of nodes in the list
    if(head==NULL||head->next==NULL){
        return head;
    }
    else if(head->next->next==NULL){
        return head->next;
    }
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    } 
    return slow;
}
Node* reverseHalfList(Node* &head){
    Node* middle = findMiddle(head);
    Node* prev = NULL;
    Node* curr = middle;
    Node* forward = curr;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    Node* temp = head;
    int count=1;
    while(temp->next!=middle){
        temp=temp->next;
        count++;
    }
    if(count%2==0){
        temp->next=NULL;
    }
    return prev;
}
bool isPalindrome(Node* head){
    Node* head2 = reverseHalfList(head);
    Node* temp1 = head;
    Node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data!=temp2->data){
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}
int main(){
    cout<<"First"<<endl;
    Node* head1 = new Node(7);
    InsertAtHead(6,head1);
    InsertAtHead(5,head1);
    InsertAtHead(4,head1);
    InsertAtHead(3,head1);
    InsertAtHead(2,head1);
    InsertAtHead(1,head1);
    print(head1);
    cout<<isPalindrome(head1)<<endl;
    cout<<"Second"<<endl;
    Node* head2 = new Node(3);
    InsertAtHead(6,head2);
    InsertAtHead(7,head2);
    InsertAtHead(7,head2);
    InsertAtHead(6,head2);
    InsertAtHead(3,head2);
    print(head2);
    cout<<isPalindrome(head2)<<endl;
    cout<<"Third"<<endl;
    Node* head3 = new Node(3);
    InsertAtHead(6,head3);
    InsertAtHead(7,head3);
    InsertAtHead(4,head3);
    InsertAtHead(7,head3);
    InsertAtHead(6,head3);
    InsertAtHead(3,head3);
    print(head3);
    cout<<isPalindrome(head3)<<endl;
}