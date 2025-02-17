#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void add(struct Node** head, int data) {
    // Create new node
    struct Node* newNode = (struct Node*)malloc((sizeof(struct Node)));
    newNode->data = data;
    newNode->next = NULL;

    // If our list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Add our new node to the end of our list
    struct Node *key = *head;
    while (key->next != NULL) {
        key = key->next;
    }
    key->next = newNode;
}

void delete(struct Node** head, int data) {
    // If our list is empty, return
    if (*head == NULL) return;

    struct Node* cur = *head;
    struct Node* prev = NULL;
    // Check if the first element is the one to delete
    if (cur->data == data) {
        *head = cur->next;
        free(cur);
        return;
    }

    // Loop through our linked list
    while(cur->next != NULL && cur->data != data) {
        prev = cur;
        cur = cur->next;
    }

    // If we dont find our data, then return
    if (cur == NULL) return;

    // We found our data, so delete
    prev->next = cur->next;
    free(cur);
}

int contains(struct Node* head, int data) {
    struct Node* cur = head;
    int found = 0;
    while (cur != NULL) {
        if (cur->data == data) {
            found = 1;
        }
        cur = cur->next;
    }
    return found;
}

void printLinkedList(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    add(&head, 4);
    add(&head, 5);
    
    printf("Linked List: ");
    printLinkedList(head);

    delete(&head, 4);

    printf("Delete 4: ");
    printLinkedList(head);

    printf("Does linked list have 3?: ");
    if (contains(head, 3) == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}