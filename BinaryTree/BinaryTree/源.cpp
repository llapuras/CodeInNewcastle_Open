#include <iostream>
using namespace std;
#define NUM(a) (sizeof(a)/sizeof(a[0]))

struct node {
	int value;
	struct node* left;
	struct node* right;
};
struct node* root = NULL;

// implement the functions described by these headers
void insert_integer(struct node** tree, int value) {
	node* newnode = new node;
	newnode->value = value;
	newnode->left = newnode->right = NULL;
	node* par;
	node* cur;

	if (*tree == NULL) {
		cout << "true" << endl;
		root = newnode;
	}
	else {
		par = NULL;
		cur = root;
		while (cur != NULL) {
			par = cur;
			//cout << "newnode->value: " << newnode->value << endl;
			//cout << "cur->value: " << cur->value << endl;
			//cout << "root->value: " << root->value << endl;
			if (newnode->value < cur->value)
				cur = cur->left;
			else
				cur = cur->right;
			//cout << "find proper node!" << endl;
		}
		if (par->value > newnode->value)
			par->left = newnode;
		else
			par->right = newnode;
	}
}

void print_tree(struct node* tree) {
	if (tree) {
		print_tree(tree->left);
		cout << tree->value << endl;
		print_tree(tree->right);
	}
}

void terminate_tree(struct node* tree) {

};

int main() {
	int a[] = { 1,3,5,2,9,8,13,0 };
	int k = NUM(a);
	node** tree = new node*;
	tree = &root;
	for (int i = 0; i < k; i++) {
		insert_integer(tree, a[i]);
	}

	//²åÈëÐÂÖµ²âÊÔ
	insert_integer(tree, 12);
	insert_integer(tree, 4);

	print_tree(root);
	return 0;
}