#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node *root = NULL;

// Function to create a new node
Node* getNode(int key) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node *insert(Node *node, int key) {
    if (node == NULL) {
        Node *new = getNode(key);
        node = new;
    } else if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to search a node in BST
Node* search(Node *node, int key) {
    while (node != NULL) {
        if (key == node->key) {
            return node;
        } else if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return NULL;
}

// Function to delete a node from BST
Node* del(Node* node, int key) {
    if (node == NULL)
        return node;

    if (key < node->key) {
        node->left = del(node->left, key);
    } else if (key > node->key) {
        node->right = del(node->right, key);
    } else {
        // Node with only one child or no child
        if (node->left == NULL) {
            Node *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            Node *temp = node->left;
            free(node);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = node->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        node->key = temp->key;

        // Delete the inorder successor
        node->right = del(node->right, temp->key);
    }
    return node;
}

// Function for inorder traversal
void inorder(Node *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

int main() {
    int ch, key;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                root = insert(root, key); // Fixed: pass root to insert
                printf("Inorder: ");
                inorder(root);
                break;

            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                if (search(root, key)) // Fixed: pass root to search
                    printf("Found\n");
                else 
                    printf("Not Found\n");
                break;

            case 3:
                printf("Enter the element you want to delete: ");
                scanf("%d", &key);
                root = del(root, key);
                printf("Inorder: ");
                inorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Enter valid number\n");
        }
    }

    return 0;
}
