#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *prev;
    struct node *next;
} *start = NULL;

void create_list(int data);
void copy();
void display();

int main()
{
    int choice, n, m, i;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Copy" << endl;
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
            copy();
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
    struct node *tmp = new struct node;
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        struct node *q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
    }
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

void copy()
{
    struct node *ptr1 = start;
    struct node *ptr2 = NULL;
    struct node *ptr3 = NULL;

    while (ptr1 != NULL)
    {
        struct node *tmp = new struct node;
        tmp->info = ptr1->info;
        tmp->prev = NULL;
        tmp->next = NULL;

        if (ptr2 == NULL)
        {
            ptr2 = tmp;
            ptr3 = tmp;
        }
        else
        {
            ptr3->next = tmp;
            tmp->prev = ptr3;
            ptr3 = tmp;
        }

        ptr1 = ptr1->next;
    }

    cout << "Copied List:" << endl;
    struct node *q = ptr2;
    while (q != NULL)
    {
        cout << q->info << "   ";
        q = q->next;
    }
    cout << endl;
}