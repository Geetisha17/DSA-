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
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=nullptr;

        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;

        ListNode*l1=sortList(head);
        ListNode*l2=sortList(slow);
        return merge(l1,l2);
    }
};