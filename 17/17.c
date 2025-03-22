#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Geheugenfout.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void delete(Node **head, int data) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node met waarde %d niet gevonden.\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int search(Node *head, int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    display(head);

    delete(&head, 20);
    display(head);

    printf("Zoeken naar 30: %s\n", search(head, 30) ? "Gevonden" : "Niet gevonden");
    printf("Zoeken naar 20: %s\n", search(head, 20) ? "Gevonden" : "Niet gevonden");

    return 0;
}
