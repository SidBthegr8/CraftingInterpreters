#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char *key;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(const char *data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(!newNode){
        printf("memory allocation failed!\n");
        exit(1);
    }

    newNode->key = (char *)malloc(strlen(data)+1);
    if(!newNode->key){
        printf("newNode->key allocation failed!");
        exit(1);
    }
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main(){
    char choice[100];
    char *endptr;
    int num;
    while(1){
        printf("Enter your choice: 1. Create a new node 2. Exit\n");
        fgets(choice, sizeof(choice), stdin);
        num = strtol(choice, &endptr, 10);
        switch(num){
            case 1:{
            char data[100];
            printf("Enter data to be stored in new node\n");
            fgets(data, sizeof(data), stdin);
            printf("%s", data);
            break;
            }
            case 2:
            exit(0);
            break;
            default:
            exit(1);
        }
    }
    return 0;
}
