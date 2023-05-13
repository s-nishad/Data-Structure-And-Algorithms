#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void printList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
}

struct node *createLinkedList (int a[], int n) {
    struct node *head = NULL, *temp = NULL, *current = NULL;

    for (int i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = a[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
};

struct node *insertAtBegin (struct node *head, int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    struct node *newHead = temp;
    return newHead;
}

struct node *insertAtEnd (struct node *head, int data) {
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    current->next = temp;

    return head;

}

struct node *insertAtMiddle (struct node *head, int position, int data) {
    struct node *current = head;
    int counter = 0;
    while (current != NULL) {
        counter++;

        if (counter == position) {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = data;
            new_node->next = current->next;
            current->next = new_node;
        }

        current = current->next;
    }
    return head;
}

struct node *deleteNode (struct node *head, int data) {
    struct node *new_Head = (struct node *)malloc(sizeof(struct node));
    new_Head->next = head;
    struct node *current = new_Head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            current->next = current->next->next;
        }
        current = current->next;
    }
    return new_Head->next;
}

int main() {
    int a[] = {10, 15, 20, 25, 30};
    int n = sizeof(a)/sizeof(a[0]);

    struct node *head = createLinkedList(a, n);
    printList(head);

    struct node *afterInsertB_Head = insertAtBegin(head, 5);
    printList(afterInsertB_Head);

    struct node *afterInsertE_Head = insertAtEnd(afterInsertB_Head, 35);
    printList(afterInsertE_Head);

    struct node *afterInsertM_Head = insertAtMiddle(afterInsertE_Head, 4, 22);
    printList(afterInsertM_Head);

    struct node *afterDelete_Head = deleteNode(afterInsertM_Head, 22);
    printList(afterDelete_Head);

}
