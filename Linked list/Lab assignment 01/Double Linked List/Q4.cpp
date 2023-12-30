#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *prev;
    struct node *next;
} *start = NULL;

void create_list(int data);
void replace();
void display();

int main()
{
    int choice, n, m, i;
    start = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Replace 1st node" << endl;
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
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
    }
}

void replace()
{
    struct node *q, *tmp;

    if (start->next == NULL)
    {
        cout << "There's only one node in the list!" << endl;
        return;
    }
    q = start;
    while (q->next != NULL)
    {
        q = q->next;
    }
    tmp = new struct node;
    tmp->info = start->info;
    tmp->prev = q;
    tmp->next = NULL;
    q->next = tmp;
    start = start->next;
    start->prev = NULL;
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