#include<iostream>
#include"queues.h"
using namespace std;
int main()
{
	int choice,n,m;
	queue s1;
	while(1)
	{
		cout<<"1. PUSH"<<endl;
		cout<<"2. POP"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. Quit"<<endl;

		cout<<"Enter ur choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"How many elements u want to push:"<<endl;
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cout<<"Enter the element"<<endl;
					cin>>m;
					s1.push(m);
				}
				break;
			
			case 2:
				s1.pop();
				break;
			case 3:
				s1.display();
				break;
			case 4:
				exit(1);
			default:
				cout<<"Wrong choice"<<endl;
		}
	}
	return 0;
}
