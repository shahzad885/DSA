#include "my_header.h"
int main()
{
	control c1;
	c1.root=c1.insert(18, 12, "I1", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(15, 12, "I2", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(20, 12, "I3", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(10, 12, "I4", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(19, 12, "I5", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(35, 12, "I6", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(26, 12, "I7", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(38, 12, "I8", "P: 50, V: 99", true, c1.root, NULL);
	c1.root=c1.insert(24, 12, "I9", "P: 50, V: 99", true, c1.root, NULL);
	c1.inorder(c1.root);
	c1.root=c1.del(c1.root, 24);
	c1.root=c1.insert(55, 41, "I10", "P: 49, V: 12", false, c1.root, NULL);
	cout<<"After deleting & inserting"<<endl;
	c1.inorder(c1.root);
	c1.search_by_name("I2");
	return 0;
}
