/*
	Name: Huffman
	Version: 0.1
	Date: 02-12-2023
	Author: @Umair-PC
*/
#include "my_header.h"
#include<graphics.h>
#include<string>
#include<sstream>  
using namespace std;
void control::swaping_to_balance(node *&ref)
{
	int key_temp;
	string name;
	node *sub_left;
	node *sub_right;
	node *ptr=ref;
	while(ptr->parent != NULL)
	{
		if(ptr->key < ptr->parent->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			sub_left=ptr->sub_left;
			sub_right=ptr->sub_right;
			
			ptr->key=ptr->parent->key;
			ptr->name=ptr->parent->name;
			ptr->sub_left=ptr->parent->sub_left;
			ptr->sub_right=ptr->parent->sub_right;
			
			ptr->parent->key=key_temp;
			ptr->parent->name=name;
			ptr->parent->sub_left=sub_left;
			ptr->parent->sub_right=sub_right;
		}
		ptr=ptr->parent;
	}
}
void control::swaping_after_del(node *&ref)
{
	int key_temp;
	string name;
	node *sub_left;
	node *sub_right;
	node *ptr=ref;
	node *child_with_small_key;
	//Changed || to &&
	while(ptr->left != NULL && ptr->right != NULL)
	{
		if(ptr->left->key < ptr->right->key)
		{
			child_with_small_key=ptr->left;
		}
		else
		{
			child_with_small_key=ptr->right;
		}
		if(child_with_small_key->key < ptr->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			sub_left=ptr->sub_left;
			sub_right=ptr->sub_right;
			
			ptr->key=child_with_small_key->key;
			ptr->name=child_with_small_key->name;
			ptr->sub_left=child_with_small_key->sub_left;
			ptr->sub_right=child_with_small_key->sub_right;
			
			child_with_small_key->key=key_temp;
			child_with_small_key->name=name;
			child_with_small_key->sub_right=sub_right;
			child_with_small_key->sub_left=sub_left;
		}
		ptr=child_with_small_key;
	}
	//Change started
	if(ptr->left!=NULL)
	{
		child_with_small_key=ptr->left;
		if(child_with_small_key->key < ptr->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			sub_left=ptr->sub_left;
			sub_right=ptr->sub_right;
			
			ptr->key=child_with_small_key->key;
			ptr->name=child_with_small_key->name;
			ptr->sub_left=child_with_small_key->sub_left;
			ptr->sub_right=child_with_small_key->sub_right;
			
			child_with_small_key->key=key_temp;
			child_with_small_key->name=name;
			child_with_small_key->sub_right=sub_right;
			child_with_small_key->sub_left=sub_left;
		}
	}
	//Change Ended
}
int control::get_height(node *ptr, bool &status)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		
		int ld= get_height(ptr->left, status);
		int rd= get_height(ptr->right, status);
		if(ld != rd)
		{
			status = false;
		}
		if(rd > ld)
		{
			return rd+1;
		}
		else
		{
			return ld+1;
		}
	}
} 
void control::insert(node *&root, int key, string name, node *sub_left, node *sub_right, char ins_for)
{
	node *temp=new node();
	temp->key=key;
	temp->name=name;
	temp->sub_left=sub_left;
	temp->sub_right=sub_right;
	if(root == NULL)
	{
		root=temp;
	}
	else
	{
		node *q=root, *parent=NULL;
		while(q != NULL)
		{
			bool l_status=true;
			int lh=get_height(q->left, l_status);
			bool r_status=true;
			int rh=get_height(q->right, r_status);
			if(lh >rh && l_status == true)
			{
				parent=q;
				q=q->right;
			}
			else if(lh == rh && r_status == false)
			{
				parent=q;
				q=q->right;
			}
			else
			{
				parent=q;
				q=q->left;
			}
		}
		if(parent->left == NULL)
		{
			parent->left=temp;
			temp->parent=parent;
		}
		else
		{
			parent->right=temp;
			temp->parent=parent;
		}
		//Printing the GUI of Huffman Tree
		if(ins_for=='h')
		{
			setbkcolor(BLACK); 
			cleardevice(); 
			int level=get_huffman_height(temp);
			create(temp, x1, y1, x2, y2, level);
		}
		//Ended Here
		swaping_to_balance(temp);
	}
	
}
int control::max_depth(node *ptr)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		int ld= max_depth(ptr->left);
		int rd= max_depth(ptr->right);
		if(rd > ld)
		{
			return rd+1;
		}
		else
		{
			return ld+1;
		}
	}
}
int control::get_huffman_height(node *ptr)
{
	if(ptr == NULL)
	{
		return 0;
	}
	else
	{
		int ld= get_huffman_height(ptr->sub_left);
		int rd= get_huffman_height(ptr->sub_right);
		if(rd > ld)
		{
			return rd+1;
		}
		else
		{
			return ld+1;
		}
	}
}
void control::print_level(node *ptr, int level)
{
	if(ptr== NULL)
	{
		return;
	}
	if(level==0)
	{
		cout<<ptr->key<<" ";
	}
	else
	{
		print_level(ptr->left, level-1);
		print_level(ptr->right, level-1);
	}
}
void control::level_order_traversel()
{
	int height=max_depth(main_root);
	for(int i=0; i<height; i++)
	{
		print_level(main_root, i);
		cout<<endl;
	}
}
node * control::get_last_node(node *&root)
{
	node *q=root, *loc=NULL;
	while(q != NULL)
	{
		bool l_status=true;
		int lh=get_height(q->left, l_status);
		bool r_status=true;
		int rh=get_height(q->right, r_status);
		if(lh == rh)
		{
			loc=q;
			q=q->right;
		}
		else if(lh>rh)
		{
			loc=q;
			q=q->left;
		}
	}
	return loc;
}
node * control::pop(node *&root)
{
	node *loc=root;
	node *lastNode=get_last_node(root);
	//Case-A: 
	if(loc->left == NULL && loc->right == NULL)
	{
		root=NULL;
	}
	//Case-B
	else if(loc->left != NULL && loc->right == NULL)
	{
		root=loc->left;
		root->parent=NULL;
	}
	//Case-C
	else
	{
		node *lastNp=lastNode->parent;
		//Detaching Last Node
		if(lastNp->left == lastNode)
		{
			lastNp->left=NULL;
		}
		else
		{
			lastNp->right=NULL;
		}
		lastNode->left=root->left;
		lastNode->right=root->right;
		lastNode->parent=NULL;
		
		root->left->parent=lastNode;
		//This if is a change
		if(root->right != NULL)
		root->right->parent=lastNode;
		
		root=lastNode;
		swaping_after_del(lastNode);
	}
	return loc;
}
void control::total_item(node *ptr, int &count)
{
	if(ptr == NULL)
	{
		return ;
	}
	else
	{
		count=count+1;
		total_item(ptr->left, count);
		total_item(ptr->right, count);
	}
}
void control::make_huffman_tree()
{
	node *ptr1;
	node *ptr2;
	node *temp;
	//1. Show Introduction
	introduction();
	//2. Take Input
	get_input();
	//Ended
	while(main_root->left != NULL || main_root->right != NULL)
	{
		show_top_queue();
		mouse_wait_action();
		ptr1=pop(main_root);
		ptr2=pop(main_root);
		insert(main_root, ptr1->key+ptr2->key, "?", ptr1, ptr2, 'h');
	}
	//Graphics Instruction: Printing the last Item
	setbkcolor(BLACK); 
	cleardevice(); 
	show_top_queue();
	int level=get_huffman_height(main_root);
	create(main_root, x1, y1, x2, y2, level);
	//Show Codes
	mouse_wait_action();
	int window3=initwindow(1000, 600);
	setcurrentwindow(window3);
	show_codes(main_root, "");
	setcurrentwindow(window1);
	//Ended Here	
}
void control::show_codes(node *ptr, string code)
{
	if(ptr == NULL)
	{
		return;
	}
	else if(ptr->sub_left == NULL && ptr->sub_right == NULL)
	{
		settextstyle(8, 0, 2);
		setcolor(WHITE);
		setbkcolor(BLACK);
		char* char_arr = &ptr->name[0]; 
		outtextxy(200, code_height, char_arr);
		outtextxy(250, code_height, " : ");
		char* char_arr_1 = &code[0]; 
		outtextxy(300, code_height, char_arr_1);
		code_height=code_height+50;
		cout<<code<<" : "<<ptr->name<<endl;
		return ;
	}
	else
	{
		code.push_back('0');
		show_codes(ptr->sub_left, code);
		if(!code.empty())
		code = code.substr(0, code.size()-1);
		code.push_back('1');
		show_codes(ptr->sub_right, code);
	}
}
void control::create(node *ptr, int x1, int y1, int x2, int y2, int level)
{
	if(ptr ==NULL)
	{
		return ;
	}
	else
	{
		//Creating Line
		setcolor(YELLOW);
	    line(x1, y1, x2, y2);
	    //Labeling Line
	    if(x1-x2<0)
	    {
	    	settextstyle(8, 0, 2);
			setcolor(WHITE);
			setbkcolor(BLACK);
	    	outtextxy(x1+(x2-x1)/2, y2,"0");
		}
		else if(x1-x2>0)
		{
			settextstyle(8, 0, 2);
			setcolor(WHITE);
			setbkcolor(BLACK);
			outtextxy(x1-5-(x1-x2)/2, y2,"1");
		}
	    //Creating  Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(x1, y1, 30);
		floodfill(x1,y1,WHITE);
		//Putting Text
		if(ptr->sub_left == NULL && ptr->sub_right == NULL)
		{
			settextstyle(8, 0, 4);
			setcolor(WHITE);
			setbkcolor(RED);
			char* char_arr = &ptr->name[0]; 
			outtextxy(x1-10, y1-15,char_arr);
			setbkcolor(RED);
		}
		else //Show Sum on the node
		{
			stringstream ss;  
			ss<<ptr->key;  
			string s;  
			ss>>s;
			settextstyle(3, 0, 3);
			setbkcolor(RED);
			setcolor(WHITE);
			char* char_arr = &s[0]; 
			outtextxy(x1-14, y1-10, char_arr); 
		}
		//Creating  Circle(for hiding line)
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(x2, y2, 30);
		floodfill(x2,y2,WHITE);
		//Recursion
	    create(ptr->sub_left, x1-(50*level), y1+80, x1, y1, level-1);
	    create(ptr->sub_right, x1+(50*level), y1+80, x1, y1, level-1);
	}
}
void control::create_Queue_GUI()
{	
	int counter=0;
	total_item(main_root, counter);
	int x=(getmaxx()/2)-(counter/2)*sqr_w;
	clear_KeyLoc(); //Firstly Clear Key Location Linked List
	for(int i=0; i<counter; i++)
	{
		node *ptr_temp=pop(main_root);
		insert(temp_root, ptr_temp->key, ptr_temp->name, ptr_temp->sub_left, ptr_temp->sub_right, 'm');
		//Text Block
			//Converting INT to STRING
			stringstream ss;  
			ss<<ptr_temp->key;  
			string s;  
			ss>>s;
			//ENDED
			settextstyle(3, 0, 4);
			setcolor(WHITE);
			if(ptr_temp->sub_left == NULL)
			setbkcolor(RED);
			else
			setbkcolor(GREEN);
			char* char_arr = &s[0]; 
			outtextxy(x+10, sqr_y+25, char_arr); 
			//SHOWING CHARACTER
			if(ptr_temp->sub_left == NULL)
			{
				setbkcolor(BLACK);
				settextstyle(8, 0, 4);
				setcolor(WHITE);
				char* char_arr = &ptr_temp->name[0]; 
				outtextxy(x+10, sqr_y+85, char_arr); 
			}
			//ENDED
		//Text Block Ended
		setcolor(WHITE);
		insert_into_keyLoc(ptr_temp->key, x, x+sqr_w, sqr_y, sqr_y+sqr_h); //Insert Key along with Location into KeyLoc
		rectangle(x, sqr_y, x+sqr_w, sqr_y+sqr_h);
		if(ptr_temp->sub_left == NULL)
		setfillstyle(SOLID_FILL,RED);
		else
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(x+10,sqr_y+10,WHITE);
		x=x+(sqr_w+10);
	}
	//Create Bottom Next Button
	next_btn();
}
void control::next_btn()
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(getmaxx()-150, getmaxy()-100, getmaxx()-50, getmaxy()-50);
	floodfill(getmaxx()-100,getmaxy()-75,WHITE);
	settextstyle(3, 0, 4);
	setcolor(WHITE);
	setbkcolor(BLUE);
	outtextxy(getmaxx()-140, getmaxy()-90, "Next");
}
void control::copying_temp_to_main()
{
	int counter=0;
	node *ptr;
	total_item(temp_root, counter);
	for(int i=0; i<counter; i++)
	{
		ptr=pop(temp_root);
		insert(main_root, ptr->key, ptr->name, ptr->sub_left, ptr->sub_right, 'm');
	}
}
void control::show_top_queue()
{
	create_Queue_GUI();
	copying_temp_to_main();
}
void control::clear_KeyLoc()
{
	KeyLoc *temp=NULL;
	while(start != NULL)
	{
		temp=start;
		start=start->next;
		delete(temp);
	}
}
void control::insert_into_keyLoc(int key, int x1, int x2, int y1, int y2)
{
	KeyLoc *q=start;
	KeyLoc *temp=new KeyLoc();
	temp->key=key;
	temp->x1=x1;
	temp->x2=x2;
	temp->y1=y1;
	temp->y2=y2;
	if(start == NULL)
	{
		start=temp;
	}
	else
	{
		while(q->next != NULL)
		{
			q=q->next;
		}
		q->next=temp;
	}
}
void control::mouse_wait_action()
{
	while(1)
	{
		 while (!ismouseclick(WM_LBUTTONDOWN))
		 {
		 	delay(100);
		 }
		 int x, y; 
		 getmouseclick(WM_LBUTTONDOWN, x, y);
		 //If User has clicked on next Button
		 int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		 if(x>x1 && x<x2 && y>y1 && y<y2)
		 {
		 	break;
		 }
		 else
		 {
		 	int key=get_key_of_loc(x, y);
		 	if(key != -404)
		 	{
		 		node *loc=NULL;
		 		//Open Second Screen
		 		window2=initwindow(1000,1000);
		 		//Get the location
		 		find_loc(key, main_root, loc);
		 		//Display Structure
		 		setcurrentwindow(window2);
		 		int level=get_huffman_height(loc);
				create(loc, 500, 50, 500, 50, level);
		 		setcurrentwindow(window1);
			}
		 }
	}
}
int control::get_key_of_loc(int x, int y)
{
	KeyLoc *q=start;
	int x1, x2, y1, y2;
	while(q != NULL)
	{
		x1=q->x1;
		x2=q->x2;
		y1=q->y1;
		y2=q->y2;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			return q->key;
		}
		q=q->next;
	}
	return -404;
}
void control::find_loc(int key, node *ptr, node *&loc)
{
	if(ptr == NULL)
	{
		return ;
	}
	else if(ptr->key == key)
	{
		loc=ptr;
		return ;
	}
	else
	{
		find_loc(key, ptr->left, loc);
		find_loc(key, ptr->right, loc);
	}
}
void control::introduction()
{
	//Next Button
	next_btn();
	//Definition
		//Heading
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(getmaxx()/2-100, 10, "Huffman Tree");
		//Explanation
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(200, 50, "Huffman coding is a lossless data compression algorithm.");
		outtextxy(25, 90, "The idea is to assign variable-length codes to characters based on their frequency.");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Example
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 130, "Example: ");
		//Explanation
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 170, "Data: AAAAAAAABBBBCCCCCDD      (We want to send this data on the Network)");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Step-1
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 200, "Step-1:        (We are going to calculate the frequency)");
		//A
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 235, "A -> 8");
		//B
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 270, "B -> 4");
		//C
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 305, "C -> 5");
		//D
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 340, "D -> 2");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Step-2
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 380, "Step-2:");
		//Select
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(50, 410, "Select two low frequency nodes and make a tree.");
		outtextxy(50, 440, "The internel node frequency will be their sum.");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Creating the tree
		//Creating Lines
		setcolor(YELLOW);
		line(600, 560, 550, 640);
		line(600, 560, 650, 640);
		//Internel Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(600, 560, 30);
		floodfill(600,560,WHITE);
		//D Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(550, 640, 30);
		floodfill(550,640,WHITE);
		//B Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(650, 640, 30);
		floodfill(650,640,WHITE);
		//Putting Text
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(RED);
		outtextxy(590, 545, "6");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(540, 625, "2");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(540, 680, "D");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(640, 625, "4");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(640, 680, "B");
		
		//Updated Data
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLACK);
		outtextxy(800, 620, "Updated Frequency:   5, 6, 8");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	//Step-3
		//Heading
		settextstyle(3, 0, 4);
		setcolor(RED);
		setbkcolor(BLACK);
		outtextxy(50, 720, "Step-3:");
		setcolor(WHITE);
		outtextxy(300, 720, "Repeat step two until only one element in left in queue.");
		
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}
	cleardevice();
	/*
	//Creating Tree
		//Creating Lines
		setcolor(YELLOW);
		line(900, 900, 850, 980);
		line(900, 900, 950, 980);
		line(850, 820, 800, 900);
		line(850, 820, 900, 900);
		//Internel Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(900, 900, 30);
		floodfill(900,900,WHITE);
		
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,RED);
		circle(850, 820, 30);
		floodfill(850,820,WHITE);
		//D Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(850, 980, 30);
		floodfill(850,980,WHITE);
		//B Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(950, 980, 30);
		floodfill(950,980,WHITE);
		//C Circle
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,BLUE);
		circle(800, 900, 30);
		floodfill(800,900,WHITE);
		//Putting Text
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(RED);
		outtextxy(890, 885, "6");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(840, 965, "2");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(940, 965, "4");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(BLUE);
		outtextxy(790, 885, "5");
		
		settextstyle(3, 0, 4);
		setcolor(WHITE);
		setbkcolor(RED);
		outtextxy(830, 805, "11");
	while(1)
	{
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		int x, y; 
		getmouseclick(WM_LBUTTONDOWN, x, y);
		//If User has clicked on next Button
		int x1=getmaxx()-150, y1=getmaxy()-100, x2=getmaxx()-50, y2=getmaxy()-50;
		if(x>x1 && x<x2 && y>y1 && y<y2)
		{
			break;
		}
	}*/
}
void control::get_input()
{
	string a, b;
	cout<<"Enter the data: "<<endl;
	getline(cin, a);
	string temp="";
	int count=0;
	for(int i=0; i<a.size(); i++)
	{
		if(temp.find(a[i]) >= temp.length())
		{
			temp.push_back(a[i]);
		}
	}
	for(int i=0; i<temp.size(); i++)
	{
		for(int j=0; j<a.size(); j++)
		{
			if(temp[i] == a[j])
			{
				count++;
			}
		}
		b=temp[i];
		insert(main_root, count, b, NULL, NULL, 'm');
		count=0;
	}
}
