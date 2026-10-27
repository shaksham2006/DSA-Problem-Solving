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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        int left = 0;
        int right = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            if(size==k-1){
                left = temp->val;
            }
            temp = temp->next;
            size++;
        }
        temp = head;
        int count = 1;
        while(count < (size-k+1)){
            temp=temp->next;
            count++;
        }
        right = temp->val;
        temp = head;
        int idx = 1;
        while(temp!=NULL){
            if(idx == k){
                temp->val = right;
            }else if(idx == (size-k+1)){
                temp->val = left;
            }
            temp = temp->next;
            idx++;
        }
        return head;
        
    }
};