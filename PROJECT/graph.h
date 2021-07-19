//stack rray header
#ifndef GRAPH_H
#define GRAPH_H

class queue
{
	int *arr;		
	int capacity;
	int front;		
	int rear;
	int count;

public: 
	
	queue(int size = 10);

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
	bool clear();
};

class Stack 
{
    int top;
    int c;	
public: 
    int a[1000];
    int m;
  
    Stack()  { top = -1;int c=0;int m=9999; } 
    bool push(int x); 
    int pop(); 
    bool isEmpty();
    int peek();
    int size();
    void print();
    int quick(int g,int min);
    bool reachable(bool t);
};

void Pathfinder(int,int,int,int**);
void PrintMat(int **, int);
void graph();

#endif

