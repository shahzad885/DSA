#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *start = NULL;

void create_list(int data);
void display();

int main()
{
    int choice, n, m, i;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Display" << endl;
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
                cout << "Enter element " << (i + 1) << ": ";
                cin >> m;
                create_list(m);
            }
            break;
        case 2:
            display();
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
    struct node *q, *tmp, *prev = NULL;
    tmp = new struct node;
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL || start->info <= data)
    {
        tmp->link = start;
        start = tmp;
    }
    else
    {
        q = start;
        while (q != NULL && q->info > data)
        {
            prev = q;
            q = q->link;
        }
        prev->link = tmp;
        tmp->link = q;
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
        q = q->link;
    }
    cout << endl;
}
