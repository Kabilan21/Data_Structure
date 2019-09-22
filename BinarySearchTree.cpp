#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct tree
{
    int data;
    struct tree *left,*right;
};

int maximum(struct tree *node);
struct tree *root,*p;

void inorder(struct tree *node)
{
    if(node==0)
    {
        cout<<"Tree is empty";
        return ;
    }
    if(node->left)
        inorder(node->left);
    cout<<node->data;
    if(node->right)
        inorder(node->right);
}



struct tree *ins(struct tree *node,int key)
{
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
    temp->data = key;
    temp->right = NULL;
    temp->left = NULL;
    if(node == NULL)
        node=temp;
    else
    {
        if(key < node->data)
           node->left =  ins(node->left,key);
        else
           node->right = ins(node->right,key);
    }
    return node;
}

struct tree *sea(struct tree *node,int key)
{
    if(node == NULL)
     return node;
    else
    {
    if(node->data == key)
    return node;
    else
    {
        if( key < node->data)
            {
                p = node;
            sea(node->left,key);
            }
        else
        {
            p =node;
            sea(node->right,key);
}
  }
    }
}

void delet(int key)
{
    struct tree *node;
    node = sea(root,key);
   if(node->right== NULL && node->left==NULL)
   {
       if(node==root)
       {
       root=NULL;
       }
       if(p->left==node)
        p->left=NULL;
       else
        p->right=NULL;
       free(node);
       //cout<<"deleted:"<<key<<"\n";
   }
   else if(node->left && node->right)
   {
     int q;
    q = maximum(node);
    node->data = q;
   }
   else
   {
       if(node == root)
       {
        if(node->left)
        {
            root = node->left;
            free(node);
        }
        else{
            root = node->right;
            free(node);
        }
       }
     if(p->left == node)
     {
        if(node->left)
        p->left=node->left;
        else
            p->left = node->right;
     }
     if(p->right == node)
     {
         if(node->left)
            p->right = node->left;
         else
            p->right = node->right;
     }
   }
}

int maximum(struct tree *node)
{
    int i;
    struct tree *q;
    node = node->left;
    q = node;
    while(node)
    {
        q = node;
        node=node->right;
    }
    i = q->data;
    delet(i);
    return i;
}

int main()
{

root = ins(root,60);
ins(root,30);
ins(root,40);
ins(root,70);
ins(root,80);
ins(root,25);
delet(25);
delet(30);
delet(60);
delet(70);
delet(80);
delet(40);
inorder(root);
}
