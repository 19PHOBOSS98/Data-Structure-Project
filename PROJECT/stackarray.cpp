#include "stackarray.h"

#include <iostream>

#define MAX 10

using namespace std;

	static int a[MAX]={};
    static int b,c=0,top=-1;
    static char g;

void push(int x) 
{ 
    if (top >= (MAX-1)) 
    { 
        cout << "Stack Overflow";
    } 
    else
    { 
        a[++top] = x;
        c++;
        cout<<"Item: "<<a[top]<<" was pushed to stack";
    }
    
} 
  
void pop() 
{ 
    if (top < 0) 
    { 
        cout << "Stack Underflow"; 
    } 
    else
    { 
        int x = a[top--];
        c--;
        cout<<"Item: "<<x<<" was popped from stack";
    } 
    
} 

void search(int x)
{
    if(top < 0)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        int y=0;
        for(int i=0;i<=top;++i)
        {
            if(a[i]==x)
            {
                cout<<"Item: "<<a[i]<<" is found in stack at position: "<<i+1<<endl;
                y=1;
            }
        }
        if(y==0)
        {
            cout<<"Item: "<<x<<" is not found in stack";
        }
    }
}

void count()
{
        cout<<"There are "<<c<<" items in stack"; 
}

void print() 
{
    if(top < 0)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
    	cout<<"Stack Content: ";
    	for(int i = 0;i<=top;i++)
    	cout<<a[i]<<" ";
    }
}

void stackAry()
{
	int w=1;
	 while (w)
    {
        cout<<"\nSTACK ARRAY MENU\n[1] PUSH\n[2] POP\n[3] PRINT\n[4] SEARCH\n[5] COUNT\n[6] EXIT\nOption: ";
        cin>>g;
        cin.ignore();
        switch (g)
        {
            case'1':
            {
                cout<<"\nEnter item: ";
                cin>>b;
                cout<<endl;
                push(b);
                cout<<endl;
                break;
            }        
            case'2':
            {
                cout<<endl;
                pop();
                cout<<endl;
                break;
            }
                        
            case'3': 
            {
                cout<<endl;
                print();
                cout<<endl;
                break;
            }
            case'4': 
            {
                cout<<endl<<"Search for item: ";
                cin>>b;
                search(b);
                cout<<endl;
                break;
            }
                
            case'5':
            {
                cout<<endl;
                count();
                cout<<endl;
                break;
            }
            case'6':
            {
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
		    	break;
            }
            default:
            {
                cout<<"Invalid Entry\n please enter a valid one\n";
                break;
            }
            
        }
    }
}
