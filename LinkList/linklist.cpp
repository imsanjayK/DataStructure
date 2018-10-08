#include <cstdlib> // malloc include
#include <iostream>
using namespace std;
//#define size 10
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insertAtBegin(int value)
{
    //struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = new node;
    if (ptr == NULL)
    {
        cout << "Overflow";
    }
    else
    {
        ptr->data = value;
        ptr->next = head;
        head = ptr;
    }
}
void insertAtEnd(int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL)
    {
        cout << "Overflow";
    }
    else
    {
        ptr->data = value;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}
void insertAtGivenPosition(int value, int pos)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL)
    {
        cout << "Overflow";
    }
    else
    {
        ptr->data = value;
        temp = head;
        for (int nodeIndex = 1; nodeIndex < pos - 1; nodeIndex++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Can't insert" << endl;
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void deleteAtBegin()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "Empty list" << endl;
    }
    else
    {
        ptr = head;
        head = ptr->next;
        cout << ptr->data << " Deleted" << endl;
        free(ptr);
    }
}
void deleteAtEnd()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        cout << "Empty list" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        cout << temp->data << " Deleted" << endl;
        free(temp);
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " | ";
        temp = temp->next;
    }
}
int main()
{
    system("cls");
    int choice = 0, x, pos;
    while (choice != 9)
    {
        printf("Choose one option from the following list ...\n");
        printf("===============================================");
        printf("\n1.Insert in begining 2.Insert at last 3.Insert at any random location\n4.Delete from Beginning 5.Delete from last  6.Delete node after specified location\n7.Search for an element 8.Show 9.Exit\n");
        printf("\nEnter your choice?\n");
        cin >> choice;
        switch (choice)
        {
        case 1:
            printf("\nEnter : ");
            cin >> x;
            insertAtBegin(x);
            break;
        case 2:
            printf("\nEnter : ");
            cin >> x;
            insertAtEnd(x);
            break;
        case 3:
            printf("\nEnter : ");
            cin >> x;
            printf("\nEnter pos : ");
            cin >> pos;
            insertAtGivenPosition(x, pos);
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            //    deleteAtGivenPosition();
            break;
        case 7:
            //    search();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }

    // display();
}