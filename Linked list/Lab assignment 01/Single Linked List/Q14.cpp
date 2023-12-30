#include <iostream>
using namespace std;

struct node
{
    int coeff;
    int power;
    struct node *link;
} *start = NULL;

void create(int coeff, int power);
void multiply(int num);
void display();

int main()
{
    int choice, coeff, power, num;
    while (1)
    {
        cout << "1. Create" << endl;
        cout << "2. Multiply" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter coefficient: ";
            cin >> coeff;
            cout << "Enter power: ";
            cin >> power;
            create(coeff, power);
            break;
        case 2:
            cout << "Enter a number to multiply: ";
            cin >> num;
            multiply(num);
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

void create(int coeff, int power)
{
    struct node *q, *tmp;
    tmp = new struct node;
    tmp->coeff = coeff;
    tmp->power = power;
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

void display()
{
    struct node *q = start;
    if (q == NULL)
    {
        cout << "Polynomial is empty" << endl;
        return;
    }
    cout << "Polynomial: ";
    while (q != NULL)
    {
        cout << q->coeff;
        if (q->power != 0)
        {
            cout << "x^" << q->power;
        }
        if (q->link != NULL)
        {
            cout << " + ";
        }
        q = q->link;
    }
    cout << endl;
}

void multiply(int num)
{
    struct node *q = start;
    while (q != NULL)
    {
        q->coeff *= num;
        q->power++;
        q = q->link;
    }
}