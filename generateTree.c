#include<stdlib.h>
#include<stdio.h>
typedef struct tree{
    struct tree *left;
    int data;
    struct tree *right;
}Tree;

// different ways of displaying a tree
void inorder(Tree *t){
    if(t == NULL)
        printf("Tree is empty.\n");
    else{
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

void postorder(Tree *t){
    if(t == NULL)
        printf("Tree is empty.\n");
    else{
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

void preorder(Tree *t){
    if(t == NULL)
        printf("Tree is empty.\n");
    else{
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

// creates a binary tree
void createTree(Tree **t, int x){
    printf("Inside createTree function");
        Tree *temp = (Tree *)malloc(sizeof(Tree));
        temp->data = x;
        temp->left = temp->right = NULL;
        Tree *curr = *t, *prev = NULL;
        if(curr == NULL){
            *t = temp;
        }
        else{
            while(curr != NULL){
                prev = curr;
                if(x < curr->data)
                    curr->left = temp;
                else
                    curr->right = temp;
            }
        }
        if(x < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }


int leafCount(Tree *t){
    if(t != NULL){
        if(t->left == NULL && t->right == NULL)
            return 1;
        return(leafCount(t->left) + leafCount(t->right));
    }
    return 0;
}

int maximum(int x, int y){
    if(x > y)
        return (x + 1);
    else return (y + 1);
}

int height(Tree *t){
    if(t == NULL)
        return -1;
    else{
        if(t->left == NULL && t->right == NULL)
            return 0;
        else
            return(maximum(height(t->left) ,height(t->right)) + 1);
    }
}

Tree *deleteNode(Tree *t, int x){
    Tree *curr = t, *prev = NULL, *q, *insuc;
    // search for x
    while (curr != NULL && curr->data != x) {
        prev = curr;
        if(x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(curr == NULL)
        printf("Node not found");
    else{
        // no left subtree
        if(curr->left == NULL)
            // get left subtree
            q = curr->right;
        // no right subtree
        else if(curr->right == NULL)
            // get left subtree
            q = curr->left;
        else{
            // both subtrees are present, find inorder successor
            insuc = curr->right;
            while(insuc->left != NULL)
                insuc = insuc->left;
            // inorder successor found, attach left subtree to left of inorder successor
            insuc->left = curr->left;
            q = curr->right;
        }
        if(prev == NULL)
            return q;
        else if(curr == prev->left)
            prev->left = q;
        else
            prev->right = q;
    }
    return t;
}


int main(){
    int *a;
    int i, size;
    Tree *root = NULL;
    printf("Enter number of elements:");
    scanf("%d", &size);
    a = (int *)malloc(size * sizeof(int));

    for(i = 0 ; i < size ; i++){
        printf("Enter %dth element:",i);
        scanf("%d", &a[i]);
    }

    for(i=0;i<size;i++)
        printf("%d ", a[i]);

    for (i = 0 ; i < size ; i++) {
        createTree(&root,a[i]);
    }
    inorder(root);
    return 0;
}



// enter a node to a binary search tree recursively

// root contains address of root element
Tree *rinsert(Tree *root, int x){
    if(root == NULL){
        // create first node
        Tree *temp = (Tree *)malloc(sizeof(Tree));
        temp->data = x;
        temp->left =temp->right = NULL;
        return root;
    }
    else{
        if(x > root->data)
            // element is greater than root
            root->left = rinsert(root->right, x);
        else
            // element is leser than root
            root->right = rinsert(root->left, x);
            return root;
    }
}
