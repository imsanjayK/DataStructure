#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} linkList;
linkList *start;

void push(int value)
{
    cout << "push" << endl;
    linkList *newNode = new linkList;
    newNode->data = value;
    newNode->next = start;
    start = newNode;
}
void pushBack(int value)
{
    cout << "pushB" << endl;
    linkList *newNode = new linkList;
    linkList *iterator;
    newNode->data = value;
    if (start == NULL)
    {
        // cout << "pushB" << endl;

        newNode->next = NULL;
        start = newNode;
        return;
    }

    iterator = start;

    while (iterator->next)
    {
        iterator = iterator->next;
    }
    iterator->next = newNode;
    newNode->next = NULL;
}
void display()
{
    cout << "display" << endl;
    linkList *iterator;
    iterator = start;
    while (iterator != NULL)
    {
        cout << iterator->data << endl;
        iterator = iterator->next;
    }
}
void deleteAtBegin()
{
    linkList *temp;
    temp = start;
    start = temp->next;
    free(temp);
}
void deleteAtEnd()
{
    linkList *iterator;
    linkList *pItr;
    iterator = start;
    while (iterator->next != NULL)
    {
        pItr = iterator;
        iterator = iterator->next;
    }
    pItr->next = NULL;
    cout << "deleted " << iterator->data;
    free(iterator);
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