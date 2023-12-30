#ifndef my_header_H
#define my_header_H
#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *link=NULL;
};

struct control
{
	public: 
	struct node *rear=NULL, *front=NULL, *start=NULL;
	int counter=0;
	int nodes=0;
	int Max=10;
	
	void push(int data);
	int pop();
	void display();
	void reverse();
	bool is_empty();
};
#endif
