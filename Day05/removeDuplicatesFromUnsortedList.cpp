class Solution {
public:
    void removeDuplicates(Node* head)
    {
        unordered_set<int> us;

        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            if (us.find(curr->data) != us.end())
            {
                prev->next = curr->next;
                delete (curr);
            }
            else
            {
                us.insert(curr->data);
                prev = curr;
            }
            curr = prev->next;
        }
    }
};