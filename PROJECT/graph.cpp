//graphs
#include "graph.h"
#include<iostream>
#include<iomanip>
#include<stdlib.h>
#define MAX 1000 
#define SIZE 10
using namespace std;
int m=9999;

queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

void queue::dequeue()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	front = (front + 1) % capacity;
	count--;
}

void queue::enqueue(int item)
{
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

int queue::peek()
{
	if (isEmpty())
	{
		cout<<"its empty"<<endl;
	}
	else
	{
	    return arr[front];
	}
}

int queue::size()
{
	return count;
}

bool queue::isEmpty()
{
	return (size() == 0);
}

bool queue::isFull()
{
	return (size() == capacity);
}

bool queue::clear()
{
    while(!isEmpty())
    {
    	dequeue();
    }
}

/**********************************************************************************/
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX-1)) 
    { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else
    { 
        a[++top] = x;
        c++;
        return true;
    }
    
} 
  
int Stack::pop() 
{ 
    if (top < 0) 
    { 
        cout << "Stack Underflow"; 
        return 0; 
    } 
    else
    { 
        int x = a[top--];
        c--;
        return x; 
    } 
    
} 
bool Stack::isEmpty() 
{ 
    return (top < 0); 
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout<<"its empty"<<endl;
    }
    else
    {
        int x = a[top]; 
        return x; 
    }
}

int Stack::size()
{
        return c; 
}

void Stack::print() 
{
	int k;
	cout<<endl<<endl<<"Path: ";
	for(k = 0;k<=top;k++)
	cout<<a[k]<<" ";
	cout<<"\nPath Length: "<<k-1;
	m=quick(k-1,m);
	reachable(true);
}

int Stack::quick(int g,int min)
{
    if(g<min)
        min=g;
    return min;
}
	
bool Stack::reachable(bool t)
{
    return t;
}
/**********************************************************************************/


void PrintMat(int **mat, int n)
{
	int i, j;
 
	cout<<"\n\n"<<setw(6)<<"";
	for(i = 0; i < n; i++)
		cout<<setw(2)<<"("<<i+1<<")";
	cout<<"\n\n";
 

	for(i = 0; i < n; i++)
	{
		cout<<setw(3)<<"("<<i+1<<")";
		for(j = 0; j < n; j++)
		{
			cout<<setw(4)<<mat[i][j];
		}
		cout<<"\n\n";
	}
}


void Pathfinder(int s,int d,int n,int** adj)
{
    int t=0;
    Stack path;
    queue q[n];
    
    bool *visited=new bool[n];
    bool *visitedq=new bool[n];
    for(int i=0;i<n;++i)
    {
        visited[i]=false;
        visitedq[i]=false;
    }
    
    path.push(s);
    visited[s-1]=true;
    visitedq[s-1]=true;
    for(int j=0;j<n;++j)
                {
                    if((adj[s-1][j]==1)&&(!visited[j]))
                    {
                        q[s-1].enqueue(j+1);
                    }
                }
    cout<<endl<<"Finding Possible Routs:";
    cout<<endl<<"_______________________";
    while(!path.isEmpty())
    {
        s=path.peek();
        visited[s-1]=true;
        if(!visitedq[s-1])
        {
            for(int j=0;j<n;++j)
            {
                    if((adj[s-1][j]==1)&&(!visited[j]))
                    {
                            q[s-1].enqueue(j+1);
                    }
            }
            visitedq[s-1]=true;
        }    
            
        if(path.peek()==d)
        {
            path.print();
            t=1;
            q[s-1].clear();
        }

        if(q[s-1].isEmpty())
        {
            path.pop();
            visited[s-1]=false;
            visitedq[s-1]=false;
        }
        
        else
        {
            path.push(q[s-1].peek());
            q[s-1].dequeue();
        }
        
    }
    if(t)
    {
        cout<<endl<<"_______________________";
        cout<<endl<<"Shortest Rout: "<<path.m;
    }
    else
    {
        cout<<endl<<"...They are Unconnected"<<endl<<"Path Length: Infinity";
    }
    
}

void graph()
{
	int w=1;
	while(w)
	{
		string bb,ee;
		int i, v, e, j, v1, v2, beginning, end;
 
	
		cout<<"Enter the number of vertexes of the graph: ";
		cin>>v;
	 
		
		int **graph;
		graph = new int*[v];
	 
		for(i = 0; i < v; i++)
		{
			graph[i] = new int[v];
			for(j = 0; j < v; j++)graph[i][j] = 0;
		}
	 
		cout<<"\nEnter the number of edges of the graph: ";
		cin>>e;
	 
		
		for(i = 0; i < e; i++)
		{
			cout<<"\nEnter the vertex pair for edge "<<i+1;
			cout<<"\nV(1): ";
			cin>>v1;
			cout<<"V(2): ";
			cin>>v2;
			cin.ignore();
			graph[v1-1][v2-1] = 1;
			graph[v2-1][v1-1] = 1;
		}
	 
	
		PrintMat(graph, v);
		
		int tr=1;
		while(tr)
		{
			int y=1;
			while(y)
			{
				cout<<endl<<endl<<"Calculating Path Length";
	        cout<<endl<<"Source Vertex: ";
	        getline (cin, bb);
	        
	        cout<<"Destination Vertex: ";
	        getline (cin, ee);
	        if ((!bb.length () == 1)||(!ee.length () == 1))
	    	    {
	    	        cout << "Invalid Input\n";
	    	    }
	    	    else
	    	    {
	    	    	beginning=atoi(bb.c_str());
	    	    	end=atoi(ee.c_str());
	    	    	y=0;
				}
			}
	    	
	        
	        
	        if((beginning<=v)&&(beginning>0)&&(end>0)&&(end<=v))
	        {
	            Pathfinder(beginning,end,v,graph);
	        }
	        else
	        {
	            cout<<"Invalid entry please try again";
	        }
	        int l = 1;
	        while (l)
	    	{
	    	    string in;
	    	    char c;
	    	    cout << "\nFind another path between points? [y/n]: ";
	    	    getline (cin, in);
	    	    if (!in.length () == 1)
	    	    {
	    	        cout << "Invalid Input\n";
	    	    }
	    	    else
	    	    {
	    	        c = in[0];
	    	        switch (c)
	    	        {
	    	            case 'y':
	        		    {
	        		        l = 0;
	        		        break;
	        		    }
	        		    case 'Y':
	        		    {
	        		        l = 0;
	        		        break;
	        		    }
	        		    case 'n':
	        		    {
	        		        l = 0;
	        		        tr = 0;
	        	     	    break;
	        		    }
	        		    case 'N':
	        		    {
	        		        l = 0;
	        		        tr = 0;
	        		        break;
	        		    }
	        		    default:
	        		    {
	        		        cout << "Invalid Input\n";
	        		        break;
	        		    }
	    		    }
	    	    }
	    	}
		}
		
		int r = 1;
        while (r)
    	{
    	    string input;
    	    char c;
    	    cout << "\nBack to main menu? [y/n]: ";
    	    getline (cin, input);
    	    if (!input.length () == 1)
    	    {
    	        cout << "Invalid Input\n";
    	    }
    	    else
    	    {
    	        c = input[0];
    	        switch (c)
    	        {
    	            case 'y':
        		    {
        		        r = 0;
        		        w = 0;
        		        break;
        		    }
        		    case 'Y':
        		    {
        		        r = 0;
        		        w = 0;
        		        break;
        		    }
        		    case 'n':
        		    {
        		        r = 0;
        	     	    break;
        		    }
        		    case 'N':
        		    {
        		        r = 0;
        		        break;
        		    }
        		    default:
        		    {
        		        cout << "Invalid Input\n";
        		        break;
        		    }
    		    }
    	    }
    	}
	}
	
    
        
}


