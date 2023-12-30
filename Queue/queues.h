#ifndef queues_H
#define queues_H
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *link;
};

struct queue
{
	public: 
	struct node *front=NULL;
	struct node *rear=NULL;	
	void push(int data);
	void display();
	void pop();
};
#endif


