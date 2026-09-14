class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* temp = head;
        while (temp != NULL) {
            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }
        temp = head;

        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }

            temp = temp->next->next;
        }
        Node* newHead = head->next;
        temp = head;

        while (temp != NULL) {
            Node* copy = temp->next;

            temp->next = copy->next;

            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }

            temp = temp->next;
        }

        return newHead;
    }
};