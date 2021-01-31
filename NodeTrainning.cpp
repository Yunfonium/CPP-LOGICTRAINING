/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

class Node{
    public :
        int data;
        Node *next;
};
    int a = 10, b = 15;

void push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}
void insertAfter(Node *pre_node , int new_data){
    if(pre_node == NULL){
        cout << "the given previous node cannot be NULL.";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = pre_node->next;
    pre_node->next = new_node;
}

void append(Node **head_ref, int new_data){
    Node *new_node = new Node();
    Node *last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}
void printList(Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

void deleteNode(Node **head_ref,int key){
    
    Node *temp = *head_ref;
    Node *prev = NULL;
    
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    
    prev->next = temp ->next;
    delete temp;
}

void deleteNodePos(Node **head_ref, int position){
    if(*head_ref == NULL){
        return;
    }
    Node *temp = *head_ref;
    if(position == 0){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    for(int n=0;temp!=NULL && n<position-1;n++ )
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)
        return;
    Node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
    return;
}

int main()
{

    Node *ptr = NULL;
    Node *ndptr = NULL;
    push(&ndptr,5);
    append(&ndptr,11);
    push(&ptr,a);
    append(&ptr,b);
    while( ndptr != NULL){
        insertAfter(ptr->next,ndptr->data);
        ndptr = ndptr->next;
    }

    printList(ptr);
    cout << endl;
    deleteNode(&ptr,11);
    printList(ptr);
    cout << endl;
    deleteNodePos(&ptr,1);
    printList(ptr);


    

    return 0;
    
}



