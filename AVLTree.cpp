#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node*right;
    Node*left;
    Node(int c){
        value=c;
        left=nullptr;
        right=nullptr;
    }
};

int height(Node*root){
    if(root==NULL){
        return -1;
    }
    int lh=height(root->left);
    int rh=height(root->right);    
    return lh>rh ? lh+1:rh+1;
}

Node*Rrotate(Node*root){
    Node*temp= root->left;
    root->left=temp->right;
    temp->right=root;
    return temp;
}

Node*Lrotate(Node*root){
    Node*temp= root->right;
    root->right=temp->left;
    temp->left=root;
    return temp;
}

Node*Insert(Node*root, int value){

    if (root==NULL)
    {
        Node*node = new Node(value);
        root=node;
        return root;
    }
    else if (value>root->value)
    {
        root->right=Insert(root->right,value);
        if((height(root->left)-height(root->right))>1 || (height(root->left)-height(root->right))<-1){
            if (value>root->right->value)
            {
                
                root =Lrotate(root);
            }
            else{
                root->right=Rrotate(root->right);
                root=Lrotate(root);
            }
        }
    }
    else{
        root->left=Insert(root->left,value);
        if ((height(root->left)-height(root->right))>1 || (height(root->left)-height(root->right))<-1)
        {
            if (value<root->left->value)
            {
                root=Rrotate(root);
            }
            else{
                root->left=Lrotate(root->left);
                root=Rrotate(root);
            }
        }
        
    }
    
    return root;
}

void Display(Node *root)
{
    if(root=NULL)
    {
        return;
    }
    Display(root->left);
    cout<<root->value<<" ";
    Display(root->right);
}

bool search(Node*root, int Search){
    if (root==NULL)
    {
        return false;
    }
     if (Search>root->value)
    {
        return search(root->right,Search);
    }
     if (Search==root->value)
    {
        return true;
    }
    else{
        return search(root->left,Search);
    }
    
}

Node* findmax(Node*node){
    Node*curr=node;
    while (curr->right!=NULL)
    {
        curr=curr->right;
    }
    return curr;
}

Node* findmin(Node*node){
    Node*curr=node;
    while (curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}


Node*Delete(Node*node,int value){
	if (node==NULL)
	{
		return node;
	}
	else if (node->value==value)
	{
		if (node->left==NULL && node->right==NULL)
		{
			delete node;
			return NULL;
		}
		else if (node->left!=NULL && node->right==NULL)
		{
			Node*temp=node->left;
			delete node;
			return temp;
		}
		else if (node->left==NULL && node->right!=NULL)
		{
			Node*temp=node->right;
			delete node;
			return temp;
		}
		else{
			int min = findmin(node->right)->value;
			node->value=min;
			node->right=Delete(node->right,min);
		}
	}
	else if (node->value<value)
	{
		node->right=Delete(node->right,value);
		return node;
	}
		node->left=Delete(node->left,value);
		return node;
	
}

int main(){
    Node*root=NULL;
    bool loop =true;
    while (loop)
    {
        cout << "Press" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Display" << endl;
        cout << "4. Height of tree" << endl;
        cout << "0. Exit" << endl;
        int num;
        cin>>num;
        switch (num)
        {
        case 1:
            cout<<"Enter a value to insert: ";
            int value;
            cin>>value;
            root=Insert(root,value);
            height(root);
            break;
        
        case 2:
            cout<<"Enter a calue to search: ";
            int Search;
            cin>>Search;
            bool found;
            found =search(root,Search);
            // cout<<search(root,Search);
            found ? cout<< "found"<<endl: cout<<"not found"<<endl;
            break;
        case 3:
            Display(root);
            break;
        case 4:
            cout<<"Height of root: "<<height(root)<<endl;
            break;
        case 5:
            cout<<"Enter the value to delete";
            int del;
            cin>>del;
            Delete(root,del);
            break;
        case 0:
            loop=false;
            break; 

        default:
            break;
        }
    }
    
}