#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure
struct Student {
    int id;
    char name[50];
    float marks;
    struct Student* next;
};

struct Student* head = NULL;

// CREATE
void addStudent() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = head;
    head = newNode;

    printf("Student Added Successfully\n");
}

// READ
void displayStudents() {
    struct Student* temp = head;

    if(temp == NULL) {
        printf("No Records Found\n");
        return;
    }

    while(temp != NULL) {
        printf("ID: %d | Name: %s | Marks: %.2f\n",
               temp->id, temp->name, temp->marks);
        temp = temp->next;
    }
}

// UPDATE
void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    struct Student* temp = head;

    while(temp != NULL) {
        if(temp->id == id) {
            printf("Enter new Name: ");
            scanf("%s", temp->name);

            printf("Enter new Marks: ");
            scanf("%f", &temp->marks);

            printf("Updated Successfully\n");
            return;
        }
        temp = temp->next;
    }

    printf("Student Not Found\n");
}

// DELETE
void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    struct Student *temp = head, *prev = NULL;

    if(temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Deleted Successfully\n");
        return;
    }

    while(temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Student Not Found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted Successfully\n");
}

// SEARCH
void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    struct Student* temp = head;

    while(temp != NULL) {
        if(temp->id == id) {
            printf("Found -> ID: %d | Name: %s | Marks: %.2f\n",
                   temp->id, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }

    printf("Student Not Found\n");
}

// MENU
int main() {
    int choice;

    while(1) {
        printf("\n--- STUDENT MANAGEMENT SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: updateStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayStudents(); break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}