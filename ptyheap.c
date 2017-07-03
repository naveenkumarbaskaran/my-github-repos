#include<stdio.h>
#include<stdlib.h>
struct heap
{
  int data;
  int pty;
 };


main()
{
  int i,n,p,struct heap h[20];
  struct heap x;
  int count;
  count =0
  while(1)
  {
     1.insert
     2.delete
     3.exit
    
     switch(ch)
     {
      case 1: printf("enter the no and pty");
              scanf("%d %d",&n,&p);
              insert(n,p,h,&count);
              break;
 
      case 2: x=pqdelete(h,&count);
              printf("the value of the element = %d and Pty=%d",x.data,x.pty);
              break;
      case 3 : exit(0);
     }
  }
 }

 //inserting into a min heap
 void insert( int x, int p,struct heap *h,int *count)
 {
  struct heap temp;
  temp.data=x;
  temp.pty=p;

  h[*count]=temp;//initial position of the element
  (*count)++;

  i=*count-1;
  j=(i-1)/2;
  //as long as the pty of the element being inserted
  //is lower than the pty of the parent
  //move the parent down
  while((i>0) &&(temp.pty < h[j].pty))
  {
    h[i]=h[j];
    i=j;
     j=(i-1)/2;
  }
  h[i]=temp;
}



 //deleting the root element 
 
 struct heap pqdelete(struct heap *h, int *count)
 {
    struct heap temp;
    temp=h[0];
    h[0]=h[*count-1];
    (*count)--;
    adjust(h,*count);
    return temp;
 }

   
    void display(int *h, int count)
   {
     int i;
     for(i=0;i<count;++i)
         printf("%d ",h[i]);
   }




   void adjust(struct heap *h, int count)
   {
     int i,j;
     struct heap key;

     key=h[0];
     j=0;
     i=j*2+1;// get the left child
      
     while(i<=count-1)//as long as a left child exists
     {
      if((i+1)<=count-1)//right child exists
      {
        if(h[i+1]<h[i])
           i++;//get the index of the smallest child
      }
       if(key.pty > h[i].pty)
       {
         h[j]=h[i]; //move the child up
         j=i;
         i=2*j+1;
       }
       else
          break;
      }
      h[j]=key; 
    }













   /*void adjust(int *h, int count)
   {
    int i,j,key;

    j=0;
    key=h[j];
    i=2*j+1;//get the left child
   
    while(i<=count-1)//as long as the left child exists
    {
      if((i+1)<=count-1)//check whether right child exists
        if(h[i+1]>h[i])//get the largest child
          i++; 
      if(key<h[i])
      {
         h[j]=h[i];//move the child up
         j=i;
         i=2*j+1;//get the new child position
       }
      else
       break;
     }
     h[j]=key;
    }
   

 
   void heapify(int *h,int count)
   {
    int i,j,k,key;

    for(k=1;k<count;k++)
    {
      i=k;
      key=h[i];
       j=(i-1)/2;
      while(i>0 && key >h[j])
      {
        h[i]=h[j];
        i=j;
        j=(i-1)/2;
      }
      h[i]=key;
    }
  }*/
      


     
  
