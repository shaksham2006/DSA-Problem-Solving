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
//  1. Ek loop se size of the linked list calculate kro
//  2. Size ko n se divide kro jo bhi quotient aye utne elements starting of linked list se leke hr group me jayennge too wo hr subaray ka size smjho 
//  3. fir jo remainder hai utne groups me ek ek element ko baat do shuru se hr group me fir hme size finalize ho jayega uske baad linked list me traverse krke subarrays me elements fill krdenge . 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        // 1. Calculate total size
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        temp = head;
        // 2. Calculate quotient and remainder
        int quot = size / k;
        int rem = size % k;
        // 3. Store heads of the parts
        vector<ListNode*> arr;
        for (int i = 0; i < k; i++) {
            int partSize = quot;
            if (rem > 0) {
                partSize++;
                rem--;
            }
            // Store the starting node of this part
            arr.push_back(temp);
            // Move to the last node of this part
            for (int j = 1; j < partSize; j++) {
                temp = temp->next;
            }
            // Disconnect the current part
            if (temp != NULL) {
                ListNode* nextPart = temp->next;
                temp->next = NULL;
                temp = nextPart;
            }
        }

        return arr;
    }
};
