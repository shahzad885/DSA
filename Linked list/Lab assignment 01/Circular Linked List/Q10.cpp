#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *start;

void create_list(int);
void swap(int, int);
void display();

int main()
{
    int choice, n, m, i;
    start = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Swap" << endl;
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
                cout << "Enter element " << i + 1 << ": ";
                cin >> m;
                create_list(m);
            }
            break;
        case 2:
            int node1, node2;
            cout << "Enter 1st num: ";
            cin >> node1;
            cout << "Enter 2nd num: ";
            cin >> node2;
            swap(node1, node2);
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

void create_list(int info)
{
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->info = info;
    tmp->link = NULL;

    if (start == NULL)
    {
        start = tmp;
        tmp->link = start;
    }
    else
    {
        q = start;
        while (q->link != start)
            q = q->link;
        q->link = tmp;
        tmp->link = start;
    }
}

void swap(int node1, int node2)
{
    struct node *p1 = NULL, *q1 = start;
    while (q1 && q1->info != node1)
    {
        p1 = q1;
        q1 = q1->link;
    }

    struct node *p2 = NULL, *q2 = start;
    while (q2 && q2->info != node2)
    {
        p2 = q2;
        q2 = q2->link;
    }

    if (q1 == NULL || q2 == NULL)
        return;

    if (p1 != NULL)
        p1->link = q2;
    else
        start = q2;

    if (p2 != NULL)
        p2->link = q1;
    else
        start = q1;

    struct node *temp = q2->link;
    q2->link = q1->link;
    q1->link = temp;
}

void display()
{
    struct node *q;
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    q = start;
    cout << "List is:" << endl;
    do
    {
        cout << q->info << "   ";
        q = q->link;
    } while (q != start);
    cout << endl;
}