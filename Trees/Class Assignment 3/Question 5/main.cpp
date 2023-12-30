#include "my_header.h"
int main()
{
	control c1;
	c1.insert(71);
	c1.insert(67);
	c1.insert(16);
	c1.insert(64);
	c1.insert(14);
	c1.insert(31);
	c1.insert(54);
	c1.insert(93);
	c1.insert(40);
	c1.insert(76);
	c1.insert(7);
	c1.insert(19);
	//c1.level_order_traversel();
	//cout<<"Deleting 64 & 31"<<endl;
///	c1.del(71);
//	c1.del(67);
//	c1.del(16);
	c1.del(64);
//	c1.del(14);
	c1.del(31);
//	c1.del(54);
//	c1.del(93);
//	c1.del(40);
//	c1.del(76);
//	c1.del(7);
	c1.level_order_traversel();
	return 0;
}
