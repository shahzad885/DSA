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
struct KeyLoc
{
	int key, x1, x2, y1, y2;
	KeyLoc *next=NULL;
};
struct control
{
	public:
		int window1, window2;
		node * main_root=NULL;
		node *temp_root=NULL;
		KeyLoc *start=NULL;
		int x1=500, y1=300, x2=500, y2=300;
		int sqr_h=80, sqr_w=80, sqr_x=0, sqr_y=20, code_height=100;
		
	void swaping_to_balance(node *&ref);
	void swaping_after_del(node *&ref);
	int get_height(node *ptr, bool &status);
	void insert(node *&ptr, int key, string name, node *sub_left, node *sub_right, char ins_for);
	int max_depth(node *ptr);
	void print_level(node *ptr, int level);
	void level_order_traversel();
	node * get_last_node(node *&ptr);
	void find(int key, node *ptr, node *&loc);
	node * pop(node *&ptr);
	void make_huffman_tree();
	void show_codes(node *ptr, string code);
	void total_item(node *ptr, int &count);
	int get_huffman_height(node *ptr);
	void create(node *ptr, int x1, int y1, int x2, int y2, int level);
	void create_Queue_GUI();
	void show_top_queue();
	void copying_temp_to_main();
	void mouse_wait_action();
	void clear_KeyLoc();
	void insert_into_keyLoc(int key, int x1, int x2, int y1, int y2);
	int get_key_of_loc(int x, int y);
	void find_loc(int key, node *ptr, node *&loc);
	void introduction();
	void next_btn();
	void get_input();
};
#endif
