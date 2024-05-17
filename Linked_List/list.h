#include<iostream>
using namespace std;

class List;

class Node{
    int data;

    public:
    Node *next;

    int getData(){
        return data;
    }

    ~Node(){
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"delete"<<data<<endl;
    }
    Node(int d):data(d),next(NULL){};

    friend class List;
};

class List{
    Node *head;
    Node *tail;

    int helper(Node *start,int key){
        //base case 
        if(start==NULL){
            return -1;
        }
        if(start->data==key){
            return 0;
        }
        int subIdx=helper(start->next,key);
        if(subIdx==-1){return -1;}
        return subIdx+1;
    }

    public:
    List():head(NULL),tail(NULL){};

    Node *begin(){
        return head;
    }

    void push_front(int data){
        if(head==NULL){
            Node *n = new Node(data);
            tail = head =n;
        }else{
            Node *n = new Node(data);
            n->next = head;
            head =n;
        }
    }
    void push_back(int data){
       if(head==NULL){
        Node *n = new Node(data);
        head = tail =n;
       }else{
        Node *n = new Node(data);
        tail->next = n;
        tail=n;
       }
    }
    void insert(int data,int pos){
       if(pos==0){
        push_front(data);
       }else{
        Node*temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        Node *n = new Node(data);
        n->next=temp->next;
        temp->next=n;
       }
    }
    int search(int key){
        Node*temp=head;
        int idx=0;

        if(head && head->data==key) return idx;

        while(temp!=NULL){
            if(temp->next->data==key){
                return idx;
            }else{
                idx++;
                temp=temp->next;
            }
        }
    }
    int recursiveSearch(int key){
        int idx = helper(head,key);
        return idx;
    }
    void pop_front(){
        Node*temp=head;
        head = temp->next;
        temp->next=NULL;
        delete temp;
    }
    Node *pop_back(Node *head){
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        Node*curr=head;
        Node*prev=NULL;
        while(curr!=NULL){
            prev=curr;
            curr=curr->next;
        }
        delete curr;
        prev->next=NULL;
        return head;
    }
    void pop_back_2(){
        Node *temp = head;
        Node *prev = NULL;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        delete temp;
        prev->next=NULL;
    }
    Node *remove(Node *head,int val){
        Node*temp=head;
        while(head && head->data==val){
            head = head->next; 
        } 
        while(temp){
            if(temp->next && temp->next->data==val){
                temp->next = temp->next->next;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
    Node* reverseList(Node* head) 
    {
        if(head==NULL){
            return NULL;
        }
       Node*temp;
       Node*curr=head;
       Node*prev=NULL;

       while(curr){
        temp=curr->next;
        curr->next=NULL;
        prev=curr;
        curr=temp;
       }
       return head;
    }

    int kth(int k){
        Node*temp =head;
        int cnt=0;
        Node*curr=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        int half = cnt-k;
        for(int i=0;i<half;i++){
            curr=curr->next;
        }
        return curr->data;
    }

    int kth_1(int k){
        Node *curr = head;
        Node *prev = head;
        int cnt=0;
        while(cnt<k){
            curr=curr->next;
            cnt++;
        }
        while(curr->next!=NULL){
            prev = prev->next;

            curr = curr->next;
        }
        return prev->next->data;
    }
    Node *duplicate(Node*head){
        Node*temp=head;

        while(temp!=NULL){
            Node*start=temp->next;
            if(temp->next && temp->data ==start->data){
                temp = start->next;
            }else{
                temp = temp->next;
            }
        }
        return head;
    }


     
    ~List(){
        if(head!=NULL){
            delete head;
        }
        head= NULL;
    }
};