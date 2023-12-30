#include "my_header.h"
using namespace std;
void control::find(int key, node *&parent, node *&loc)
{
	if(root == NULL)
	{
		loc=root;
		parent=NULL;
		return ;
	}
	else if(root->key == key)
	{
		loc=root;
		parent=NULL;
		return;
	}
	else if(root->key<key)
	{
		loc=root->right;
		parent=root;
	}
	else
	{
		loc=root->left;
		parent=root;
	}
	while( loc != NULL)
	{
		if(loc->key == key)
		{
			return ;
		}
		else if(loc->key<key)
		{
			parent=loc;
			loc=loc->right;
		}
		else
		{
			parent=loc;
			loc=loc->left;
		}
	}
}
void control::insert(int key,int price,string name)
{
	node *temp, *parent=NULL, *loc=NULL;
	find(key, parent, loc);
	if(loc != NULL)
	{
		cout<<"Item Already Exsist"<<endl;
		return ;
	}
	temp=new node();
	temp->key=key;
	temp->price=price;
	temp->name=name;
	if(parent == NULL)
	{
		root=temp;
	}
	else
	{
		if(parent->key<key)
		{
			parent->right=temp;
		}
		else
		{
			parent->left=temp;
		}
	}
}
void control::case_a(node *&parent, node *&loc)
{
	if(parent == NULL)
	{
		root=NULL;
	}
	else
	{
		if(parent->left == loc)
		{
			parent->left=NULL;
		}
		else
		{
			parent->right=NULL;
		}
	}
}
void control::case_b(node *&parent, node *&loc)
{
	node *child;
	if(loc->left == NULL)
	{
		child=loc->right;
	}
	else
	{
		child=loc->left;
	}
	if(parent==NULL)
	{
		root=child;
	}
	else
	{
		if(parent->left == loc)
		{
			parent->left=child;
		}
		else
		{
			parent->right=child;
		}
	}
}
void control::case_c(node *&parent, node *&loc)
{
	node *ptr, *ptsave;
	ptsave=loc;
	ptr=loc->right;
	while(ptr->left != NULL)
	{
		ptsave=ptr;
		ptr=ptr->left;
	}
	if(ptr->right==NULL)
	{
		case_a(ptsave, ptr);
	}
	else
	{
		case_b(ptsave, ptr);
	}
	if(parent == NULL)
	{
		root=ptr;
		ptr->left=loc->left;
		ptr->right=loc->right;
	}
	else
	{
		if(parent->left == loc)
		{
			parent->left=ptr;
			ptr->left=loc->left;
			ptr->right=loc->right;
		}
		else
		{
			parent->right=ptr;
			ptr->left=loc->left;
			ptr->right=loc->right;
		}
	}
}
void control::del(int key)
{
	node *parent, *loc;
	if(root == NULL)
	{
		cout<<"Tree is empty"<<endl;
		return ;
	}
	find(key, parent, loc);
	if(loc->left == NULL && loc->right == NULL)
	{
		case_a(parent, loc);
	}
	else if(loc->left != NULL && loc->right == NULL)
	{
		case_b(parent, loc);
	}
	else if(loc->left == NULL && loc->right != NULL)
	{
		case_b(parent, loc);
	}
	else
	{
		case_c(parent, loc);
	}
	delete(loc);
}
void control::inorder(node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	else
	{
		inorder(ptr->left);
		cout<<ptr->key<<" "<<ptr->name<<" "<<ptr->price<<endl;
		inorder(ptr->right);
	}
}
void control::search(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	if(loc != NULL)
	{
		cout<<loc->key<<" "<<loc->name<<" "<<loc->price<<endl;
	}
	else
	{
		cout<<"Item doesn't exsist"<<endl;
	}
}
