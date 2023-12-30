#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *prev;
    struct node *next;
} *start = NULL, *last = NULL;

void create_list(int data);
void replace();
void display();

int main()
{
    int choice, n, m, i;
    start = NULL;
    last = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Replace last node" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many nodes do you want: ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Enter element " << (i + 1) << ": ";
                cin >> m;
                create_list(m);
            }
            break;
        case 2:
            replace();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

void create_list(int data)
{
    struct node *tmp;
    tmp = new struct node;
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (start == NULL)
    {
        start = tmp;
        last = tmp;
    }
    else
    {
        last->next = tmp;
        tmp->prev = last;
        last = tmp;
    }
}

void replace()
{
    if (start == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    struct node *q = last;
    last = last->prev;
    last->next = NULL;
    q->next = start;
    q->prev = NULL;
    start->prev = q;
    start = q;
}

void display()
{
    struct node *q = start;
    if (q == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    cout << "List is:" << endl;
    while (q != NULL)
    {
        cout << q->info << "   ";
        q = q->next;
    }
    cout << endl;
}