#ifndef my_header_H
#define my_header_H
#include<iostream>
using namespace std;
struct node
{
	int key;
	int price;
	string name;
	node *left=NULL;
	node *right=NULL;
};
struct control
{
	public:
		node *root=NULL;
	void find(int key, node *&parent, node *&loc);
	void insert(int key,int price,string name);
	void case_a(node *&parent, node *&loc);
	void case_b(node *&parent, node *&loc);
	void case_c(node *&parent, node *&loc);
	void del(int key);
	void inorder(node *ptr);
	void search(int key);
};
#endif
