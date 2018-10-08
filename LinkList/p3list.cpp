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
    newNode->data = value;
    newNode->next = start;
    start = newNode;
}
void pushBack(int value)
{
    linkList *newNode = new linkList;
    linkList *iterator;
    if (start == NULL)
    {
        newNode = start;
        newNode->next = NULL;
    }
    else
    {
        iterator = start;
        while (iterator->next)
        {
            iterator = iterator->next;
        }
        iterator->next = newNode;
        newNode->data = value;
        newNode->next = NULL;
    }
}
void display()
{
    linkList *iterator;
    if (start == NULL)
    {
        cout << "empty";
    }
    else
    {
        iterator = start;
        while (iterator)
        {
            cout << iterator->data << endl;
            iterator = iterator->next;
        }
    }
}
void pop()
{
    linkList *newNode;
    if (start == NULL)
    {
        cout << "empty";
    }
    else
    {
        newNode = start;
        start = newNode->next;
        free(newNode);
    }
}
void popBack()
{
    linkList *iterator;
    linkList *pItr;
    if (start == NULL)
    {
        cout << "empty";
    }
    else
    {
        iterator = start;
        while (iterator->next)
        {
            //cout << iterator->data << endl;
            pItr = iterator;
            iterator = iterator->next;
        }
        pItr->next = NULL;
        free(iterator);
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
    cout << "--------------" << endl;
    pop();
    display();
    cout << "--------------" << endl;
    popBack();
    //cout << maxRepeat();
    display();
    return 0;
}