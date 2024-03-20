#include <iostream>
#include <string>
 
using namespace std;
template <typename t>
class Node
{
public:
	t data;
	Node<t>* next;
	Node(t value)
	{
		data = value;
		next = nullptr;
	}
};
template <typename t>
class LinkedList
{
	Node<t>* head;
	int counter;
public:
	LinkedList() //   Time: O(1) , Space : O(1) 
	{
		head = nullptr;
		counter = 0;
	}
	bool isEmpty() // Time: O(1) , Space: O(1)
	{
		return (head == nullptr);
	}
	void insertFirst(t item) // Time: O(1) , Space: O(1)
	{
		Node<t>* newnode = new Node<t>(item); // Time: O(1) , Space: O(1)
		newnode->next = nullptr;
		head = newnode;
		counter++;
	}
	void insert(int pos, t item) // Time: O(n) , Space: O(n)
	{
		if (pos > 0 && pos <= counter + 1)
		{
			Node<t>* newnode = new Node<t>(item);
			if (isEmpty() || pos == 1) // empty or First
			{
				newnode->next = head;
				head = newnode;
			}
			else   // Middle or end
			{
				Node<t>* t = head;
				int index = 1;
				while (index < pos - 1)
				{
					t = t->next;
					index++;
				}
				newnode->next = t->next;
				t->next = newnode;
			}
		
			counter++;
		}
		else
		{
			cout << "Error: Invalid Position\n";
			return;
		}
	}
	void append(t item) // Time: O(n) , Space: O(n)
	{
		Node<t>* newnode = new Node<t>(item);
		if (isEmpty())
			insertFirst(item);
		else {
			Node<t>* t = head;
			while (t->next != nullptr)
			{
				t = t->next;
			}
			newnode->next = nullptr;
			t->next = newnode;
		}
		counter++;
	}
	int isFuond(t key) // Time: O(n) , Space: O(n)
	{
		Node<t>* t = head;
		int index = 1;
		while (t != nullptr)
		{
			if (t->data == key)
			{
				return index;
			}
			t = t->next;
			index++;
		}
		return -1;
	}
	void Delete(int pos) // Time: O(n) , Space: O(n)
	{
		if (pos < 1 || pos > counter)
		{
			cout << "Error: Invalide input\n";
			return;
		}
		if (isEmpty())
		{
			cout << "The LinkedList Is Empty\n";
			return;
		}
		 if (pos == 1)
		{
			Node<t>* delptr = head;
			head = head->next;
			delete delptr;
		}
		else
		{
			Node<t>* Tem = head;
			int index = 1;
			while (index < pos - 1)
			{
				Tem = Tem->next;
				index++;
			}
			Node<t>* delptr = Tem->next;
			Tem->next = Tem->next->next;
			delete delptr;
		}
		 counter--;
	}
	void disp()  // Time: O(n) , Space: O(n)
	{
		Node<t>* t = head;
		while (t != nullptr)
		{
			cout << t->data<<" ";
			t = t->next;
		}
		cout << "\n";
	}
	int getCount() // Time: O(1) , Space: O(1)
	{
		return counter;
	}

	Node<t>* getHead()  // Time: O(1) , Space: O(1)
	{
		return head;
	}

	/**********************************  Assiagnment *************************************/

	/*
	* remove - function to remove Occurrance for some Element 
	* 
	* @key: an integer element
	* 
	* Return: void
	*/
	void remove(t key)   // Time: O(n * log n) , Space: O(n)
	{
		Node<t>* delptr;
		while (head->data == key) // áæ ÇáÚäÕÑ ãæÌæÏ Ýí ÇáÇæá
		{
			delptr = head;
			head = head->next;
			delete delptr;
		}
		Node<t>* curr = head;
		Node<t>* temp = head;
		while (curr->next != nullptr)  // Time: O(n) , Space: O(n)
										// áæ ÇáÚäÕÑ ãæÌæÏ Ýí ÇáæÓØ  
		{
			if (curr->next->data == key)
			{
				delptr = curr->next; // ÈæíäÊÑ ÈíÔÇæÑ Úáí ÇáäæÏ ÇáãÍÐæÝå
				temp = delptr->next;// ÈÊÇÚÊ ÇáäæÏ ÇáãÍæÝå ÞÈá ÇáÍÐÝ next åäÍÌÒ Çá
				delete delptr;     // ÍÐÝ ÇáäæÏ ãä ÇáãíãæÑí
				if (temp) // 1 2 3 4 4 4 5 4 4 
				{
					while (temp->data == key)  // time: o(n) * O(log n)
												// ÍÐÝ ßá ÇáÚäÇÕÑ ÇáãÊÊÇáíå
					{
						delptr = temp;		// ÈæíäÊÑ ÈíÔÇæÑ Úáí ÇáäæÏ ÇáãÍÐæÝå
						temp = delptr->next;	// ÈÊÇÚÊ ÇáäæÏ ÇáãÍæÝå ÞÈá ÇáÍÐÝ next åäÍÌÒ Çá	
						delete delptr;

						if (!temp)break;
					}
				}
				 curr->next = temp;		// áÑÈØ ÇáÚäÇÕÑ ÈÚÏ ÇáÍÐÝ 
			}

			curr = curr->next;
			if (!curr)
				break;
		}
	}
};

/*
	* sum - function to sum all elemts of list with recursive
	*
	* @head: head of list 
	*
	* Return: return sum elements of list
	*/
template <typename t>
t sum(Node<t> *head)   // Time: O(n) , Space: O(n)
{
	if (head->next == nullptr)
		return head->data;
	return head->data + sum(head->next);
}


int main()
{
	LinkedList<int> l;
	l.insertFirst(4);
	l.insert(2, 4);
	l.insert(3, 2);
	l.insert(4, 3);
	l.insert(5, 1);
	l.insert(6, 4);
	l.insert(7, 4);
	l.insert(8, 4);
	l.insert(9, 5);
	l.insert(10, 4);
	l.insert(11, 4);

	cout << l.getCount() << "\n";
	l.disp();
	//cout << sum(l.getHead()) << "\n";
	l.remove(4);
	l.disp();


	/*l.insert(7, "45");
	l.append("70");
	cout << l.getCount() << "\n";
	l.disp();
	cout << l.isFuond("40") << "\n\n";
	 
	cout << l.getCount() << "\n";
	l.disp();*/
 

	return 0;
}