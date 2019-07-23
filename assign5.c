#include <stdio.h>
#include <stdlib.h>

struct node
{
   int info;
   struct node *next;
};

typedef struct node node;

node *inserthead(node *head, int a);
void printlist(node *head);
void freelist(node *head);

node *CopyList(node *head);
node *Previous(node *head, node *current);
void PrintReverse(node *head);

int main()
{
   node *ptr=NULL;
   node *ptr2=NULL;
   int i;

   for (i = 0; i<10; i++)
       ptr = inserthead(ptr, rand() % 100);

   printlist(ptr);

   ptr2 = CopyList(ptr);
   printlist(ptr2);
   PrintReverse(ptr2);

   freelist(ptr);
   freelist(ptr2);
}

node *inserthead(node *head, int a)
{

   node *ptr;

   ptr = (node*)malloc(sizeof(node));
   ptr->info = a;
   ptr->next = head;

   return(ptr);
}


void printlist(node *head)
{
   while (head != NULL)
   {
       printf("%d ", head->info);
       head = head->next;
   }
   printf("\n");
}

void freelist(node *head)
{
   node *ptr = head;
   while (head != NULL)
   {
       head = head->next;
       free(ptr);
       ptr = head;
   }
}

node *CopyList(node *head)
{
   node *prev, *cur, *newlist = NULL;

   prev = NULL;

   printf("\n");
  
   while (head != prev) {
       cur = head;

       while (cur->next != prev) {
           cur = cur->next;
       }
       prev = Previous(head, cur);

       newlist = inserthead(newlist, cur->info);
       prev = cur;
   }

   return newlist;
}

node *Previous(node *head, node *current)
{
   node *prev = NULL;
   if (head == NULL || current == head)
   {
       return NULL;
   }
   while (head != current)
   {
       prev = head;
       head = head->next;
   }
   return prev;
}

void PrintReverse(node *head)
{
   node *prev, *cur;

   prev = NULL;

   printf("\n");
   while (head != prev) {
       cur = head;

       while (cur->next != prev) {
           cur = cur->next;
       }
       prev = Previous(head, cur);

       printf("%d ", cur->info);
       prev = cur;
   }

   printf("\n");
}
