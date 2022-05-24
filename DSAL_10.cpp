#include <iostream>
#include <fstream>
using namespace std;

class student
{
public:
    int rollNo;
    string name;

    void getdata()
    {
        cout << "Enter the Roll No : ";
        cin >> rollNo;

        cout << "Enter the name : ";
        cin >> name;
    }

    void display()
    {
        cout << "Roll No : " << rollNo << endl;
        cout << "Name : " << name << endl;
    }
};

class record
{
public:
    student s;
    fstream f;
    void create()
    {
        int n;
        cout << "Enter the number of students : ";
        cin >> n;
        f.open("student.dat", ios::out);
        for (int i = 0; i < n; i++)
        {
            s.getdata();
            f.write((char *)&s, sizeof(student));
        }
        f.close();
    }

    void print()
    {
        f.open("student.dat", ios::in);
        f.seekg(0, ios::beg);
        while (f.read((char *)&s, sizeof(student)))
        {
            if (s.rollNo != -1)
            {
                s.display();
            }
        }
        f.close();
    }

    int search()
    {
        int n;
        cout << "Enter the roll no to be searched/deleted : ";
        cin >> n;
        int i = 0;
        f.open("student.dat", ios::in);
        f.seekg(0, ios::beg);
        while (f.read((char *)&s, sizeof(student)))
        {
            if (s.rollNo == n)
            {
                s.display();
                return n;
            }
            i++;
        }

        f.close();
        return -1;
    }

    void delete_entry()
    {
        int pos = search();

        if (pos == -1)
        {
            cout << "Student details not found!!!";
        }

        f.open("student.dat", ios::in | ios::out);
        f.seekg(0, ios::beg);
        int offset = pos * sizeof(student);
        f.seekp(offset);
                s.name = "";
        f.write((char *)&s, sizeof(student));
        f.seekg(0);
        f.close();
        cout << "Record Deleted" << endl;
    }
};

int main()
{
    record r;
    int choice;
MENU:

    cout << "----------Menu----------" << endl;
    cout << "1.Insert" << endl;
    cout << "2.Display" << endl;
    cout << "3.Search" << endl;
    cout << "4.Delete" << endl;
    cout << "5.Exit" << endl;
    cout << "Enter the choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        r.create();
        break;

    case 2:
        r.print();
        break;

    case 3:
        r.search();
        break;

    case 4:
        r.delete_entry();
        break;

    case 5:
        return 0;
        break;

    default:
        cout << "Enter Correct Choice" << endl;
        break;
    }

    if (choice != 5)
    {
        goto MENU;
    }
}