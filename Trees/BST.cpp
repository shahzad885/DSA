#include<iostream>
using namespace std;
struct node
{
	int key;
	node *left=NULL;
	node *right=NULL;
} *root=NULL;

void find(int key, node *&parent, node *&loc)
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
void insert(int key)
{
	node *temp, *parent=NULL, *loc=NULL;
	find(key, parent, loc);
	if(loc != NULL)
	{
		cout<<"Ite Already Exsist"<<endl;
		return ;
	}
	temp=new node();
	temp->key=key;
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
void case_a(node *&parent, node *&loc)
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
void case_b(node *&parent, node *&loc)
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
void case_c(node *&parent, node *&loc)
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
void del(int key)
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
void inorder(node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	else
	{
		inorder(ptr->left);
		cout<<ptr->key<<endl;
		inorder(ptr->right);
	}
}
void pre_order(node *ptr)
{
	if(ptr== NULL)
	{
		return;
	}
	else
	{
		cout<<ptr->key<<endl;
		pre_order(ptr->left);
		pre_order(ptr->right);
	}
}
void post_order(node *ptr)
{
	if(ptr== NULL)
	{
		return;
	}
	else
	{
		post_order(ptr->left);
		post_order(ptr->right);
		cout<<ptr->key<<endl;
	}
}
int max_depth(node *ptr)
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
int specific_depth(int key, node *ptr, int count)
{
	if(ptr == NULL)
	{
		cout<<"Key does not exsist"<<endl;
	}
	else if(ptr->key == key)
	{
		return count;
	}
	else
	{
		if(key > ptr->key)
		{
			specific_depth(key, ptr->right, count+1);
		}
		else
		{
			specific_depth(key, ptr->left, count+1);
		}
	}
}
void display_terminal(node *ptr)
{
	if(ptr == NULL)
	{
		cout<<"Tree is Empty"<<endl;
		return ;
	}
	else if(ptr->left == NULL && ptr ->right== NULL)
	{
		cout<<ptr->key<<endl;
	}
	else
	{
		display_terminal(ptr->left);
		display_terminal(ptr->right);
	}
}
void inorder_successor(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	//Case 1: If has a right node
	if(loc->right != NULL)
	{
		node *ptr=loc->right;
		while(ptr->left != NULL)
		{
			ptr=ptr->left;
		}
		cout<<"Successor is: "<<ptr->key<<endl;
	}
	else //Case 2: Doesn't have a right node(For Leaf Node)
	{
		node *successor=NULL, *ancestor=root;
		while(loc != ancestor)
		{
			if(ancestor->key>loc->key)
			{
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
				cout<<"no successor found";
			}
		}
		cout<<"Successor is: "<<successor->key<<endl;
	}
}
void inorder_predecessor(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	if(loc -> left != NULL)
	{
		node *ptr=loc->left;
		while(ptr -> right != NULL)
		{
			ptr=ptr->right;
		}
		cout<<"Predecessor is: "<<ptr->key<<endl;
	}
	else
	{
		node *predicessor=NULL, *ancestor=root;
		while(ancestor != loc)
		{
			if(ancestor->key < loc->key)
			{
				predicessor=ancestor;
				ancestor=ancestor->right;
			}
			else
			{
				ancestor=ancestor->left;
			}
		}
		cout<<"Predecessor is: "<<predicessor->key<<endl; 
	}
}
void preorder_successor(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	if(loc->left != NULL)
	{
		cout<<"Preorder Successor: "<<loc->left->key<<endl;
	}
	else if(loc->right != NULL)
	{
		cout<<"Preorder Successor: "<<loc->right->key<<endl;
	}
	else //Leaf Case
	{
		node *ancestor=root, *successor=NULL;
		while(ancestor != loc)
		{
			if(ancestor->key > key)
			{
				if(ancestor->right != NULL)
				successor=ancestor->right;
				
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
			}
		}
		if(successor == NULL)
		{
			cout<<"Successor Doesn't exsist"<<endl;
		}
		else
		{
			cout<<"Preorder Successor: "<<successor->key<<endl;
		}
	}
}
void preorder_predecessor(int key)
{
	node *parent, *loc;
	//case - 1
	if(key==root->key)
	{
		cout<<"Root doesn't have predecessor"<<endl;
		return ;
	}
	find(key, parent, loc);
	
	//case - 2
	if(parent->left == NULL || parent->left == loc)
	{
		cout<<"Preorder Predecessor: "<<parent->key<<endl;
	}
	
	//case - 3
	else
	{
		node *predecessor=NULL;
		predecessor=parent->left;
		while(predecessor->right != NULL || predecessor->left != NULL)
		{
			if(predecessor->right != NULL)
			predecessor=predecessor->right;
			else
			predecessor=predecessor->left;
		}
		cout<<"Preorder Predecessor: "<<predecessor->key<<endl;
	}
}
void postorder_successor(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	if(key==root->key)
	{
		cout<<"Root does not have successor in postorder"<<endl;
	}
	else if(loc==parent->right || parent->right == NULL)
	{
		cout<<"Post-order successor: "<<parent->key<<endl;
	}
	else if(loc == parent->left)
	{
		node *ptr=parent->right;
		while(ptr->left !=NULL || ptr->right != NULL)
		{
			if(ptr->left !=NULL)
			ptr=ptr->left;
			else
			ptr=ptr->right;
		}
		cout<<"Post-order successor: "<<ptr->key<<endl;
	}
}
void postorder_predecessor(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	if(loc->right != NULL)
	{
		cout<<"Postorder Predecessor: "<<loc->right->key<<endl;
	}
	else if(loc->left != NULL)
	{
		cout<<"Postorder Predecessor: "<<loc->left->key<<endl;
	}
	else if(parent->left != NULL && parent->right == loc)
	{
		cout<<"Postorder Predecessor: "<<parent->left->key<<endl;
	}
	else 
	{
		node *ancestor=root, *predecessor;
		while(ancestor != loc)
		{
			if(ancestor->key<key)
			{
				if(ancestor->left != NULL)
					predecessor=ancestor;
				ancestor=ancestor->right;
			}
			else
			{
				ancestor=ancestor->left;
			}
		}
		cout<<"Postorder Predecessor: "<<predecessor->left->key<<endl;
	}
}
void display_having_two_childs(node *ptr)
{
	if(ptr == NULL)
	{
		return ;
	}
	else
	{
		if(ptr->left != NULL && ptr ->right!= NULL)
		{
			cout<<ptr->key<<endl;
		}
		display_having_two_childs(ptr->left);
		display_having_two_childs(ptr->right);
	}
}
void display_having_one_child(node *ptr)
{
	if(ptr == NULL)
	{
		return ;
	}
	else
	{
		if((ptr->left == NULL && ptr ->right!= NULL) || (ptr->left != NULL && ptr -> right== NULL))
		{
			cout<<ptr->key<<endl;
		}
		display_having_one_child(ptr->left);
		display_having_one_child(ptr->right);
	}
}
void position_with_parent(int key)
{
	node *parent, *loc;
	find(key, parent, loc);
	if(parent->left == loc)
	{
		cout<<"Its on left side"<<endl;
	}
	else
	{
		cout<<"Its on right side"<<endl;
	}
}
void print_level_nodes(node *ptr, int level)
{
	if(ptr == NULL)
	{
		return ;
	}
	else if(level == 0)
	{
		cout<<ptr->key<<" ";
	}
	else 
	{
		print_level_nodes(ptr->left, level-1);
		print_level_nodes(ptr->right, level-1);
	}
}
void level_order_traversel()
{
	int height=max_depth(root);
	for(int i=0; i<height; i++)
	{
		print_level_nodes(root, i);
		cout<<endl;
	}
}
void even_count(node *ptr, int &e)
{
	if(ptr == NULL)
	{
		return ;
	}
	
	else
	{
		if(ptr->key%2 ==0)
		{
			e=e+1;
		}
		even_count(ptr->left, e);
		even_count(ptr->right, e);
	}
}
int main()
{
	insert(20);
	insert(10);
	insert(26);
	insert(4);
	insert(18);
	insert(24);
//	insert(28);
//	insert(14);
////	insert(19);
//	insert(25);
	//insert(27);
//	insert(13);
//	cout<<"Max Depth is: "<<max_depth(root)-1<<endl;
//	cout<<"Depth of 20 is: "<<specific_depth(4, root, 0)<<endl;
	//del(40);
	//inorder(root);
	//pre_order(root);
	//post_order(root);
	//display_terminal(root);
	inorder_successor(26);
//	inorder_predecessor(14);
//	preorder_successor(13);
//	preorder_predecessor(26);
//	postorder_successor(19);
//	postorder_predecessor(13);
	//display_having_two_childs(root);
	//display_having_one_child(root);
//	position_with_parent(19.5);
//	level_order_traversel();
	//cout<<"Number of nodes: "<<count(root);
	/*int even=0;
	even_count(root, even);
	cout<<"Nodes with Even Key: "<<even<<endl;*/
	//cout<<"Number of Levels: "<<max_depth(root);
}
