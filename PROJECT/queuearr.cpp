//queue array
#include "queuearr.h"

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void enqueue(int data);
int denqueue();

	const int size=10;
	int arr[size],cap = size,front = -1,rear = -1;

void enqueue(int data){
	if ((rear+1)%size==front)
	{
		cout << "OverFlow\n";
		return;
	}
	else if((front==-1)&&(rear==-1))
	{
		  front=rear=0;
	}
	else
	{
	rear = (rear + 1) % size;
	}
	arr[rear] = data;
}

int denqueue(){
	
	if ((front==-1)&&(rear==-1))
	{
		cout << "UnderFlow\n";
	}
	else if(front==rear)
	{
		int e=front;
		rear=front=-1;
		return arr[e];
	}
	else
	 {
	 	int e=front;
	 	front = (front + 1) % size;
	 	return arr[e];
	 	
	 }
}



void QA()
{
	
	int option;
	int data;
	int w=1;
	while(w){
	cout<<"\nQUEUE MENU";
	cout<<"\n[1] enqueue";
	cout<<"\n[2] dequeue";
	cout<<"\n[3] print";
	cout<<"\n[4] EXIT";
	cout<<"\nOption:";
	cin>>option;
	cin.ignore();
	switch(option){
		case 1:
			{
					cout<<"\nData:";
			        cin>>data;
			        cin.ignore();
			        enqueue(data);
				
			        cout<<"\nQUEUE: ";
			        for(int i=front; i<=rear; i++)
			        cout<<arr[i]<<"  ";
				break;
			}
				
		        
		case 2:
		{
					cout<<"\n"<<denqueue()<<" is deleted.";
					
					cout<<"\nQUEUE: ";
			        for(int i=front; i<=rear; i++)
			        {	
			        	cout<<arr[i]<<"  ";
					}
	
				break;
		} 
		
		
		        
		case 3:
		{
				
				if ((front == -1) && (rear == -1)) 
				{
      				cout<<"Queue is empty"<<endl;
  				}
  				 else
  				 {
  				 	cout<<"\nList of nodes: \n";
   					for(int i=front; i<=rear; i++)
			        cout<<arr[i]<<"  ";
				 }
   				
      			break;
		}
		
		case 4:
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
	 
      	default: cout<<"\nInvalid choice"<<endl;
	}
	}
}


