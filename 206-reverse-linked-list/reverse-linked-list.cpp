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
    ListNode* reverseList(ListNode* head) {
        
        vector<int> array;
        ListNode* temp=head;
        while(temp!=NULL){
            array.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        int i=array.size()-1;
         while(temp!=NULL){
            temp->val=array[i];
            i--;
            temp=temp->next;
        }
       
       return head;

    }
};