#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

int detect_loop(struct Node* head){
    struct Node *slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return 1;
    }
    return 0;
}

int main(){
    struct Node *head=malloc(sizeof(struct Node));
    struct Node *second=malloc(sizeof(struct Node));
    struct Node *third=malloc(sizeof(struct Node));
    head->data=10; head->next=second;
    second->data=20; second->next=third;
    third->data=30; third->next=second; // loop here
    if(detect_loop(head))printf("Loop Detected\n");
    else printf("No Loop\n");
    return 0;
}
