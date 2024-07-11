#include<iostream>
using namespace std;

class Node
{
    public :
        char data;
        Node *left , *right, *next;

        Node()
        {

            left = right = next = NULL;
        }
};

class Tree
{
    public :
        Node *head;
        Tree()
        {
            head = NULL;
        }

        void push(Node*);
        Node* pop();
        bool is_empty();
};

void Tree :: push(Node *New)
{
   if(head == NULL)
   {
        head = New;
   }
   else
   {
        New -> next = head;
        head = New;
   }
}

bool Tree :: is_empty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node* Tree :: pop()
{
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        Node * temp;
        temp = head;
        head = head -> next;
        return temp;
        delete temp;
    }

}

class ExpTree
{
    public :
        Node *root , *l , *r;
        Tree tobj;

        void Prefix(string);
        void Postfix(string);
        void inOrder(Node*);
        void preOrder(Node*);
        void postOrder(Node*);

};

void ExpTree :: Prefix(string prefix)
{
    for (int i = prefix.length() - 1 ; i >= 0 ; i--)
    {
        char c = prefix[i];
        root = new Node();
        root -> data = c;
        if(c == '*' || c == '/' || c == '+' || c == '-' || c == '^')
        {
            l = tobj.pop();
            r = tobj.pop();
            root -> left = l;
            root -> right = r;
            tobj.push(root);
        }
        else if ((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z'))
        {
            tobj.push(root);
        }
    }
}

void ExpTree :: Postfix(string postfix)
{
    for (int i = 0 ; i < postfix.length() ; i++)
    {
        char c = postfix[i];
        root = new Node();
        root -> data = c;
        if(c == '*' || c == '/' || c == '+' || c == '-' || c == '^')
        {
            l = tobj.pop();
            r = tobj.pop();
            root -> left = l;
            root -> right = r;
            tobj.push(root);
        }
        else if ((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z'))
        {
            tobj.push(root);
        }
    }    

}

void ExpTree :: inOrder(Node *head)
{   
    if(head != NULL)
    {
        inOrder (head -> left);
        cout <<head -> data << " ";
        inOrder (head -> right);
    }
}

void ExpTree :: preOrder(Node *head)
{
    if (head != NULL)
    {
        cout <<head -> data << " ";
        preOrder (head -> left);
        preOrder (head -> right);
    }
}    

void ExpTree :: postOrder (Node *head)
{
    if(head != NULL)
    {
        postOrder (head -> left);
        postOrder (head -> right);
        cout <<head ->data << " ";
    }
}

int main()
{
    
    string postfix , prefix;
    int choice;
    

    Tree tobj;
    ExpTree eobj;

    while(1)
    {
        cout << endl <<"\n1.ENTER PREFIX "<< endl;
        cout << "\n2.ENTER POSTFIX"<< endl;
        cout << "\n3.EXIT" << endl;
        cout << "\nENTER CHOICE" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1 :
                cout << "Enter expression : " << endl;
                cin >> prefix;
                eobj.Prefix(prefix);
                cout << "\nInorder : "; 
                eobj.inOrder(eobj.root);
                cout << "\nPreorder :";
                eobj.preOrder(eobj.root);
                cout << "\nPostorder :";
                eobj.postOrder(eobj.root);
                break;

            case 2 :
                cout << "Enter expression : " << endl;
                cin >> postfix;
                eobj.Postfix(postfix);
                cout << "\nInorder : "; 
                eobj.inOrder(eobj.root);
                cout << "\nPreorder :";
                eobj.preOrder(eobj.root);
                cout << "\nPostorder :";
                eobj.postOrder(eobj.root); 
                break;

            case 3 :
                return 0;
                break;

            default :
                cout << "Invalid input....";
                break;    

        }

    }

}