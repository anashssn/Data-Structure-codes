#include <iostream>
using namespace std;

class Node {
public:
	int key;
	int data;
	Node* next;
	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
	}
	Node(int k, int d)
	{
		key = k;
		data = d;
	}
};
class SinglyLinkedList
{
public:
	Node* head;
	SinglyLinkedList()
	{
		head = NULL;
	}
	SinglyLinkedList(Node *n)
	{
		head = n;
	}
	Node* nodeExists(int k) //traversing (if node exists using key value)
	{
		Node* temp = NULL;
		Node* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}
	// append a node to the list 
	void appendNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node Appended" << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = n;
				cout << "Node Appended" << endl;
			}
		}
	}

	void prependNode(Node* n)
	{
		if (nodeExists(n->key) != NULL)
		{
			cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
		}
		else
		{
			n->next = head;
			head = n;
			cout << "Node Prepended" << endl;

		}
	}
	void insertNodeAfter(int k, Node* n) //insert node in b/w  two nodes
	{
		Node* ptr = nodeExists(k);
		if (ptr == NULL)
		{
			cout << "No Node exists of the key value: " << k << endl;
		}
		else
		{
			if (nodeExists(n->key) != NULL)
			{
				cout << "Node already exists with key value: " << n->key << ". Append another node with different key value." << endl;
			}
			else
			{
				n->next = ptr->next;
				ptr->next = n;
				cout << "Node Inserted" << endl;
			}
		}
	}

	void deleteNodeByKey(int k)//delete node using key value
	{
		if (head == NULL)
		{
			cout << "Singly Linked List is empty." << endl;
		}
		else if (head != NULL)
		{
			if (head->key == k)
			{
				head = head->next;
				cout << "Node Unlinked of key value: " << k << endl;
			}
			else
			{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while (currentptr != NULL)
				{
					if (currentptr->key == k)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				if (temp != NULL)
				{
					prevptr->next = temp->next;
					cout << "Node Unlinked of key value: " << k << endl;
				}
				else
				{
					cout << "Node doesn't exist of key value: " << k << endl;
				}
			}
		}
	}

	void updateNodeByKey(int k, int d) //update using key
	{
		Node* ptr = nodeExists(k);
		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node data updated successfully" << endl;
		}
		else
		{
			cout << "Node doesn't exists with key value: " << k << endl;
		}
	}
	void printlist()
	{
		if (head == NULL)
		{
			cout << "Singly Linked List is empty" << endl;
		}
		else
		{
			cout << "Singly Linked List values are: " << endl;
			Node* temp = head;
			while (temp != NULL)
			{
				cout << "(" << temp->key << "," << temp->data << ") -->";
				temp = temp->next;
			}
		}
	}
};
int main()
{
	SinglyLinkedList s;
	int option;
	int key1, k1, data1;
	do
	{
		cout << "\n What operation do you want to perform? Select an option. Enter 0 to exit." << endl;
		cout << "1. AppendNode() " << endl;
		cout << "2. PrependNode() " << endl;
		cout << "3. InsertNodeAfter() " << endl;
		cout << "4. DeleteNodeByKey() " << endl;
		cout << "5. UpdataNodeByKey() " << endl;
		cout << "6. PrintLinkedList() " << endl;

		cin >> option;
		Node* n1 = new Node();

		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "1. Append Node \n Enter key and data of the node to be appended. " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.appendNode(n1);
			break;
		case 2:
			cout << "2. PrependNode \n Enter key and data of the node to be prepended. " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.prependNode(n1);
			break;
		case 3:
			cout << "3. Insert Node After \n Enter key after which you need to insert the node. " << endl;
			cin >> k1;
			cout << "Enter the key and data of node to be inserted. " << endl;
			cin >> key1;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;
			s.insertNodeAfter(k1, n1);
			break;
		case 4:
			cout << "4. Delete Node By Key \n Enter the key of the node you want to delete." << endl;
			cin >> k1;
			s.deleteNodeByKey(k1);
			break;
		case 5:
			cout << "5. Update Node By Key \n Enter the key and new data to be updated. " << endl;
			cin >> key1;
			cin >> data1;
			s.updateNodeByKey(key1, data1);
			break;
		case 6:
			cout << "6. Print Linked List." << endl;
			s.printlist();
			break;
		default:
			cout << "Enter proper option number" << endl;
		}
	} while (1);
	return 0;
}
