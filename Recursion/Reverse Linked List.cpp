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
public:
    ListNode* node;
    ListNode* listRev(ListNode* root){
            if (root->next){
                listRev(root->next)->next = root;
                return root;
            } else {
                node = root;
                return root;
            }
    }
    ListNode* reverseList(ListNode* head) {
        if (!head){
            return head;
        }
        listRev(head)->next = NULL;
        return node;
    }
};