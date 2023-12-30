#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
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
                cout << "Enter the " << i << " element: ";
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

    if (start == NULL)
    {
        tmp->next = tmp;
        start = tmp;
    }
    else
    {
        q = start;
        while (q->next != start)
            q = q->next;
        q->next = tmp;
        tmp->next = start;
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
    do
    {
        p = p->next;
        cnt++;
    } while (p != start);

    if (cnt % 2 != 0)
    {
        cout << "List has an odd number of nodes" << endl;
        return;
    }

    cout << "First Half: ";
    for (int i = 0; i < cnt / 2; i++)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;

    cout << "Second Half: ";
    do
    {
        cout << p->info << " ";
        p = p->next;
    } while (p != start);
    cout << endl;
}