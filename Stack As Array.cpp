#include <iostream>	
#include <string>
using namespace std;

class Stack {
	private:
		int top; // sabse upar walay element ko detect karega
		int arr[5];
	public:
		Stack() // constructor
		{
			top = -1; // abhi stack is empty
			for (int i = 0; i < 5; i++)
			{
				arr[i] = 0;
			}
		}

		bool isEmpty()
		{
			if (top == -1)
				return true;
			else
				return false;
		}

		bool isFull()
		{
			if (top == 4)
				return true;
			else
				return false;
		}

		void push(int val)
		{
			if (isFull())
			{
				cout << "stack overflow" << endl;
			}
			else
			{
				top++;
				arr[top] = val;
			}
		}

		int pop()
		{
			if (isEmpty())
			{
				cout << "stack underflow" << endl;
				return 0;
			}
			else
			{
				int popValue = arr[top];
				arr[top] = 0;
				top--;
				return popValue;
			}
		}

		int count()
		{
			return(top + 1);
		}

		int peek(int pos)
		{
			if (isEmpty())
			{
				cout << "stack underflow" << endl;
				return 0;
			}
			else
				return arr[pos];
		}

		void change(int pos, int val)
		{
			arr[pos] = val;
			cout << "Value has been changed at location " << pos << "to" << val << endl;
		}

		void display()
		{
			cout << "Values of stack are:" << endl;
			for (int i = 4; i <= 4; i--)
			{
				cout << arr[i] << endl;
			}
		}

};
int main()
{
	Stack s1; //object of class stack
	int option, position, value;

	do
	{
		cout << "What operation do you want to perform in the stack? Select a number form 1-9. Enter 0 to exit" << endl;
		cout << "1. Push() " << endl;
		cout << "2. Pop() " << endl;
		cout << "3. isEmpty() " << endl;
		cout << "4. isFull() " << endl;
		cout << "5. peek() " << endl;
		cout << "6. count() " << endl;
		cout << "7. change() " << endl;
		cout << "8. display() " << endl;
		cout << "9. Clear screen " << endl << endl;

		cin >> option;
		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Enter a value to push in the stack" << endl;
			cin >> value;
			s1.push(value);
			break;

		case 2:
			cout << "Popped value: " << s1.pop() << endl;
			break;

		case 3:
			if (s1.isEmpty())
				cout << "Stack is empty" << endl;
			else
				cout << "Stack is not empty" << endl;
			break;

		case 4:
			if (s1.isFull())
				cout << "Stack is full" << endl;
			else
				cout << "Stack is not full" << endl;
			break;

		case 5:
			cout << "Enter the position you want to see from the stack" << endl;
			cin >> position;
			cout << "Value at the entered position: " << s1.peek(position) << endl;
			break;

		case 6:
			cout << "Total count of the stack: " << s1.count() << endl;
			break;

		case 7:
			cout << "Enter the postion of the value you want to change" << endl;
			cin >> position;
			cout << endl;
			cout << "Enter the new value " << endl;
			cin >> value;
			s1.change(position, value);
			break;
		case 8:
			s1.display();
			break;
		case 9:
			system("cls");
			break;
		default:
			cout << "Enter proper option number" << endl;
		}

	} while (option != 0);
	return 0;
} 