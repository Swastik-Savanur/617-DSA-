#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
typedef struct node NODE;

NODE* newNode(int data) {
    NODE* n = (NODE*)malloc(sizeof(NODE));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

NODE* insert(NODE* root, int data) {
    if (root == NULL) return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void inorder(NODE* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void search(struct node* root, int key) {
    if (!root)
        printf("Not Found\n");
    else if (key == root->data)
        printf("Found\n");
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}  // ✅ fixed missing brace

int main() {
    struct node* root = NULL;
    int ch, x;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("enter data :\n");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("enter data to be searched:\n");
                scanf("%d", &x);
                search(root, x);
                break;

            case 3:
                inorder(root);   // ✅ fixed function name
                printf("\n");
                break;

            case 4:
                exit(0);
        }
    }
    return 0;
}

