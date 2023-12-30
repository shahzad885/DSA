#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *prev;
    struct node *next;
} *start;

void create_list(int);
void count();

int main()
{
    int choice, n, m, i;
    start = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Count Non-zero, Odd and Even elements" << endl;
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
            count();
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

void create_list(int data)
{
    struct node *tmp, *q;
    tmp = new struct node;
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;

    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = tmp;
        tmp->prev = q;
    }
}

void count()
{
    struct node *q = start;
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int cnt = 0, even = 0, odd = 0;
    while (q != NULL)
    {
        if (q->info != 0)
        {
            cnt++;
            if (q->info % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        q = q->next;
    }
    cout << "Non-zero Elements: " << cnt << endl;
    cout << "Even Elements: " << even << endl;
    cout << "Odd Elements: " << odd << endl;
}