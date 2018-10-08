#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct list
{
    int data;
    struct list *next;
} linkList;
linkList *start;

void push(int value)
{
    linkList *newNode = new linkList;
    if (newNode == NULL)
    {
        cout << "start NUll";
    }
    else
    {
        newNode->data = value;
        newNode->next = start;
        start = newNode;
    }
}
void pushBack(int value)
{
    linkList *newNode = new linkList;
    linkList *temp;
    if (newNode == NULL)
    {
        cout << "start NUll";
    }
    else
    {
        newNode->data = value;
        if (start == NULL)
        {
            newNode->next = NULL;
            start = newNode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                // preNode = temp ;
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
}
void display()
{
    linkList *temp;
    if (start == NULL)
    {
        cout << "empty";
        return;
    }
    temp = start;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void deleteAtEnd()
{
    linkList *newNode;
    linkList *temp;

    if (start == NULL)
    {
        cout << "list empty";
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            newNode = temp;
            temp = temp->next;
        }
        newNode->next = NULL;
        free(temp);
    }
}

void deleteAtBegin()
{
    linkList *temp;
    if (start == NULL)
    {
        cout << "list empty";
    }
    else
    {
        temp = start;
        start = temp->next;
        free(temp);
    }
}
int main()
{
    system("cls");
    cout << "main" << endl;
    push(11);
    push(27);
    push(23);
    push(23);
    push(23);
    push(40);
    push(99);
    pushBack(99);
    display();
    cout << "-----------------" << endl;
    deleteAtBegin();
    display();
    cout << "-----------------" << endl;
    deleteAtEnd();
    //cout << maxRepeat();
    display();
    return 0;
}