 #include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* pre;
    // constructor 
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->pre=NULL;
    }
};
void print(Node* &head)
{
    Node* temp=head;
    while(temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &tail,Node* &head,int d)

{
    // empty list
    if(head==NULL)
    {
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else
    {
      Node* temp=new Node(d);
      temp->next=head;
      head=temp;
    }
}
void insertAtTail(Node* &tail,Node* &head,int d)

{
    // empty list
    if(tail==NULL)
    {
        Node* temp=new Node(d);
        tail=temp;
        head=temp;
    }
    Node* temp=new Node(d);
    tail->next=temp;
    temp->pre=tail;
    tail=temp;
}
void insertAtPos(Node* &tail,Node* &head,int pos,int d)
{
    // insert at head
    if(pos==1)
    {
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        temp=temp->next;
        cnt++;

    }
    // insert at last pos
    if(temp->next==NULL)
    {
        insertAtTail(tail,head,d);
        return;
    }
    // creating a node for d
    Node* ins=new Node(d);
    ins->next=temp->next;
    temp->next->pre=ins;
    temp->next=ins;
    ins->pre=temp;
}
int main()
{

     Node* head=NULL;
    Node* tail=NULL;
    print(head);


    insertAtHead(tail,head,11);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
     insertAtHead(tail,head,21);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
     insertAtHead(tail,head,31);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

     insertAtTail(tail,head,341);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

     insertAtPos(tail,head,3,51);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

     insertAtPos(tail,head,5,61);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
     insertAtPos(tail,head,7,71);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    // Node* node1=new Node(10);
    // Node* head=node1;
    // Node* tail=node1;


    // cout<<"insert at head"<<endl;
    // insertAtHead(head,12);
    // print(head);
    // insertAtHead(head,13);
    // print(head);
    // insertAtHead(head,14);
    // print(head);
    // insertAtHead(head,15);
    // print(head);
    
    // cout<<"insert at tail"<<endl;
    // insertAtTail(tail,16);
    // print(head);

    // cout<<"insert at positon"<<endl;
    // insertAtPos(tail,head,3,225);
    // print(head);
    return 0;
}