class Solution {
public:
    bool hasCycle(ListNode *head) {

        set<ListNode*> visited;
        ListNode* temp = head;

        while (temp != NULL) {
            if (visited.find(temp) != visited.end()) {
                return true;
            }

            visited.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};