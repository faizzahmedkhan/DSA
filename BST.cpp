#include<iostream>
using namespace std;
#include<cstdlib>
struct BSTNode{
	int data;
	BSTNode*left;
	BSTNode*right;
};

 BSTNode* insert(BSTNode*node,int value){
	
	if(node==NULL){
		node=(BSTNode*)malloc(sizeof(BSTNode));
		node->data=value;
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	if(value<node->data){
		node->left=insert(node->left,value);
	}
	else{
		node->right=insert(node->right,value);
	}
}

void search(BSTNode*node,int value){
	if(node==NULL){
		cout<<"Not found";
	}
	
	else if(value<node->data){
		search(node->left,value);
	}
	else if(value>node->data){
		search(node->right,value);
	}
	else{
        cout << "Found";
    }
}

void Display(BSTNode*node){
	if (node==NULL)
	{
		return;
	}
	
	Display(node->left);
	cout <<node->data << " ";
	Display(node->right);
}

BSTNode* findmax(BSTNode*node){
    BSTNode*curr=node;
    while (curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}

BSTNode* findmin(BSTNode*node){
    BSTNode*curr=node;
    while (curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

BSTNode*Delete(BSTNode*node,int value){
	if (node==NULL)
	{
		return node;
	}
	else if (node->data==value)
	{
		if (node->left==NULL && node->right==NULL)
		{
			delete node;
			return NULL;
		}
		
		else if (node->left!=NULL && node->right==NULL)
		{
			BSTNode*temp=node->left;
			delete node;
			return temp;
		}
		else if (node->left==NULL && node->right!=NULL)
		{
			BSTNode*temp=node->right;
			delete node;
			return temp;
		}
		else{
			int min = findmin(node->right)->data;
			node->data=min;
			node->right=Delete(node->right,min);
		}
	}
	else if (node->data<value)
	{
		node->right=Delete(node->right,value);
		return node;
	}
		node->left=Delete(node->left,value);
		return node;
	
}

int main(){
	int value;
	
	BSTNode*Root=NULL;
	
	bool sign =true;
	while(sign==true){
		int button;
		cout<<"Choose options"<<endl<<"1 for insert"<<endl<<"2 for search"<<endl<<"4 to Delete"<<endl<<"5 to Display"<<endl;
		cin>>button;
		switch(button){
		
		case 1:
			cout << "enter value: ";
			cin>>value;
			Root=insert(Root,value);
			break;
		case 2:
			cout << "enter value: ";
			cin>>value;
			search(Root,value);
			break;
			
		case 4:
			cout<<"Enter value to delete ";
			cin>>value;
			Delete(Root,value);
			break;

		case 5:
			Display(Root);
			break;
		case 6:
			sign=false;
			break;
		}
	}
}
