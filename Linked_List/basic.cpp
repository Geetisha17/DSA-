#include<iostream>
#include"list.h"
using namespace std;

int main(){
   List l; //static object but memory is dynamic
   /*l is created statically that means it will try
   to destroy objext and destroying object in main 
   will automaticaly called the destructor of the node object
   */
  l.insert(1,0);
   l.insert(2,1);
  l.insert(3,2);
  l.insert(4,3);
  l.insert(5,4);
  l.insert(6,5);
  l.insert(7,6);
  // l.pop_front();
   //l.pop_back_2();
   //l.pop_back();
   //l.remove3(40);
    Node *head = l.begin();
   // Node *pop_back=l.begin();
   // l.reverse(head);
// Node *head;
   //l.reverse(head);
   while(head!=NULL){
    cout<<head->getData()<<"->";
    head= head->next;
   }
   cout<<endl;
   cout<<l.kth(4)<<endl;
   cout<<l.kth_1(4)<<endl;
//     cout<<l.search(10)<<endl;
//    cout<<l.recursiveSearch(40)<<endl;
}
