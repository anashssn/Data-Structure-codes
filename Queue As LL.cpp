#include <iostream>
#include <cstdlib>
using namespace std;

class node
{
public:
	int data;
	node* link;
	node()
	{
	    data= 0;
	    link = NULL;
	}
	node(int d)
	{
	    data = d;
	}
};

class queueAsLL
{
public:
	node* f = NULL;
	node* r = NULL;

	bool isEmpty()
	{
		if (f == NULL && r == NULL)
			return true;
		else
			return false;
	}
	void enqueue(int value)
	{
		node* ptr = new node();
		ptr->data = value;
		ptr->link = NULL;

		if (f == NULL && r == NULL)
		{
			f = ptr;
			r = ptr;
		}
		else
		{
			r->link = ptr;
			r = ptr;
		}
		cout<<"Enqueued"<<endl;
	}
	void dequeue()
	{
	    node* ptr = f;

		if (isEmpty())
			cout << "Queue is empty" << endl;
		else
			if (f == r)
            {
				f = r = NULL;
			}
			else
			{
				f = f->link;
			}
			free(ptr);
			cout<<"Dequeued"<<endl;
	}
	void displayQueue()
	{
		if (isEmpty())
			cout << "Queue is empty" << endl;
		else
		{
		    cout<<"The elements of the Queue are: "<<endl;
			node* ptr = f;
			while (ptr != NULL)
			{
				cout << ptr->data << " ";
				ptr = ptr->link;
			}
		}
	}
};
int main()
{
	queueAsLL q;
	int option;
	int val;
	do
	{
	    cout<<endl;
		cout << "What operation do you want to perform? Enter 0 to exit. " << endl;
		cout << "1. isEmpty" << endl;
		cout << "2. Enqueue" << endl;
		cout << "3. Dequeue" << endl;
		cout << "4. Display" << endl;
        cout<<endl;
		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			if (q.isEmpty())
				cout << "Queue is empty" << endl;
			else
				cout << "Queue is not empty" << endl;
			break;
		case 2:
			cout << "Enter the value you want to enqueue" << endl;
			cin >> val;
			q.enqueue(val);
			break;
		case 3:
			q.dequeue();
		case 4:
			q.displayQueue();
				break;
		default:
			cout << "Enter proper number" << endl;
		}
	}while(option!=0);
return 0;
}
