#include<iostream>
#include "my_header.h"
using namespace std;

void control::push(int data)
{
	if(counter == Max && rear->link==front)
	{
		cout<<"Queue Overflow"<<endl;
	}
	else
	{
		if(nodes <Max)
		{
			node *temp=new node();
			temp->data=data;
			if(rear == NULL)
			{
				front=temp;
				rear=temp;
				rear->link=temp;
				start=temp;
			}
			else
			{
				temp->link=start;
				rear->link=temp;
				rear=temp;
			}
			nodes++;
		}
		else
		{
			if(front == NULL)
			{
				rear=start;
				front=start;
				rear->data=data;
			}
			else
			{
				rear=rear->link;
				rear->data=data;
			}
		}
		counter++;
	}
}

int control::pop()
{
	int data;
	if(front == NULL)
	{
		cout<<"Queue Underflow ";
		return -1;
	}
	else
	{
		if(front == rear)
		{
			data=front->data;
			front->data=NULL;
			front=rear=NULL;
			
		}
		else
		{
			data=front->data;
			front->data=NULL;
			front=front->link;
			
		}
		counter--;
		return data;
	}
}
void control::display()
{
	struct node *q=front;
	if(q != NULL)
	{
		do
		{
			cout<<q->data<<endl;
			q=q->link;
		}while(q != rear->link);
	}
}
bool control::is_empty()
{
	if(front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void control::reverse()
{
	int data;
	if(is_empty() == true)
	{
		return;
	}
	else
	{
		data=pop();
		reverse();
		push(data);
	}
}
