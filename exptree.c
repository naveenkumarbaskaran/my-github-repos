//program to create an expression tree and evaluate
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  char data;
  struct tnode *left;
  struct tnode *right;
};
void inorder(struct tnode*);
void preorder(struct tnode*);
void postorder(struct tnode*);
struct tnode *create_exp(char *);
void push(struct tnode*,struct tnode**,int*);
struct tnode* pop(struct tnode**, int*);
int isoper(char);
int evaluate(struct tnode*);
main()
{
  struct tnode *root;
  int ch,num,k;
   char postfix[100];
  root=NULL;
  printf("Enter the postfix expression..");
  scanf("%s",postfix);
  root=create_exp(postfix);
  printf("\nThe inorder traversal order of the expression\n");
  inorder(root);  
  printf("\nThe Preorder Traversal order of the expression\n");
  preorder(root);
  printf("\nThe result of the expression..\n"); 
  int result=evaluate(root);
  printf("the result=%d\n",result);
}


  struct tnode *create_exp(char *postfix)
  {
     int i;
      char ch;
     struct tnode *temp;
     struct tnode *stk[10];//stack
     int top=-1;
     i=0;
     while(postfix[i]!='\0')
     {
        
        ch=postfix[i];
        temp=(struct tnode*)malloc(sizeof(struct tnode));
        temp->data=ch;
        temp->left=temp->right=NULL;
        if(isoper(ch))
        {
          temp->right=pop(stk,&top);
          temp->left=pop(stk,&top);
          //temp->data=ch;
          push(temp,stk,&top);
        }
        else
          push(temp,stk,&top);
      i++;
      }
      temp=pop(stk,&top);
      return temp;
   }
   
   int isoper(char ch)
   {
     switch(ch)
     {
     case '+':
     case'-':
     case '*':
     case '/':return 1;
     default:return 0;
    }
    
 }

   struct tnode* pop(struct tnode **stk,int *top)
   {
      struct tnode *temp;
      temp=stk[*top];
      (*top)--;
      return temp;
    }

    void push(struct tnode *temp,struct tnode **stk, int *top)
    {
         (*top)++;
          stk[*top]=temp;
     }    
       
    
   void inorder(struct tnode *t)
   {
    if(t!=NULL)
    {
      inorder(t->left);
      printf("%c ",t->data);
      inorder(t->right);
      
     }
   }

  void preorder(struct tnode *t)
  {
    if(t!=NULL)
    {
      printf("%c ",t->data);
      preorder(t->left);
      preorder(t->right);
    }
  }

  
  int evaluate(struct tnode* t)
  {
    int data;
    switch(t->data)
    {
       case '+':return(evaluate(t->left) + evaluate(t->right));
       case '-':return(evaluate(t->left) - evaluate(t->right));
       case '*':return(evaluate(t->left) * evaluate(t->right));
       case '/':return(evaluate(t->left) / evaluate(t->right));
       default:return(t->data -'0');//if i/p of form 123*+
              /*{
               printf("Enter the value of %c",t->data); //if i/p of form abc*+
               scanf("%d",&data);//read values of a,b,&c and evaluate
               return data;
              }*/
      }          
   }




 








 

  


   
  
  
  

  

 



   


  

     
      




  
