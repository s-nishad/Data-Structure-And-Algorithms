#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insertAtbegin(int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insertAtmiddle(int value,int pos){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;

    struct node *temp=head;
    for(int i=2;i<pos;i++){
        if(temp->next!=NULL){
            temp = temp->next;
        }
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertAtend(int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    struct node *temp = head;
    while(temp!=NULL){
        temp = temp->next;
    }
    temp = new_node;
}

void deleteAtbegin(){
    head = head->next;
}

void deleteAtmiddle(int pos){
    struct node *temp = head;
    for(int i=2;i<pos;i++){
        if(temp->next!=NULL){
            temp = temp->next;
        }
    }
    temp->next = temp->next->next;
}

void deleteAtend(){
    struct node *temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void printList(){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    insertAtbegin(1);
    insertAtbegin(2);
    insertAtbegin(3);
    insertAtbegin(4);
    insertAtbegin(5);
    insertAtbegin(6);

    printList();
    insertAtmiddle(0,4);
    printList();
    deleteAtmiddle(4);
    printList();
    deleteAtend();
    printList();

return 0;
}
