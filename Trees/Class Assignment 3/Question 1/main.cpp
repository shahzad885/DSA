#include "my_header.h"
int main()
{
	control c1;
	c1.insert(1, 20, "Item 1");
	c1.insert(2, 11, "Item 2");
	c1.insert(3, 22, "Item 3");
	c1.insert(4, 32, "Item 4");
	c1.insert(5, 40, "Item 5");
	c1.del(3);
	c1.inorder(c1.root);
	cout<<"Searching"<<endl;
	c1.search(4);
	return 0;
}
