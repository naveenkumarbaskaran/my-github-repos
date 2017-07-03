#include<stdio.h>
#include<stdlib.h>
void insert(int *t, int);
void preorder(int*,int);
void inorder(int*,int);
void postorder(int*,int);
int leafcount(int *,int);
int height(int*,int);
void main()
{
  int t[100];//storage for tree elements
  int i,ch,num,k;
  for(i=0;i<100;i++)
    t[i]=0;
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
                 insert(t,num);
                 break;
        case 2: preorder(t,0);
                 break; 
        case 3: postorder(t,0);
                 break;
        case 4:inorder(t,0);
                 break;
        case 5: k=leafcount(t,0);
                 printf("\nthe number of leaf nodes=%d",k);

                 break;
         case 6: k=height(t,0);
                 printf("\nthe height of tree=%d",k);

                 break;
         /*case 7:printf("Enter the node to be deleted\n");
                scanf("%d",&num);
                root=tdelete(root,num);
                 break;*/
         case 8:exit(0);
       }
    }
  }    
  
   //insert a node into a BST
  void insert(int *t,int x)
  {

   int i=0;
  
   while(t[i]!=0)
   {
     if(x<t[i])
      i=2*i+1;//branch left
     else
      i=2*i+2;//branch right
   }
   t[i]=x;
  }

  //preorder traversal
  void preorder(int *t, int i)
  {
    if(t[i]!=0)
    {
       printf("%d ",t[i]);
       preorder(t,2*i+1);
       preorder(t,2*i+2);
    }
  } 
   
//inorder traversal
  void inorder(int *t, int i)
  {
    if(t[i]!=0)
    {
       inorder(t,2*i+1);
       printf("%d ",t[i]);
       inorder(t,2*i+2);
    }
  } 

  //post order traversal
 
   void postorder(int *t, int i)
  {
    if(t[i]!=0)
    {
       postorder(t,2*i+1);
       postorder(t,2*i+2);
       printf("%d ",t[i]);
    }
  } 
  
  //find the minimum element
   int min(int *t)
   {
     int i=0;
     while(t[2*i+1]!=0)
        i=2*i+1  
     return(t[i]);
   }      


//find the maximum element
   int max(int *t)
   {
     int i=0;
     while(t[2*i+2]!=0)
        i=2*i+2  
     return(t[i]);
   }   
  

  
  
  
  
  
    




     
      




  
