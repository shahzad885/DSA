#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *start = NULL;

void create_list(int data);
void count(int num);
void display();

int main()
{
    int choice, n, m, i;
    start = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Count Occurrences" << endl;
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
            cout << "Enter the element: ";
            cin >> m;
            count(m);
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
    }
    else
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = tmp;
    }
}

void count(int num)
{
    struct node *q = start;
    if (start == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    int cnt = 0;
    while (q != NULL)
    {
        if (q->info == num)
        {
            cnt++;
        }
        q = q->link;
    }
    cout << num << " occurs " << cnt << " times in the list." << endl;
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
        q = q->link;
    }
    cout << endl;
}