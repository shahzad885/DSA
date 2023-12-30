//Stack - Array

#include<iostream>
using namespace std;


int stack[5];
int top = -1;

void push(int n )
{
	//int stack,top;
	
	if( top == 5 )
	{
		cout<<" Overflow !!";
	}
	else
	{
		top++;
		stack[top] = n;
		
	}
	
}
void pop(){
	
	if ( top == -1){
		cout<<"Underflow";
	}
	else
	{
		cout << " item removed";
		top--;
	}
}

void display()
{
	cout<<"The array is:"<<endl;
	for(int i=0;i<=top;i++)
	{
		cout<<stack[i]<<endl;
	}
}
int main(){
	
	//int choice;
    int n,values;

    while (1)
    {
        cout << "1.Push" << endl;
        cout << "2. Pop " << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
        	int values;
			cout<<"enter values :";
			cin>>values;
            push(values);
          
            break;

        case 2:
            
            pop();
            break;
            
        case 3:
				display();
				break;
	
		case 4:
				exit(1);
				
		default:
				break;
  }
}
    return 0;
	
	
}


