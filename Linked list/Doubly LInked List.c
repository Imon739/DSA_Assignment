#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;

void forward_traversal()
{
    if (head==NULL)
    {
        return;
    }
    struct node *temp =  head;
    while(temp != NULL)
    {
        printf("%d ->",temp->value);
        temp = temp->next;
    }
    printf(" end\n");
}

void backward_traversal()
{
    if (head==NULL)
    {
        return;
    }
    struct node *temp =  tail;
    while(temp != NULL)
    {
        printf("%d ->",temp->value);
        temp = temp->prev;
    }
    printf(" end\n");
}

void insertFirst(int num)
{
    struct node *newItem;
    newItem = (struct node *) malloc(sizeof(struct node));
    newItem->value = num;
    newItem->prev = NULL;

    if(head == NULL)
    {
        head = newItem;
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }
    else
    {
        newItem->next = head;
        head->prev = newItem;
        head = newItem;
    }
}

void insertTail(int num)
{
    struct node *newItem;
    newItem = (struct node *) malloc(sizeof(struct node));
    newItem->value = num;
    newItem->next = NULL;
    if(head==NULL)
    {
        head = newItem;
        newItem->prev = NULL;
        newItem->next = NULL;
        tail = head;
    }
    else
    {
        tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        tail->next = newItem;
        newItem->prev = tail;
        tail = newItem;
    }
}


void insert_after_value(int num, int x)
{
    struct node *newItem, *temp, *temp1;
    newItem = (struct node *) malloc(sizeof(struct node));
    newItem->value = num;
    if(head==NULL)
    {
        head = newItem;
        newItem->prev = NULL;
        newItem->next = NULL;
        tail = head;
    }
    else
    {
        temp = head;
        while(temp != NULL && temp->value != x){
            temp = temp->next;
        }
        if (temp == NULL)
            printf("\n %d is not present in the list ", x);
        else
        {
            temp1 = temp->next;
            newItem->prev = temp;
            newItem->next = temp1;
            temp1->prev = newItem;
            temp->next = newItem;
        }
    }
}

void insert_position(int num, int pos)
{
    struct node *newItem, *temp;
    newItem = (struct node *) malloc(sizeof(struct node));
    newItem->value = num;

    if(pos == 1)
    {
        insertFirst(num);
        return;
    }

    temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newItem);
        return;
    }

    newItem->next = temp->next;
    newItem->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = newItem;
    }
    temp->next = newItem;

    if(newItem->next == NULL)
    {
        tail = newItem;
    }
}

void delete_head()
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->next;

    if(head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }
    free(temp);
}
void delete_tail()
{
    if(tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = tail;
    tail = tail->prev;

    if(tail != NULL)
    {
        tail->next = NULL;
    }
    else
    {
        head = NULL;
    }
    free(temp);
}

void deletefromPosition(int pos)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos == 1)
    {
        delete_head();
        return;
    }

    struct node *temp = head;
    for(int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if(temp == tail)
    {
        tail = temp->prev;
    }

    free(temp);
}

void delete_value(int num)
{
    struct node *temp = head;

    while(temp != NULL && temp->value != num)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("%d not found in the list\n", num);
        return;
    }
    if(temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }
    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        tail = temp->prev;
    }
    free(temp);
}

void delete_nth_occurance(int num, int n)
{
    struct node *temp = head;
    int count = 0;

    while(temp != NULL)
    {
        if(temp->value == num)
        {
            count++;
            if(count == n)
            {
                if(temp->prev != NULL)
                {
                    temp->prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }

                if(temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                else
                {
                    tail = temp->prev;
                }

                free(temp);
                return;
            }
        }
        temp = temp->next;
    }
    printf("The %dth occurrence of %d not found in the list\n", n, num);
}

void search(int num) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->value == num) {
            printf("Value %d found at position %d.\n", num, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Value %d not found in the list.\n", num);
}

int main()
{
    head = NULL;
    tail = NULL;
    int choice, num;

    while(1)
    {
        printf("\n01.Forward Traversal \n02.Backward Traversal \n03.Insert First \n04.Insert Last \n05.Insert After a val \n06.Insert at a pos \n07.Delete head\n08.Delete tail \n09.Delete from a Position\n10.Delete a Value \n11.Delete nth occurance \n12.Search \n13.EXIT\n\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nAfter traversal : ");
            forward_traversal();
        }
        else if(choice == 2)
        {
            printf("\nAfter traversal : ");
            backward_traversal();
        }
        else if(choice == 3)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertFirst(num);
        }
        else if(choice == 4)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insertTail(num);
        }
        else if(choice == 5)
        {
            int x;
            printf("\nEnter the value of X: ");
            scanf("%d", &x);
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insert_after_value(num, x);
        }
        else if(choice == 6)
        {
            int pos;
            printf("\nEnter the position: ");
            scanf("%d", &pos);
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            insert_position(num, pos);
        }
        else if(choice == 7)
        {
            delete_head();
        }
        else if(choice == 8)
        {
            delete_tail();
        }
        else if(choice == 9)
        {
            int pos;
            printf("\nEnter position: ");
            scanf("%d", &pos);
            deletefromPosition(pos);
        }
        else if(choice == 10)
        {
            int value;
            printf("\nEnter the value you want to delete: ");
            scanf("%d", &value);
            delete_value(value);
        }
        else if(choice == 11)
        {
            int value, n;
            printf("\nEnter the value you want to delete: ");
            scanf("%d", &value);
            printf("\nEnter the value of n: ");
            scanf("%d", &n);
            delete_nth_occurance(value, n);
        }

        else if(choice == 12)
        {
            printf("\nEnter the value you want search: ");
            scanf("%d", &num);
            search(num);
        }
        else if(choice == 13)
        {
            printf("Thank You !!!\n\n");
            break;
        }
        else
        {
            printf("Wrong choice, enter again");
        }
    }
    return 0;
}
