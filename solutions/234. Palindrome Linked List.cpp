/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        
        if(temp==NULL || temp->next==NULL) return true;
        
        ListNode* prev=NULL;
        ListNode* t=head;
        while(t != NULL) {
            
            ListNode* temp=t->next;
            t->next=prev;
            prev=t;
            t=temp;
            
        }
        
        while(temp && prev) {
            if(temp->val == prev->val) {
                temp=temp->next;
                prev=prev->next;
            }
            else {
                return false;
            }
        }
        
        if(temp==NULL && prev==NULL)
            return true;
        else return false;
    }
};*/
    
class Solution {
public:
    bool isPalindrome(ListNode* head1)
    {
        stack<int>s;
        ListNode* head=head1;
        while(head!=NULL)
        {
            s.push(head->val);
            head=head->next;
        }
        while(!s.empty() && head1)
        {
            if(s.top()!=head1->val)
            {
                return false;
            }
            s.pop();
            head1=head1->next;
        }
        return s.empty();
    }
};
