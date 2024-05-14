#include <iostream>
using namespace std;
#include <cstdlib>
#include <math.h>

struct Node
{
    char value;
    Node *next;
    Node(char input){
        value=input;
    }
};
struct EvNode
{
    double value;
    EvNode *next;
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
    ENode *next;
    ENode(DNode*value){
        entry=value;
    }
};
    


void EvPush(EvNode **etop, int c){
    EvNode *ptr= new EvNode(c);
    ptr->next=*etop;
    *etop=ptr;
}

void EvPop(EvNode **etop){
    if(*etop==NULL){
        cout<<"Stack underflow";
    }
    else{
        EvNode *temp= *etop;
        *etop=(*etop)->next;
        free(temp);
    }
}

void EPush(ENode **ttop, DNode* c){
    ENode*ptr= new ENode(c);
    ptr->next=*ttop;
    *ttop=ptr;
}
void EPop(ENode**ttop){
    if(*ttop==NULL){
        cout<<"Stack underflow";
    }
    ENode*temp=*ttop;
    *ttop=(*ttop)->next;
    free(temp);
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

void Push(Node **top,char c){
    Node* ptr =new Node(c);
    ptr->next=*top;
    *top=ptr;
}

void Pop(Node**top){
    if (*top==nullptr)
    {
        cout<<"Stack underflow"<<endl;
    }
    else{
        Node *temp=*top;
        *top=(*top)->next;
        free(temp);
    }
    
}

string IntoPost(Node *top, string Infix){
    
    string Postfix = "";

    for (int i = 0; i < Infix.length(); i++)
    {
        if ((Infix[i] >= 'a' && Infix[i] <= 'z') || (Infix[i] >= 'A' && Infix[i] <= 'Z'))
        {
            // cout << Infix[i] << " is added to Postfix" << endl;
            Postfix += Infix[i];
        }
        else if (Infix[i] == '(')
        {
            // cout << "( is added to stack" << endl;
            Push(&top, Infix[i]);
        }
        else if (Infix[i] == ')')
        {
            while ((top != nullptr) && (top->value != '('))
            {
                // cout << top->value << " is popped from the stack and added to Postfix" << endl;
                Postfix += top->value;
                Pop(&top);
            }
            // cout << top->value << " is popped from the stack" << endl;
            Pop(&top);
        }
        else
        {
            while ((top != nullptr) && (prec(Infix[i]) <= prec(top->value)) && (top->value != '('))
            {
                // cout << top->value << " is popped from the stack and added to Postfix" << endl;
                Postfix += top->value;
                Pop(&top);
            }
            // cout << Infix[i] << " is added to the stack" << endl;
            Push(&top, Infix[i]);
        }
    }
    // cout << "Length of the string is completed" << endl;
    while (top != nullptr)
    {
        // cout << top->value << " is popped from the stack and added to Postfix" << endl;
        Postfix += top->value;
        Pop(&top);
    }

    return Postfix;
}

double Evaluation(EvNode *etop, string Postfix){
    for (double i = 0; i < Postfix.length(); i++)
    {
        if ((Postfix[i] >= 'a' && Postfix[i] <= 'z') || (Postfix[i] >= 'A' && Postfix[i] <= 'Z'))
        {
            cout<<"Enter a value for "<<Postfix[i]<<endl;
            double value;
            cin>>value;
            EvPush(&etop,value);
        }
        else if (Postfix[i]<='0'&&Postfix[i]>='9')
        {
            EvPush(&etop,Postfix[i]-'0');
        }
        else{
            double op =etop->value;
            EvPop(&etop);
            double op1 =etop->value;
            EvPop(&etop);

            double result = Operator(Postfix[i],op1,op);
            EvPush(&etop, result);
        }
    }
    return etop->value;
}

void Display(DNode*root){
    if (root==NULL)
    {
        return ;
    }
    Display(root->left);
    cout<<root->value<<" ";
    Display(root->right);
}

void EvTree(string Postfix, ENode**ttop){
    
    for (int i = 0; i < Postfix.length(); i++)
    {
        DNode*ptr=new DNode(Postfix[i]);
        if ((Postfix[i]>='a' && Postfix[i]<='z')|| (Postfix[i]>='A' && Postfix[i]<='Z'))
        {
            EPush(ttop, ptr);
        }
        else if ((Postfix[i]>='0' && Postfix[i]<='9'))
        {
            EPush(ttop,ptr);
        }
        else{
            ptr->right=(*ttop)->entry;
            EPop(ttop); 
            ptr->left=(*ttop)->entry;
            EPop(ttop);

            EPush(ttop,ptr);
        }
    }
    
}

int main(){
    Node *top=nullptr;
    EvNode *etop=nullptr;
    ENode *ttop=NULL;

    string Infix="(a-b/c)*(a/k-l)";
    string Postfix=IntoPost(top,Infix);
    cout<<"Postfix: "<<Postfix<<endl;   

    double PostfixEvaluation = Evaluation(etop, Postfix);
    cout<<"Evaluation :"<<PostfixEvaluation<<endl;

    EvTree(Postfix, &ttop);
    Display(ttop->entry);

    return 0;
}