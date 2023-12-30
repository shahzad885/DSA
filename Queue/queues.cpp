#include<iostream>
#include "queues.h"
using namespace std;

void queue::push(int data)
{
	struct node *temp=new node(), *q;
	temp= new node();
	temp->data=data;
	temp->link=rear;
	if(front==NULL && rear==NULL)
	{
		front=temp;
	}
	rear=temp;
}

void queue::display()
{
	struct node *q=rear;
	while(q != NULL)
	{
		cout<<q->data<<endl;
		q=q->link;
	}
}

void queue::pop()
{
	struct node *temp,*q=rear;
	while(q->link->link!=NULL)
	{
		q=q->link;
	}
	temp=q->link;
	front=q;
	front->link=NULL;
	delete(temp);
}

