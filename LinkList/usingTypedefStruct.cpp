#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
//struct node
{
    int data;
    struct node *next;
    //linkList *next;
} linkList;
linkList *start;
//struct node *start;
void insertAtBegin(int value); // push
void insertAtEnd(int value);   // push_back enqueue
void display();                // traverse list
int maxRepeat();               // count value with max. repeatation
void deleteAtBegin();          //pop dequeue
void deleteAtEnd();            // pop_back
//void sort();
int main()
{
    system("cls");
    cout << "main" << endl;
    insertAtBegin(11);
    insertAtBegin(27);
    insertAtBegin(23);
    insertAtBegin(23);
    insertAtBegin(23);
    insertAtBegin(40);
    insertAtBegin(99);
    insertAtEnd(99);
    display();
    deleteAtBegin();
    display();
    deleteAtEnd();
    //cout << maxRepeat();
    display();
    return 0;
}
// void sort()
// {
//     linkList *displayNode = start;
//     // struct node *displayNode = start;
//     // cout << "display" << endl;
//     int count = 0;
//     while (displayNode != NULL)
//     {
//         //cout << "display in ";
//         //cout << displayNode->data << endl;
//         //displayNode->data
//         ++count;
//         displayNode = displayNode->next;
//     }
//     int arr[count];
//     for(int i=0 ; i< count ; ++i){

//     }
// }
void deleteAtEnd()
{

    if (start == NULL)
    {
        cout << "Nothing to delete" << endl;
    }
    else
    {
        linkList *temp, *previousToTemp;
        temp = start;

        while (temp->next != NULL)
        {
            previousToTemp = temp;
            temp = temp->next;
        }
        previousToTemp->next = NULL;
        cout << temp->data << " Deleted" << endl;
        free(temp);
    }
}
void deleteAtBegin()
{
    linkList *temp;
    if (start == NULL)
    {
        cout << "Nothing to delete" << endl;
    }
    else
    {
        temp = start;
        start = temp->next;
        cout << temp->data << " Deleted" << endl;
        free(temp);
    }
}

void insertAtBegin(int value)
{
    //cout << "insert" << endl;
    linkList *newNode = new linkList;
    // struct node *newNode = new node;
    if (newNode == NULL)
    {
        cout << "Overflow";
    }
    else
    {
        //cout << "insert in" << endl;
        //newNode = start;
        newNode->data = value;
        // if (newNode == NULL)
        // {
        //     newNode->next = NULL;
        //     start = newNode;
        // }
        // else
        newNode->next = start;
        start = newNode;
    }
}
void insertAtEnd(int value)
{
    linkList *temp;
    linkList *newNode = new linkList;
    // struct node *displayNode = start;
    // cout << "display" << endl;
    newNode->data = value;
    if (start == NULL)
    {
        newNode->next = start; //points to NULL
        start = newNode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            //cout << "display in ";
            //cout << newNode->data << endl;
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
void display()
{
    linkList *displayNode = start;
    // struct node *displayNode = start;
    // cout << "display" << endl;
    while (displayNode != NULL)
    {
        cout << "display in ";
        cout << displayNode->data << endl;
        displayNode = displayNode->next;
    }
}
int maxRepeat()
{
    if (start == NULL)
    {
        cout << "Empty list" << endl;
        return 0;
    }
    linkList *displayNode = start;

    // struct node *displayNode = start;
    // cout << "display" << endl;
#if 1
    int count[100] = {0};
    while (displayNode != NULL)
    {
        // cout << "display in ";
        ++count[displayNode->data];
        displayNode = displayNode->next;
    }
    // for (int i = 0; i < 100; ++i)
    // {
    //     cout << i << " " << count[i] << endl;
    // }
    int value, max = count[0];
    for (int i = 0; i < 100; ++i)
    {
        if (max < count[i])
        {
            max = count[i];
            value = i;
            //cout << i << " " << count[i] << endl;
            //cout << "max " << max << " value " << i;
        }
    }
    //cout << "max " << max << " value " << value;
    return value;
#endif
}