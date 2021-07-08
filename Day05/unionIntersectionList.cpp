class Solution {
public:

    void insert(Node** head_ref, int new_data)
    {

        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
        new_node->data = new_data;
    
        new_node->next = (*head_ref);
    
        (*head_ref) = new_node;
    }


    bool isPresent(Node* root, int data)
    {
        Node* curr = root;
        while (curr != NULL)
        {
            if (curr -> data == data)
                return 1;
            curr = curr -> next;
        }
        return 0;
    }

    Node* getIntersectionList(Node* root1, Node* root2)
    {
        Node* result = NULL;
        Node* curr = root1;

        while (curr != NULL)
        {
            if (isPresent(root2, curr -> data))
                insert(&result, curr -> data);
            curr = curr -> next;
        }
        return result;
    }


    Node* getUnion(Node* head1, Node* head2)
    {
        Node* result = NULL;
        Node *curr1 = head1, *curr2 = head2;

        while (curr1 != NULL)
        {
            push(&result, curr1 -> data);
            curr1 = curr1 -> next;
        }

        while (curr2 != NULL)
        {
            if (!isPresent(result, curr2 -> data))
                push(&result, curr2 -> data);
            curr2 = curr2 -> next;
        }
        return result;
    }

};