#include <stdio.h>
#include <stdlib.h>
struct tree {
    struct tree *left;
    struct tree *right;
    char data;
}*t1;

struct tree* make(struct tree *t)
{
    int l,r;
    t = (struct tree *)malloc(sizeof(struct tree));
    printf("Data for this node:\n");
    scanf("%d",&(t->data));
    printf("Enter 1 for adding left child else 0\n");
    scanf("%d",&l);
    if(l)
        t->left=make(t->left);
    else
        t->left = NULL;
    printf("Enter 1 for adding right child else 0\n");
    scanf("%d",&r);
    if(r)
        t->right=make(t->right);
    else
        t->right = NULL;
    return t;
}

void preorder(struct tree *t)
{
    if(t != NULL)
    {
        printf("%c\n",t->data);
        if(t->left != NULL)
            preorder(t->left);

        if(t->right != NULL)
            preorder(t->right);
    }
}


void inorder(struct tree *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            inorder(t->left);

    printf("%c\n",t->data);

        if(t->right != NULL)
            inorder(t->right);
    }
}


void postorder(struct tree *t)
{
    if(t != NULL)
    {
        if(t->left != NULL)
            postorder(t->left);

        if(t->right != NULL)
            postorder(t->right);

        printf("%c\n",t->data);
    }
}


int main()
{
    printf(":::::::::::::::::Tree-Creation::::::::::::::::::\n");
    t1=make(t1);
    printf("::::::::::::::::::PRE-ORDER METHOD::::::::::::::::::\n");
    preorder(t1);
    printf("::::::::::::::::::IN-ORDER METHOD::::::::::::::::::\n");
    inorder(t1);
    printf("::::::::::::::::::POST-ORDER METHOD::::::::::::::::::\n");
    postorder(t1);
    return 0;
}


