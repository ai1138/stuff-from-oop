// rec12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>
using namespace std;


class List
{
public:
	friend ostream& operator<<(ostream& os, const List& rhs);
	List()
	{
		this->header = new Node(21,nullptr,nullptr);
		this->trailer = new Node(21,nullptr,nullptr);
		this->header->next = this->trailer;
		this->header->prev = nullptr;
		this->trailer->prev = this->header;
		this->trailer->next = nullptr;
		listSize = 0;
	}
	void push_back(int data)
	{
		Node* added = new Node(data,nullptr,nullptr);
		Node* old = trailer->prev;
		old->next = added;
		trailer->prev = added;
		added->next = trailer;
		added->prev = old;
		added->data = data;
		listSize += 1;
	}
	int pop_back()
	{
		Node* temp = this->trailer->prev;
		Node* newLast = temp->prev;
		newLast->next = this->trailer;
		this->trailer->prev = newLast;
		temp->next = nullptr;
		temp->prev = nullptr;
		int data = temp->data;
		delete temp;
		listSize -= 1;
		return data;
	}
	int& front()
	{
		return header->next->data;
	}
	int front() const
	{
		return  header->next->data;
	}
	int& back()
	{
		return trailer->prev->data;
	}
	int back() const
	{
		return trailer->prev->data;
	}
	int size() const
	{
		return listSize;
	}
	void push_front(int data)
	{
		Node* added = new Node(data, nullptr, nullptr);
		Node* old = header->next;
		old->prev = added;
		header->next = added;
		added->next = old;
		added->prev = header;
		added->data = data;
		listSize += 1;
	}
	int pop_front()
	{
		Node* temp = this->header->next;
		Node* newFront = temp->next;
		newFront-> prev = this->header;
		this->header->next = newFront;
		temp->next = nullptr;
		temp->prev = nullptr;
		int data = temp->data;
		delete temp;
		listSize -= 1;
		return data;
	}
	void clear()
	{
		Node* temp = this->header->next;
		while (temp->next != nullptr)
		{
			
		}

	}
private:
	struct Node
	{
		Node(int data, Node* next, Node* prev) :data(data = 0), next(next = nullptr), prev(prev = nullptr) {}
		int data;
		Node* next;
		Node* prev;;
	};
	Node* header;
	Node* trailer;
	int listSize;
};
void changeFrontAndBack(List& theList)
{
	theList.front() = 17;
	theList.back() = 42;
}
void printListInfo(const List& myList) 
{
	cout << "size: " << myList.size()
		<< ", front: " << myList.front()
		<< ", back(): " << myList.back()
		<< ", list: " << myList << endl;
}

int main()
{
	// Task 1
	cout << "\n------Task One------\n";
	List myList;
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList.push_back(" << i * i << ");\n";
		myList.push_back(i * i);
		printListInfo(myList);
	}
	cout << "===================\n";

	cout << "Modify the first and last items, and display the results\n";
	changeFrontAndBack(myList);
	printListInfo(myList);
	cout << "===================\n";

	cout << "Remove the items with pop_back\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_back();
	}
	cout << "===================\n";
}

ostream& operator<<(ostream& os, const List& rhs)
{
	List::Node* temp = rhs.header->next;
	while(temp->next != nullptr)
	{
		os << temp->data;
		temp = temp->next;
	}
	return os;
}
