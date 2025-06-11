/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* merge(ListNode*l1,ListNode*l2)
    {
        ListNode*dummy = new ListNode(-1);
        ListNode*temp=dummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        while(l1)
        {
            temp->next=l1;l1=l1->next;temp=temp->next;
        }
        while(l2)
        {
            temp->next=l2;l2=l2->next;temp=temp->next;
        }
        return dummy->next;
    }
    ListNode* mergeSort(vector<ListNode*>&lists,int l,int r)
    {
        if(l>r) return NULL;
        if(l==r) return lists[l];
        int mid = (l+r)/2;
        ListNode*a=mergeSort(lists,l,mid);
        ListNode*b=mergeSort(lists,mid+1,r);
        return merge(a,b);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        return mergeSort(lists,0,n-1);
    }
};