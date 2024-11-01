#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* link;
};
class stackAsLL
{
public:
	Node* top;
	stackAsLL()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	void push(int value)
	{
		Node* ptr = new Node();
		ptr->data = value;
		ptr->link = top;
		top = ptr;
	}
	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			Node* ptr = top;
			int popvalue = top->data;
			top = top->link;
			return popvalue;
			delete(ptr);
		}
	}
	void showTop()
	{
		if (isEmpty())
			cout << "Stack is empty." << endl;
		else
			cout << "Element at top is: " << top->data;
	}
	void Display()
	{
		if (isEmpty())
			cout << "Stack is empty." << endl;
		else
		{
			cout << "Elements of stack are" << endl;
			Node* temp = top;
			while (temp != NULL)
			{
				cout << temp->data << endl;
				temp = temp->link;
			}
		}
	}
};
int main()
{
	stackAsLL s;
	int option;
	int val;
	do
	{
		cout << "What operation do you want to perform? Enter 0 to exit. " << endl;
		cout << "1. isEmpty" << endl;
		cout << "2. Push" << endl;
		cout << "3. Pop" << endl;
		cout << "4. Display Top" << endl;
		cout << "5. Display Stack" << endl;

		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			if (s.isEmpty())
				cout << "Stack is empty" << endl;
			else
				cout << "Stack is not empty" << endl;

			break;
		case 2:
			cout << "Enter the value you want to push" << endl;
			cin >> val;
			s.push(val);
			break;
		case 3:
			cout << "Pop value is: " << s.pop() << endl;
			break;
		case 4:
			s.showTop();
			break;
		case 5:
			s.Display();
			break;
		default:
			cout << "Enter proper number" << endl;
		}
	} while (option != 0);
	return 0;
}