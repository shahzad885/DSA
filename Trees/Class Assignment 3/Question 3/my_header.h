#ifndef my_header_H
#define my_header_H
#include<iostream>
using namespace std;
struct node
{
	int key;
	string name;
	node *parent=NULL, *left=NULL, *right=NULL;
};
struct control
{
	public:
		node * root=NULL;
		
	void swaping_to_balance(node *&ref);
	void swaping_after_del(node *&ref);
	int get_height(node *ptr, bool &status);
	void insert(int key, string name);
	int max_depth(node *ptr);
	void print_level(node *ptr, int level);
	void level_order_traversel();
	node * get_last_node();
	void find(int key, node *ptr, node *&loc);
	void case_a(node *&parent, node *&loc, node *&lastNode);
	void case_b(node *&parent, node *&loc, node *&lastNode);
	void case_c(node *&parent, node *&loc, node *&lastNode);
	void del(int key);
	void sorted_display();
};
#endif
