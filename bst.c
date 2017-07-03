#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
void inorder(struct tnode*);
void preorder(struct tnode*);
void postorder(struct tnode*);
void insert(struct tnode**,int);
int leafcount(struct tnode *);
int height(struct tnode *);
struct tnode* rinsert(struct tnode *, int);
struct tnode* tdelete(struct tnode*,int );
void main()
{
  struct tnode *root;
  int ch,num,k;
   root=NULL;
 while(1)
 {
      printf("\n1.Insert");
      printf("\n2.Preorder");   
      printf("\n3. Postorder");
      printf("\n4.Inorder");
      printf("\n5. Leaf nodes");
      printf("\n6.Height of a tree");
      printf("\n7.delete a node");
      printf("\n8.exit");
      scanf("%d",&ch);
       switch(ch)
       {
         case 1 :printf("Enter the element");
                 scanf("%d",&num);
                 insert(&root,num);
                 //root=insert(root,num);
                 break;
        case 2: preorder(root);
                 break; 
        case 3: postorder(root);
                 break;
        case 4:inorder(root);
                 break;
        case 5: k=leafcount(root);
                 printf("\nthe number of leaf nodes=%d",k);

                 break;
         case 6: k=height(root);
                 printf("\nthe height of tree=%d",k);

                 break;
         case 7:printf("Enter the node to be deleted\n");
                scanf("%d",&num);
                root=tdelete(root,num);
                 break;
         case 8:exit(0);
       }
    }
  }    
  
   //delete a node iteratively
   struct tnode *tdelete(struct tnode *t, int x)
   {
       
    struct tnode *curr, *prev, *q, *insucc;

     curr=t;
     prev=NULL;

    //search for x
    while((curr!=NULL)&&(curr->data!=x))
    {
      prev=curr;
      if(x<curr->data)
          curr=curr->left;
       else
          curr=curr->right;
     }
    if(curr==NULL)
     printf("Node not found...\n");
    else
      {
        if(curr->left==NULL)//no left sub tree
           q=curr->right;//get right subtree 
        else if(curr->right==NULL)//no right subtree
           q=curr->left;//get left subtree
        else
        {
          //both subtrees present
          //find inorder successor
          insucc=curr->right;
          while(insucc->left!=NULL)
             insucc=insucc->left;
          //inorder found(insucc)
          //attach left subtree of curr to left of inorder successor
          insucc->left=curr->left;
          q=curr->right;
        }
          if (prev==NULL) //deleting the root, return new root(q)
             return q;
          else if(prev->left==curr)
             prev->left=q; //attach q to the left of prev
          else
             prev->right=q;//attach q to the right of prev
        return t;
     }
  }


  //fucntion to find minimum element in a BST
  int min(struct tnode *t)
  {
    while(t->left!=NULL)
     t=t->left;
    return(t->data);
 }

 //function to find a maximum element in a BST
 int max(struct tnode *t)
  {
    while(t->right!=NULL)
     t=t->right;
    return(t->data);
 }

//insert a node into a BST iteratively
void insert(struct tnode **t,int x)
  {
    struct tnode *temp,*prev,*curr;
    temp=(struct tnode*)malloc(sizeof(struct tnode));
    temp->data=x;
    temp->left=temp->right=NULL;

    curr=*t;
    prev=NULL;
     if(curr==NULL)//first node
      *t=temp;
    else
    {
      while(curr!=NULL) 
      {
         prev=curr;
         if(x<curr->data)
           curr=curr->left;
         else
           curr=curr->right;
      }
      if(x<prev->data)
        prev->left=temp;
     else
        prev->right=temp;
    }
  }
  
//preorder traversal 
  void preorder(struct tnode *t)
  {
    if(t!=NULL)
    {
      printf("%d ",t->data);
      preorder(t->left);
      preorder(t->right);
    }
  }

  //post order traversal
  void postorder(struct tnode *t)
  {
    if(t!=NULL)
    {
      postorder(t->left);
      postorder(t->right);
      printf("%d ",t->data);
    }
  }

  //inorder traversal
 void inorder(struct tnode *t)
  {
    if(t!=NULL)
    {
      inorder(t->left);
      printf("%d ",t->data);
      inorder(t->right);
      
    }
  }
  
  //count the no of leaf nodes
  int leafcount(struct tnode *t)
  {
     int l,r;
    if(t!=NULL)
    {
     if((t->left==NULL)&&(t->right==NULL))
       return 1;
     l=leafcount(t->left);
     r=leafcount(t->right);
     return(l+r);
    }  
   return 0;  
 }

    //find the height of a tree
   int height(struct tnode *t)
  {
     int l,r;
    if(t!=NULL)
    {
     if((t->left==NULL)&&(t->right==NULL))
       return 0;
     l=height(t->left);
     r=height(t->right);
     if(l>r)
       return(l+1);
     return(r+1);
     }
    return -1;
 }

  
       
  

  //insert a node recursively

  struct tnode* rinsert(struct tnode *t, int x)
  {
      struct tnode *temp;
     if(t==NULL)
      {
         temp=(struct tnode*)malloc(sizeof(struct tnode));
         temp->data=x;
         temp->left=temp->right=NULL;
         return temp;
      }
        if(x<t->data)
           t->left=rinsert(t->left,x);
             else
           t->right=rinsert(t->right,x);
        return t;
     
    }



   
  



   


  

  
  
  
  
    




     
      




  
