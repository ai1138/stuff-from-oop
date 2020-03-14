// rec11.cpp 
#include <iostream>
#include <vector>
struct Node 
{
	Node(int data = 0, Node * next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) 
{
	headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) 
{
	while (headPtr) {
		Node* next = headPtr->next;
		delete headPtr;
		headPtr = next;
	}
}
Node* listBuild(const vector<int>& vals) {
	Node* result = nullptr;
	for (size_t index = vals.size(); index > 0; --index) {
		listAddHead(result, vals[index - 1]);
	}
	return result;
}
int main()
{
    std::cout << "Hello World!\n";
}
