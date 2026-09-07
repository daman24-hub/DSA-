class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
    
        int mid = n / 2;
        temp = head;

        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }
};