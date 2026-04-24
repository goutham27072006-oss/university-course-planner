//singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create
void create() {
    int choice = 1;
    while (choice) {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else {
            struct node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }

        printf("Press 1 to continue: ");
        scanf("%d", &choice);
        if (choice!=1){
            return 1; 
        }
    }
}

// Display
void display() {
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count
void count() {
    int c = 0;
    struct node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    printf("Total nodes = %d\n", c);
}

// Insert at beginning
void insert_begin() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

// Delete from beginning
void delete_begin() {
    if (head == NULL) return;
    struct node *temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_end() {
    if (head == NULL) return;
    struct node *temp = head;

    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Reverse
void reverse() {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main(){
    create();

    display();
    count();

    insert_begin();
    display();

    insert_end();
    display();

    delete_begin();
    display();

    delete_end();
    display();

    reverse();
    printf("Reversed ");
    display();

    return 0;
}

