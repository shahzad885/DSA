#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
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
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL)
    {
        start = tmp;
        start->link = start;
    }
    else
    {
        q = start;
        while (q->link != start)
        {
            q = q->link;
        }
        q->link = tmp;
        tmp->link = start;
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
    do
    {
        cout << q->info << "   ";
        q = q->link;
    } while (q != start);
    cout << endl;
}

void copy()
{
    if (start == NULL)
    {
        cout << "List is empty. Cannot copy." << endl;
        return;
    }

    struct node *ptr1 = start;
    struct node *ptr2 = NULL;
    struct node *ptr3 = NULL;

    do
    {
        struct node *tmp;
        tmp = new struct node;
        tmp->info = ptr1->info;
        tmp->link = NULL;

        if (ptr2 == NULL)
        {
            ptr2 = tmp;
            ptr3 = tmp;
        }
        else
        {
            ptr3->link = tmp;
            ptr3 = tmp;
        }

        ptr1 = ptr1->link;
    } while (ptr1 != start);

    cout << "Copied List:" << endl;
    node *q = ptr2;
    do
    {
        cout << q->info << "   ";
        q = q->link;
    } while (q != NULL);
    cout << endl;
}