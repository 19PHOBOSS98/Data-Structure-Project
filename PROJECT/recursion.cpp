//recursion
#include "recursion.h"

#include<iostream>
using namespace std;
static int i,b,e,v,r;
int power(int x, int n){
	if((n==0)&&(x!=0))
	{
	return 1;
	}
	
	
	else
	{	
    	if(n==1)
    		return x;
  		else {
   	 		return x* power(x,n-1);
		}
	}
}	

int factorial(int m){
	
    	if(m==0)
    		return 1;
  		else {
   	 		return m* factorial(m-1);
		}
}

int summation (int y){
	
    	if(y==0)
    		return 0;
  		else {
   	 		return y+ summation(y-1);
		}
}

void rec()
{
	int w=1;
	while (w)
	{	
		cout<<"\nRECURSION MENU \n[1] power \n[2] factorial \n[3] summation\n[4] EXIT\nOption: ";
		cin>> i;
		cin.ignore();
	  	switch(i)
		{
	  		case 1: 
	  				cout<<"Base: ";
					cin>>b;
					cin.ignore();
	  				cout<<"Exponent: ";
	  				cin>>e;
	  				cin.ignore();
	  				if(b==0&&e==0)
					{
						cout<<"undefined \n";
						break;
					}
					cout<<power(b,e)<<endl;
	  				break;
	  		case 2: cout<<"Value: ";
	  				cin>>v;
	  				cin.ignore();
	  				cout<<factorial(v)<<endl;
	  				break;
	  		case 3: cout<<"Range Value: ";
	  				cin>>r;
	  				cin.ignore();
	  				cout<<summation(r)<<endl;
	  				break;
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
	  		default:cout<<"Invalid Input \n";
					break;
		}
	  		
	}
}


