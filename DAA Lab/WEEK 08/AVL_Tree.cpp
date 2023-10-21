#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *left;
	struct node *right;
	int height;
};
int height(struct node*&root)
{
	if (root == NULL)
		return 0;
	return root->height;
}
int max(int a, int b)
{
	return (a > b)? a : b;
}
void rightRotate(struct node*&root)
{

	struct node *x=root->left;
	struct node*t2=x->right;

	x->right = root;
	root->left = t2;

	root->height = max(height(root->left),height(root->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;
	root=x;
}
void leftRotate(struct node*&root)
{
	struct node *y=root->right;
	struct node*t2=y->left;

	y->left = root;
	root->right = t2;

	root->height = max(height(root->left),height(root->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;
	root=y;
}

int getBalance(struct node*&root)
{
	if (root== NULL)
		return 0;
	return height(root->left) - height(root->right);
}
void insert(struct node*&root, int key)
{
	if (root == NULL)
	{
		struct node*newNode=new struct node;
		root=newNode;
		newNode->info=key;
		newNode->right=NULL;
		newNode->left=NULL;
	}
	if (key < root->info)
	insert(root->left, key);
	else if (key > root->info)
		insert(root->right, key);

	root->height = 1 + max(height(root->left),
						height(root->right));


	int balance = getBalance(root);


	if (balance > 1 && key < root->left->info)
		rightRotate(root);

	if (balance < -1 && key > root->right->info)
		leftRotate(root);

	if (balance > 1 && key > root->left->info)
	{
		leftRotate(root->left);
		 rightRotate(root);
	}

	if (balance < -1 && key < root->right->info)
	{
		 rightRotate(root->right);
		 leftRotate(root);
	}

}

void preOrder(struct node *&root)
{
	if(root != NULL)
	{
		cout << root->info << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main()
{
	struct node*root=NULL;
	int choice;
	do
	{
		cout<<"1.enter 2.display 3.exit:";
		cin>>choice;
		if(choice==1)
		{
			cout<<"enter ele:";
			int ele,after;
			cin>>ele;

			insert(root,ele);
		}
		if(choice==2)
		{
			cout << "Preorder traversal of the constructed AVL tree is \n";
			preOrder(root);
		}
		
	}while(choice!=3);
	return 0;
}


