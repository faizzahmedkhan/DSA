#include<iostream>
using namespace std;
#include<cstdlib>
struct Record{
    int Rollno;
    float GPA;
    Record*next;
    int index;
    Record(int r, float gpa, int i){
        Rollno = r;
        GPA=gpa;
        index=i;
        next=NULL;
    }
};
Record* insert(Record*head,int r,int gpa, int index){
	
	if(head==NULL){
        Record*ptr=new Record(r,gpa,index);
		head=ptr;
        return head;
	}
    head->next= insert(head->next,r,gpa,index);
    return head;
	
}

void Index(Record**head, int i){
    (*head)->index=i;
    Index(&(*head)->next,i);
}

bool search(Record*head,int s){
	
	if (head==NULL)
    {
        return false;
    }
    else if (s==head->Rollno)
    {
        cout<<"Found "<<head->Rollno;
        return true;
    }
    return search(head->next, s);
}
void print(Record*head){
	if (head==NULL)
    {
        return;
    }
    cout<<"Rollno"<<head->Rollno<< " ;GPA"<<head->GPA<<endl;
    print(head->next);
}

Record *Delete(Record*head, int del){
	
	if (head==NULL)
    {
        return head;
    }
    if(head->Rollno==del){
		Record*temp=head->next;
        Index(&temp,head->index);
        delete head;
        return temp;
	}
	head->next=Delete(head->next,del);
    return head;
}


void All(Record*head){
	All(head->next);
    delete head;
}



 int main(){
	Record*head=NULL;
    int index=0;
    bool signal =true;
    while(signal){
		cout<<"Press 1 to insert"<<endl;
		cout<<"Press 2 to search"<<endl;
		cout<<"Press 3 to print"<<endl;
		cout<<"Press 4 to delete"<<endl;
		cout<<"Press 5 to delete all"<<endl;
        int opt;
		cin>> opt;
		if(opt==1){
			int roll; float g;
            cout<<"Enter the Roll No. and GPA"<<endl;
            cin>>roll>>g;
            head=insert(head,roll,g,index);
            index++;
		}
		else if(opt==2){
            if (head==NULL)
            {
                cout<<"khaali "<<endl;
            }
            else 
            {
                int tosearch;
                cout<<"Enter value to search ";
                cin>>tosearch;
                bool check=search(head,tosearch);
                if (!check)
                {
                    cout<<"Not found "<<endl;
                }
            }
		}
		else if(opt==3){
			print(head);
		}
		else if(opt==4){
            if (head == NULL)
            {
                cout << "Linked List is empty" << endl;
            }
            else{
            int toDel;
            cout<<"Enter the Rollno to get deleted "<<endl;
            cin>>toDel;
            head=Delete(head,toDel);
            index--;
		    }
        }
		else if(opt==5){
            
			All(head);
            head=NULL;
            index=0;
		}
        else if (opt==6)
        {
            cout<<index<<endl;
        }
        
		else if (opt==0)
        {
            signal=false;
        }
        else{
            cout<<"kia bol rha hai "<<endl;
        }
        
    }
	
}
