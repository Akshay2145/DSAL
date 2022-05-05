#include <iostream>
#include <queue>

using namespace std;

class Node
{
    private: 
        int nodenumber;
        Node *next;
    public:
        Node (int n )
        {
            nodenumber=n;
            next=NULL;
        }
        friend class Graph;

};


class Graph
{
    private:
        Node **adjlist;
        bool *visited;
        int totalV;
        int totalE;

        void addEdge(int source,int destination)
        {
            //Node* newnode = new Node(source);
            Node* newnode = new Node(destination);
            newnode->next = adjlist[source];
            adjlist[source]=newnode;


        }

        void clear()
        {
            for (int i=0 ; i<totalV ; i++)
            {
                visited[i]=false;
            }
        }
    public:
        Graph(int vertices , int edges)
        {
            totalE=edges;
            totalV=vertices;
            adjlist = new Node* [vertices]; //creating new array of size vertices of node pointers
            visited = new bool[vertices];
            for (int i=0 ; i<vertices ; i++)
            {
                adjlist[i]=NULL;
                visited[i]=false;
            }
            
        }

        void createGraph()
        {
            int source,destination;
            for (int i=0;i<totalE;i++)
            {
                cout<<"Enter Source and Destination \n";
                cout<<"Source: ";
                cin>>source;
                cout<<"Destination: ";                
                cin>>destination;
                addEdge(source,destination);
            }
        }

        void display()
        {
            cout<<"Graph is --> \n";
            for (int i=0 ; i<totalV ; i++)
            {
                if (adjlist[i]==NULL)
                {
                    cout<<"No connections for node " << i <<" \n";
                }
                else{
                    cout<<"Node connected to "<<i <<" --> ";
                    Node *temp=adjlist[i];
                    while (temp != NULL)
                    {
                        cout << temp->nodenumber << "  ";
                        temp=temp->next;
                    }
                    cout<<"\n";
                }
            }
        }

        void dfs(int cnode)
        {
            cout<<"At node "<<cnode<<"\n";
            visited[cnode]=true;
            Node *temp = adjlist[cnode];
            while (temp)
            {
                if (! visited[temp->nodenumber])
                {
                    dfs(temp->nodenumber);
                }
                temp=temp->next;
            }
            return ;
            
        }

        void bfs(int startnode)
        {
            clear();
            queue<int>que;
            cout<<"Bfs --> ";
            que.push(startnode);
            visited[startnode]=true;
            while (! que.empty())
            {
                int temp=que.front();
                cout<<temp<<" ";
                que.pop();
                Node *current = adjlist[temp]; 
                while (current!= NULL) //checking for nodes connected to current node
                {
                    if ( ! visited[current->nodenumber])
                    {
                        visited[current->nodenumber]=true;
                        que.push(current->nodenumber);
                    }
                    current=current->next;
                }
            }
            cout<<"\n";
            clear();
            return ;
        }
};

int main()
{   
    cout<<"Enter number of nodes: ";
    int node=0,edges=0;
    cin>>node;
    cout<<"Enter number of edges: ";
    cin>>edges;
    Graph G(node,edges);
    G.createGraph();
    
    int choice=0 , choice2=0;
    while (choice!=3)
    {
        cout<<"1.Display graph\n";
        cout<<"2.Traverse the graph\n";
        cout<<"3.Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            G.display();
            break;
        case 2:
            cout<<"1.DFS\n";
            cout<<"2.BFS\n";
            cin>>choice2;
            if (choice2==1)
            {
                cout<<"Dfs on graph \n";
                G.dfs(1);
                cout<<"\n";
            }
            else{
                cout<<"Bfs on graph \n";
                G.bfs(1);       
            }
            break;
        default:
            break;
        }
    }
    
    return 0;
}