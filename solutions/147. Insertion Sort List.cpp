        
        if(list==NULL) return head;
        while(list != NULL) {
            prev=NULL;
            r=root;
            while(r->next != NULL && list->val < r->val) {
                prev=r;
                r=r->next;
            }
            
            ListNode *newNode = new ListNode(list->val);
            
            if(r->next == NULL && prev==NULL) {
                if(newNode->val < r->val) {
                    r->next = newNode;
                    root=r;
                } else {
                    newNode->next=r;
                    root=newNode;
                }
            } 
            else if(r->next==NULL && prev!=NULL) {
                if(newNode->val < r->val) {
                    r->next = newNode;
                } else {
                    prev->next=newNode;
                    newNode->next=r;
                }
            } else if(prev == NULL) {
                newNode->next = root;
                root=newNode;
            } else {
                newNode->next = r;
                prev->next = newNode;
            }
            list=list->next;
        }
        return reverse(root);
    }
};
