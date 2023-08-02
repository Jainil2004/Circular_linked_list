#include <stdio.h>
#include <stdlib.h>

/*
GOAL OF THIS CODE:
Create a fully functional circular linked list
1. there should be a function for adding a node in the list wherever the user wants.
2. there should be a function for deletion of a node in the list.
3. there should be a function for printing the circular linked list from the element given by the user.
4. there should be a function to find if a particular node is present in the list or not.
5. there should be a function to find out the number of nodes in the list.
6. there should be a function to find out if the list is empty or not.
7. there should be a function that changes the reference to the list.
*/

struct node {
    int data;
    struct node* next;
};

struct node* list_initializer(int node1_data, int node2_data, int node3_data, int node4_data)
{
    struct node* node1 = (struct node*) malloc(sizeof(struct node));
    struct node* node2 = (struct node*) malloc(sizeof(struct node));
    struct node* node3 = (struct node*) malloc(sizeof(struct node));
    struct node* node4 = (struct node*) malloc(sizeof(struct node));

    if (node1 != NULL)
    {
        node1->data = node1_data;
        node1->next = node2;
    }
    if (node2 != NULL)
    {
        node2->data = node2_data;
        node2->next = node3;
    }
    if (node3 != NULL)
    {
        node3->data = node3_data;
        node3->next = node4;
    }
    if (node4 != NULL)
    {
        node4->data = node4_data;
        node4->next = node1;
    }

    return node1;
}

void node_adder(struct node** ref, int new_node_data, int node_finder_data)
{
    struct node* ptr = *ref;

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_node_data;

    do
    {
        if (ptr->data == node_finder_data)
        {
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
        ptr = ptr->next;
    } while (ptr->next != (*ref)->next);

    *ref = new_node;
}

void node_deleter(struct node** ref, int node_finder_data)
{
    if (*ref != NULL)
    {
        struct node* ptr = *ref;

        do
        {
            if (ptr->next->data == node_finder_data)
            {
                struct node* temp = ptr->next;
                printf("node with data = \'%d\' deleted.\n", temp->data);
                ptr->next = ptr->next->next;
                *ref = ptr->next;
                free(temp);

                return;
            }
            ptr = ptr->next;
        } while (ptr->next != (*ref)->next);
    }
    else
    {
        printf("list is empty. Nothing to delete.\n");
    }
}

void list_printer(struct node* ref)
{
    struct node* ptr = ref;
    printf("ref -> ");

    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr->next != ref->next);

    printf("ref\n");
}

void node_checker(struct node* ref, int node_finder_data)
{
    struct node* ptr = ref;
    int position = 1;

    do
    {
        if (ptr->data == node_finder_data)
        {
            printf("node with data = \'%d\' found in list at %d position.\n", node_finder_data, position);
            return;
        }
        ptr = ptr->next;
        position = position + 1;
    } while (ptr->next != ref->next);

    printf("node with data = \'%d\' not found in the list.\n", node_finder_data);
}

int node_counter(struct node* ref)
{
    struct node* ptr = ref;
    int counter = 0;

    do
    {
        counter = counter + 1;
        ptr = ptr->next;
    } while (ptr->next != ref->next);

    // printf("total number of nodes found in the list = \'%d\'", counter);
    return counter;
}

void list_empty_checker(struct node** ref)
{
    if (*ref != NULL)
    {
        printf("list is not empty. at present there are %d nodes in the list\n", node_counter((*ref)));
    }
    else
    {
        printf("list is empty.\n");
    }
}

void ref_changer(struct node** ref, int node_finder_data)
{
    struct node* ptr = *ref;

    do
    {
        if (ptr->data == node_finder_data)
        {
            printf("node with data = \'%d\' found. Reference point changed!\n", node_finder_data);
            *ref = ptr;
            return;
        }
        ptr = ptr->next;
    } while (ptr->next != (*ref)->next);
    printf("node with data = \'%d\' not found! reference change aborted.\n", node_finder_data);
}

int main()
{
    struct node* ref = NULL;
    int node1_data, node2_data, node3_data, node4_data;
    int new_node_data;
    int node_finder_data;
    int mode;
    int test_setup;

    printf("this program depicts the implementation of a circular linked list.\n");

    printf("following are the Options avaliable for list manipulation:\n1.Initialize List.\n2.Add a node in the list.\n3.delete a node from the list.\n4.check if a node is present in the list\n5.check the number of nodes present in the list\n6.check if the list is empty\n7.change reference in the list\n8.Print the circular linked list\n9.Re-print the manipulation panel.\n10.EXIT\n");
    
    while(mode != 10)
    {
    printf("please enter the operation you want to perform\n");
    scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            printf("do you want to load the test setup?\n");
            scanf("%d", &test_setup);

            if (test_setup == 1)
            {
                printf("test setup loaded successfully\n");
                node1_data = 10;
                node2_data = 20; 
                node3_data = 30;
                node4_data = 40;
            }
            else
            {
                printf("please enter the node data\n");
                printf("node1 data:\n");
                scanf("%d", &node1_data);
                printf("node2 data:\n");
                scanf("%d", &node2_data);
                printf("node3 data:\n");
                scanf("%d", &node3_data);
                printf("node4 data:\n");
                scanf("%d", &node4_data);
            }
            ref = list_initializer(node1_data, node2_data, node3_data, node4_data); 

            break;
        case 2:
            printf("\nThis will add a new node in the list.\n");
            printf("please enter the data for the new node");
            scanf("%d", &new_node_data);
            printf("please enter the data of the node after which you would like to add the new node.\n");
            scanf("%d", &node_finder_data);

            node_adder(&ref, new_node_data, node_finder_data);
            
            break;
        case 3:
            printf("\nThis will delete a node from the list\n");
            printf("please enter the data of the node you would like to delete.\n");
            scanf("%d", &node_finder_data);

            node_deleter(&ref, node_finder_data);

            break;
        case 4:
            printf("please enter the data of the node you would like to check for in the list.\n");
            scanf("%d", &node_finder_data);

            node_checker(ref, node_finder_data);

            break;
        case 5:
            printf("total number of nodes found in the list = \'%d\'", node_counter(ref));

            break;
        case 6:
            list_empty_checker(&ref);

            break;
        case 7:
            printf("\nthis will change the reference point in the list.\n");
            printf("please enter the data of the node you would like to make the new ref. point\n");
            scanf("%d", &node_finder_data);

            ref_changer(&ref, node_finder_data);

            break;
        case 8:
            list_printer(ref);

            break;
        case 9:
            printf("following are the Options avaliable for list manipulation:\n1.Re-Initialize List.\n2.Add a node in the list.\n3.delete a node from the list.\n4.check if a node is present in the list\n5.check the number of nodes present in the list\n6.check if the list is empty\n7.change reference in the list\n8.Print the circular linked list\n9.Re-print the manipulation panel.\n10.EXIT\n");

            break;
        case 10: 
            goto exit;

            break;
        default:
            printf("operation not found!!! please check the operations list and try again.\n");
            break;
        }
    }

    exit:
    return 0;  
}


/*
    **FOR TESTING ONLY**
    ref = list_initializer(10, 20, 30, 40);
    list_printer(ref);
    node_adder(&ref, 555, 40);
    list_printer(ref);
    node_checker(ref, 41);
    node_deleter(&ref, 555);
    list_printer(ref);
    node_counter(ref);
    list_empty_checker(&ref);
    ref_changer(&ref, 40);
    list_printer(ref);

*/