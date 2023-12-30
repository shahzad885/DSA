#ifndef my_header_H
#define my_header_H
#include<iostream>
using namespace std;
struct node
{
	int key;
	int price;
	string name;
	string diatery_info;
	bool status;
	node *left=NULL;
	node *right=NULL;
	node *parent=NULL;
};
struct control
{
	public:
		node *root=NULL;
		
	int height(node *ptr);
	int getbalance(node *ptr);
	node* rightRotation(node *ptr);
	node* leftRotation(node *ptr);
	node* insert(int key, int price, string name, string dia_info, bool status, node *ptr, node *parent);
	node* del(node *ptr, int key);
	void inorder(node *ptr);
	void find_by_key(int key, node *&parent, node *&loc);
	void find_by_name(string name, node *ptr, node *&loc);
	void search_by_key(int key);
	void search_by_name(string name);
};
#endif
