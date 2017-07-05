#include<stdio.h>
#include<stdlib.h>
struct node
{
 int element;
 struct node *prev,*next;
}*s,*t,*b;
int isempty();
int push();
int pop();
int top();
int show();
int main()
{
 int ch,z;
 do
 {
  printf("\n1.push");
  printf("\n2.pop");
  printf("\n3.top");
  printf("\n4.show");
  printf("\nEnter ur choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    push();
    show();
   break;
   case 2:
    pop();
    show();
   break;
   case 3:
    top();
   break;
   case 4:
    show();
   break;
   default:
    printf("\nEnter the correct choice");
   break;
  }
  printf("\nPress 1 to contn:");
  scanf("%d",&z);
 }while(z==1);
 return 0;
}

int push()
{
 int num;
 printf("Enter the element:");
 scanf("%d",&num);
 t=malloc(sizeof(struct node));
 if(t==NULL)
 printf("\nStack is full");
 else
 {
  if(s==NULL)
  {
   t->element=num;
   t->next=NULL;
   t->prev=NULL;
   s=t;
  }
  else
  {
   t->element=num;
   t->next=s;
   t->prev=NULL;
   s->prev=t;
   s=t;
  }
 }
}

int pop()
{
 if(s==NULL)
 printf("\nStack is empty");
 else
 {
  b=s;
  s=s->next;
  if(s==NULL)
  free(b);
  else
  {
   s->prev=NULL;
   free(b);
  }
 }
}

int top()
{
 if(s==NULL)
 printf("\nStack is empty");
 else
 printf ("%d",s->element);
}

int show()
{
 if(s==NULL)
 printf("\nStack is empty");
 else
 b=s;
 while(b!=NULL)
 {
  printf("\n|%d|",b->element);
  b=b->next;
 }
}
