#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};

void visit(Node* n)
{
	if (n == nullptr)
		return;
	cout << n->value << ' ';
	visit(n->left);
	visit(n->right);
}

void in(Node* n)
{
	if (n == nullptr)
		return;
	visit(n->left);
	cout << n->value << ' ';
	visit(n->right);
}

void post(Node* n)
{
	if (n == nullptr)
		return;
	visit(n->left);
	visit(n->right);
	cout << n->value << ' ';
}

int main()
{
	Node node[11];

	for (int i = 0; i <= 10; i++)
	{
		node[i].value = i;
		node[i].left = NULL;
		node[i].right = NULL;
	}
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
			node[i / 2].left = &node[i];
		else
			node[i / 2].right = &node[i];
	}
	in(&node[1]);
	cout << "\n";
	post(&node[1]);

	return 0;
}