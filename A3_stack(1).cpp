#include <iostream>
using namespace std;

class Node 
{
    public :
        char data;
        Node *next;
};

class stack 
{
    public :
        Node *head;
        int count;

        stack()
        {
            head = NULL;
            count = 0;
        }
        void push(char);
        char pop();
        char peek();
        void display();
        bool is_empty();
        int icount();

};

bool stack :: is_empty()
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

void stack :: push (char ch)
{
    Node *New ;
    New = new Node;
    New -> data = ch;
    New -> next = head;
    head = New;
    count++ ;
}

char stack :: pop()
{
    if (!is_empty())
    {
       Node *temp;
       temp = head;
       char key = temp -> data;
       head = head -> next;
       delete temp;
       count-- ;
       return key;
    }

    else 
    {
        cout << "The stack is empty";
        return 0;
    }
}

char stack :: peek()
{
    if(!is_empty())
    {
        return head -> data;
    }
    return '\0';
}

void stack :: display()
{
    Node * temp;
    temp = head;
    if (is_empty())
    {
        cout << "The stack is empty.";
    }
    else 
    {
        do
        {
            cout << temp -> data <<"\t";
            temp = temp -> next;
        }
        while (temp -> next != NULL);
    }
}

int stack :: icount()
{
    return count;
}

class expression
{
    public :
        string infix;
        string prefix = "";
        string postfix = "";
        stack st;

        int priority(char);
        string InfixPostfix(string);
        string InfixPrefix(string);
        string reverseStr (string);
        int EvaluatePostfix(string);
        int EvaluatePrefix(string);
        void displayExp(char);
        bool is_operator(char);
        bool is_operand(char);
}; 


bool expression :: is_operator(char ch)
{
    if( ch == '*' || ch == '/' || ch == '+' || ch == '-' )
    {
        return true;
    }     
    else
    {
        return false;
    }
    
}

bool expression :: is_operand (char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int expression :: priority(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    
    else if (ch == '*'|| ch == '/')
    {
        return 2;
    }

    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return -1;
}

string expression :: InfixPostfix(string infix)
{
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            postfix = postfix + c;
        }

        else if(c == '(')
        {
            st.push(c);
        }

        else if(c == ')')
        {
            while(!st.is_empty() && st.peek() != '(')
            {
                postfix = postfix + st.pop();
            }     
            if (!st.is_empty() && st.peek() == '(')
            {
                st.pop();
            }
        }

        else
        {
            while (!st.is_empty() && priority(c) <= priority(st.peek()) )
            {                    
                postfix = postfix + st.pop();
            }
            st.push(c);
        }
    }

    while (!st.is_empty())
    {
        postfix = postfix + st.pop();
    }
    cout << "\n";
    cout << "The post fix expression is " << postfix;
    cout << "\n";
    return postfix;
}
string expression :: reverseStr(string str)
{
    string reversed;
    for (int i = str.length() - 1; i >= 0 ; i--)
    {
        if(str[i] == '(')
        {
            str[i] = ')';
        }
        else if(str[i] == ')')
        {
            str[i] = '(';
        }
        
        reversed += str[i];
    }
    return reversed;
}

string expression :: InfixPrefix (string infix)
{
    string revInfix = reverseStr(infix);
    string tempPrefix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = revInfix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            tempPrefix = tempPrefix + c;
        }

        else if(c == '(')
        {
            st.push(c);
        }

        else if(c == ')')
        {
            while(!st.is_empty() && st.peek() != '(')
            {
                tempPrefix = tempPrefix + st.pop();
            }     
            if (!st.is_empty() && st.peek() == '(')
            {
                st.pop();
            }
        }

        else
        {
            while (!st.is_empty() && priority(c) <= priority(st.peek()) )
            {                    
                tempPrefix = tempPrefix + st.pop();
            }
            st.push(c);
        }
    }

    while (!st.is_empty())
    {
        tempPrefix = tempPrefix + st.pop();
    }

    prefix = reverseStr(tempPrefix);
    cout << "\n";
    cout << "The pre fix expression is " << prefix;
    cout << "\n";
    return prefix;
}

int expression :: EvaluatePostfix (string postfix)
{   
    string evaluate;
    for(int i = 0 ; i < postfix.length() ; i++)
    {
        char c = postfix[i];
        if ( is_operand(c))
        {   
            int val;
            cout << "enter the value of expression "<< c << " : \t" ;
            cin >> val;
            st.push(val);
        }
        else if(is_operator(c))
        {
            int a = st.pop();
            int b = st.pop();

            switch(c)
            {
                case '+' :
                    st.push(a + b);
                    break;

                case '-' :
                    st.push(b - a);
                    break;

                case '*' :
                    st.push(a * b);   
                    break;

                case '/' :
                    st.push(b / a);
                    break;

               /* case '^' :
                    st.push(pow(b , a));
                    break;
                */    

                default  : 
                    cout << "invalid input. ";            
            }
        }
    } 
    int ans = st.pop();
    cout << "The evaluation of the given expression is :" << ans;
    return ans;
}

int expression :: EvaluatePrefix(string prefix)
{
    //string RevPrefix = reverseStr(prefix);
    
    for (int i = prefix.length() - 1 ; i >= 0 ; i -- )
    {
        
        char c = prefix[i];
        
        if(is_operand(c))
        {
            int val;
            cout << "Enter the vakue of expression " << c << " : ";
            cin >> val;
            st.push(val);
        }
        else if(is_operator(c))
        {
            int a = st.pop();
            int b = st.pop();

            switch(c)
            {
                /*case '^' :
                    st.push(pow(b , a));
                    break;
                */    
                
                case '*' :
                    st.push(a * b);
                    break;

                case '/' :
                    st.push(b / a);
                    break;

                case '+' : 
                    st.push(a + b);
                    break;

                case '-' :
                    st.push(b - a);
                    break;

                default :
                    cout << "invlaid input " << endl;   
                    break;             
            }

        }   

    }
    int ans = st.pop();
    cout << "The Evaluated expression is :" << ans << "\n ";
    return ans;

}


int main()
{
    expression sobj;
    int choice = -1;
    string infix;
    cout << "Enter the expression for conversion: ";
    cin >> infix;

    while (true)
    {
        cout << endl
             << endl
             << "Stack Menu" << endl;
        cout << "1. Convert Infix to Postfix" << endl;
        cout << "2. Evaluate postfix." << endl;
        cout << "3. Convert Infix to Prefix" << endl;
        cout << "4. Evaluate Prefix."<< endl ;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1 :
                sobj.InfixPostfix(infix);
                break;

            case 2 :
                sobj.EvaluatePostfix(sobj.postfix);
                break;
            
            case 3 :
                sobj.InfixPrefix(infix);
                break;

            case 4 :
                sobj.EvaluatePrefix(sobj.prefix);
                break;

            case 5 :
                return 0;

            default :
                cout << "Invalid input.....";
                break;        

        }
    }
}
