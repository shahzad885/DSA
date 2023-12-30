#ifndef my_header_H
#define my_header_H
#include<iostream>
using namespace std;
struct node
{
	int key;
	string name;
	node *parent=NULL, *left=NULL, *right=NULL, *sub_left=NULL, *sub_right=NULL;
};
struct control
{
	public:
		node * root=NULL;
		
	void swaping_to_balance(node *&ref);
	void swaping_after_del(node *&ref);
	int get_height(node *ptr, bool &status);
	void insert(int key, string name, node *sub_left, node *sub_right);
	int max_depth(node *ptr);
	void print_level(node *ptr, int level);
	void level_order_traversel();
	node * get_last_node();
	void find(int key, node *ptr, node *&loc);
	node * pop();
	void make_huffman_tree();
	void show_codes(node *ptr, string code);
	void total_item(node *ptr, int &count);
};
#endif
