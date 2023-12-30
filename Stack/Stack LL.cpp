#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *top;

void push(int);
void pop();
void display();

int main()
{
    int choice, n, m, i;
    top = NULL;

    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "How many nodes do you want: ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Enter the element: ";
                cin >> m;
                push(m);
            }
            break;

        case 2:
            if (top == NULL)
            {
                cout << "List is empty" << endl;
                continue;
            }
            pop();
            break;

        case 3:
            display();
            break;

        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}

void push(int data)
{
    struct node *tmp = new node;
    tmp->info = data;
    tmp->link = top;
    top = tmp;
}

void pop()
{
    if (top == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    struct node *tmp = top;
    cout << "Popped element: " << top->info << endl;
    top = top->link;
    delete tmp;
}

void display()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    struct node *tmp = top;

    cout << "Stack elements: ";
    while (tmp != NULL)
    {
        cout << tmp->info << " ";
        tmp = tmp->link;
    }
    cout << endl;
}
