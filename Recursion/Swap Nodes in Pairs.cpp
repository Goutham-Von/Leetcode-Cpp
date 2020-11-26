class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head != NULL and head->next != NULL){
            ListNode* temp = head->next;
            head->next = swapPairs(temp->next);
            temp->next = head;
            return temp;
        }
        return head;
    }
};