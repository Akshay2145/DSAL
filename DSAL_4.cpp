#include <iostream>
#include <string>

using namespace std;

#define MAX 10

class Infonode
{
    int no;
    string name;

    public:
    Infonode(int no, string name)
    {
        this->no = no;
        this->name = name;
    }

    Infonode()
    {
        this->no = -1;
        this->name = "" ;
    }

    friend class Hash;

};

class Hash
{
    Infonode table[MAX];

public:

int hash(int no)
{
    return no % MAX;
}

void insert (int no , string name)
{
    int index = this->hash(no);
    // Infonode *n1 = new Infonode(no, name);
    if(this->table[index].no == -1)
    {
        this->table[index].no = no;
        this->table[index].name = name;
    }
    else{
        int count = 1;
        while(this->table[index].no != -1 and count < MAX)
        {
            index = (index + 1) % MAX;
            count++;
        }
        if(count < MAX)
        {
            this->table[index].no = no;
            this->table[index].name = name;
        } 
        else
        {
            cout << "Table is full" << endl;
            return; 
        }

    }
    cout<<"Inserted sucessfully"<<endl;
}


void  insert_replacement(int no , string name)
{
    int index = this->hash(no);
    if(this->table[index].no == -1)
    {
        this->table[index].no = no;
        this->table[index].name = name;
    }
    else if(this->hash(this->table[index].no) != index)
    {
        string name1 = this->table[index].name;
        int no1 = this->table[index].no;
        this->table[index].no = no;
        this->table[index].name = name;
        this->insert_replacement(no1, name1);   
    }
    else
    {
        int count = 1;
        while(this->table[index].no != -1 and count < MAX)
        {
            index = (index + 1) % MAX;
            count++;
        }
        if(count < MAX)
        {
            this->table[index].no = no;
            this->table[index].name = name;
        } 
        else
        {
            cout << "Table is full" << endl;
            return ; 
        }

    }

        cout<<"Inserted sucessfully"<<endl;

}


void search(int no)
{
    int index = this->hash(no);
    bool flag = false;
    for (int i = 0; i < MAX; i++)
    {
        if (this->table[index].no == no)
        {
            flag = true;
            break;
        }
        else
        {
            index = (index + 1) % MAX;
        }
    }

    if (flag == true)
    {
        cout << "Entry found at index: " << index << endl;
        cout << "Name: " << this->table[index].name << endl;
        cout << "Number: " << this->table[index].no << endl;
    }
    else
    {
        cout << "Entry not found!" << endl;
    }
}


void display()
{
    cout << "Inde             Name             Number" << endl;
    for (int i = 0; i < MAX; i++)
    {
        if (this->table[i].no != -1)
        {
            cout << i << "             " << this->table[i].name << "             " << this->table[i].no << endl;
        }
    }
}

};


int main()
{
    Hash h;
    int ch;
    string name;
    int no;
    cout << "\n<<-----MENU----->>" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Insert with replacemnt " << endl;
    cout << "3. Search" << endl;
    cout << "4. Display " << endl;
    cout << "5. Exit" << endl;
    while (true)
    {
        cout << "\n\nEnter choice : ";
        
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter number : ";
            cin >> no;
            h.insert(no, name);
            break;
        }
        case 2:
        {
            cout << "Enter name : ";
            cin >> name;
            cout << "Enter number : ";
            cin >> no;
            h.insert_replacement(no, name);
            break;
        }
        case 3:
        {
            cout<<"Enter number : ";
            cin>>no;
            h.search(no);
            break;
        }
        case 4:
        {
            h.display();
            break;
        }
        case 5:
        {
            exit(1);
            break;

        }
        default:
            cout << "Please enter valid choice" << endl;
        }
    }
    return 0;
}