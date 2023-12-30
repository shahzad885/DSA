#include<iostream>
#include "my_header.h"
using namespace std;

void control::push(int data)
{
	struct node *temp=new node();
	temp->data=data;
	if(rear == NULL)
	{
		front = temp;
	}
	else
	{
		rear->link=temp;
	}
	rear=temp;
}

int control::pop()
{
	if(front !=NULL)
	{
		int data=front->data;
		struct node *temp=front;
		front=front->link;
		delete(temp);
		return data;
	}
	else
	{
		cout<<"Stack underflow: ";
		rear=NULL;
		front=NULL;
		return -1;
	}
}
void control::display()
{
	struct node *q=front;
	while(q != NULL)
	{
		cout<<q->data<<endl;
		q=q->link;
	}
}
//mussaratabdullah@gmail.com
