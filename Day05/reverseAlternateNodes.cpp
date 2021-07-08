class Solution {
public:

    Node* reverse(Node*& curr, int k)
    {
        Node* prev = nullptr;
        while (curr && k--)
        {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


    Node* skipKNodes(Node*& curr, int k)
    {
        Node* prev = nullptr;   
        while (curr && k--)
        {
            prev = curr;
            curr = curr->next;
        }  
        return prev;
    }


    Node* reverseKGroupAlternate(Node* head, int k) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr)
        {
            Node* lastNode = curr;
            Node* frontNode = reverse(curr, k);
            if (!prev)
                head = frontNode;
            else
                prev->next = frontNode;

            lastNode->next = curr;
            prev = skipKNodes(curr, k);
        }
        return head;
    }
};