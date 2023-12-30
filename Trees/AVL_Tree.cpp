#include<iostream>
using namespace std;
struct node
{
	int key;
	int balance;
	node *right=NULL, *left=NULL;
} *root=NULL;

node *insert(int key, node *pptr, bool &ht_inc)
{
	node *aptr, *bptr;
	if(pptr== NULL)
	{
		pptr=new node();
		pptr->key=key;
		pptr->balance=0;
		ht_inc=true;
		return pptr;
	}
	else
	{
		if(pptr->key > key)
		{
			pptr->left=insert(key, pptr->left, ht_inc);
			if(ht_inc == true)
			{
				switch(pptr->balance)
				{
					case -1:
						pptr->balance=0;
						ht_inc=false;
						break;
					case 0:
						pptr->balance=1;
						break;
					case 1:
						aptr=pptr->left;
						if(aptr->balance == 1)//left to left rotation
						{
							pptr->left=aptr->right;
							aptr->right=pptr;
							aptr->balance=0;
							pptr->balance=0;
							pptr=aptr;
						}
						else//Left to right rotation
						{
							bptr=aptr->right;
							//Move
							aptr->right=bptr->left;
							bptr->left=aptr;
							pptr->left=bptr->right;
							bptr->right=pptr;
						
							//Balancing
							if(bptr->balance == 1)
							{
								pptr->balance=-1;
							}
							else
							{
								pptr->balance=0;
							}
							if(bptr->balance == -1)
							{
								aptr->balance=1;
							}
							else
							{
								aptr->balance=0;
							}
							bptr->balance=0;
							pptr=bptr;
						}
						ht_inc=false;
						break;	
				}
			}
		}
		if(pptr->key < key)
		{
			pptr->right=insert(key, pptr->right, ht_inc);
			if(ht_inc == true)
			{
				switch(pptr->balance)
				{
					case 1:
						pptr->balance=0;
						ht_inc=false;
						break;
					case 0:
						pptr->balance=-1;
						break;
					case -1:
						aptr=pptr->right;
						if(aptr->balance == -1)//right to right rotation
						{
							pptr->right=aptr->left;
							aptr->left=pptr;
							aptr->balance=0;
							pptr->balance=0;
							pptr=aptr;
						}
						else
						{
							bptr=aptr->left;
							//Move
							aptr->left=bptr->right;
							bptr->right=aptr;
							pptr->right=bptr->left;
							bptr->left=pptr;
							//Balancing
							if(bptr->balance==-1)
							{
								pptr->balance=1;
							}
							else
							{
								pptr->balance=0;
							}
							if(bptr->balance == 1)
							{
								aptr->balance=-1;
							}
							else
							{
								aptr->balance=0;
							}
							bptr->balance=0;
							pptr=bptr;
						}
						ht_inc=false;
						break;
				}
			}
		}
		return pptr;
	}
}
void inorder(node *ptr)
{
	if(ptr== NULL)
	{
		return ;
	}
	else
	{
		inorder(ptr->left);
		cout<<ptr->key<<endl;
		inorder(ptr->right);
	}
}
int main()
{
	bool ht_inc;
	root=insert(20, root, ht_inc);
	root=insert(18, root, ht_inc);
	root=insert(11, root, ht_inc);
	root=insert(46, root, ht_inc);
	root=insert(33, root, ht_inc);
	root=insert(7, root, ht_inc);
	root=insert(96, root, ht_inc);
	inorder(root);
}
