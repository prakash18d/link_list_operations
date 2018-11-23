

#include<iostream>
using namespace std;

struct MyStruct
{
	int data;
	MyStruct *next;
};

class Linklist
{
public:
	MyStruct *head;
	MyStruct *CreateNode(int val)
	{
		MyStruct *temp = new MyStruct();
		temp->data = val;
		temp->next = NULL;
		return temp;
	}

	Linklist() :head(NULL)
	{
	}
	void preappend(int val)
	{
		MyStruct *temp = CreateNode(val);
		if (IsEmpty())
			head = temp;
		else
		{
			temp->next = head;
			head = temp;
		}

	}
	void append_position(int val, int pos)
	{
		MyStruct *temp = CreateNode(val);
		MyStruct *trav = head;
		for (int i = 1; i<pos - 1; i++)
		{
			trav = trav->next;
			if (trav == NULL)
			{

				cout << "please enter right position" << endl;
				return;
			}

		}

		temp->next = trav->next;
		trav->next = temp;

	}
	void append_last(int val)
	{
		MyStruct *temp = CreateNode(val);
		MyStruct *trav = head;
		while (!trav->next == NULL)
		{
			trav = trav->next;
		}
		trav->next = temp;
		temp->next = NULL;
	}
	int Delete()
	{
		int val = -1;
		if (!IsEmpty())
		{
			MyStruct *temp = head;
			head = head->next;
			cout << "Releasing the node with " << temp->data << endl;
			val = temp->data;
			delete temp;
		}
		return val;
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void List()
	{



		for (MyStruct *trav = head; trav != NULL; trav = trav->next)
		{
			cout << trav->data << "\t";
		}

		cout << endl << "_________________________________" << endl;
	}
	void reverseprint(struct MyStruct *p)
	{
		if (p == NULL)
			return;

		reverseprint(p->next);
		cout << p->data << "      ";
	}
	void reverse_rec(struct MyStruct *p)
	{
		if (p->next == NULL)
		{
			head = p;
			return;
		}
		reverse_rec(p->next);
		MyStruct *q = p->next;
		q->next = p;
		p->next = NULL;


	}

};

int main()
{

	Linklist l;
	cout << "inserting at first" << endl;
	l.preappend(10);
	l.List();
	l.preappend(20);
	l.List();
	l.preappend(30);
	l.List();
	l.preappend(40);
	l.List();
	l.preappend(50);
	l.List();
	l.Delete();
	l.List();
	cout<<" reverse print list "<<endl;
	
	l.reverse_rec(l.head);
	l.List();
	l.Delete();
	l.append_position(60,3);
	l.List();
	cout << "ending at last" << endl;;
	l.append_last(80);
	l.List();
	l.append_last(70);
	l.List();


}
