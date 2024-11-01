#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* rightchild;
	Node* leftchild;
};

class Tree
{
public:
	Node* root;
	Tree()
	{
		root = NULL;
	}

	void AddNode(int number)
	{
		Node* temp = new Node;

		temp->data = number;
		temp->leftchild = NULL;
		temp->rightchild = NULL;

		if (root == NULL)
		{
			root = temp;
		}
            else
		{
			Node* current;
			current = root;
			while (true)
			{
				if (temp->data < current->data)
				{
					if (current->leftchild == NULL)
					{
						current->leftchild = temp;
						break;
					}
					else
					{
						current = current->leftchild;
					}
				}
				else
				{
					if (current->rightchild == NULL)
					{
						current->rightchild = temp;
						break;
					}
					else
					{
						current = current->rightchild;
					}
				}
			}
		}
	}

	void Display(Node* temp)
	{
		if (temp->leftchild != NULL)
		{
			Display(temp->leftchild);
		}

		cout << temp->data << " ";

		if (temp->rightchild)
		{
			Display(temp->rightchild);
		}
	}

	void Search(int number)
	{
		Node* temp = root;
		while (temp != NULL)
		{
			if (temp->data > number)
			{
				temp = temp->leftchild;
			}
			else if (temp->data < number)
			{
				temp = temp->rightchild;
			}
			else
			{
				cout << "Yes. The entered number exists in the current tree." << endl;
				return;
			}
		}
		cout << "No. Your number isn't in the tree." << endl;
	}

	void MinimumNumber(Node* Root)
	{
		if (Root->leftchild == NULL)
		{
			cout << "The minimum number is : " << Root->data << endl;
		}
		else
		{
			MinimumNumber(Root->leftchild);
		}
	}

	void MaximumNumber(Node* Root)
	{
		if (Root->rightchild == NULL)
		{
			cout << "The largest number is : " << Root->data << endl;
		}
		else
		{
			MaximumNumber(Root->rightchild);
		}
	}

	void DeleteNode(int number)
	{
		Node* current;
		Node* previous;
		int direction;
		current = root;
		while (current != NULL)
		{
			if (current->data > number)
			{
				previous = current;
				current = current->leftchild;
				direction = 0;
			}
			else if (current->data < number)
			{
				previous = current;
				current = current->rightchild;
				direction = 1;
			}
			else
			{
				if (current->rightchild == NULL && current->leftchild == NULL)
				{
					if (direction == 1)
					{
						previous->rightchild = NULL;
						delete current;
					}
					else
					{
						previous->leftchild = NULL;
						delete current;
					}
				}
				else if (current->rightchild != NULL && current->leftchild == NULL)
				{
					if (direction == 1)
					{
						previous->rightchild = current->rightchild;
						delete current;
					}
					else
					{
						previous->leftchild = current->rightchild;
						delete current;
					}
				}
				else if (current->rightchild == NULL && current->leftchild != NULL)
				{
					if (direction == 1)
					{
						previous->rightchild = current->leftchild;
						delete current;
					}
					else
					{
						previous->leftchild = current->rightchild;
						delete current;
					}
				}
				else if (current->rightchild != NULL && current->leftchild != NULL)
				{
					current->data = Minimum(current->rightchild);
				}
			}
		}
	}
private:
	int Minimum(Node* temp)
	{
		while (true)
		{
			if (temp->leftchild != NULL)
			{
				temp = temp->leftchild;
			}
			else
			{
				int number = temp->data;
				DeleteNode(temp->data);
				return number;
			}
		}
	}
};

int main()
{
	Tree BinaryTree;
	BinaryTree.AddNode(5);
	BinaryTree.AddNode(2);
	BinaryTree.AddNode(3);
	BinaryTree.AddNode(12);
	BinaryTree.AddNode(9);
	BinaryTree.AddNode(21);
	BinaryTree.AddNode(19);
	BinaryTree.AddNode(25);

	BinaryTree.DeleteNode(12);
	BinaryTree.Display(BinaryTree.root);
}
