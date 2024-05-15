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

void mirror(BSTNode*root){
	if (root==NULL)
	{
		return;
	}
	else{
		mirror(root->left);
		mirror(root->right);

		BSTNode*temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}

int height(BSTNode*root){
	if (root==NULL)
	
		return 0;
	
	else{
		int lh =height(root->left);
		int rh=height(root->right);

		if (lh>rh)
			return(lh+1);
		else return (rh+1);
	}
	
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

bool compareTrees(BSTNode* root1, BSTNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    
    return (root1->data == root2->data) && // romve it to compare structure
           compareTrees(root1->left, root2->left) &&
           compareTrees(root1->right, root2->right);
}

bool ancestors(BSTNode*p, int target){
	if (p!=NULL )
	{
		if (p->data==target)
		{
			return true;
		}
		if (ancestors(p->left,target) || ancestors(p->right,target))
		{
			cout<<p->data<<" ";
			return true;
		}
	}
	return false;
}

void successors(BSTNode*p,int target){
	if(p==NULL){
		cout<<"Not found";
	}
	else if(target<p->data){
		search(p->left,target);
	}
	else if(target>p->data){
		search(p->right,target);
	}
	if (p->data==target)
	{
		if (p->right!=NULL)
		{
			BSTNode*temp=p->right;
			while (temp->left!=NULL)
				temp=temp->left;
			cout<<temp->data<<endl;
		}
	}
}

void trace(BSTNode*root,int d){
	if (root==NULL)
	{
		return ;
	}
	if (d==0)
	{
		cout<<root->data<<" ";
	}
	else{
		trace(root->left,d-1);
		trace(root->right,d-1);
	}
	
}

bool mirrorcheck(BSTNode* root1, BSTNode* root2) {
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    
    return (root1->data == root2->data) &&
           compareTrees(root1->left, root2->right) &&
           compareTrees(root1->right, root2->left);
}

int main(){
	int value;
	BSTNode*Root=NULL;
	BSTNode*Root1=NULL;
	bool sign =true;
	while(sign==true){
		int button;
		cout<<"Choose options"<<endl<<"1 for insert"<<endl<<"2 for search"<<endl<<"3 for insert in 2nd tree"<<endl<<"4 to Delete"<<endl<<"5 to Display"<<endl<<"6 to mirror "<<endl
		<<"7 for height"<<endl<<"8 to compare"<<endl<<"9 to find ancestors"<<endl<<"10 to go to a distance"<<endl<<"11 to check mirroring"<<endl<<
		"12 for successors"<<endl<<"0 to end"<<endl;
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
			
        case 3:
            cout<<" Enter value: ";
            cin>>value;
            Root1=insert(Root1,value);
            break;    
		case 4:
			cout<<"Enter value to delete ";
			cin>>value;
			Delete(Root,value);
			break;

		case 5:
			Display(Root);
            cout<<"dusra ";
            Display(Root1);
			break;

		case 6:
			int opt;
			cout<<"Mirror 1st tree or 2nd: ";
			cin>>opt;
			if (opt==1)
			{
				mirror(Root);
			}
			else{
			mirror(Root1);
			}
			break;

		case 7:
			cout<<height(Root)<<endl;
			break;	
        case 8:
            if (compareTrees(Root,Root1))
            cout<<"Same "<<endl;
            else
                cout<<"alag "<<endl;
            break;
		case 9:
			int tar;
			cout<<"Enter the target node: ";
			cin>>tar;
			ancestors(Root,tar);
			break;
		case 10:
			int dis;
			cout<<"Enter the distance you want to reach: ";
			cin>>dis;
			trace(Root,dis);
			break;
		case 11:
			if (mirrorcheck(Root,Root1))
            cout<<"Mirror "<<endl;
            else
                cout<<"Not mirror "<<endl;
            break;
		case 12:
			cin>>value;
			successors(Root,value);
		case 0:
			sign=false;
			break;

		}
	}
}
