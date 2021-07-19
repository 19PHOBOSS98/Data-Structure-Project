//magic square
#include "magicsqr.h"

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

void magicSqr()
{
    string b;
    int j;
    int w=1;
    while(w)
    {
        int d=0,i=0,a[9]={};
        while(i!=9)
        {
        cout<<"Please Enter Numbers For A Magic Square: ";
        getline (cin, b);
            
            if ((b.length()>1)||(!isdigit(b[0])))
            {
                    cout<<"Invalid Input\n";
            }
            else
            {
                j=atoi(b.c_str());
                
                
                if (j<=0)
                {
                cout<<"Invalid Input\n";
                }
                int h=1;
                for(int k=0;k<=i;++k)
                {
                	if(j==a[k])
	                {
	                    cout<<"You already entered this number\n";
	                    h=0;
	                    break;
	                }
				}
                
                if(h)
                {
                    a[i]=j;
                    i++;
                }
            }
            
        }
        for(int x=0;x<3;x++)
        {
            
            cout<<endl;
            for(int z=0;z<3;z++)
            {
              cout<<a[z+d]<<"   ";
            }
            d=d+3;
        }
        if((a[0]+a[1]+a[2]==15)&&(a[3]+a[4]+a[5]==15)&&(a[6]+a[7]+a[8]==15)&&(a[0]+a[4]+a[8]==15)&&(a[2]+a[4]+a[6]==15)&&(a[0]+a[3]+a[6]==15)&&(a[1]+a[4]+a[7]==15)&&(a[2]+a[5]+a[8]==15))
        {
            cout<<"\n\nThe Entered Values Form A Magic Square";
        }
        else
        {
            cout<<"\n\nThe Entered Values DO NOT Form A Magic Square";
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

