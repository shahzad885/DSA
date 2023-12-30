#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
} *start;

void create_list(int);
void operations();

int main()
{
    int choice, n, m, i;
    start = NULL;
    while (1)
    {
        cout << "1. Create List" << endl;
        cout << "2. Operations" << endl;
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
            operations();
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
        {
            q = q->next;
        }
        q->next = tmp;
        tmp->prev = q;
    }
}

void operations()
{
    struct node *q = start;
    if (start == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int largest = q->info;
    int smallest = q->info;
    int sum = 0;
    int cnt = 0;
    int avg = 0;

    while (q != NULL)
    {
        if (q->info > largest)
        {
            largest = q->info;
        }
        if (q->info < smallest)
        {
            smallest = q->info;
        }
        sum += q->info;
        q = q->next;
        cnt++;
    }

    q = start;
    while (q->next != NULL)
    {
        q = q->next;
    }

    while (q != NULL)
    {
        q = q->prev;
        if (q == NULL)
        {
            break;
        }
        sum += q->info;
        cnt++;
    }

    avg = sum / cnt;

    cout << "Largest Element: " << largest << endl;
    cout << "Smallest Element: " << smallest << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
}