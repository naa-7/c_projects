#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct node 
{
    int key;
    int value;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;
node *temp = NULL;
node *current = NULL;


void push(node **head, int key, int value);
void append(node **head, int key, int value);
void print(node *head, node *tail);
int *delete(int key);
void print_list();
void print_list_in_reversed_order(node *head);
void is_empty();
void length();



void push(node **head, int key, int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new_node;
        
    (*head) = new_node;
}
    

void append(node **head, int key, int value) {
    
    node *new_node = (node*)malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if ((*head) == NULL)
    {
        new_node->prev = NULL;
        (*head) = new_node;
        return;
    }

    tail = (*head);

    while (tail->next !=NULL)
        tail = tail->next;

    tail->next = new_node;
    tail->prev = temp; //new_node->prev = temp;
}

void print(node *head, node *tail) 
{
    if (head == NULL)
        is_empty();
    else
    {
        if (tail == NULL)
        {
            printf("HEAD POSITION:[ (%d->%d) ]\n", head->key,head->value);  
            printf("TAIL POSITION:[ (%d->%d) ]\n", head->key,head->value);  
            printf("#############################################\n");

        }
        else {
            printf("HEAD POSITION:[ (%d->%d) ]\n", head->key,head->value);  
            printf("TAIL POSITION:[ (%d->%d) ]\n",tail->next->key,tail->next->value);
            printf("#############################################\n");
        }
    }
}

int *delete(int key)
{
    current = head;
    if (head == NULL)
    {
        printf("EMPTY LIST!\n");
        printf("#############################################\n");
        return (NULL);
    } 
    
    while (current->key != key)
    {
        if (current->next == NULL)
        {
            printf("ELEMENT NOT FOUND!\n");
            printf("#############################################\n");
            return (NULL);
        }

        else
        {
            temp = current;
            current = current->next;
        }
    }
    
    if (current == head)
        head = head->next;
    
    else
        temp->next = current->next;
   
    printf("DELETED VALUE:[ (%d->%d) ]\n",current->key,current->value);
    printf("#############################################\n");
       
    return 0;
}

void print_list()
{
    temp = head;
    printf("Linked list:\n[ ");
    while (temp != NULL)
    {
        printf("(%d->%d) ",temp->key, temp->value);
        temp = temp->next;
    }
    printf("]\n");
    printf("#############################################\n");
}

void print_list_in_reversed_order(node *head)
{
    if (head == NULL)
        return;
    print_list_in_reversed_order(head->next);
    printf("(%d->%d) ", head->key, head->value);
}

void is_empty() 
{
    if (head == NULL) {
        printf("EMPTY LIST!\n");
        printf("#############################################\n");
    }
}

void length()
{
    int length = 0;
    for (current  = head;  current != NULL; current = current->next)
    {
        ++length;
    }
    printf("LIST SIZE:[ %d ]\n", length);
    printf("#############################################\n");
    
}

int main(int argc, char const *argv[])
{
 
    int i =1, number, value;
    printf("\n##############################################################################\n");
    printf("###########################  LINKED LIST UTILITY  ############################\n");
    printf("##############################################################################\n\n");
    start:printf(" OPTIONS:\n");
    printf(" -----------------------------------------------------------------------------\n");
    printf("|  -------------------------------------------------------------------------  |\n");
    printf("| |                                                                         | |\n");
    printf("| |   [1] MAKE LIST     [2] PRINT LIST          [3] PRINT REVERSED LIST     | |\n");
    printf("| |   [4] APPEND LIST   [5] DELETE ELEMENT      [6] PUSH NEW HEAD ELEMENT   | |\n");
    printf("| |   [7] DELETE LIST   [8] CHECK SIZE OF LIST  [9] HEAD & TAIL POSTION     | |\n");
    printf("| |   [10] Quit                                                             | |\n");
    printf("| |                                                                         | |\n");
    printf("|  -------------------------------------------------------------------------  |\n");
    printf(" -----------------------------------------------------------------------------\n");
    printf(" ANSWER: ");
    while(scanf("%d",&number)) {
      printf("\n#############################################\n");

      switch (number)
      {
        case 1:
            if (head == NULL)
            {
                printf("ENTER HEAD ELEMENT OF LIST: ");
                scanf("%d",&value);
                push(&head,i,value);
                printf("#############################################\n");
            }
            else 
            {
                printf("* WARNING: LIST IS NOT EMPTY *\nPRESS [7] TO DELETE CURRENT LIST\n");
                printf("#############################################\n");
            }
            i++;
            goto start;

        case 2:
            if (head == NULL)
                is_empty();
            else 
                print_list();
            goto start;
        
        case 3:
            if (head == NULL)
                is_empty();
            else 
            {
            printf("[ ");
            print_list_in_reversed_order(head); 
            printf("]\n");
            printf("#############################################\n");
            }
            goto start;
            

        case 4:
            if (head == NULL) 
                is_empty();
            
            else
            {   
                int element, size; 
                printf("ENTER NUMBER OF ELEMENTS TO APPEND: ");
                scanf("%d",&size);
                printf("ENTER ELEMENT: ");
                for (int count = 0; count < size; count++)
                {
                    scanf("%d", &element);
                    append(&head,i,element);
                    ++i;
                }
                printf("#############################################\n");
            
            }
           
            goto start;

        case 5:
            if (head == NULL) 
            {
                printf("LIST IS EMPTY!!\n");
                printf("#############################################\n");
            }
            else
            {
                printf("ENTER KEY OF ELEMENT: ");
                scanf("%d",&value);
                delete(value);
            }
            goto start;

        case 6:
            printf("ENTER ELEMENT: ");
            scanf("%d",&value);
            push(&head,i,value);
            printf("#############################################\n");
            i++;
            goto start;

        case 7:
            head = NULL;
            printf("LIST IS EMPTY!!\n");
            printf("#############################################\n");
            i = 1;
            goto start;

        case 8:
            length();
            goto start;
        
        case 9:
            print(head,tail);
            goto start;

        default:
            printf("##############################################################################\n");
            printf("############################## END OF PROGRAM ################################\n");
            printf("##############################################################################\n");

            break;
        
      }
      if (number > 10)
        goto start;
      else 
        break;
    }
    return 0;
}
