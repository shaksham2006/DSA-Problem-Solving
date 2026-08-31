class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalpoints;
        vector<int> ans;
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return {-1,-1};
        }
        ListNode* prev=head;
        ListNode* temp=head->next;
        int count=1;
        while(temp->next!=NULL){
            if((temp->val<prev->val && temp->val<temp->next->val) ||
               (temp->val>prev->val && temp->val>temp->next->val)){
                criticalpoints.push_back(count);
            }
            prev=temp;
            temp=temp->next;
            count++;
        }
        if(criticalpoints.size()<2){
            return {-1,-1};
        }
        int mindis=INT_MAX;
        for(int i=1;i<criticalpoints.size();i++){
            mindis=min(mindis,criticalpoints[i]-criticalpoints[i-1]);
        }
        int maxdis=criticalpoints.back()-criticalpoints.front();
        ans.push_back(mindis);
        ans.push_back(maxdis);

        return ans;
    }
};