#include <iostream>
using namespace std;
#include <math.h>
#include <algorithm>

struct Node
{
    char value;
    Node*next;
    Node(char input){
        value=input;
    }
};

struct EvNode{
    double value;
    EvNode*next;
    EvNode(double input){
        value=input;
    }
};

struct DNode
{
    char value;
    DNode*left;
    DNode*right;
    DNode(char c){
        value=c;
        left=NULL;
        right=NULL;
    }
};

struct ENode
{
    DNode*entry;
    ENode*next;
    ENode(DNode*value){
        entry=value;

    }
};



void Push(Node**top, char c){
    Node*ptr=new Node(c);
    ptr->next=*top;
    *top=ptr;
}
void Pop(Node**top){
    if(*top==NULL){
        cout<<"kuch daal to";
    }
    Node*temp=*top;
    *top=(*top)->next;
    free(temp);
}

void EvPush(EvNode**evtop, double c){
    EvNode*ptr= new EvNode(c);
    ptr->next=*evtop;
    *evtop=ptr;
}
void EvPop(EvNode**evtop){
    if (*evtop==NULL)
    {
        cout<<"stack underflow";
    }
    EvNode*temp=*evtop;
    *evtop=(*evtop)->next;
    free(temp);
}

void EPush(ENode**etop, DNode*c){
    ENode*ptr= new ENode(c);
    ptr->next=*etop;
    *etop=ptr;
}
void EPop(ENode**etop){
    if (*etop==NULL)
    {
        cout<<"stack underflow";
    }
    ENode*temp= *etop;
    *etop=(*etop)->next;
    free(temp);
}

int prec(char op){
     if (op == '|')
    {
        return 0;
    }
    else if (op == '&')
    {
        return 1;
    }
    else if (op == '<' || op == '>')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 3;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 4;
    }
    else if (op == '(')
    {
        return 5;
    }
    else
    {
        return -1;
    }
}

int Operator(char opr,double op1,double op){
    switch (opr)
    {
    case '+':
        return op1+op;
    
    case '-':
        return op1-op;

    case '*':
        return op1*op;

    case '/':
        return op1/op;

    case '&':
        return (op1!=0) && (op!=0);

    case '|':
        return (op1!=0) || (op!=0);

    case '>':
        return op1 > op;

    case '<':
        return op1 < op;

    default:
        return -1;
    }
}

string Conversion(string Infix, Node*top){
    reverse(Infix.begin(),Infix.end());
    string Prefix="";
    for (int i = 0; i < Infix.length(); i++)
    {
        if ((Infix[i]>='a'&&Infix[i]<='z') || (Infix[i]>='A'&&Infix[i]<='Z'))
        {
            Prefix+=Infix[i];
        }
        else if (Infix[i]==')')
        {
            Push(&top,Infix[i]);
        }
        else if (Infix[i]=='(')
        {
            while (top!=NULL && top->value!=')')
            {
                Prefix += top->value;
                Pop(&top);
            }
            Pop(&top);
        }
        else 
        {
            while(top!=NULL && prec(top->value)>=prec(Infix[i])&& top->value!='('){
                Prefix+=top->value;
                Pop(&top);
            }
            Push(&top,Infix[i]);
        }
        
    }
    while (top)
    {
        Prefix+=top->value;
        Pop(&top);
    }
    reverse(Prefix.begin(),Prefix.end());
    return Prefix;
}

double Evaluation(string Prefix, EvNode*evtop){
    reverse(Prefix.begin(), Prefix.end());  
    for (int i = 0; i < Prefix.length(); i++)
    {
        if ((Prefix[i]>='a'&& Prefix[i]<='z') || (Prefix[i]>='A'&&Prefix[i]<='Z'))
        {
            cout<<"Enter a value for "<<Prefix[i]<<" ";
            double value;
            cin>>value;
            EvPush(&evtop, value);
        }
        else if (Prefix[i]>='0' && Prefix[i]<='9')
        {
            EvPush(&evtop,Prefix[i]-'0');
        }
        else{
            double op= evtop->value;
            EvPop(&evtop);
            double op1= evtop->value;
            EvPop(&evtop);
            double res = Operator(Prefix[i],op1,op);
            EvPush(&evtop,res);
        }
    }
    return evtop->value;
}

void Display(DNode*root){
    if(root==NULL){
        return;
    }
    Display(root->left);
    cout<<root->value<<" ";
    Display(root->right);
}

void EvTree(string Prefix, ENode**etop){

    reverse(Prefix.begin(),Prefix.end());

    for (int i = 0; i < Prefix.length(); i++)
    {
         DNode*ptr=new DNode(Prefix[i]);
        if ((Prefix[i]>='a' && Prefix[i]<='z')|| (Prefix[i]>='A' && Prefix[i]<='Z'))
        {
            EPush(etop, ptr);
        }
        else if ((Prefix[i]>='0' && Prefix[i]<='9'))
        {
            EPush(etop,ptr);
        }
        else{
            ptr->right=(*etop)->entry;
            EPop(etop);
            ptr->left=(*etop)->entry;
            EPop(etop);

            EPush(etop,ptr);
        }
    }
}

int main(){
    string Infix= "(a-b/c)*(a/k-l)";
    Node *top=NULL;
    EvNode*evtop=NULL;
    ENode*etop=NULL;
    
    string Prefix=Conversion(Infix,top);
    cout<<"Prefix is: "<<Prefix<<endl;

    double PrefixEv=Evaluation(Prefix,evtop);
    cout<<"Evaluation for Prefix is: "<<PrefixEv<<endl;
    
    EvTree(Prefix,&etop);
    Display(etop->entry);
    return 0;
}