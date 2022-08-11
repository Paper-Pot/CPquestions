class Solution {
    
    public:


    // merge to sorted linked List

        ListNode* helper(ListNode* List1, ListNode* List2) {
            
            ListNode* temp1 = List1;
            ListNode* nextNode1 = temp1->next;

            ListNode* temp2 = List2;
            ListNode* nextLink2 = temp2->next;

            while(nextLink1!=NULL && temp2 !=NULL) {
                if(temp2->val >= temp1->val and temp2->val < nextLink1->val) {
                    temp1->next = temp2;
                    nextLink2 = temp2->next;
                    temp2->next = nextLink1;
                    temp1 = temp2;
                    temp2 = nextLink2;
                } else {
                    temp1=nextLink1;
                    nextLink1 = nextLink1->next;
                    if(nextLink1==NULL){
                            temp1->next = temp2;
                            return List1;
                    }
                }
            }

            if(nextNode1==NULL){
                temp1->nextNode = temp2;
                return List1;
            }
            return List1;
        }
        ListNode* mergeTwoLists(ListNode* List1, ListNode* List2) {
            if(!List1) return List2;
            if(!List2) return List1;
            
            if(List1->val <= List2->val) {
                return helper(List1,List2);
            } else {
                return helper(List2,List1);
            }
        }
};