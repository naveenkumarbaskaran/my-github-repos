#include<stdio.h>
#include<stdlib.h>


struct student
{
 int x;
 struct student *next;
}node;

struct student *first = NULL,*last = NULL,*temp = NULL;


void add_beg()
{
  temp = (struct student *)malloc(sizeof(node));
  printf("\n Enter the element\n");
  scanf("%d",&(temp->x));
  if(first == NULL)
  {
    temp->next = NULL;
    first = temp;
    last = first;
  }
  else
  {
   temp->next = first;
   first = temp;
  }
}

void add_end()
{
  temp = (struct student *)malloc(sizeof(node));
  printf("\n Enter the element\n");
  scanf("%d",&(temp->x));
   if(first == NULL)
  {
    temp->next = NULL;
    first = temp;
    last = first;
  }
  else
  {
   temp->next = NULL;
   last->next = temp;
   last = temp;
  }
}

void add_middle()
{ 
  if(first == NULL)
  {printf("\n No element is there\n");}
  else if(first==last)
  {printf("\n Only one element is there\n");
   temp = (struct student *)malloc(sizeof(node));
   printf("\n Enter the element\n");
   scanf("%d",&(temp->x));
   temp->next = NULL;
   last->next = temp;
   last = temp;
  }
  else
  {
    printf("\n enter the position to be inserted\n");
    int pos;
    scanf("%d",&pos);
    int i;
    temp = first;
    for(i=1;i<pos-1;i++)
    {
      temp = temp->next;
    }
    struct student *temp2;
    temp2 = (struct student *)malloc(sizeof(node));
    printf("\n Enter the element\n");
    scanf("%d",&(temp2->x));
    temp2->next = temp->next;
    temp->next = temp2;
    
  }
}

void del_beg()
{
  if(first == NULL)
  {printf("\n No element to delete \n");}
  else if(first == last)
  { temp = first;first = NULL; free(temp);printf("\n Element has been deleted\n");}
  else
  {
    temp = first;
    first = first->next;
    temp->next = NULL;
    free(temp);
    printf("\n Element has been deleted\n");
    
  }
}

void del_end()
{
  if(first == NULL)
  {printf("\n No element to delete \n");}
  else if(first == last)
  { temp = first;first = NULL; free(temp);printf("\n Element has been deleted\n");}
  else
  {  
   
    temp = first;
    while(temp->next!=last)
    { 
      temp = temp->next;
    }
    
    temp->next = NULL;
    struct student *temp2 = last;
    
    last = temp;
    free(temp2);
    printf("\n Element has been deleted\n");
    
  }
}

void del_middle()
{
  int n,count = 0;
  struct student *prev;
  printf("\n Enter the element to be deleted\n");
  scanf("%d",&n);
  temp = first;
  while(temp!=NULL)
  {
    if(temp->x != n)
    { prev = temp;
       temp = temp->next;
    }
    else
    {
      count++; 
     
      prev->next = temp->next;
      temp->next = NULL;
      free(temp);
      printf("\n Element has been deleted\n");
      
    } 
  }
  
  if(count == 0)
  printf("\n element not found \n");
  
}

void reverse()
{
  temp = last;
  struct student *temp2 = NULL;
  while(temp!=first)
 {
  temp2 = first;
  while(temp2->next!=temp)
  {
    temp2 = temp2->next;
  }
  temp->next = temp2;
  temp = temp2;
  }
  
  temp->next = NULL;
  first = last;
  last = temp;
}

void display()
{
  temp = first;
  printf("\n");
  while(temp!=NULL)
  {
    printf(" %d ",temp->x);
    temp = temp->next;
  }
}


void main()
{
 int ch;
 do
 {
   printf("\n     Menu\n1.Insert Beginning\n2.Insert End \n3.Insert middle\n4.Delete Beginning\n5.Delete End \n6.Delete middle\n7.Reverse\n8.Display\n");
   printf("\n Enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
     add_beg();
     break;
     case 2:
     add_end();
     break;
     case 3:
     add_middle();
     break;
     case 4:
     del_beg();
     break;
     case 5:
     del_end();
     break;
     case 6:
     del_middle();
     break;
     case 7:
     reverse();
     break;
     case 8:
     display();
     break;
   }
   
 }while(ch>0 && ch<9);
}
