#include <iostream>
using namespace std;
class TreeNode
{
private:
    int data;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~TreeNode()
    {
        delete left;
        delete right;
    }

    friend class BinaryTree;
};

#define MAX 100
template <typename T>
class Stack
{
private:
    T data[MAX];
    int Top;
public:
    Stack()
    {
        Top=-1;
    }    

    bool isEmpty()
    {
        if(Top==-1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(Top==MAX-1)
        {
            return true;
        }
        return false;
    }

    void push(T element)
    {
        if(isFull())
        {
            cout<<" The Stack is Full !! "<<endl;
            return ;
        }
        data[++Top]=element;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<" The Stack is Empty !! "<<endl;
            return ;
        }

        Top--;
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<" The Stack is Empty !! "<<endl;
            return NULL;
        }

        return data[Top];
    }

    friend class BinaryTree;
};

class BinaryTree
{
private:
    TreeNode *root;
public:
    BinaryTree()
    {
        root=NULL;
    }

    void create_BT()
    {
        int element;
        cout<<" Enter the data of the TreeNode : ";
        cin>>element;
        TreeNode *newNode=new TreeNode(element);
        if(root==NULL)
        {
            root=newNode;
        }
        else
        {
            TreeNode *temp=root;
            do
            {
                char ch;
                cout<<" Where you want to enter the TreeNode to (L/R) of "<<temp->data<<" : ";
                cin>>ch;
                if(ch=='L')
                {
                    if(temp->left==NULL)
                    {
                        temp->left=newNode;
                        temp=newNode;
                    }
                    else
                    {
                        temp=temp->left;
                    }
                }
                else if(ch=='R')
                {
                    if(temp->right==NULL)
                    {
                        temp->right=newNode;
                        temp=newNode;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }

            }while(temp!=newNode);
        }
    }

    void PreOrder_recursive(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        cout<<temp->data<<" ";
        PreOrder_recursive(temp->left);
        PreOrder_recursive(temp->right);
    }
    void PreOrder_nonrecursive(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        Stack<TreeNode*> stack;
        TreeNode* current=temp;
        while(current!=NULL || !stack.isEmpty())
        {
            while(current!=NULL)
            {
                cout<<current->data<<" ";
                if(current->right!=NULL)
                {
                    stack.push(current->right);
                }
                current=current->left;
            }

            if(!stack.isEmpty())
            {
                current=stack.top();
                stack.pop();
            }  
        }
    }
    void PreOrder()
    {
        TreeNode* temp=root;
        int option;
        cout<<" -------------- Menu -------------- "<<endl;
        cout<<" 1. Recursive "<<endl;
        cout<<" 2. Non-Recursive "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        cout<<" Displaying the Preorder traversal of Binary Tree : ";
        if(option==1)
        {
            return PreOrder_recursive(temp);
        }
        else if(option==2)
        {
            return PreOrder_nonrecursive(temp);
        }
        else
        {
            cout<<" Invalid Option. "<<endl;
            return ;
        }
    }

    void InOrder_recursive(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        InOrder_recursive(temp->left);
        cout<<temp->data<<" ";
        InOrder_recursive(temp->right);
    }
    void InOrder_nonrecursive(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        Stack<TreeNode*> stack;
        TreeNode* current=temp;
        while(current!=NULL || !stack.isEmpty())
        {
            while(current!=NULL)
            {
                stack.push(current);
                current=current->left;
            }

            current=stack.top();
            stack.pop();
            cout<<current->data<<" ";
            current=current->right;
        }
    }
    void InOrder()
    {
        TreeNode* temp=root;
        int option;
        cout<<" -------------- Menu -------------- "<<endl;
        cout<<" 1. Recursive "<<endl;
        cout<<" 2. Non-Recursive "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        cout<<" Displaying the Inorder traversal of Binary Tree : ";
        if(option==1)
        {
            return InOrder_recursive(temp);
        }
        else if(option==2)
        {
            return InOrder_nonrecursive(temp);
        }
        else
        {
            cout<<" Invalid Option. "<<endl;
            return ;
        }
    }

    void PostOrder_recursive(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        PostOrder_recursive(temp->left);
        PostOrder_recursive(temp->right);
        cout<<temp->data<<" ";
    }
    void PostOrder_nonrecursive(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        Stack<TreeNode*> stack1,stack2;
        stack1.push(temp);
        TreeNode* current;
        while(!stack1.isEmpty())
        {
            current=stack1.top();
            stack1.pop();
            stack2.push(current);
            if(current->left!=NULL)
            {
                stack1.push(current->left);
            }
            if(current->right!=NULL)
            {
                stack1.push(current->right);
            }
        }

        while(!stack2.isEmpty())
        {
            current=stack2.top();
            stack2.pop();
            cout<<current->data<<" ";
        }
    }
    void PostOrder()
    {
        TreeNode* temp=root;
        int option;
        cout<<" -------------- Menu -------------- "<<endl;
        cout<<" 1. Recursive "<<endl;
        cout<<" 2. Non-Recursive "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        cout<<" Displaying the Postorder traversal of Binary Tree : ";
        if(option==1)
        {
            return PostOrder_recursive(temp);
        }
        else if(option==2)
        {
            return PostOrder_nonrecursive(temp);
        }
        else
        {
            cout<<" Invalid Option. "<<endl;
            return ;
        }
    }

    int heightOfBinaryTree(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return 0;
        }

        return 1+max(heightOfBinaryTree(temp->left),heightOfBinaryTree(temp->right));
    }
    void heightOfBinaryTree()
    {
        TreeNode* temp=root;
        cout<<" The Height of the Binary Tree is : "<<heightOfBinaryTree(temp)<<endl;
        return ;
    }

    int leafNodesOfBinaryTree(TreeNode *temp)
    {
        if(temp==NULL)
        {
            return 0;
        }
        if(temp->left==NULL && temp->right==NULL)
        {
            return 1;
        }

        return leafNodesOfBinaryTree(temp->left)+leafNodesOfBinaryTree(temp->right);
    }
    void leafNodesOfBinaryTree()
    {
        TreeNode* temp=root;
        cout<<" Number of Leaf Nodes in the Binary Tree are : "<<leafNodesOfBinaryTree(temp)<<endl;
        return ;
    }

    int internalNodesOfBinaryTree(TreeNode *temp)
    {
        if(temp==NULL || (temp->left==NULL && temp->right==NULL))
        {
            return 0;
        }
        return 1+internalNodesOfBinaryTree(temp->left)+internalNodesOfBinaryTree(temp->right);
    }
    void internalNodesOfBinaryTree()
    {
        TreeNode *temp=root;
        cout<<" Number of Internal Nodes in the Binary Tree are : "<<internalNodesOfBinaryTree(temp)<<endl;
        return ;
    }

    void mirrorOfBinaryTreeHelper(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }

        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        mirrorOfBinaryTreeHelper(root->left);
        mirrorOfBinaryTreeHelper(root->right);
    }
    void mirrorOfBinaryTree()
    {
        mirrorOfBinaryTreeHelper(root);
        cout<<" Mirror of Binary Tree created Successfully !! "<<endl;
        return ;
    }

    TreeNode* copyBinaryTree(TreeNode* temp)
    {
        if(temp==NULL)
        {
            return NULL;
        }

        TreeNode* root_copy=new TreeNode(temp->data);

        root_copy->left=copyBinaryTree(temp->left);
        root_copy->right=copyBinaryTree(temp->right);

        return root_copy;

    }
    BinaryTree& operator=(const BinaryTree &obj)
    {
        if(this == &obj)
        {
            return *this;
        }

        this->root=copyBinaryTree(obj.root);
        return *this;
    }

    void delete_BT()
    {
        delete root;
    }

};
int main()
{
    BinaryTree obj_BT;
    int option;
    do
    {
        cout<<endl;
        cout<<" ----------------- Menu ----------------- "<<endl;
        cout<<" 1. Create a Binary Tree "<<endl;
        cout<<" 2. Display Preorder traversal of Binary Tree "<<endl;
        cout<<" 3. Display Inorder traversal of Binary Tree "<<endl;
        cout<<" 4. Display Postorder traversal of Binary Tree "<<endl;
        cout<<" 5. Height of the Binary Tree "<<endl;
        cout<<" 6. Number of Leaf Nodes of the Binary Tree "<<endl;
        cout<<" 7. Number of Internal Nodes of the Binary Tree "<<endl;
        cout<<" 8. Mirror of the Binary Tree "<<endl;
        cout<<" 9. Delete Binary Tree "<<endl;
        cout<<" 10. Copy this Binary Tree to another Tree "<<endl;
        cout<<" 11. Exit "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        switch(option)
        {
            case 1:
                obj_BT.create_BT();
                break;
            case 2:
                obj_BT.PreOrder();
                break;
            case 3:
                obj_BT.InOrder();
                break; 
            case 4:
                obj_BT.PostOrder();
                break;       
            case 5:
                obj_BT.heightOfBinaryTree();
                break;    
            case 6:
                obj_BT.leafNodesOfBinaryTree();
                break;    
            case 7:
                obj_BT.internalNodesOfBinaryTree();
                break;   
            case 8:
                obj_BT.mirrorOfBinaryTree();
                break;
            case 9:
                obj_BT.delete_BT();
                cout<<" Binary Tree Deleted Successfully !! "<<endl;
                cout<<endl;
                exit(0); 
                break;   
            case 10:
                BinaryTree new_BT=obj_BT;
                cout << "Copied the Original Binary Tree into a New Binary Tree Successfully!" << endl;
                cout<<"Original Binary Tree is :- "<<endl;
                obj_BT.PreOrder();
                cout<<endl;
                cout<<"Copied Binary Tree is :- "<<endl;
                new_BT.PreOrder();
                cout<<endl;
                break;             
        }
        cout<<endl;
    }while(option>=1 && option<=10);

    return 0;
}




















#include<iostream>
#include<stdlib.h>
using namespace std;
 class BSTnode
 {
	public:
		int data;
		BSTnode *rchild,*lchild;

 };
 class tree
 {
	public:
		void create();
		void insert(BSTnode *,BSTnode*);

		void display();
		void preorder(BSTnode *);
		void postorder(BSTnode *);
		void inorder(BSTnode *);
		void search();
		BSTnode* searchmin(BSTnode *);
		void searchmax(BSTnode *);
		void searchgiven(BSTnode *,int,int);
		void searchgiven1(BSTnode *,int,int);
		BSTnode * mirror(BSTnode *);
		BSTnode* delet(BSTnode *,int);

	BSTnode *root;
	tree()
	{
		root=NULL;

	}
 };

 /*Using create function we just create new node of tree*/

 void tree::create()
 {

		char ch;
		BSTnode *freshnode;
		while(1)
		{
			freshnode=new BSTnode;
			freshnode->rchild=NULL;
			freshnode->lchild=NULL;
			
			cout<<"\n\n Enter data to create new node\t";
			cin>>freshnode->data;
			if(root==NULL)
			{
				root=freshnode;
				
			}
			else
				insert(root,freshnode);
			cout<<"\n You Wnat to add more nodes\t\t";
			cin>>ch;
			if(ch=='n')
			{     
					break;
			}
		}

	}


	/*using insert function we insert node into tree at given position*/

void tree::insert(BSTnode *root,BSTnode *freshnode)
{
	char ch;

		if(root->data<freshnode->data)
		{
			if(root->rchild==NULL)
			{
				root->rchild=freshnode;
			}
			else
			{
				insert(root->rchild,freshnode);
			}
		}
		else
		{
		  if(root->lchild==NULL)
			{
				root->lchild=freshnode;
			}
			else
			{
				insert(root->lchild,freshnode);
			}
		}

}
void tree::display()
{
	int ans;

	do
	{
		cout<<"\n\n\t\tMethods of tree traversal";
		cout<<"\n\n\t1.Preorder\n\t2.Postorder\n\t3.Inorder\n\t4.Exit\n";
		cout<<"\nEnter your choice\t";
		cin>>ans;
		switch(ans)
		{
			case 1:
					
					cout<<"\n\nPreorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					preorder(root);
					cout<<"\n-------------------------------------\n";

					break;
			case 2:
				
					cout<<"\n\nPostorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					postorder(root);
					cout<<"\n-------------------------------------\n";

					break;
			case 3:
					
					cout<<"\n\nInorder travrsal of Tree\n\n";
					cout<<"\n-------------------------------------\n";
					inorder(root);
					cout<<"\n-------------------------------------\n";
					break;
			case 4:
					break;
		}

	}  while(ans<4);
}
void tree::preorder(BSTnode *root1)
{
	if(root1!=NULL)
	{
		cout<<"\t"<<root1->data;
		preorder(root1->lchild);
		preorder(root1->rchild);
	}

}
void tree::postorder(BSTnode *root1)
{
	if(root1!=NULL)
	{
		postorder(root1->lchild);
		postorder(root1->rchild);
		cout<<"\t"<<root1->data;
	}

}
void tree::inorder(BSTnode *root1)
{
	if(root1!=NULL)
	{
		inorder(root1->lchild);
		cout<<"\t"<<root1->data;
		inorder(root1->rchild);
	}

}
void tree::search()
{
	int ans,ele;
	BSTnode *p;
	BSTnode *m;

	do
	{
		cout<<"\n\n\n\t\tOptions for Search";
		cout<<"\n\n\t1.Search Smallest\n\t2.Search Maximum\n\t3.Search the Element\n\t4.Search non Recursion\n\t5.Exit\n";
		cout<<"\nEnter your choice\t";
		cin>>ans;
		switch(ans)
		{
			case 1:
					
					p=searchmin(root);
					break;
			case 2:
					
					searchmax(root);
					break;
			case 3:
					
					cout<<"\nEnter the Element to Search";
					cin>>ele;
					searchgiven(root,ele,1);
					break;
			case 4:
					
					cout<<"\nEnter the Element to Search";
					cin>>ele;
					searchgiven1(root,ele,1);
					break;
			
		}

	}  while(ans<5);
}
BSTnode* tree::searchmin(BSTnode *root1)
{
	while(root1->lchild!=NULL)
	{
		root1=root1->lchild;
	}
	cout<<"\n\n Smallest Element is  "<<root1->data;
		return(root1);
}
void tree::searchmax(BSTnode *root1)
{
	while(root1->rchild!=NULL)
	{
		root1=root1->rchild;
	}
	cout<<"\n\n Maximum Element is  "<<root1->data;


}
void tree::searchgiven(BSTnode *root1,int elm,int count)
{
		if(root1==NULL)
				cout<<"\nElement is not present in tree\t";
		else 
		{
			if(root1->data==elm)
				cout<<"\nElement found at level\t"<<count;
		
			else
			{
		  		 if(root1->data<elm)
			       {
						count++;
						searchgiven(root1->rchild,elm,count);
		 		 }
		 		 if(root1->data>elm)
		 		  {
						count++;
						searchgiven(root1->lchild,elm,count);
				   }
			}
		}
}

void tree::searchgiven1(BSTnode *root1,int key,int count)
{
			int flag=0;
  			while(root1!=NULL)
			{
				if (key<root1->data)
				{
					root1=root1->lchild;
					//cout<<"\n\t"<<root1->data;
					count++;
				}
				if(key>root1->data)
				{
					root1=root1->rchild;
					//cout<<"\n\t"<<root1->data;
					count++;
				}
				if(root1->data==key)
				{
					cout<<"Element found at level \t"<<count;
					flag=1;
					break;
				}
			}
				if(root1==NULL)
				cout<<"\nElement is not present in tree\t";
		
 }
BSTnode * tree ::delet(BSTnode *root1,int key)
{
	BSTnode *temp;
	if(root1==NULL)
	{
		cout<<"\nElement not found :";

		return(root1);
	}
	if(key< root1->data)                // delete in left subtree
	{
		root1->lchild=delet(root1->lchild,key);
		return(root1);
	}
	if(key > root1->data)                // delete in right subtree
	{
		root1->rchild=delet(root1->rchild,key);
		return(root1);
	}
	if(root1->data==key)
	{
		
	// element is found
		if(root1->lchild==NULL && root1->rchild==NULL)   // a leaf node
		{
		temp=root1;
		root1=NULL;
 		free(temp);
 		return(root1);
		}
		if(root1->lchild==NULL&&root1->rchild!=NULL)				//Having Right child
		{
		temp=root1;
		root1=root1->rchild;                                                     
		free(temp);
		 return(root1);
		}
		if(root1->rchild==NULL&&root1->lchild!=NULL)				//Having Leftchild
		{
		temp=root1;
		root1=root1->lchild;
		free(temp);
		return(root1);
		}
if(root1->lchild!=NULL && root1->rchild!=NULL)		//Both Child

{
int temp1;
	// node with two children
		temp=searchmin(root1->rchild);
		root1->data=temp->data;
		root1->rchild=delet(root1->rchild,temp->data);
		return(root1);
}
}
}
BSTnode * tree::mirror(BSTnode*root1)
 {
 	BSTnode *temp;
 	temp=NULL;
 	if(root1!=NULL)
 	{
 		temp=new(BSTnode);
 		temp->data=root1->data;
 		temp->lchild=mirror(root1->rchild);
 		temp->rchild=mirror(root1->lchild);
 	}
 	return(temp);
 }
 int main()
 {
	
	tree t;
	int ch;


	do
	{
		
		cout<<"\n\n-----------------TREE------------------------ \n\n";
		cout<<"\n\t1.Create\n\t2.Disply\n\t3.Search\n\t4.Insert the Node\n\t5.Delete\n\t6.Mirror\n\t7.Exit\n";
		cout<<"\nEnter your choice\t";
		cin>>ch;
		switch(ch)
		{
			case 1:
					t.create();
					break;
			case 2:
					t.display();
					break;
			case 3:
					t.search();
					break;
			case 4:	
					BSTnode *freshnode;
		
					freshnode=new BSTnode;
					freshnode->rchild=NULL;
					freshnode->lchild=NULL;
			
					cout<<"\n\n Enter data to create new node\t";
					cin>>freshnode->data;
					t.insert(t.root,freshnode);
					break;
			case 5:
					 int key;
					BSTnode *temp;
					cout<<"\nEnter the data to Delete the node";
				  	cin>>key;
					temp=t.delet(t.root,key);
					cout<<"\n\n\tDelete the node";
					break;	
			case 6:
					BSTnode *mroot;
					mroot=t.mirror(t.root);
					cout<<"\n\n\t Original tree\n";
					t.preorder(t.root);
					cout<<"\n\t Mirror Image of tree \n";
					t.preorder(mroot);
					break;

		}

	}  while(ch<7);
return(0);
 }














