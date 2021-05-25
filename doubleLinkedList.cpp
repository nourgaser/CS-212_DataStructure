#include<iostream>
using namespace std;
struct node
{
	node *prev;
	int data;
	node *next;
};
class list
{
private:
	node *head, *tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void createnode(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		temp->prev = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}
	void displayFR()
	{
		node *temp;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
	void displayRF()
	{
		node *temp;
		temp = tail;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->prev;
		}
	}
	void insert_start(int value)
	{
		node *temp = new node;
		temp->data = value;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	void insert_position(int pos, int value)
	{
		node *pre=new node;
		node *cur=new node;
		node *temp = new node;
		cur = head;
		for (int i = 1; i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->data = value;
		temp->prev = pre;
		temp->next = cur;
		pre->next = temp;
		cur->prev = temp;
	}
	void delete_first()
	{
		node *temp;
		temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
	}
	void delete_last()
	{
		node *current;
		current = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete current;
	}
	void delete_position(int pos)
	{
		node *current=new node ;
		node *previous=new node;
		current = head;
		for (int i = 1; i < pos; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		delete current;
		current = previous->next;
		current->prev = previous;
	}
};
int main()
{
	list obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout << "\n--------------------------------------------------\n";
	cout << "---------------Displaying All nodes---------------";
	cout << "\n--------------------------------------------------\n";
	obj.displayFR(); 
	cout << "\n--------------------------------------------------\n";
	//obj.displayRF();
	
	/*
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Inserting At End-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.displayFR();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Inserting At Start----------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.displayFR();
	cout << "\n--------------------------------------------------\n";
	cout << "-------------Inserting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.insert_position(3, 60);
	obj.displayFR();
	cout << "\n--------------------------------------------------\n";
	cout << "----------------Deleting At Start-----------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_first();
	obj.displayFR();
	cout << "\n--------------------------------------------------\n";
	cout << "-----------------Deleing At End-------------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_last();
	obj.displayFR();*/
	cout << "\n--------------------------------------------------\n";
	cout << "--------------Deleting At Particular--------------";
	cout << "\n--------------------------------------------------\n";
	obj.delete_position(3);
	obj.displayFR();
	cout << "\n--------------------------------------------------\n";
	// system("pause");
	return 0;
}