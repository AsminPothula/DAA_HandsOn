#include <stdio.h>
#include <stdlib.h>

#define MAX 20
int queue[MAX], front = -1, rear = -1;

int isEmpty() {
    return (front == -1); 
}

int isFull() {
    return ((rear + 1) % MAX == front); 
}

int insert() {
    if (isFull()) {
        printf("Queue Overflow\n");
        return 0;
    }
    if (isEmpty()) {
        front = 0; 
    }
    rear = (rear + 1) % MAX; 
    printf("Enter the element to be inserted: ");
    scanf("%d", &queue[rear]);
    printf("Element inserted successfully\n");
    return 0;
}

int delete() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return 0;
    }
    printf("Deleted element: %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % MAX; 
    }
    return 0;
}

int display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return 0;
    }
    printf("Queue elements:\n");
    int i = front;
    while (1) {
        printf("%d\n", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX; 
    }
    return 0;
}

int main(void) {
    int choice;
    while (1) {
        printf("\n\nQueue Menu:");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nSelect Menu Option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Menu Choice.\n");
        }
    }
    return 0;
}
