#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    char data;
    struct node *next;
} * top;
void push(char data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    struct node *temp;
    if (top == NULL)
    {
        cout << "Empty Stack" << endl;
    }
    else
    {
        temp = top;
        top = temp->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if (top == NULL)
    {
        cout << "empty";
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    system("cls");
    push('1');
    push('2');
    push('3');
    push('4');
    push('5');
    push('6');
    display();
    cout << "--------------" << endl;
    pop();
    display();
}