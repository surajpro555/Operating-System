/*9. Write a program to implement LRU policy and calculate Hit ratio and Miss ratio.*/
#include<bits/stdc++.h>
using namespace std;
int n,f,r[100],hit=0;
bool present(int num,vector<int>frame)
{
	for(auto it: frame)
		if(it == num)
		  return true;
	return false;
}
int least_used(vector<int>frame,int curr) 
{ 
    vector<bool>visit(f,false);
    int count=0;
    for(int i=curr-1;i>=0;i--)
	{
        for(int j=0;j<f;j++)
        {
            if(r[i]==frame[j])
            {
               count++;
               visit[j]=true;
               break;
            }
        }
        if(count==f-1)
         break;
    }
    for(int k=0;k<f;k++)
    {
       if(visit[k]==false)
         return k;
    }
    return 0;
}
int main() 
{
	vector<int>frame;
	cout<<"Enter frame size:";
	cin>>f;
	cout<<"Enter the length of reference string: ";
	cin>>n;
	cout<<"Enter reference string: ";
	for(int i=0;i<n;i++) {
		cin>>r[i];
	}
	cout<<"LRU Page replacement policy:\n";
	for(int i=0;i<n;i++)
    {
	    if(frame.size()==0) 
        {
	       frame.push_back(r[i]);
	    }
        else{
	        if(present(r[i],frame))
	            hit++;
            else{
	            if((int)frame.size() < f)
	            frame.push_back(r[i]); 
                else
	            frame[least_used(frame,i)]=r[i];
	        }
	    }
		// Printing frame
	    cout<<"\n"<<r[i]<<" ---> ";
        for(auto it:frame)
		{
	        cout<<it<<"  ";
		}
	}
	cout<<"\n\nNumber of Hits:"<<hit<<"\n";
	cout<<"Hit ratio:"<<(float)hit/n<<"\n";	
    cout<<"\nNumber of faults:"<<(n-hit)<<"\n";	
    cout<<"Miss ratio:"<<(float)(n-hit)/n<<"\n";		
}
/*
Enter frame size:4
Enter the length of reference string: 12
Enter reference string: 1 2 3 4 1 2 5 1 2 3 4 5
LRU Page replacement policy:

1 ---> 1
2 ---> 1  2
3 ---> 1  2  3
4 ---> 1  2  3  4
1 ---> 1  2  3  4
2 ---> 1  2  3  4
5 ---> 1  2  5  4
1 ---> 1  2  5  4
2 ---> 1  2  5  4
3 ---> 1  2  5  3
4 ---> 1  2  4  3
5 ---> 5  2  4  3

Number of Hits:4
Hit ratio:0.333333

Number of faults:8
Miss ratio:0.666667
*/