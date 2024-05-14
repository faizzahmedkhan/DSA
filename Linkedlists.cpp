#include<iostream>
using namespace std;
#include<cstdlib>
struct Record{
    int Rollno;
    float GPA;
    Record*next;
};
void insert(Record**head){
	Record*ptr=(Record*)malloc(sizeof(Record));
	cout<<"Enter Rollno and GPA"<<endl;
	cin>>ptr->Rollno;
	cin>>ptr->GPA;
	ptr->next=NULL;
	if(*head==NULL){
		*head=ptr;
	}
	else{
		Record*curr=*head;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=ptr;
	}
}
void search(Record**head){
	int tosearch;
	int count=0;
	cout<<"Enter value to search";
	cin>>tosearch;
	Record*curr=*head;
	while(curr!=NULL){
		if(curr->Rollno==tosearch){
			
			count=1;
			break;
		}
		else{
			curr=curr->next;
		}
		
		
	}
	if(count==1){
			cout<<"Found";
		}
		else{
			cout<<"not found";
		}
}
void print(Record*head){
	Record*curr=head;
	while(curr!=NULL){
		cout<<"Rollno"<<curr->Rollno<< " ;GPA"<<curr->GPA<<endl;
		curr=curr->next;
	}
}
void Delete(Record**head){
	Record*curr=*head;
	int toDel;
	cout<<"Enter the Rollno to get deleted"<<endl;
	cin>>toDel;
	if(toDel==(*head)->Rollno){
		*head=(*head)->next;
		free(curr);
	}
	else{
	Record*prev=(*head);
	curr=(*head)->next;
	while(curr!=NULL){
		if(curr->Rollno==toDel){
			prev->next=curr->next;
			break;
		}
		curr =curr->next;
		prev=prev->next;
		}
		
	if(curr==NULL){
			cout<<"Not found";
	}
	}
}


void All(Record**head){
	Record*curr=*head;
	while(curr!=NULL){
		*head=curr->next;
		free(curr);
		curr=*head;
	}
}



 int main(){
	Record*head=NULL;
	int opt ;
	string cont;
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to search"<<endl;
		cout<<"Press 3 to print"<<endl;
		cout<<"Press 4 to delete"<<endl;
		cout<<"Press 5 to delete all"<<endl;
		cin>> opt;
		if(opt==1){
			insert(&head);
		}
		else if(opt==2){
			search(&head);
		}
		else if(opt==3){
			print(head);
		}
		else if(opt==4){
			Delete(&head);
		}
		else if(opt==5){
			All(&head);
		}
		cout<<"Do you want to continue?";
		cin>>cont;
	while(cont=="a"){
		
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to search"<<endl;
		cout<<"Press 3 to print"<<endl;
		cout<<"Press 4 to delete"<<endl;
		cout<<"Press 5 to delete all"<<endl;
		cin>> opt;
		if(opt==1){
			insert(&head);
		}
		if(opt==2){
			search(&head);
		}
		if(opt==3){
			print(head);
		}
		if(opt==4){
			Delete(&head);
		}
		if(opt==5){
			All(&head);
		}
		cout<<"Do you want to continue?";
		cin>>cont;
	}
	
}
