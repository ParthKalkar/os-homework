#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
void print_list(struct Node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
void insert_node(struct Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
	printf("No previous node");
	return;
	}
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next; prev_node->next = new_node;
}
void insert_end(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void insert_front(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data; new_node->next = (*head_ref); (*head_ref)    = new_node;
}
void delete_node(struct Node **head_ref, int key)
{
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp; temp = temp->next;
    }
    if (temp == NULL) return; prev->next = temp->next; free(temp);
}

int main()
{
    struct Node* head = NULL;
    insert_front(&head, 3); insert_end(&head, 10); insert_node(head->next, 2); insert_end(&head, 1); insert_node(head->next, 8);
    printf("\n Created Linked list is: "); print_list(head);
    delete_node(&head,1); printf("\n");
    print_list(head);



	return 0;
}

