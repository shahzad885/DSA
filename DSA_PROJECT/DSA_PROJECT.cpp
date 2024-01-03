#include<graphics.h>
#include<iostream>
using namespace std;

//#define MAX 20

struct edge {
    char dest;
    edge* link = NULL;
};

struct Queue {
    struct node* vertix = NULL;
    struct Queue* link = NULL;
} * rear = NULL, * front = NULL;

struct node {
    char name;
    int index;
    edge* adj = NULL;
    node* next = NULL;
} * start = NULL;;

void insert_node(char ch, int index);
node* find(char ch);
void insert_edge(char source, char dest);
void delete_node(char ch);
void delete_edge(char source, char dest);
void delnode_edge(char dest);
void display();
void bfs(char v);
void visualize(char arr[], int counter, struct Queue* front);
void push(node* vertix);
node* pop();
void qdisplay();
void displayIntro();
void displayProcedure();
void displayExample();
void displayTC();
void quiz();


int main() {
    
    cout<<"  ---------------------------------------      WELCOME TO BFS TUTORIAL       ----------------------------------------- "<<endl;

    int choice;
    while(true){
    	cout<<endl;
    	cout<<endl;
    	cout<<"1.INTRODUCTION"<<endl;
    	cout <<"2.EXAMPLE"<<endl;
        cout << "3.PROCEDURE"<<endl;
        cout << "4.TIME COMPLEXITY"<<endl;
        cout << "5.VISUALIZATION "<<endl;
        cout << "6.QUIZ"<<endl;
    
        
        cout << "Enter your choice: ";
        cin >> choice;
        
        
        switch (choice) {
           
            case 1:
            	displayIntro();
           	    break;
		   	case 2:
		   		
		   		displayExample();
		   		break;
		   		
		   	case 3:
		   		displayProcedure();
		   		break;
		   		
		   	case 4:
		   	 displayTC();
		   		break;
		   		
		    case 5:
			initwindow(1380, 820);
    		settextstyle(10, 0, 1); 
		    insert_node('A', 0);
		    insert_node('B', 1);
		    insert_node('C', 2);
		    insert_node('D', 3);
		    insert_node('E', 4);
		    insert_edge('A', 'B');
		    insert_edge('B', 'A');
		    insert_edge('A', 'C');
		    insert_edge('C', 'A'); 
		    insert_edge('A', 'D');   
		    insert_edge('D', 'A'); 
		    insert_edge('A', 'E');
		    insert_edge('E', 'A'); 
		    insert_edge('B', 'C'); 
		    insert_edge('C', 'B'); 
		    insert_edge('C', 'D');
		    insert_edge('D', 'C'); 
		
		    bfs('A');
		    getch();
		    closegraph();
		    break;
		    
		    case 6:
                quiz();
                break;
           
            default:
            cout << "Invalid choice" << endl;
          
           
		}
	}//while
    return 0;
}

void push(node* vertix) {
    struct Queue* temp = new Queue();
    temp->vertix = vertix;
    if (front == NULL) {
        front = temp;
    }
    else {
        rear->link = temp;
    }
    rear = temp;
}

node* pop() {
    if (front != NULL) {
        node* data = front->vertix;
        front = front->link;
        return data;
    }
    else {
        cout << "Stack underflow: ";
        rear = NULL;
        front = NULL;
        return NULL;
    }
}

void qdisplay() {
    struct Queue* q = front;
    while (q != NULL) {
        cout << q->vertix->name << endl;
        q = q->link;
    }
}

void insert_node(char ch, int index) {
    node* temp = new node();
    temp->name = ch;
    temp->index = index;
    node* ptr = start;
    if (start == NULL) {
        start = temp;
        return;
    }
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

node* find(char ch) {
    node* ptr = start;
    while (ptr != NULL) {
        if (ptr->name == ch) {
            break;
        }
        else {
            ptr = ptr->next;
        }
    }
    return ptr;
}

void insert_edge(char source, char dest) {
    edge* ptr;
    edge* temp = new edge();
    node* u = find(source);
    node* v = find(dest);
    if (u == NULL) {
        cout << "Source doesn't exist" << endl;
        return;
    }
    else if (v == NULL) {
        cout << "Destination doesn't exist" << endl;
        return;
    }
    temp->dest = dest;
    if (u->adj == NULL) {
        u->adj = temp;
        return;
    }
    ptr = u->adj;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void delete_node(char ch) {
    node* q = start;
    node* temp;
    if (q->name == ch) {
        temp = start;
        start = start->next;
        delete (temp);
        return;
    }
    while (q->next->next != NULL) {
        if (q->next->name == ch) {
            temp = q->next;
            q->next = q->next->next;
            delete (temp);
            return;
        }
        q = q->next;
    }
    if (q->next->name == ch) {
        temp = q->next;
        q->next = NULL;
        delete (temp);
        return;
    }
}

void delete_edge(char source, char dest) {
    node* ptr = start;
    edge* temp, * q;
    node* u = find(source);
    if (u == NULL) {
        cout << "Source doesn't exist" << endl;
        return;
    }
    if (u->adj->dest == dest) {
        temp = u->adj;
        u->adj = u->adj->link;
        delete (temp);
        return;
    }
    q = u->adj;
    while (q->link->link != NULL) {
        if (q->link->dest == dest) {
            temp = q->link;
            q->link = q->link->link;
            delete (temp);
            return;
        }
        q = q->link;
    }
    if (q->link->dest == dest) {
        temp = q->link;
        q->link = NULL;
        delete (temp);
        return;
    }
}

void delnode_edge(char dest) {
    node* ptr = start;
    edge* temp, * q;
    while (ptr != NULL) {
        if (ptr->adj->dest == dest) {
            temp = ptr->adj;
            ptr->adj = ptr->adj->link;
            delete (temp);
            continue;
        }
        q = ptr->adj;
        while (q->link->link != NULL) {
            if (q->link->dest == dest) {
                temp = q->link;
                q->link = q->link->link;
                delete (temp);
                continue;
            }
            q = q->link;
        }
        if (q->link->dest == dest) {
            temp = q->link;
            q->link = NULL;
            delete (temp);
        }
        ptr = ptr->next;
    }
}

void display() {
    node* ptr = start;
    edge* q = NULL;
    while (ptr != NULL) {
        q = ptr->adj;
        cout << ptr->name << " : ";
        while (q != NULL) {
            cout << q->dest << " , ";
            q = q->link;
        }
        cout << endl;
        ptr = ptr->next;
    }
}

void bfs(char v) {
	int MAX =20;
    bool visited[MAX];
    char temp_array[MAX];
    int counter = 0;
    for (int i = 0; i < 20; i++) {
        visited[i] = false;
    }
    node* temp = NULL, * temp2 = NULL;
    node* q = find(v);
    cout << q->name << ", ";
    push(q);
    temp_array[counter] = q->name;
    counter++;
    // 1. Clear Screen 2. Iterate on temp_array 3. Iterate on queue
    visualize(temp_array, counter, front);
    getch();
    visited[q->index] = true;
    while (rear != NULL && front != NULL) {
        temp = pop();
        // 1. Clear Screen 2. Iterate on temp_array 3. Iterate on queue
        visualize(temp_array, counter, front);
        getch();
        edge* adj = temp->adj;
        while (adj != NULL) {
            temp2 = find(adj->dest);
            if (visited[temp2->index] == false) {
                cout << temp2->name << ", ";
                visited[temp2->index] = true;
                push(temp2);
                temp_array[counter] = temp2->name;
                counter++;
            }
            adj = adj->link;
        }
        // 1. Clear Screen 2. Iterate on temp_array 3. Iterate on queue
        visualize(temp_array, counter, front);
        getch();
    }
}

void visualize(char arr[], int counter, Queue* front) {
    cleardevice();
    string s1, s2;
    int output_x = 1050, output_y = 100, radius = 25;
    int rect_x = 50, rect_y = 50, width = 50, height = 50;
    outtextxy(rect_x - 5, 20, "Queue ");
    outtextxy(output_x - 32, output_y - 60, "BFS Traversed");
    line(rect_x - 5, rect_y - 5, 900, rect_y - 5);
    line(rect_x - 5, rect_y + height + 10, 900, rect_y + height + 10);
    for (int i = 0; i < counter; i++) {
        s1 = arr[i];
        circle(output_x, output_y, radius);
        outtextxy(output_x - 15, output_y - 15, &s1[0]);
        output_y = output_y + 80;
    }
    Queue* q = front;
    while (q != NULL) {
        rectangle(rect_x, rect_y, rect_x + width, rect_y + height);
        s2 = q->vertix->name;
        outtextxy(rect_x + 15, rect_y + 15, &s2[0]);
        rect_x = rect_x + 60;
        q = q->link;
    }
}

void displayIntro() {
    // Initialize graphics mode
    initwindow(1280, 800, "BFS INTRO");
    setbkcolor(WHITE);
    cleardevice();

    // Load image
    readimagefile("img/intro.jpg", 0, 0, 800, 200);  

    // Wait for user input
    getch();

    // Close graphics mode
    closegraph();



}

void displayProcedure(){
	
    initwindow(1280, 650, "FS");
    setbkcolor(WHITE);
    cleardevice();

    // Load image
    readimagefile("img/procedure.jpg", 0, 0, 900, 350);  

    // Wait for user input
    getch();

    // Close graphics mode
    closegraph();
	
}
void displayExample(){
	
	
	 initwindow(1280, 650, "BFS EXAMPLE");
    setbkcolor(WHITE);
    cleardevice();

    // Load image
    readimagefile("img/example.jpg", 0, 0, 900, 600);  

    // Wait for user input
    getch();

    // Close graphics mode
    closegraph();
}


void displayTC(){
initwindow(1380, 650, "FS");
    setbkcolor(WHITE);
    cleardevice();

    // Load image
    readimagefile("img/TC.jpg", 0, 0, 1080, 600);  

    // Wait for user input
    getch();

    // Close graphics mode
    closegraph();
}




void showresult(int correct,int incorrect) {
    system("CLS");
    cout << "Quiz Results:" << endl;
    cout << "Correct Answers: " << correct << endl;
    cout << "Incorrect Answers: " << incorrect << endl;
}

void quiz() {
	int incorrect = 0;
    int correct = 0;
    int i = 0;
    char choice[50];

    // Question 1
system("CLS");
cout << "1. What does BFS stand for in the context of graph traversal?" << endl;
cout << "   a. Best-First Search" << endl;
cout << "   b. Breadth-First Search" << endl;
cout << "   c. Binary-First Search" << endl;
cout << "   d. Balanced-First Search" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}

// Question 2
system("CLS");
cout << "2. Which data structure is typically used to implement the BFS algorithm?" << endl;
cout << "   a. Stack" << endl;
cout << "   b. Queue" << endl;
cout << "   c. Array" << endl;
cout << "   d. Linked List" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}

// Question 3
system("CLS");
cout << "3. In BFS, which vertex is processed first?" << endl;
cout << "   a. The vertex with the lowest index" << endl;
cout << "   b. The vertex with the highest index" << endl;
cout << "   c. Any random vertex" << endl;
cout << "   d. The vertex at the front of the queue" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'd') {
    correct++;
}
else
{
	incorrect++;
}

// Question 4
system("CLS");
cout << "4. What is the main advantage of BFS over DFS (Depth-First Search)?" << endl;
cout << "   a. Simplicity" << endl;
cout << "   b. Memory Efficiency" << endl;
cout << "   c. Time Efficiency" << endl;
cout << "   d. All of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'd') {
    correct++;
}
else
{
	incorrect++;
}

// Question 5
system("CLS");
cout << "5. In a graph, what does an edge represent in BFS?" << endl;
cout << "   a. A connection between two vertices" << endl;
cout << "   b. A loop in the graph" << endl;
cout << "   c. A directed path" << endl;
cout << "   d. A disconnected node" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}

// Question 6
/*system("CLS");
cout << "6. How is BFS implemented in C++ for graph traversal?" << endl;
cout << "   a. Recursion" << endl;
cout << "   b. Iteration" << endl;
cout << "   c. Both a and b" << endl;
cout << "   d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 7
system("CLS");
cout << "7. What is the purpose of the visited array in BFS?" << endl;
cout << "   a. To store the vertices" << endl;
cout << "   b. To mark visited vertices" << endl;
cout << "   c. To keep track of the queue" << endl;
cout << "   d. To store the graph structure" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 8
system("CLS");
cout << "8. Which of the following is a standard library used in C++ for queues?" << endl;
cout << "   a. stack" << endl;
cout << "   b. list" << endl;
cout << "   c. queue" << endl;
cout << "   d. set" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 9
system("CLS");
cout << "9. In BFS, what is the time complexity for visiting all vertices in a graph with V vertices and E edges?" << endl;
cout << "   a. O(V)" << endl;
cout << "   b. O(E)" << endl;
cout << "   c. O(V + E)" << endl;
cout << "   d. O(log V)" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 10
system("CLS");
cout << "10. What happens if a graph contains a cycle in BFS traversal?" << endl;
cout << "    a. The algorithm terminates successfully" << endl;
cout << "    b. It leads to an infinite loop" << endl;
cout << "    c. The cycle is ignored" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 11
system("CLS");
cout << "11. Which operation is performed on the nodes during BFS?" << endl;
cout << "    a. Insertion" << endl;
cout << "    b. Deletion" << endl;
cout << "    c. Both a and b" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 12
system("CLS");
cout << "12. What is the space complexity of BFS?" << endl;
cout << "    a. O(V)" << endl;
cout << "    b. O(E)" << endl;
cout << "    c. O(V + E)" << endl;
cout << "    d. O(1)" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 13
system("CLS");
cout << "13. In BFS, which vertex is explored first in a graph with multiple connected components?" << endl;
cout << "    a. Any random vertex" << endl;
cout << "    b. The vertex with the lowest index" << endl;
cout << "    c. The vertex with the highest index" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 14
system("CLS");
cout << "14. What is the role of the queue in BFS?" << endl;
cout << "    a. To store vertices in a random order" << endl;
cout << "    b. To store vertices in a sorted order" << endl;
cout << "    c. To maintain the order of traversal" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 15
system("CLS");
cout << "15. Which of the following is a real-world application of BFS?" << endl;
cout << "    a. Web Crawling" << endl;
cout << "    b. Sorting Arrays" << endl;
cout << "    c. Binary Search" << endl;
cout << "    d. QuickSort" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}

// Question 16
system("CLS");
cout << "16. What is the output of BFS on an unweighted graph with multiple connected components?" << endl;
cout << "    a. Single tree" << endl;
cout << "    b. Multiple trees" << endl;
cout << "    c. Single path" << endl;
cout << "    d. Single node" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 17
system("CLS");
cout << "17. How does BFS guarantee that the shortest path is found in an unweighted graph?" << endl;
cout << "    a. It considers the vertices in ascending order" << endl;
cout << "    b. It considers the vertices in descending order" << endl;
cout << "    c. It considers all vertices at once" << endl;
cout << "    d. It doesn't guarantee the shortest path" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 18
system("CLS");
cout << "18. In BFS, what is the role of the adjacency list?" << endl;
cout << "    a. To store the vertices" << endl;
cout << "    b. To store the edges" << endl;
cout << "    c. To store the graph structure" << endl;
cout << "    d. To store the visited vertices" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 19
system("CLS");
cout << "19. What is the purpose of the queue in BFS?" << endl;
cout << "    a. To store the graph vertices" << endl;
cout << "    b. To maintain the order of traversal" << endl;
cout << "    c. To store the visited vertices" << endl;
cout << "    d. To store the edges" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}

// Question 20
system("CLS");
cout << "20. In BFS, what happens if a vertex is encountered but is already marked as visited?" << endl;
cout << "    a. It is ignored" << endl;
cout << "    b. It is added to the queue" << endl;
cout << "    c. It leads to an error" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}

// Question 21
system("CLS");
cout << "21. How is the initial vertex added to the queue in BFS?" << endl;
cout << "    a. Push operation" << endl;
cout << "    b. Pop operation" << endl;
cout << "    c. Front operation" << endl;
cout << "    d. Rear operation" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}

// Question 22
system("CLS");
cout << "22. What is the time complexity of BFS on a sparse graph?" << endl;
cout << "    a. O(V)" << endl;
cout << "    b. O(E)" << endl;
cout << "    c. O(V + E)" << endl;
cout << "    d. O(log V)" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}

// Question 23
system("CLS");
cout << "23. In BFS, what does the 'front' pointer of the queue represent?" << endl;
cout << "    a. The first element of the queue" << endl;
cout << "    b. The last element of the queue" << endl;
cout << "    c. The middle element of the queue" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}

// Question 24
system("CLS");
cout << "24. What is the output of BFS on a disconnected graph?" << endl;
cout << "    a. Single tree" << endl;
cout << "    b. Multiple trees" << endl;
cout << "    c. Single path" << endl;
cout << "    d. Single node" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}

// Question 25
system("CLS");
cout << "25. What is the role of the 'visited' array in BFS?" << endl;
cout << "    a. To store the graph structure" << endl;
cout << "    b. To mark visited vertices" << endl;
cout << "    c. To store the queue" << endl;
cout << "    d. To store the edges" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}*/

//    	// Question 25
//    system("CLS");
//    cout << "?*
//    cout << "   a. " << endl;
//    cout << "   b." << endl;
//    cout << "   c. " << endl;
//    cout << "   d. " << endl;
//    cout << "Enter Your Answer" << endl;
//    cin >> choice[i++];
//    if (choice[i - 1] == 'd') {
//        correct++;
//    }
//    
  


   

    showresult(correct,incorrect);
}

