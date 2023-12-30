#include "my_header.h"
#include<iostream>
#include <string>
#include<graphics.h>
using namespace std;
int main()
{
	control c1;
	node *ptr=NULL; 
	c1.window1=initwindow(getmaxwidth(),getmaxheight()-10);
	c1.insert(c1.main_root, 5, "A", NULL, NULL, 'm');
	c1.insert(c1.main_root, 9, "B", NULL, NULL, 'm');
	c1.insert(c1.main_root, 45, "F", NULL, NULL,'m');
	c1.insert(c1.main_root, 12, "C", NULL, NULL,'m');
	c1.insert(c1.main_root, 13, "D", NULL, NULL,'m');
	c1.insert(c1.main_root, 16, "E", NULL, NULL,'m');
	//c1.level_order_traversel();
	//c1.show_top_queue();
	//int counter=0;
	//c1.total_item(c1.temp_root, counter);
	//cout<<"TEMP: "<<counter<<endl;
	//c1.show_top_queue();
	c1.make_huffman_tree();
	//c1.show_codes(c1.main_root, "");
	cout<<"Waiting for key";
	getch();
	closegraph();
}
