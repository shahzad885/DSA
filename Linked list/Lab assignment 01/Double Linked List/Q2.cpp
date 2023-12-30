#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
} *start;

void create_list(int);
void split();

int main()
{
    int choice, n, m, i;
    start = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Split" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many nodes do you want: ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Enter the " << i + 1 << " element: ";
                cin >> m;
                create_list(m);
            }
            break;
        case 2:
            split();
            break;
        case 3:
            exit(1);
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
    tmp->next = NULL;
    tmp->prev = NULL;

    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp;
        tmp->prev = q;
    }
}

void split()
{
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    struct node *p = start;
    int cnt = 0;
    while (p != NULL)
    {
        p = p->next;
        cnt++;
    }

    if (cnt % 2 != 0)
    {
        cout << "List has an odd number of nodes" << endl;
        return;
    }

    cout << "First Half: ";
    p = start;
    for (int i = 0; i < cnt / 2; i++)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;

    cout << "Second Half: ";
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}