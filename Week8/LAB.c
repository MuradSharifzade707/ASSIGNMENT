#include <stdio.h> 
#include <string.h>
#include <stdbool.h> 
#include <stdlib.h>

bool var = false;

typedef struct Node {
	char data [256];
	struct Node *next;
} node_t;

void luckyCustomer(node_t **head_ref, char *key)
{
	node_t *temp = *head_ref;
	node_t *prev;

	if (temp != NULL && strcmp(temp -> data, key) == 0){
		*head_ref = temp -> next;
		free(temp);
		return;
}
	while (temp != NULL && strcmp(temp -> data, key) != 0){
		prev = temp;
		temp = temp->next;
}

if (temp == NULL){ 
        printf("Undefined user or command! \n");
        var = true;
        return; 
    }
    prev->next = temp->next; 
    free(temp); 
}

void print_list(node_t *node) {
    printf("\nQueue: ");
    while (node != NULL) {
        printf("%s ", node->data);
        node = node->next;
    }
}

void addToTail(node_t **head_ref, char *new_customer) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    node_t *last = *head_ref;
    strcpy(new_node->data, new_customer);
    new_node->next = NULL;

    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

int main() {

    node_t *head = (node_t *) malloc(sizeof(node_t));

    char input[256];
    bool quit = 0;

    strcpy(head->data, "Turgut");
    head->next = NULL;
    addToTail(&head, "Nazrin");
    addToTail(&head, "Nigar");
    addToTail(&head, "Kamran");
    addToTail(&head, "Eljan");

    print_list(head);
    printf("\n");

    while(!quit) {
    printf("Enter a command: ");
    scanf("%s", input);
    if (strcmp(input,"quit") == 0) {
        quit = 1;
    
	}
    else if (strcmp(input,"admit") == 0) {

        printf("%s was accepted\n", head -> data);
        luckyCustomer(&head, head->data);
    }
    else{
        luckyCustomer(&head, input);
        if(!var){
        addToTail(&head, input);
        }
        var = false;
    }

    print_list(head);
    printf("\n");

    }

    return 0;
}




