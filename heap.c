#include<stdio.h>
#include<stdlib.h>
void display(int *, int);
int maxremove(int *, int *);
void adjust(int *, int);
void heapify(int *,int);
void heapsort(int*,int);
main()
{
  int i,h[20];
  int count,num;
  printf("Enter the no of elements");
  scanf("%d",&count);
  printf("Enter the elements..");
  for(i=0;i<count;i++)
       scanf("%d",&h[i]);

  heapify(h,count);
  display(h,count);

   num=maxremove(h,&count);
  printf("The maximum element removed..%d\n",num);
  
  printf("New heap ...\n");
  display(h,count);
 }
  

   //bottom up approach of creating a heap
   void heapify(int *h,int count)
   {
      int k,key,i,j;
     for(k=(count-2)/2;k>=0;k--)//for each parental node
     {
        j=k;
        key=h[k];
        i=2*j+1;
        
        while(i<count)//if the left child exists
        {
          if((i+1)<count)//if right child exists
           {
             if(h[i+1]>h[i])
               i++;//get the index of the largest child
            }            
           if(key<h[i])//compare the key with largest child
            {
              h[j]=h[i];//move the child up if key is less
              j=i;
              i=2*j+1;//get the new left child's index  
             }
             else
              break;
          }
         h[j]=key;
       }
    }


  //top down approach of creating a heap

  void heapify(int *h, int count)
  {
     int i,j,k,key;
     for(k=1;k<count;k++)
     {
       i=k;
       key=h[i];//insert key into the heap
       j=(i-1)/2;//parent of i
       while((i>0)&&(h[j]<key))
       {
         //as long as the parents value is less
         //than key's value
         //move the parent down
        h[i]=h[j];
        i=j;
        j=(i-1)/2;
       }
      h[i]=key;
     }
   }

   void display(int *h, int count)
   {
     int i;
     for(i=0;i<count;++i)
         printf("%d ",h[i]);
   }

  
   int maxremove(int *h, int *count)
   {
     int t;
     t=h[0];
     h[0]=h[*count-1];
     (*count)--;
     adjust(h,*count);
     return t;
   }

  void adjust(int *h, int count)
   {
     int i,j,key;
     
     key=h[0];//get the root element
     j=0;//parent's index
     
     i=2*j+1;//get the left child

     while(i<count)//as long as left child exists
     {
       //check if right child exists
       if((i+1)<count)
       {
         if(h[i+1]>h[i])
             i++;//get the index of the largest child
        }
        if(key<h[i])//if key less than the largest child
        {
          //move the child up  
         h[j]=h[i];           
         j=i;
          i=2*j+1;//get the new index of the left child
         }
         else
          break; 
     }
      h[j]=key;
   } 

 
















  










  

     
  
