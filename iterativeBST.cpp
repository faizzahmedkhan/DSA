#include<iostream>
#include<cstdlib>
using namespace std;

struct BST
{
    int data;
    BST*left;
    BST*right;
};

BST* insert(BST*node, int value){
    BST*ptr=new BST();
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=value;
    if (node==NULL)
    {
        node=ptr;
        return node;
    }
    BST*curr=node;
    BST*parent=NULL;
        while (curr!=NULL)
        {
            parent=curr;
            if (curr->data>value)
            {   
                curr=curr->left;
            }   
            else if (curr->data<value)
            {
                curr=curr->right;
            }
            
        }
        if (parent->data>value)
        {
            parent->left=ptr;
        }
        if (parent->data<value)
        {
            parent->right=ptr;
        }
    return node;    
}



void search(BST*node, int value){
    BST*curr=node;
    bool sign=false;
    while(curr != NULL){
        if(value < (curr)->data){
            (curr) = (curr)->left;
        }
        else if(value > (curr)->data){
            (curr) = (curr)->right;
        }
        else{
            cout << "Found"<<endl;
            sign = true;
            break;
        }
    }
    if (sign ==false)
    {
        cout<<"Not found"<<endl;
    }
}

// void Delete(BST*node, int value){
//     BST*curr=node;
//     while (curr!=NULL)
//     {
//         if (node->data==value)
//         {
//             BST*temp            
//         }
        
//     }
    
// }

void findmax(BST*node){
    BST*curr=node;
    while (curr->right!=NULL)
    {
        curr=curr->right;
    }
    cout<<curr->data;
}

void findmin(BST*node){
    BST*curr=node;
    while (curr->left!=NULL)
    {
        curr=curr->left;
    }
    cout<<curr->data;
}

int main(){
	bool sign =true;
    BST*node=NULL;
    int value;
	while(sign){
		int button;
		cout<<"Choose options"<<endl<<"1 for insert"<<endl<<"2 for search"<<endl<<"3 to end"<<endl<<"4 for max"<<endl<<"5 for max"<<endl;
		cin>>button;
		switch(button){
		
		case 1:
            cout << "Enter value: ";
            cin >> value;
			node = insert(node, value);
			break;
        case 2:
            int s;
            cin>>s;
            search(node,s);
            break;
        case 3:
            sign=false;
            break;
        case 4:
            findmax(node);
            break;
        case 5:
            findmin(node);
            break;
        }
    }
}