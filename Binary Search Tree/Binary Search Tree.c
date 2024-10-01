#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct BinaryTreeNode
{
    int key;
    struct BinaryTreeNode *left, *right;
};

struct BinaryTreeNode* newNodeCreate(int value)
{
    struct BinaryTreeNode* temp = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value)
{
    if (node == NULL)
    {
        return newNodeCreate(value);
    }
    if (value < node->key)
    {
        node->left = insertNode(node->left, value);
    }
    else if (value >= node->key)
    {
        node->right = insertNode(node->right, value);
    }
    return node;
}

void inOrder(struct BinaryTreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

void preOrder(struct BinaryTreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        printf(" %d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct BinaryTreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ",root->key);
    }
}

struct BinaryTreeNode* findMin(struct BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct BinaryTreeNode* findMax(struct BinaryTreeNode* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    while(node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

struct BinaryTreeNode* findSecondMin(struct BinaryTreeNode* node)
{

    struct BinaryTreeNode* temp;

    while(node->left != NULL)
    {
        temp = node;
        node = node->left;
    }

    if(node->right != NULL)
    {
        temp = findMin(node->right);
    }
    return temp;
}

struct BinaryTreeNode* findSecondMax(struct BinaryTreeNode* node)
{
    struct BinaryTreeNode* temp = NULL;
    while(node->right != NULL)
    {
        temp = node;
        node = node->right;
    }
    if(node->left != NULL)
    {
        temp = findMax(node->left);
    }
};

struct BinaryTreeNode* searchNode(struct BinaryTreeNode* node, int val)
{
    if(node == NULL)
    {
        printf("Not found !!!\n");
        return NULL;
    }
    if(node->key == val)
    {
        printf("Value found !!!\n");
        return node;
    }
    if(node->key > val)
    {
        node->left = searchNode(node->left, val);
    }
    else
    {
        node->right = searchNode(node->right, val);
    }
};

struct BinaryTreeNode* delete(struct BinaryTreeNode* node, int val)
{
    if (node == NULL)
    {
        printf("Not found !!!\n");
        return NULL;
    }

    if (node->key > val)
    {
        node->left = delete(node->left, val);
    }
    else if (node->key < val)
    {
        node->right = delete(node->right, val);
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        else if (node->left == NULL)
        {
            struct BinaryTreeNode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct BinaryTreeNode* temp = node->left;
            free(node);
            return temp;
        }
        else
        {
            struct BinaryTreeNode* temp = findMin(node->right);
            node->key = temp->key;
            node->right = delete(node->right, temp->key);
        }
    }
    return node;
}
void updateNode(struct BinaryTreeNode* root, int oldVal, int newVal)
{
    root = delete(root, oldVal);
    root = insertNode(root, newVal);

    printf("Updated successfully from %d to %d\n", oldVal, newVal);
}

int countLeafNodes(struct BinaryTreeNode* node) {
    if(node == NULL)
    {
        return NULL;
    }
    if(node->left == NULL && node->right == NULL)
    {
        return 1;
    }
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}


int findHeight(struct BinaryTreeNode* node) {
    if(node == NULL)
    {
        return -1;
    }

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    return fmax(leftHeight, rightHeight) + 1;

}
int main()
    {
        struct BinaryTreeNode * root = NULL;
        int choice, value;

        while(1)
        {
            printf("\nBinary Search Tree Menu:\n");
            printf("__________________________\n");
            printf(" 01.Insert Node\n 02.In-order Traversal\n 03.Pre-order Traversal\n 04.Post-order Traversal\n");
            printf(" 05.Search Node\n 06.Find Minimum\n 07.Find Maximum\n 08.Update Node\n 09.Delete Node\n");
            printf(" 10.Find Second Maximum\n 11.Find Second Minimum\n");
            printf(" 12.Count Leaf Node\n 13.Height the Tree\n 14.Exit\n\n");
            printf("Enter choice : ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
            }
            else if(choice == 2)
            {
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
            }
            else if(choice == 3)
            {
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
            }
            else if(choice == 4)
            {
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
            }
            else if(choice == 5)
            {
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(root, value);
            }
            else if(choice == 6)
            {
                printf("Minimum: ");
                struct BinaryTreeNode* a = findMin(root);
                if (a != NULL)
                {
                    printf("%d\n", a->key);
                }
            }
            else if(choice == 7)
            {
                printf("Maximum: ");
                struct BinaryTreeNode* b = findMax(root);
                if (b != NULL)
                {
                    printf("%d\n", b->key);
                }
            }
            else if(choice == 8)
            {
                int oldVal, newVal;
                printf("Enter the old value to update: ");
                scanf("%d", &oldVal);
                printf("Enter the new value: ");
                scanf("%d", &newVal);
                updateNode(root, oldVal, newVal);
            }
            else if(choice == 9)
            {
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete(root, value);
            }
            else if(choice == 10)
            {
                printf("Second Maximum: ");
                struct BinaryTreeNode* c = findSecondMax(root);
                if (c != NULL)
                {
                    printf("%d\n", c->key);
                }
            }
            else if(choice == 11)
            {
                printf("Second Minimum: ");
                struct BinaryTreeNode* d = findSecondMin(root);
                if (d != NULL)
                {
                    printf("%d\n", d->key);
                }
            }
            else if(choice == 12)
            {
                int leafCount = countLeafNodes(root);
                printf("Number of leaf nodes: %d\n", leafCount);
            }
            else if(choice == 13)
            {
                int height = findHeight(root);
                printf("Height of the tree: %d\n", height);
            }
            else if(choice == 14)
            {
                printf("Thank you !!!\n");
                break;
            }
            else
            {
                printf("Invalid choice. Select again: \n");
            }
        }
        return 0;
}
