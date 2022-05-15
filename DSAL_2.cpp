#include <iostream>
#include <string>
using namespace std;

class node
{
    string k;
    string m;
    node *left;
    node *right;

public:
    node()
    {
        left = NULL;
        right = NULL;
    }

    node(string k, string m)
    {
        this->k = k;
        this->m = m;
        left = NULL;
        right = NULL;
    }
    friend class dict;
};

class dict
{
public:

    node *root;

    dict()
    {
    root = NULL;
    }

    node* Create_node(string k, string m)
    {
        node *new_node = new node(k,m);
        return new_node;
    }
    void create(node *temp)
    {
        int ch;
        do
        {
            temp = new node();
            cout << "\nEnter Keyword:";
            cin.ignore();
            getline(cin,temp->k);
            cout << "\nEnter Meaning:";
            getline(cin,temp->m);

            if (!root)
            {
                root = temp;
            }
            else
            {
                insert(root, temp);
            }
            cout << "\nDo u want to add more (y=1/n=0):";
            cin >> ch;
        } while (ch == 1);
    }

    void insert(node *root, node *temp)
    {
        if (temp->k < root->k )
        {
            if (root->left == NULL)
                root->left = temp;
            else
                insert(root->left, temp);
        }
        else
        {
            if (root->right == NULL)
                root->right = temp;
            else
                insert(root->right, temp);
        }
    }

    void disp(node *root)
    {
        if (root != NULL)
        {
            disp(root->left);
            cout << root->k<<"-->"<< root->m<<endl;
            disp(root->right);
        }
    }

    void Disp()
    {
        if(this->root == NULL)
        {
            cout<<"Tree is empty\n";
            return ;
        }
        else{
            disp(this->root);
        }
    }

    int search(node *root, string k)
    {
        int c = 0;
        if(root==NULL)
        {
            return -1;
        }
        while (root != NULL)
        {
            c++;
            if (k == root->k)
            {
                cout << "\nNo of Comparisons:" << c;
                return 1;
            }
            if (k < root->k)
                root = root->left;
            if (k > root->k)
                root = root->right;
        }

        return -1;
    }

    node *del(node *root, string k)
    {
        node *temp , *succ;
        if(root==NULL)
        {
            cout<<"Keyword not found"<<endl;
            return root;
        }
        if(k < root->k)
        {
            root->left = del(root->left,k);
        
        }
        else if(root->k < k)
        {
            root->right = del(root->right,k);
        }
        else
        {
            if(root->left != NULL && root->right != NULL) 
            {
                succ = root->right;
                while(succ->left != NULL)
                {
                    succ = succ->left;
                }
                root->k = succ->k;
                root->right = del(root->right,succ->k);
            }  
            else
            {
                temp = root;
                if(root->left == NULL)
                {
                    root = root->right;
                }
                else if(root->right == NULL)
                {
                    root = root->left;
                }
                delete temp;
            }
        }
        return root;
    }

    // node *get_root()
    // {
    //     return root;
    // }
};


int main()
{
    int ch;
    dict d;
    string a, b,c;
    do
    {
        cout << "\nMenu\n1.Create Dictionary\n2.Display the keyword and its meaning\n3.Search the keyword\n4.Delete the keyword\n5.Inert new word\n6.update\nEnter your choice:";
        cin>>ch;

        switch (ch)
        {
        case 1:
            d.create(d.root);
            break;
        case 2:
            d.Disp();
            break;
        case 3:
            cout << "\nEnter Keyword which u want to search: ";
            cin.ignore();
            getline(cin,a);

            if(d.search(d.root, a) != -1)
            {
                cout << "\nKeyword Found";
            }
            else
            {
            cout << "\nKeyword Not Found";
            }
            break;

        case 4:
            cout << "\nEnter Keyword which u want to delete: ";
            cin.ignore();
            getline(cin,a);
            if(d.search(d.root,a)==1)
                d.root = d.del(d.root,a);
            break;

        case 5:
            cout<<"\nEnter keyword: ";
            cin.ignore();
            getline(cin,a);
            cout<<"\nEnter meaning: ";
            getline(cin,b);
            d.insert(d.root,d.Create_node(a,b));

            break;

        case 6:
            cout<<"\nEnter keyword which u want to update: ";
            cin.ignore();
            getline(cin,a);
            if(d.search(d.root,a)==1)
            {
                d.root = 
                d.del(d.root,a);
                cout<<"\nEnter keyword: ";
                getline(cin,b);
                cout<<"\nEnter meaning: ";
                getline(cin,c);
                d.insert(d.root,d.Create_node(b,c));
            }
            else
                cout << "\nKeyword Not Found";


            break;

        default:
            cout<<"\nInvalid choice";

        }
    }while(ch <7);

    return 0;
}

