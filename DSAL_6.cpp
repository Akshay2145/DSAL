// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// #define MAX 20
// class Queue
// {
//     int *arr;
//     int front;
//     int rear;

// public:
//     Queue()
//     {
//         arr = new int[MAX];
//         front = -1;
//         rear = -1;
//     }
//     void push(int x)
//     {
//         if (rear == MAX - 1)
//         {
//             cout << "Queue overflow" << endl;
//         }
//         rear++;
//         arr[rear] = x;
//         if (front == -1)
//         {
//             front++;
//         }
//     }
//     int topp()
//     {
//         return arr[front];
//     }
//     void pop()
//     {
//         if (front == -1 || front > rear)
//         {
//             cout << "NO element in the queue" << endl;
//             return;
//         }
//         front++;
//     }
//     bool empty()
//     {
//         if (front == -1 || front > rear)
//         {
//             return true;
//         }
//         return false;
//     }
//     bool isfull()
//     {
//         if (rear == MAX - 1)
//         {
//             return true;
//         }
//         return false;
//     }
//     void queueDisplay()

//     {
//         if (empty())
//         {
//             cout << ("\nQueue is Empty\n") << endl;
//             return;
//         }

//         for (int i = front; i <= rear; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//         return;
//     }
// };

// class Node
// {
// public:
//     int val;
//     string name;
//     Node *next;
//     Node()
//     {
//         next = NULL;
//     }
//     Node(int v, string s)
//     {
//         val = v;
//         name = s;
//         next = NULL;
//     }
// };
// class New_Graph
// {
// public:
//     int vertices, edges;
//     string name_arr[20];
//     bool visited[20];
//     New_Graph()
//     {
//         vertices = 0;
//         edges = 0;
//     }
//     New_Graph(int ver, int edg)
//     {
//         vertices = ver;
//         edges = edg;
        
//     }
//     void clearVisited()
//     {
//     	for(int i=0;i<vertices;i++)
//     	{
//     		visited[i] = false;
//     	}
//     }
//     void initialize()
//     {

//         for (int i = 0; i < vertices; i++)
//         {
//             string s;
//             cout << "\nEnter " << i << "th place name ::";
//             cin >> s;
//             name_arr[i] = s;
//             visited[i] = false;
//             Node *ptr = new Node(i, s);
//             arr[i] = ptr;
//         }
//     }
//     // Node *arr[vertices];

//     Node *arr[20];

//     void addEdge(Node *src, Node *dst)
//     {
//         // cout << "in add edge";
//         if (arr[src->val] == NULL)
//         {
//             arr[src->val] = dst;
//         }
//         else
//         {
//             Node *temp = arr[src->val];
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = dst;
//         }

//         if (arr[dst->val] == NULL)
//         {
//             arr[dst->val] = src;
//         }
//         else
//         {
//             Node *temp = arr[dst->val];
//             while (temp->next != NULL)
//             {
//                 temp = temp->next;
//             }
//             temp->next = src;
//         }
//     }
//     void create()
//     {
//         this->initialize();

//         for (int i = 0; i < edges; i++)
//         {
//             string n, s;
//             int x;
//             cout << "\nEnter SRC VAL ::";
//             cin >> x;
//             // cout << "\nEnter src name:: ";
//             // cin >> n;
//             Node *src = new Node(x, name_arr[x]);
//             cout << "\nEnter DST VAL ::";
//             cin >> x;
//             // cout << "\nEnter DST name:: ";
//             // cin >> s;
//             Node *dst = new Node(x, name_arr[x]);
//             // cout << "\n to add edge";
//             this->addEdge(src, dst);
//         }
//     }
//     void Display()
//     {
//         for (int v = 0; v < vertices; ++v)
//         {
//             cout << "\n Adjacency list of vertex " << v
//                  << "\n ::";

//             Node *temp = arr[v]->next;
//             while (temp->next != NULL)
//             {
//                 cout << temp->val << " " << temp->name << " -> ";
//                 temp = temp->next;
//             }
//             cout << temp->val << " " << temp->name;

//             printf("\n");
//         }
//     }
//     void DFS(int src_vertex)
//     {
//         visited[src_vertex] = true;
//         cout << src_vertex << ":" << name_arr[src_vertex]<<"\t->";
//         Node *temp= arr[src_vertex]->next;
//         while(temp!=NULL)
//         {
//             if (!visited[temp->val])
//             {
//                 DFS(temp->val);
//             }
//             temp = temp->next;
//         }
//     }
//     void BFS(int src_vertex)
//     {
//         Queue q;
//         q.push(src_vertex);
//         visited[src_vertex]= true;
//         while(!q.empty())
//         {
//             src_vertex = q.topp();
//             q.pop();
//             cout << src_vertex << ":" << name_arr[src_vertex]<<"\t->";
//             Node *temp = arr[src_vertex];
//             while (temp!=NULL)
//             {
//                 if(visited[temp->val]==0)
//                 {
//                     visited[temp->val] = true;
//                     q.push(temp->val);

//                 }
//                 temp = temp->next;
//             }

//         }
//     }
// };

// int main()
// {
//     cout << "Hello" << endl;
//     int ch, vertices, edges, sv;
//     cout << "\nEnter Number of Vertices of Graph ::";
//     cin >> vertices;
//     cout << "\nEnter Number of Edges of Graph ::";
//     cin >> edges;

//         New_Graph g(vertices,edges);
//         do
//         {
//          cout<<"\n\n---------Main-Menu---------"
//          "\n1)Create Graph"
//          "\n2)Display Graph"
//          "\n3)DFS Traversal"
//          "\n4)BFS Traversal"
//          "\n5)Exit"
//          "\n\n\tEnter Your Choice ::";
//          cin>>ch;
//          switch(ch)
//          {
//          case 1:
//         	 g.create();
//         	 cout<<"\nGraph Created";
//         	 break;
//          case 2:
//         	 g.Display();
//         	 break;
//          case 3:
//         	 cout<<"\nEnter Starting Edge ::";
//         	 cin>>sv;
//         	 cout<<"\nDFS ::";
//         	 g.DFS(sv);
//         	 g.clearVisited();
//         	 cout<<endl;
//         	 break;
//          case 4:
//         	 cout<<"\nEnter Starting Edge ::";
//         	 cin>>sv;
//          	 cout<<"\nBFS ::";
//          	 g.BFS(sv);
//          	 g.clearVisited();
//          	 cout<<endl;
//          	 break;

//          case 5:
//         	 cout<<"\nProgram Finished";
//         	 break;

//          default:
//         	 cout<<"Enter Correct Choice ";
//         	 break;


//          }
//         }while(ch!=5);



//     return 0;
// }







#include<iostream>
#include<string>
using namespace std;
#define MAX 20
class Queue
{
    int *arr;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[MAX];
        front = -1;
        rear = -1;
    }
    void push(int x)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue overflow" << endl;
        }
        rear++;
        arr[rear] = x;
        if (front == -1)
        {
            front++;
        }
    }
    int topp()
    {
        return arr[front];
    }
    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "NO element in the queue" << endl;
            return;
        }
        front++;
    }
    bool empty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if (rear == MAX - 1)
        {
            return true;
        }
        return false;
    }
    void queueDisplay()

    {
        if (empty())
        {
            cout << ("\nQueue is Empty\n") << endl;
            return;
        }

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
};

class Node
{
public:
	int val;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int val)
	{
		this->val = val;
		next = NULL;
	}

	friend class graph;
};

class graph
{
	int vertices;
	Node *arr[20];
	bool visited[20];
	string Name[20];

	public:

	graph(int v)
	{
		vertices = v;
		for (int i = 0; i < vertices; i++)
		{
			arr[i] = NULL;
			Name[i]="";
		}
	}

	graph()
	{
		vertices = 0;
	}

	void clearVisited()
    {
    	for(int i=0;i<vertices;i++)
    	{
    		visited[i] = false;

    	}
    }

	void addEdge(int src_vertex, int dest_vertex)
    {
        Node *newn1 = new Node;
        newn1->val = dest_vertex;
        Node *temp;
		if(Name[src_vertex] == "")
		{
			cout<<"enter place for "<<src_vertex<<endl;
			cin>>Name[src_vertex];
		}
		if(Name[dest_vertex] == "")
		{
			cout<<"enter place for "<<dest_vertex<<endl;
			cin>>Name[dest_vertex];
		}

        if (arr[src_vertex] == NULL)
        {
            arr[src_vertex] = newn1;
        }
        else
        {
            temp = arr[src_vertex];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn1;
        }
    }

	void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << "Vertex " << i << " -> ";
            Node *temp = arr[i];
            while (temp != NULL)
            {
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

	int indexer(string s)
	{
		for (int i = 0; i < vertices; i++)
		{
			if (Name[i] == s)
			{
				return i;
			}
		}
	}

	void DFS(int src_vertex)
    {
        visited[src_vertex] = true;
        cout << src_vertex << ":" << Name[src_vertex]<<"\t->";
        Node *temp= arr[src_vertex]->next;
        while(temp!=NULL)
        {
            if (!visited[temp->val])
            {
                DFS(temp->val);
            }
            temp = temp->next;
        }
    }

	void BFS(int src_vertex)
    {
        Queue q;
        q.push(src_vertex);
        visited[src_vertex]= true;
        while(!q.empty())
        {
            src_vertex = q.topp();
            q.pop();
            cout << src_vertex << ":" << Name[src_vertex]<<"\t->";
            Node *temp = arr[src_vertex];
            while (temp!=NULL)
            {
                if(visited[temp->val]==0)
                {
                    visited[temp->val] = true;
                    q.push(temp->val);

                }
                temp = temp->next;
            }

        }
	}
};

int main()
{
    // cout << "Hello" << endl;
    int ch, vertices,edges, v, d;
	string s;
    cout << "\nEnter Number of Vertices of Graph ::";
    cin >> vertices;
	
        graph g(vertices);
        do
        {
         cout<<"\n\n---------Main-Menu---------"
         "\n1)Create Graph"
         "\n2)Display Graph"
         "\n3)DFS Traversal"
         "\n4)BFS Traversal"
         "\n5)Exit"
         "\n\n\tEnter Your Choice ::";
         cin>>ch;
         switch(ch)
         {
         case 1:
        	cout << "\nEnter Total Number of Edges ::";
            cin >> edges;
            for (int i = 0; i < edges; i++)
            {
                cout << "\nEnter Source Vertex ::";
                cin >> v;
                cout << "\nEnter Destination Vertex ::";
                cin >> d;
                g.addEdge(v, d);
                cout << "\nEdge Added";
            }
        	 break;
         case 2:
        	 g.display();
        	 break;
         case 3:
        	 cout<<"\nEnter Starting Edge ::";
        	 cin>>s;
        	 cout<<"\nDFS ::";
        	 g.DFS(g.indexer(s));
        	 g.clearVisited();
        	 cout<<endl;
        	 break;
         case 4:
        	 cout<<"\nEnter Starting Edge ::";
        	 cin>>s;
         	 cout<<"\nBFS ::";
         	 g.BFS(g.indexer(s));
         	 g.clearVisited();
         	 cout<<endl;
         	 break;

         case 5:
        	 cout<<"\nProgram Finished";
        	 break;

         default:
        	 cout<<"Enter Correct Choice ";
        	 break;


         }
        }while(ch!=5);



    return 0;
}