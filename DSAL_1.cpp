#include<iostream>
using namespace std;
class Node;
class Stack
{
    public:
    int top;
    Node *data[30];
    Stack()
    {
        top = -1;
    }
    void push(Node *);
    Node *pop();
    int empty();
    int full();
};
int Stack::empty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}
int Stack::full()
{
    if(top == 29)
    {
        return 1;
    }
    return 0;
}
void Stack::push(Node *p)
{
    if(!full())
    {
        top++;
        data[top] = p;
    }
    else
    {
        cout<<"\nStack is full\n";
    }
}
Node *Stack::pop()
{
    Node *x;
    if(!empty())
    {
        x = data[top];
        top--;
        return x;
    }
    else
    {
        cout<<"\nStack is empty\n";
        return NULL;
    }
}
 

 
class Node
{
    int data;
    Node *left,*right;
    public:
        Node()
        {
            data = 0;
            left = right = NULL;
        }
        Node(int x)
        {
            data = x;
            left = right = NULL;
        }
        friend class Tree;
};
class Tree
{
    Node *root;
    public:
    Tree()
    {
        root = NULL;
    }
    void Create()
    {
        cout<<"enter value or -1 to stop\n";
        root = create();
    }
    Node *create()
    {
        int x;
        cin>>x;
        Node *p;
        if(x == -1) 
        {
            return NULL;
        }
        p = new Node(x);
    
        cout<<"Enter left of "<<x<<endl;
        p->left = create();
    
        cout<<"Enter right of "<<x<<endl;
        p->right = create();
    
        return p;
    }
    void preorder()
    {
        if(root == NULL)
        {
            cout<<"Tree is empty\n";
            return ;
        }
        preorder(root);
    }

    void preorder(Node *T)
    {
        if(T != NULL)
        {
            cout<<T->data<<"  ";
            preorder(T->left);
            preorder(T->right);
        }
        
    }


    void inorder()
    {
        if(root == NULL || !root)
        {
            cout<<"Tree is empty\n";
            return ;
        }
        inorder(root);
    }


    void inorder(Node *T)
    {
        if(T != NULL)
        {
            inorder(T->left);
            cout<<T->data<<"  ";
            inorder(T->right);
        }
    }


    void postorder()
    {
        if(root == NULL)
        {
            cout<<"Tree is empty\n";
            return ;
        }
        postorder(root);
    }


    void postorder(Node *T)
    {
        if(T != NULL)
        {
            postorder(T->left);
            postorder(T->right);
            cout<<T->data<<"  ";
        }
    }

    
    int height(Node *T)
    {
        if(T == NULL)
        {
            return 0;
        }
        if(T->left == NULL && T->right == NULL)
        {
            return 0;
        }
        int hl = 0,hr = 0;
        if(T->left != NULL)
        {
            hl = 1 + height(T->left);
        }
        if(T->right != NULL)
        {
            hr = 1 + height(T->right);
        }
        if(hl > hr)
        {
            return hl;
        }
        else
        {
            return hr;
        }
    }
    

    void Height()
    {
        cout<<"Height of tree = "<<height(root)<<endl;
    }
    
    // Node* operator = (Node *S)
    // {
    //     if(this->root == NULL)
    //     {
    //         this->root = new Node(S->data);
    //     }
    //     if(S->right != NULL)
    //     {
    //         root->right = new Node(S->right->data);
    //         root->right = S->right;
    //     }
    //     if(S->left != NULL)
    //     {
    //         root->left = new Node(S->left->data);
    //         root->left = S->left;
    //     }
    //     return root;
    // }


    // Tree operator = (Tree T)
    // {
    //     this->root = T.root;
    // }

    // void operator =(Tree T)
    // {
    //     this->root = T.root;
    // }
    
    Node*mirror(Node *T,Node *S)
    {
        if(T == NULL)
        {
            T = new Node(S->data);
        }
        if(S->right != NULL)
        {
            // T->left = new Node(S->right->data);
            T->left = mirror(T->left,S->right);
        }
        if(S->left != NULL)
        {
            // T->right = new Node(S->left->data);
            T->right = mirror(T->right,S->left);
        }
        return T;
    }


    

    void Mirror(Tree T)
    {
        this->root = mirror(this->root,T.root);
    }


    void Delete()
    {
        remove(root);
        this->root = NULL;
    }


    void remove(Node * T)
    {
        if(T != NULL)
        {
            remove(T->left);
            remove(T->right);
            delete T;
        }
    }
    
    int internal(Node *T)
    {
        if(T == NULL)
        {
            return 0;
        }
        if(T->left == NULL && T->right == NULL)
        {
            return 0;
        }
        return 1+internal(T->left) + internal(T->right);
    }
    int leaf(Node *T)
    {
        if(T == NULL)
        {
            return 0;
        }
        if(T->left == NULL && T->right == NULL)
        {
            return 1;
        }
        return leaf(T->left) + leaf(T->right);
    }

    void Count()
    {
        cout<<"Internal nodes are = "<<internal(root)<<endl;
        cout<<"Leaf nodes are = "<<leaf(root)<<endl;
    }


    void Ipreorder()
    {
        Stack S;
        Node *T = root;
        
        while(T !=NULL || !S.empty())
        {
            if( T != NULL)
            {
                cout<<T->data<<"  ";
                S.push(T);
                T = T->left;
            }
            else
            {
                T = S.pop();
                T = T->right;
            }
        }
    }

        void Iinorder()
    {
        Stack S;
        Node *T = root;
        
        while(T !=NULL || !S.empty())
        {
            if( T != NULL)
            {
                S.push(T);
                T = T->left;
            }
            else
            {
                T = S.pop();
                cout<<T->data<<"  ";
                T = T->right;
            }
        }
    }

    void Ipostorder()
    {
        Stack S;
        Node *T = root;
        Node *P = NULL;
        while(T != NULL || !S.empty())
        {
            if(T != NULL)
            {
                S.push(T);
                T = T->left;
            }
            else
            {
                T = S.pop();
                if(T->right == NULL || T->right == P)
                {
                    cout<<T->data<<"  ";
                    P = T;
                    T = NULL;
                }
                else
                {
                    S.push(T);
                    T = T->right;
                }
            }
        }
    }



void print(Node* t, int space = 0, int height = 10)
{
    if (t == NULL)
    {
        return;
    }
    space += height;

    print(t->right, space);
    cout << endl;

    for (int i = height; i < space; i++) {
        cout << ' ';
    }
    cout << t->data;

    cout << endl;
    print(t->left, space);
}

void print()
{
    print(this->root);
}

    

};

int main()
{
    Tree T,T1,T2;
    int ch;
    while(1)
    {
        cout<<"1 create\n";
        cout<<"2 preorder\n";
        cout<<"3 inorder \n";
        cout<<"4 postorder\n";
        cout<<"5 Iterative preorder\n";
        cout<<"6 Iterative inorder\n";
        cout<<"7 Iterative postorder\n";
        cout<<"8 Height\n";
        cout<<"9 copy tree \n";
        cout<<"10 Swap nodes\n";
        cout<<"11 node count\n";
        cout<<"12 print\n";
        cout<<"13 delete\n";
        cout<<"0 to exit\n";
        cout<<"\nEnter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                T.Create();
                break;
            case 2: 
                cout<<"\nPreorder = ";
                T.preorder();
                cout<<endl;
                break;
            case 3: 
                cout<<"\nInorder = ";
                T.inorder();
                cout<<endl;
                break;
            case 4: 
                cout<<"\nPostorder = ";
                T.postorder();
                cout<<endl;
                break;
            case 5: 
                cout<<"\nPreorder = ";
                T.Ipreorder();
                cout<<endl;
                break;
            case 6: 
                cout<<"\nInorder = ";
                T.Iinorder();
                cout<<endl;
                break;
            case 7: 
                cout<<"\nPostorder = ";
                T.Ipostorder();
                cout<<endl;
                break;
            case 8: 
                T.Height();
                cout<<endl;
                break;

            case 9: 
                cout<<"Copied tree is\n";
                T1 = T;
                T1.print();
                cout<<endl;
                break;
            case 10: 
                cout<<"Swapped tree is\n";
                T2.Mirror(T);
                T2.print();
                cout<<endl;
                break;
            case 11: 
                T.Count();
                break;
            case 12:
                T.print();
                break;
            case 13: 
                T.Delete();
                cout<<"Tree deleted\n";
                cout<<endl;
                break;
            case 0: exit(0);
            default: cout<<"Enter a valid choice\n\n";
                     break;
        }
    }
    return 0;
}