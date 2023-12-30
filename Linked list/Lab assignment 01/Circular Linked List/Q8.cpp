#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *link;
} *start, *last;

void create_list(int);
void operations();

int main()
{
    int choice, n, m, i;
    start = NULL;
    last = NULL;
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
            last->link = start;
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
    struct node *tmp;
    tmp = new struct node;
    tmp->info = data;
    tmp->link = NULL;

    if (start == NULL)
    {
        start = tmp;
        last = tmp;
    }
    else
    {
        last->link = tmp;
        last = tmp;
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
    do
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
        q = q->link;
        cnt++;
        avg = sum / cnt;
    } while (q != start);

    cout << "Largest Element: " << largest << endl;
    cout << "Smallest Element: " << smallest << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;
}