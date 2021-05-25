#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *front = NULL;
node *rear = NULL;
node *temp;
void enqueue()
{
	int val;
	cout << "Insert the element in queue : " << endl;
	cin >> val;
	if (rear == NULL)
	{
		rear = new node();
		rear->data = val;
		rear->next = NULL;
		front = rear;
	}
	else
	{
		temp = new node();
		temp->data = val;
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
	}
}
void dequeue()
{
	temp = front;
	if (front == NULL)
	{
		cout << "Underflow" << endl;
		return;
	}
	else
		if (temp->next != NULL) {
			temp = temp->next;
			cout << "Element deleted from queue is : " << front->data << endl;
			delete front;
			front = temp;
		}
		else
		{
			cout << "Element deleted from queue is : " << front->data << endl;
			delete front;
			front = NULL;
			rear = NULL;
		}
}
void Display()
{
	temp = front;
	if ((front == NULL) && (rear == NULL))
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "Queue elements are: ";
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	int ch;
	cout << "1) Insert element to queue" << endl;
	cout << "2) Delete element from queue" << endl;
	cout << "3) Display all the elements of queue" << endl;
	cout << "4) Exit" << endl;
	do
	{
		cout << "Enter your choice : " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: enqueue(); break;
		case 2: dequeue(); break;
		case 3: Display(); break;
		case 4: cout << "Exit" << endl; break;
		default: cout << "Invalid choice" << endl;
		}
	} while (ch != 4);
	return 0;
}