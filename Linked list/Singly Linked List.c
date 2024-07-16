#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};
struct node *head;

void printList()
{
  if (head==NULL)
	  {
	      printf("\nThe linked list is currently empty!");
	      return;
	  }
  struct node *temp =  head;
  while (temp != NULL)
  {
       printf("%d ->", temp->value);
	temp = temp->next;
  }
  printf("END (for now!)");
}

void insertHead(int num){
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   //insert the new node at the head
   newItem->next = head;
   head = newItem;
}

void insertTail(int num){
   //create a new node to be inserted
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   // set prev to point to the last node of the list
   struct node *temp = head;
   while (temp->next != NULL)
       temp = temp->next;

   temp->next = newItem;
}


void insertatPosition(int num, int pos){
   //create a new node to be inserted
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   // set prev to point to the desired node of the list
   struct node *temp = head;
   for (int i=0;i<pos-1;i++)
   {
       temp = temp->next;
   }

   newItem->next = temp->next;
   temp->next = newItem;
}


void insertAfterValue(int num, int val){
   //create a new node to be inserted
   struct node *newItem;
   newItem=(struct node *)malloc(sizeof(struct node));
   newItem->value = num;
   newItem->next = NULL;
   // set prev to point to the desired node of the list
   struct node *temp = head;
   while (temp->value != val){
       temp = temp->next;
   }
   newItem->next = temp->next;
   temp->next = newItem;
}


void deleteHead()
{
   struct node *temp;
   if (head==NULL)  //list empty
	   return;
   temp = head;  // save head pointer
   head = head->next; //advance head
   free(temp);
}

void deleteTail(){
   if (head==NULL)       //list empty
	   return;
   struct node *temp = head;
   struct node *prev = NULL;
   while (temp->next != NULL){
	   prev = temp;
	   temp = temp->next;
   }
   if (prev != NULL)
  	   prev->next = NULL;
   free(temp);
}


void deletefromPosition(int pos){
   if (head==NULL)       //list empty
	   return;
   struct node *cur = head;
   struct node *prev = NULL;

   for(int i=0;i<pos;i++)
   {
       prev = cur;
	   cur=cur->next;
   }

 if (prev != NULL)
  	   prev->next = cur->next;
 free(cur);
}

void deleteVal(int x){
   if (head==NULL)       //list empty
	   return;
   struct node *temp = head;
   struct node *prev = NULL;
   while (temp->value != x){
	   prev = temp;
	   temp = temp->next;
   }
 if (prev != NULL)
  	   prev->next = temp->next;
 free(temp);
}



int main()
{

    head=NULL;
    printf("FUNCTION !!!\n");
    while(1)
    {
        int ch, num, pos, val;
        printf("\n\n01.Insert First\n02.Insert Last\n03.Insert Middle (Any other pos)\n04.Insert After a Target Val\n05.Delete Head\n06.Delete Tail\n07.Delete from a Position\n08.Delete a Value\n09.Print\n10.Search\n11.Add a function for practice \n12.Exit\n\nEnter Choice: ");
        scanf("%d", &ch);

        if(ch==1)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertHead(num);
        }
        else if (ch==2)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertTail(num);
        }
        else if (ch==3)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Position to insert: ");
            scanf("%d", &pos);
            insertatPosition(num, pos);
        }

        else if(ch==4)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Value to insert after: ");
            scanf("%d", &val);
            insertAfterValue(num, val);
        }

        else if(ch==5)
        {
            deleteHead();
        }
        else if(ch==6)
        {
            deleteTail();
        }
        else if(ch==7)
        {
            printf("\nEnter Position to Delete from: ");
            scanf("%d", &pos);
            deletefromPosition(pos);
        }
        else if (ch==8)
        {
            printf("\nEnter Value to delete: ");
            scanf("%d", &val);
            deleteVal(val);
        }

        else if(ch==9)
        {
            printList();
        }

        else if(ch==10)
        {
            //IMPLEMENT LINEAR SEARCH
        }

        else if(ch==11)
        {
            //ADD YOUR OWN FUNCTION - PRACTICE
        }

        else if(ch==12)
        {
            printf("\n\n\t\tProgram Terminated\n\n");
            break;
        }

        else
        {
            printf("\n\n\t\tWrong choice. Enter again. ");
        }
    }
    return 0;
}

