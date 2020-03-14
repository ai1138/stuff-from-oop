
#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;
struct Node
{
	int data;
	Node* next;
};
int findSubstring(string x, string y)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < y.size(); i++)
	{
		if (y[i] = x[j] && j == x.size())
		{
			return i - j;
		}
		else if (y[i] = x[j] && j != x.size() - 1)
		{
			j += 1;
		}
		else
		{
			j = 0;
		}
	}
}
//part A
Node* removeLast(Node* head)
{
	if (head == NULL)
		return NULL;

	if (head->next == NULL) {
		delete head;
		return NULL;
	}

	
	Node* secondToLast = head;
	while (secondToLast->next->next != NULL)
		secondToLast = secondToLast->next;

	 
	delete (secondToLast->next);

	
	secondToLast->next = NULL;

	return head;
}
void histogram(vector<string> x)
{
	map<string, int> m;
	int s = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (m[x[i]] > 1)
		{
			m[x[i]] = m[x[i]] + 1;
		}
		else
		{
			m[x[i]] = 1;
		}
	}
}

int main() 
{
	int A[7];
	int i;
	for (i = 0; i < 7; i++)
	{
		A[i] = i * i;
	}
	cout << A[i - 1] << endl;
	cout << *A << endl;
	int* p = &A[5];
	cout << *p << endl;
	p = p - 2;
	cout << *p << endl;
	*p = 23;
	cout << *(++p) << endl;
	*p = 23;
	for (i = 0; i < 7; i++)
	{
		cout << "A[" << "i" << "]" << " = "<< A[i] << endl;
	}


}
