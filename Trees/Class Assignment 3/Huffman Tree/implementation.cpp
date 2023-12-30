
#include "my_header.h"
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

void control::insert(int key, string name, node *sub_left, node *sub_right)
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
node * control::pop()
{
	node *loc=root;
	node *lastNode=get_last_node();
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
		total_item(ptr->sub_left, count);
		total_item(ptr->sub_right, count);
	}
}
void control::make_huffman_tree()
{
	node *ptr1;
	node *ptr2;
	node *temp;
	while(root->left != NULL || root->right != NULL)
	{
		ptr1=pop();
		ptr2=pop();
		insert(ptr1->key+ptr2->key, "?", ptr1, ptr2);
	}	
}
void control::show_codes(node *ptr, string code)
{
	if(ptr == NULL)
	{
		return;
	}
	else if(ptr->sub_left == NULL && ptr->sub_right == NULL)
	{
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
