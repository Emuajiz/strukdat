// Recursive CPP program to recursively insert
// a node and recursively print the list.
// Source: geeksforgeeks.comm
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// Allocates a new node with given data
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
// Function to insert a new node at the
// end of linked list using recursion.
Node* insertEnd(Node* head, int data)
{
    // If linked list is empty, create a
    // new node (Assuming newNode() allocates
    // a new node with given data)
    if (head == NULL)
    return newNode(data);
    // If we have not reached end, keep traversing
    // recursively.
    else
    head->next = insertEnd(head->next, data);
    return head;
}
void traverse(Node* head)
{
    if (head == NULL)
        return;
    // If head is not NULL, print current node
    // and recur for remaining list
    cout << head->data << " ";
    traverse(head->next);
}

void insertAfterKey(Node* p, int key, int data)
{
    if(p->data == key)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = p->next;
        p->next = new_node;
        printf("inserted key: %d\n", data);
    }
    else
    {
        if(p->next != NULL)
            insertAfterKey(p->next, key, data);
        else
        {
            Node *new_node = new Node;
            new_node->data = data;
            new_node->next = p->next;
            p->next = new_node;
            printf("inserted key at end: %d\n", data);
        }
        
    }
    
}

void deleteKey(Node* prev, Node* p, int key)
{
    //prev digunakan untuk menunjuk ke node sebelum node yang akan dihapus
    //p digunakan untuk menunjuk ke node yang akan dihapus
    if(prev == NULL) prev = p;
    if(p->data == key)
    {
        prev->next = p->next;
        printf("Deleted: %d\n", p->data);
        free(p);
    }
    else
    {
        if(p->next != NULL)
            deleteKey(p, p->next, key);
        else
            printf("key %d doesnt exists\n", key);
    }
    
}


// Driver code
int main()
{
    Node* head = NULL;
    head = insertEnd(head, 6);
    head = insertEnd(head, 8);
    head = insertEnd(head, 10);
    head = insertEnd(head, 12);
    head = insertEnd(head, 14);
    traverse(head);
    cout << "\n";
    insertAfterKey(head, 12, 13);

    // yang ini
    insertAfterKey(head, 8, 9);
    traverse(head);
    cout << "\n";

    insertAfterKey(head, 15, 16);
    traverse(head);
    cout << "\n";
    //yang ini
    deleteKey(head, head, 12);
    traverse(head);
    cout << "\n";
    return 0;
}