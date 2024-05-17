#include <algorithm>
#include <iostream>
#include<stack>
#include <vector>
using namespace std;

class kQueue{
    
    public:
    int n,k;

    int *arr;
    int *next;
    int *front;
    int *rear;
    int freespot;

    public:

    kQueue(int n,int k)
    {
        this->n = n;
        this->k = k;

        next = new int[n];

        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;

        front = new int[k];
        rear = new int[k];

        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        arr = new int[n];
        freespot=0;
    }

    void enqueue(int x,int qn)
    {
        //check for overflow
       if(freespot==-1){
        cout<<"overflow"<<endl;
        return;
       }
        //first the index
        int idx = freespot;

        //update freespot
        freespot = next[idx];

        //check first element
       if(front[qn-1]==-1){
        front[qn-1] = idx;
       }else{
        next[rear[qn-1]] = idx;
       }

        //already inserted 
        next[idx] = -1;
        //point rear to idx
        rear[qn-1] =idx;
        //push value
        arr[idx] = x;
    }

    int dequeue(int qn)
    {
        //check for underflow
       if(front[qn-1]==-1)
       {
        cout<<"underflow"<<endl;
        return -1;
       }

        //find index
        int idx = front[qn-1];

        //update front
        front[qn-1] = next[idx];

        //find the empty slot
        next[idx] = freespot;
       freespot = idx;

       return arr[idx];
    }
};

int main()
{
     kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;
    return 0;
}