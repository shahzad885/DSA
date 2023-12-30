/*
	Name: Max_Heap
	Version: 0.1
	Date: 02-12-2023
	Author: @Umair-PC
*/
#include "my_header.h"
using namespace std;
void control::swaping_to_balance(node *&ref)
{
	int key_temp;
	string name;
	node *ptr=ref;
	while(ptr->parent != NULL)
	{
		if(ptr->key > ptr->parent->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			ptr->key=ptr->parent->key;
			ptr->name=ptr->parent->name;
			ptr->parent->key=key_temp;
			ptr->parent->name=name;
		}
		ptr=ptr->parent;
	}
}
void control::swaping_after_del(node *&ref)
{
	int key_temp;
	string name;
	node *ptr=ref;
	node *child_with_large_key;
	//Changed || to &&
	while(ptr->left != NULL && ptr->right != NULL)
	{
		if(ptr->left->key > ptr->right->key)
		{
			child_with_large_key=ptr->left;
		}
		else
		{
			child_with_large_key=ptr->right;
		}
		if(child_with_large_key->key > ptr->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			ptr->key=child_with_large_key->key;
			ptr->name=child_with_large_key->name;
			child_with_large_key->key=key_temp;
			child_with_large_key->name=name;
		}
		ptr=child_with_large_key;
	}
	//Change started
	if(ptr->left!=NULL)
	{
		child_with_large_key=ptr->left;
		if(child_with_large_key->key > ptr->key)
		{
			key_temp=ptr->key;
			name=ptr->name;
			ptr->key=child_with_large_key->key;
			ptr->name=child_with_large_key->name;
			child_with_large_key->key=key_temp;
			child_with_large_key->name=name;
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
void control::insert(int key, string name)
{
	node *temp=new node();
	temp->key=key;
	temp->name=name;
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
	int height=max_depth(root);
	for(int i=0; i<height; i++)
	{
		print_level(root, i);
		cout<<endl;
	}
}
node * control::get_last_node()
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
void control::find(int key, node *ptr, node *&loc)
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
		find(key, ptr->left, loc);
		find(key, ptr->right, loc);
	}
}
void control::case_a(node *&parent, node *&loc, node *&lastNode)
{
	if(loc == root)
	{
		root=NULL;
	}
	else if(loc == lastNode)
	{
		if(parent->left == loc)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	else
	{
		node *lNp=lastNode->parent;
		if(lNp->left == lastNode)
		{
			lNp->left=NULL;
		}
		else
		{
			lNp->right=NULL;
		}
		
		if(parent->left == loc)
		{
			parent->left = lastNode;
		}
		else
		{
			parent->right = lastNode;
		}
		lastNode->parent=parent;
		//Check for Swaping with parent
		swaping_to_balance(lastNode);
	}
	delete(loc);
}
void control::case_b(node *&parent, node *&loc, node *&lastNode)
{
	if(loc == root)
	{
		root=loc->left;
	}
	else if(loc->left == lastNode)
	{
		node *lNp=loc->parent;
		if(lNp->left == loc)
		{
			lNp->left=lastNode;
		}
		else
		{
			lNp->right=lastNode;
		}
		lastNode->parent=lNp;
	}
	else //We even dont need this block
	{
		//Displacing lastNode
		node *lNp=lastNode->parent;
		if(lNp->left == lastNode)
		{
			lNp->left=NULL;
		}
		else
		{
			lNp->right=NULL;
		}
		//Attaching to parent of loc
		if(parent->left == loc)
		{
			parent->left = lastNode;
		}
		else
		{
			parent->right = lastNode;
		}
		lastNode->parent=lNp;
	}
	delete(loc);
}
void control::case_c(node *&parent, node *&loc, node *&lastNode)
{
	//If loc at Root
	if(loc == root)
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
		return ;
	}
	//If Bottom
	else if(loc->right == lastNode)
	{
		node *locNp=loc->parent;
		if(locNp->left == loc)
		{
			locNp->left=lastNode;
		}
		else
		{
			locNp->right=lastNode;
		}
		lastNode->parent=locNp;
		lastNode->left=loc->left;
		lastNode->right=NULL;
		
		loc->left->parent=lastNode;
		swaping_after_del(lastNode);
		return ;
	}
	//Other cases
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
		//Putting on its place
		if(parent->left == loc)
		{
			parent->left=lastNode;	
		}
		else
		{
			parent->right=lastNode;
		}
		lastNode->parent=loc->parent;
		lastNode->left=loc->left;
		lastNode->right=loc->right;
		
		loc->left->parent=lastNode;
		loc->right->parent=lastNode;
		//Swapping with Parent
		if(lastNode->parent->key<lastNode->key)
		{
			swaping_to_balance(lastNode);
		}//Swapping with child
		else
		{
			swaping_after_del(lastNode);
		}
	}
	delete(loc);
}
void control::del(int key)
{
	node *loc, *parent;
	find(key, root, loc);
	parent=loc->parent;
	node *lastNode=get_last_node();
	//Case-A: If no child;
	if(loc->left == NULL && loc->right == NULL)
	{
		case_a(parent, loc, lastNode);
	}
	//Case-B
	else if(loc->left != NULL && loc->right == NULL)
	{
		case_b(parent, loc, lastNode);
	}
	//Case-C
	else
	{
		case_c(parent, loc, lastNode);
	}
}
void control::sorted_display()
{
	while(root != NULL)
	{
		cout<<root->name<<endl;
		del(root->key);
	}
}
