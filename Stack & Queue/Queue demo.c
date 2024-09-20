#include<stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("\nQueue Overflow\n");
        return;
    }
    else if (front == -1) {
        front = rear = 0;
        queue[rear] = value;
    }
    else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = value;
    }
    else {
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front == -1) {
        printf("\nQueue Underflow\n");
        return -1;
    }

    int data = queue[front];
    queue[front] = -1;

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }

    return data;
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nCurrent Queue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, data, y;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter value to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
        }
        else if (choice == 2) {
            y = dequeue();
            if (y != -1) {
                printf("\nDequeued value: %d\n", y);
            }
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 0) {
            return 0;
        }
        else {
            printf("\nWrong choice, try again!\n");
        }
    }
    return 0;
}
