#include <iostream>
#include<string>
using namespace std;
#define size 10


class Infonode{
	string key;
	string value;
	Infonode *next;
public:
	Infonode(){
		key="";
		value="";
		next=NULL;
	}
	Infonode(string key,string value){
		this->key=key;
		this->value=value;
		next=NULL;
	}
	friend class Dictionary;
};

class Dictionary{
	Infonode *table[size];
public:
	Dictionary(){
		for(int i=0;i<size;i++){
			table[i]=NULL;
		}
	}
	int hash(string key){
		int result=0;
		int i=0;
		while(key[i]){
			result=result+int(key[i]);
			i++;
		}
		return (result%size);
	}

	void insert(string key,string value){
		int index=hash(key);
		if(table[index]==NULL){
			Infonode *temp=new Infonode(key,value);
			table[index]=temp;
		}
		else{
			Infonode *t=table[index];
			while(t->next){
				if(t->key==key){
					cout<<"\nDuplicate Entry"<<endl;
					return;
				}
				t=t->next;
			}
			t->next=new Infonode(key,value);
		}

	}

    int search(string key){
        int index=hash(key);
        int n = 0;
        if(table[index]==NULL){
            // cout<<"\nKey not found"<<endl;
            return -1;
        }
        else{
            Infonode *t=table[index];
            while(t){
                if(t->key==key){
                    // cout<<"\nKey found"<<endl;
                    return n;
                }
                t=t->next;
                n++;
            }
            // cout<<"\nKey not found"<<endl;
            return -1;
        }
    }

	void modify(string key,string m){
		int k=hash(key);
		int n=search(key);
		Infonode *t=table[k];
		for(int i=0;i<n;i++){
			t=t->next;
		}
		t->value=m;
	}

	void display(){
		for(int i=0;i<size;i++){
			Infonode* t = table[i];
			if(t!=NULL){
				cout<<"\nIndex: "<<i<<" ----> ";
				while(t->next!=NULL){
					cout<<t->key<<","<<t->value<<" ] ----> ";
					t = t->next;
				}
				cout<<t->key<<","<<t->value<<endl;
			}
		}
	}

	void Delete(string key){
		int k=hash(key);
		int n=search(key);
        if (n == -1)
        {
            cout << "Key not found" << endl;
            return;
        }
		Infonode *t=table[k];
		for(int i=0;i<n-1;i++){
			t=t->next;
		}
		Infonode *p=t->next;
		if(table[k]->key==key){
			t->key=p->key;
			t->value=p->value;
			t->next=p->next;
		}
		else if(p->next){
			t->next=p->next;
		}
		else{
			t->next=NULL;
		}

	}

};
int main() {
	Dictionary d;
	d.insert("zim", "goal");
	d.insert("bsk", "per");
	d.insert("bdf", "m1");
	d.insert("cde", "m2");
	d.insert("adg", "m3");
	d.insert("captain", "cap");
	d.insert("captain1", "vk");
	d.display();
	int ch;
	string a,b;
    int k ;
	while(ch!=6){
		cout<<"\n\nMAIN MENU\n\n";
		cout<<"1) Insert"<<endl;
		cout<<"2) Search"<<endl;
		cout<<"3) Update"<<endl;
		// cout<<"4) Delete"<<endl;
		cout<<"4) Display"<<endl;
		cout<<"5) Exit"<<endl;
		cout<<"\n";

		cout<<"\nEnter your choice   ";
		cin>>ch;

		switch(ch){
		case 1:
			//string a,b;
			cout<<"\nEnter word    ";
			cin>>a;
			cout<<"Enter value   ";
			cin>>b;
			d.insert(a,b);
			break;
		case 2:
			//string a;
			cout<<"\nEnter word for searching   ";
			cin>>a;
            k = d.search(a);
            if(k != -1)
                cout<<"\nKey found"<<endl;
            else
                cout<<"\nKey not found"<<endl;
			break;
		case 3:
			cout<<"\nEnter word   ";
			cin>>a;
			cout<<"Enter updated value   ";
			cin>>b;
			d.modify(a,b);
			break;
		// case 4:
		// 	cout<<"\nEnter word for deletion   ";
		// 	cin>>a;
		// 	d.Delete(a);
		// 	break;
		case 4:
			d.display();
			break;
		case 5:
			cout<<"\nExit!!!!!";
			break;
		}
	}


	return 0;
}