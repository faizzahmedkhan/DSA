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
		ptr->next=*head;
	}
	else{
		Record*curr=*head;
		while(curr->next!=*head){
			curr=curr->next;
		}
		curr->next=ptr;
		ptr->next=*head;
	}

}
void search(Record**head){
	int tosearch;
	int count=0;
	cout<<"Enter value to search";
	cin>>tosearch;
	Record*curr=*head;
	do {
        if(curr->Rollno == tosearch){
            count = 1;
            break;
        }
        curr = curr->next;
    } while(curr != *head);
    if(count == 1){
        cout<<"Found";
    }
    else{
        cout<<"not found";
    }
}


void print(Record*head){
	Record*curr=head;
	do {
        cout<<"Rollno "<<curr->Rollno<< " ; GPA "<<curr->GPA<<endl;
        curr = curr->next;
    } while(curr!=head);
}
void Delete(Record**head){
	Record*curr=*head;
	Record*prev=NULL;
	int toDel;
	cout<<"Enter the Rollno to get deleted"<<endl;
	cin>>toDel;
	if(toDel==(*head)->Rollno){
		while(curr->next!=*head){
			curr = curr->next;
		}
		curr->next = (*head)->next;
		free(*head);
		*head =curr->next;
	}
	else{
	curr=*head;
	while(curr->next!=*head){
		if(curr->Rollno!=toDel && curr->next!=*head){
			prev=curr;
			curr =curr->next;
		}
		
		}
		if (curr->Rollno==toDel)
		{
			prev->next=curr->next;
			free(curr);

		}
		
		
	else{
			cout<<"Not found";
	}
	}
}


void All(Record**head){
	Record*curr=*head;
	Record*temp;
	while(curr->next!=*head){

		temp=curr->next;
		free(curr);
		curr=temp;
	}
	free(*head);
	*head=NULL;
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
