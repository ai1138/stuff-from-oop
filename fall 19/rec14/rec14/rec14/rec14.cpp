#include <iostream>
using namespace std;

struct TNode
{
	TNode(int data = 0, TNode * left = nullptr, TNode * right = nullptr)
		: data(data), left(left), right(right) {}
	int data;
	TNode* left, * right;
};
struct NullPtrException
{

};
bool palindrome(char arr[], int len) 
{
	if (arr + 2 > arr + len) 
	{
		if (*arr == *(arr + len - 1)) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	if (*arr == *(arr + len - 1)) 
	{
		return true && palindrome(arr + 1, len - 2);
	}
	return false;
}
int max(TNode* root)
{

		int res = root->data;
		if (root->left)
		{
			int left = max(root->left);
			if (res < left)
			{
				res = left;
			}
		}
		if (root->right)
		{
			int right = max(root->right);
			if (res < right)
			{
				res = right;
			}
		}
	
	
	return res;
}


int main()
{
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;
}
