#include<iostream>
using namespace std;

struct Node
{
    public :
        int data;
        Node *left;
        Node *right;

        Node (int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class BST
{
    public :
        Node *root ;
        
        Node* insert(Node* , int);
        Node* search(Node* , int);
        Node* deletion(Node* , int);
        Node* deleteNode(Node* , int);
        int MinValue(Node*);
        void display(Node* );
        int height(Node*);
        Node* Mirror(Node*);


};

Node* BST :: insert (Node *root , int val)
{

    if (root == NULL)
    {
        Node *New ;
        New = new Node(val);
        return New;
    }
       
    if( val < root -> data)
    {
            root -> left = insert(root -> left , val) ;
    }
    else if (val >= root -> data)
    {
            root -> right = insert(root -> right , val);
    } 

    return root;
}

Node* BST :: search (Node* root , int key)
{
    if(root == NULL || root -> data == key)
    {
        return root ;
    }

    if(key < root -> data)
    {
        root -> left = search(root -> left , key);
    }
    else if(key > root -> data)
    {
        root -> right = search(root -> right , key );
    }
    
    return root;

}

int BST :: MinValue(Node * root)
{
    int MinVal = root -> data;
    while(root -> left != NULL)
    {
        MinVal = root -> left -> data;
        root = root -> left;
    }
    return MinVal;
}

/* Node* BST :: deletion (Node* root , int key)
{
    //searches the element to be deleted.

    if (root == NULL || root -> data == key)
    {
        return root;
    }

    if (key < root -> data)
    {
        root -> left = deletion(root -> left , key);
    }
    else if(key > root-> data)
    {
        root -> right = deletion(root -> right , key);
    }
    else
    {
        if( root -> left == NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //delete node with more child 
        root -> data = MinValue(root -> right);
        root -> right = deletion(root -> right , root -> data);
    }
    return root;
    
}
*/

Node* BST::deletion(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deletion(root->left, key);
    } else if (key > root->data) {
        root->right = deletion(root->right, key);
    } else {
        root = deleteNode(root, key);
    }

    return root;
}

Node* BST::deleteNode(Node* root, int key) {
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    } else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

     
    root->data = MinValue(root->right);
    root->right = deletion(root->right, root -> data);

    return root;
}

void BST :: display(Node * root)
{   
    //Inorder 
    if(root == NULL)
    {
        return ;
    }

    display(root -> left);
    cout << root -> data << " ";
    display (root -> right);
    
}

/*
int BST :: height(Node * root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = height(root -> left);
        int rheight = height(root -> right);

        if(lheight > rheight)
        {
            return (lheight + 1) ;
        }
        else if(rheight < lheight)
        {
            return (rheight + 1) ;
        }
    }
    
}
*/

int BST::height(Node* root) {
    if (root == NULL) 
    {
        return -1; // Return -1 for an empty tree
    } 
    else {
        int lheight = height(root->left);
        int rheight = height(root->right);

        // Return the maximum height of left or right subtree, plus 1 for the current node
        return 1 + max(lheight, rheight);
    }
}

Node* BST :: Mirror(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        Node * temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        Mirror(root -> left);
        Mirror(root -> right);
    }

    return root;

}


int main()
{
    BST bobj;
    int choice, val , key;
    

    while(1)
    {
        cout << "\n1.INSERT \n2.SEARCH \n3.DISPLAY \n4.DELETE \n5.MIRROR \n6.HEIGHT OF TREE \n7.EXIT." << endl;
        cout <<"ENTER CHOICE" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1 :
                cout << "ENTER THE ELEMENT IN TREE : " << endl ;
                cin >> val;
                bobj.root = bobj.insert(bobj.root , val);
                
                break;

            case 2 :
                cout << "ENTER THE ELEMENT TO BE SEARCH : " << endl;
                cin >> key;
                if( bobj.search(bobj.root , key) != NULL)
                {
                    cout << "ELEMENT FOUND.";
                }
                else
                {
                    cout << "ELEMENT NOT FOUND.";
                }
                break;

            case 3 :
                bobj.display(bobj.root);
                break;

            case 4 :
                cout << "ENTER THE ELEMENT TO BE DELETED : " << endl;
                cin >> key;
                bobj.root = bobj.deletion(bobj.root , key);
                bobj.display(bobj.root);
                break;

            case 5 :
                bobj.root = bobj.Mirror(bobj.root);
                bobj.display(bobj.root);
                break;

            case 6 :
                cout << "THE HEIGHT OF TREE IS : " << bobj.height(bobj.root) << endl;
                break;

            case 7 :
                return 0;
                break;

            default :
                cout << "INVALID INPUT";
                break;           


        }
    }

}