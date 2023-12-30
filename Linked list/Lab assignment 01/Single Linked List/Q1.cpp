#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *start1, *start2;

void create_list(struct node *&start, int data);
void concatenate(struct node *&list1, struct node *list2);
void display(struct node *start);

int main()
{
    int choice, n, m, i;
    start1 = start2 = NULL;
    while (1)
    {
        cout << "1. Create List 1" << endl;
        cout << "2. Create List 2" << endl;
        cout << "3. Concatenate" << endl;
        cout << "4. Display" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many nodes do you want for list 1: ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Enter element " << i + 1 << ": ";
                cin >> m;
                create_list(start1, m);
            }
            break;
        case 2:
            cout << "How many nodes do you want for list 2: ";
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << "Enter element " << i + 1 << ": ";
                cin >> m;
                create_list(start2, m);
            }
            break;
        case 3:
            concatenate(start1, start2);
            break;
        case 4:
            display(start1);
            break;
        case 5:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

void create_list(struct node *&start, int data)
{
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL)
        start = tmp;
    else
    {
        q = start;
        while (q->link != NULL)
            q = q->link;
        q->link = tmp;
    }
}

void concatenate(struct node *&list1, struct node *list2)
{
    if (list1 == NULL)
    {
        list1 = list2;
    }
    else
    {
        struct node *q = list1;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = list2;
    }
}

void display(struct node *start)
{
    struct node *q;
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    q = start;
    cout << "List is:" << endl;
    while (q != NULL)
    {
        cout << q->info << "   ";
        q = q->link;
    }
    cout << endl;
}