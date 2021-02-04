/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Queue{
    public :
    
    int front,rear,size;
    unsigned capacity;
    int *array;

};

//Function to create a Queue of given capacity.
//It initializes size of the queue as 0;
Queue *createQueue(unsigned capacity){
    Queue *queue = new Queue();
    queue->capacity = capacity;
    
    queue->front = queue->size = 0;
    
    queue->rear = queue->capacity-1;
    queue->array = new int[(queue->capacity * sizeof(int))];
    return queue;
}

int isFull(Queue *queue){
    return (queue->size == queue->capacity);
}

int isEmpty(Queue *queue){
    return (queue->size == 0);
}

void enqueue(Queue *queue, int item){
    if(isFull(queue))return INT_MIN;
    
    queue->rear = (queue->rear + 1)% queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
    cout << item << " enqueue to the queue\n";
}

int dequeue(Queue *queue){
    if(isEmpty(queue))return INT_MIN;
    int item = queue->array[queue->front + 1] % queue->capacity;
    queue->size -= 1;
    return item;
}

int front(Queue *queue){
    if(isEmpty(queue))return INT_MIN;
    return queue->array[queue->front];
}

int rear(Queue *queue){
    if(isEmpty(queue))return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{
    Queue *ptr = createQueue(1000);
    enqueue(ptr, 12);
    enqueue(ptr, 13);
    enqueue(ptr, 14);
    enqueue(ptr, 15);
    cout << front(ptr) <<endl;
    cout << rear(ptr) <<endl;
    return 0;
}

