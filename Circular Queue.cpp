#include <iostream>
using namespace std;

class CircularQueue
{
private:
	int front;
	int rear;
	int arr[5];
	int itemCount;
public:
	CircularQueue()
	{
		itemCount = 0;
		front = -1;
		rear = -1;
		for (int i = 0; i < 5; i++)
		{
			arr[i] = 0;
		}
	}
	bool isEmpty()
	{
		if (front && rear == -1)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if ((rear+1)%5 == front)
			return true;
		else
			return false;
	}
	void Enqueue(int val)
	{
		if (isFull())
		{
			cout << "Queue is full" << endl;
			return;
		}

		else if (isEmpty())
		{
			rear = 0;
			front = 0;
			arr[rear] = val;
			itemCount++;
		}

		else
		{
			rear = (rear + 1) % 5;
			arr[rear] = val;
			itemCount++;
		}
	}
	int dequeue()
	{
		int deval;
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return 0;
		}
		else if (front == rear)
		{
			deval = arr[front];
			arr[front] = 0;
			front = -1;
			rear = -1;
			itemCount--;
			return deval;
		}
		else
		{
			deval = arr[front];
			arr[front] = 0;
			front = (front + 1) % 5;
			itemCount--;
			return deval;
		}
	}
	int count()
	{
		return itemCount;
	}
	void display()
	{
		cout << "Values in the Queue" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << "  ";
		}
	}

};

int main()
{
	CircularQueue q1;

	int option, value;

	do
	{
		cout << "What operation do you want to perform on the queue? Select an option. Enter 0 to exit." << endl;
		cout << "1. Enqueue() " << endl;
		cout << "2. Dequeue() " << endl;
		cout << "3. isEmpty() " << endl;
		cout << "4. isFull() " << endl;
		cout << "5. count()" << endl;
		cout << "6. display() " << endl;
		cout << "7. Clear Screen " << endl;

		cin >> option;

		switch (option)
		{
		case 0:
			return 0;
		case 1:
			cout << "Enqueue Option - Enter a value to insert in the queue: " << endl;
			cin >> value;
			q1.Enqueue(value);
			break;
		case 2:
			cout << "Dequeue Option - The value removed: " << q1.dequeue() << endl;
			break;
		case 3:
			cout << "isEmpty Option - " << endl;
			if (q1.isEmpty())
				cout << "Queue is Empty" << endl;
			else
				cout << "Queue is not Empty" << endl;
			break;
		case 4:
			cout << "isFull Option - " << endl;
			if (q1.isFull())
				cout << "Queue is Full" << endl;
			else
				cout << "Queue is not Full" << endl;
			break;
		case 5:
			cout << "count Option - Total values in the queue: " << q1.count() << endl;
			break;
		case 6:
			cout << "Display Option - " << endl;
			q1.display();
			cout << endl;
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter proper option numnber" << endl;
			break;
		}
	} while (option != 0);
	return 0;
}