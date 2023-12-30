#include "my_header.h"
int main()
{
	control c1;
	c1.insert(5, "A", NULL, NULL);
	c1.insert(9, "B", NULL, NULL);
	c1.insert(12, "C", NULL, NULL);
	c1.insert(13, "D", NULL, NULL);
	c1.insert(16, "E", NULL, NULL);
	c1.insert(45, "F", NULL, NULL);
	c1.level_order_traversel();
	c1.make_huffman_tree();
	c1.show_codes(c1.root, "");
}
