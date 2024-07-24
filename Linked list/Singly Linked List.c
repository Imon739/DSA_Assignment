#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *head;

void printList()
{
    if (head==NULL)
    {
        printf("\nThe linked list is currently empty!\n");
        return;
    }
    struct node *temp =  head;
    while (temp != NULL)
    {
        printf("%d ->", temp->value);
        temp = temp->next;
    }
    printf("END (for now!)\n");
}

void insertHead(int num)
{
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = num;
    newItem->next = NULL;
    //insert the new node at the head
    newItem->next = head;
    head = newItem;
}

void insertTail(int num)
{
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


void insertatPosition(int num, int pos)
{
    //create a new node to be inserted
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = num;
    newItem->next = NULL;
    // set prev to point to the desired node of the list
    struct node *temp = head;

    int size = size_of_list();
    if(pos < 1 || pos > size)
    {
        printf("Invalid position !!!");
        return;
    }
    else
    {
        if(pos == 1)
        {
            insertHead(num);
            return;
        }
        else
        {
            for (int i=1; i<pos-1; i++)
            {
                temp = temp->next;
            }
            newItem->next = temp->next;
            temp->next = newItem;
        }
    }
}


void insertAfterValue(int num, int val)
{
    //create a new node to be inserted
    struct node *newItem;
    newItem=(struct node *)malloc(sizeof(struct node));
    newItem->value = num;
    newItem->next = NULL;
    // set prev to point to the desired node of the list
    struct node *temp = head;
    while(temp != NULL && temp->value != val){
        temp = temp->next;
    }
    if (temp == NULL)
        printf("\n%d is not present in the list ", val);
    else
    {
    newItem->next = temp->next;
    temp->next = newItem;
    }
}

void deleteHead()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nThe linked list is currently empty!\n");
        return;
    }
    temp = head;  // save head pointer
    head = head->next; //advance head
    free(temp);
}

void deleteTail()
{
    if(head==NULL)
    {
        printf("\nThe linked list is currently empty!\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    free(temp);
}


void deletefromPosition(int pos)
{
    if (head==NULL)
    {
        printf("\nThe linked list is currently empty!\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for(int i=0; i<pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL)
        prev->next = temp->next;
    free(temp);
}

void deleteVal(int x)
{
    if (head==NULL)
        printf("\nThe linked list is currently empty!\n");
    return;
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp->value != x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
        prev->next = temp->next;
    free(temp);
}

void search(int num)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->value == num)
        {
            printf("Value %d found at position %d.\n", num, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Value %d not found in the list.\n", num);
}

int size_of_list()
{
    int count = 0;
    struct node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_nth_occurance(int num, int n)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->value == num)
        {
            count++;
        }
        temp = temp->next;
        if(count == n)
        {
                struct node *temp = head;
                struct node *prev = NULL;

                for(int i=0; i<n; i++)
                {
                    prev = temp;
                    temp = temp->next;
                }

                if (prev != NULL)
                    prev->next = temp->next;
                free(temp);
        }
    }

}
int main()
{
    head=NULL;
    printf("FUNCTION !!!\n");
    int ch, num, pos, val;
    while(1)
    {
        printf("\n01.Insert First\n02.Insert Last\n03.Insert Middle (Any other pos)\n04.Insert After a Target Val");
        printf("\n05.Delete Head\n06.Delete Tail\n07.Delete from a Position\n08.Delete a Value \n12.Delete nth occurance ");
        printf("\n09.Print\n10.Search\n11.Size of LInked list");
        printf("\n13.Exit\n\nEnter Choice: ");
        scanf("%d", &ch);

        if(ch == 1)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertHead(num);
        }
        else if (ch == 2)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertTail(num);
        }
        else if (ch == 3)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Position to insert: ");
            scanf("%d", &pos);
            insertatPosition(num, pos);
        }

        else if(ch == 4)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Value to insert after: ");
            scanf("%d", &val);
            insertAfterValue(num, val);
        }

        else if(ch == 5)
        {
            deleteHead();
        }
        else if(ch == 6)
        {
            deleteTail();
        }
        else if(ch == 7)
        {
            printf("\nEnter Position to Delete from: ");
            scanf("%d", &pos);
            deletefromPosition(pos);
        }
        else if (ch == 8)
        {
            printf("\nEnter Value to delete: ");
            scanf("%d", &val);
            deleteVal(val);
        }

        else if(ch == 9)
        {
            printList();
        }

        else if(ch == 10)
        {
            printf("Enter value you want to search : ");
            scanf("%d", &num);
            search(num);
        }

        else if(ch == 11)
        {
            int size = size_of_list();
            printf("Size of list is %d ",size);
        }

        else if(ch == 12)
        {
            int value, n;
            printf("\nEnter the value you want to delete: ");
            scanf("%d", &value);
            printf("\nEnter the value of n: ");
            scanf("%d", &n);
            delete_nth_occurance(value, n);
        }
        else if (ch == 13)
        {
            printf("\nProgram Terminated\n\n");
            break;
        }
        else
        {
            printf("\nWrong choice. Enter again. ");
            return;
        }
    }
    return 0;
}
