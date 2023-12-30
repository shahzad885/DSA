#include "my_header.h"
using namespace std;
int control::height(node *ptr)
{
	if(ptr == NULL)
	{
		return -1;
	}
	else
	{
		int lh=height(ptr->left);
		int rh=height(ptr->right);
		if(lh>rh)
		{
			return lh+1;
		}
		else
		{
			return rh+1;
		}
	}
}
int control::getbalance(node *ptr)
{
	if(ptr == NULL)
	{
		return -1;
	}
	else
	{
		return height(ptr->left)-height(ptr->right);
	}
}
node* control::rightRotation(node *ptr)
{
	node *aptr=ptr->right;
	node *temp=aptr->left;
	aptr->left=ptr;
	ptr->right=temp;
	//Parent Swapping
	aptr->parent=ptr->parent;
	ptr->parent=aptr;
	if(temp != NULL)
	temp->parent=ptr;
	return aptr;
	
}
node* control::leftRotation(node *ptr)
{
	node *aptr=ptr->left;
	node *temp=aptr->right;
	aptr->right=ptr;
	ptr->left=temp;
	//Parent Swapping
	aptr->parent=ptr->parent;
	ptr->parent=aptr;
	if(temp != NULL)
	temp->parent=ptr;
	return aptr;
}
node* control::insert(int key, int price, string name, string dia_info, bool status, node *ptr, node *parent)
{
	//Insertion
	if(ptr == NULL)
	{
		ptr=new node();
		ptr->key=key;
		ptr->price=price;
		ptr->name=name;
		ptr->diatery_info=dia_info;
		ptr->status=status;
		ptr->parent=parent;
		return ptr;
	}
	else if(key < ptr->key)
	{
		ptr->left=insert(key, price, name, dia_info, status, ptr->left, ptr);
	}
	else if(key> ptr->key)
	{
		ptr->right = insert(key, price, name, dia_info, status, ptr->right, ptr);
	}
	else
	{
		cout<<"Duplicates Not Allowed"<<endl;
		return ptr;
	}
	//Rotation
	int balance=getbalance(ptr);
	//Case-1: Left-to-Left
	if(balance > 1 && key< ptr->left->key)
	{
		return leftRotation(ptr);
	}
	//Case-2: Right-to-Right
	else if(balance < -1 && key > ptr->right->key)
	{
		return rightRotation(ptr);
	}
	//Case-3: Left-to-Right
	else if(balance > 1 && key > ptr->left->key)
	{
		ptr->left=rightRotation(ptr->left);
		return leftRotation(ptr);
	}
	//Case-4: Right-to-Left
	else if(balance < -1 && key < ptr->right->key)
	{
		ptr->right=leftRotation(ptr->right);
		return rightRotation(ptr);
	}
	return ptr;
}
node* control::del(node *ptr, int key)
{
	if(ptr == NULL)
	{
		return ptr;
	}
	else
	{
		if(ptr->key > key)
		{
			ptr->left=del(ptr->left, key);
		}
		else if(ptr->key <key)
		{
			ptr->right=del(ptr->right, key);
		}
		else
		{
			if(ptr->left == NULL)//Right Child or no Child
			{
				node *temp=ptr->right;
				if(temp != NULL)
				temp->parent=ptr->parent;
				delete(ptr);
				return temp;
			}
			else if(ptr->right == NULL)//Left Child or no Child
			{
				node *temp=ptr->left;
				if(temp != NULL)
				temp->parent=ptr->parent;
				delete(ptr);
				return temp;
			}
			else //With Two Childs: Inorder  Successor
			{
				node *temp=ptr->right;
				while(temp->left != NULL)
				{
					temp=temp->left;
				}
				ptr->key=temp->key;
				ptr->name=temp->name;
				ptr->price=temp->price;
				ptr->status=temp->status;
				ptr->right=del(ptr->right, temp->key);
			}
		}
		//Balancing
		int balance=getbalance(ptr);
		//Case A: Right to Right
		if(balance == -2 && getbalance(ptr->right) <=0)
		{
			return rightRotation(ptr);
		}
		//Case B: Right to Left
		else if(balance ==-2 && getbalance(ptr->right)==1)
		{
			ptr->right=leftRotation(ptr->right);
			return rightRotation(ptr);
		}
		//Case C: Left to Left
		else if(balance == 2 && getbalance(ptr->left) >= 0)
		{
			return leftRotation(ptr);
		}
		//Case D: Left to Right
		else if(balance == 2 && getbalance(ptr->left) == -1)
		{
			ptr->left=rightRotation(ptr->left);
			return leftRotation(ptr);
		}
		return ptr;
	}
}
void control::find_by_key(int key, node *&parent, node *&loc)
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
void control::search_by_key(int key)
{
	node *parent, *loc;
	find_by_key(key, parent, loc);
	if(loc != NULL)
	{
		cout<<loc->key<<" "<<loc->name<<" "<<loc->price<<" "<<loc->diatery_info<<" Available: "<<loc->status<<endl;
	}
	else
	{
		cout<<"Item doesn't exsist"<<endl;
	}
}
void control::find_by_name(string name, node *ptr, node *&loc)
{
	if(ptr == NULL)
	{
		return ;
	}
	else if(ptr->name == name)
	{
		loc=ptr;
		return ;
	}
	else
	{
		find_by_name(name, ptr->left, loc);
		find_by_name(name, ptr->right, loc);
	}
}
void control::search_by_name(string name)
{
	node *loc=NULL;
	find_by_name(name, root, loc);
	if(loc != NULL)
	{
		cout<<loc->key<<" "<<loc->name<<" "<<loc->price<<" "<<loc->diatery_info<<" Available: "<<loc->status<<endl;
	}
	else
	{
		cout<<"Name doesn't exsist"<<endl;
	}
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
		cout<<ptr->key<<" "<<ptr->name<<" "<<ptr->price<<" "<<ptr->diatery_info<<" Available: "<<ptr->status<<endl;
		inorder(ptr->right);
	}
}
