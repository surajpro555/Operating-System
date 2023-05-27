/*8. Write a program to implement FIFO policy and calculate Hit ratio and Miss ratio
*/
#include<bits/stdc++.h>
using namespace std;
int n,f,r[100],miss=0;
bool ishit(vector<int>&frame,int p)
{
    for(auto i:frame)
        if(i==p)
         return true;
    return false;
}       
void fifo()
{
    vector<int>frame(f);
    int k=0;
    cout<<"\n---------------\nPage\tFrame\n---------------";
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<r[i]<<" ---> ";
        if(!ishit(frame,r[i]))
        {   
            miss++;
            frame[k]=r[i];
            k=(k+1)%f; 
            if(i<f){
                 for(int j=0;j<=i;j++)
                    cout<<frame[j]<<"  ";
            }else{
                for(auto it:frame)
                    cout<<it<<"  ";
            }
        }
    }
    cout<<"\n\nHit ratio:"<<setprecision(2)<<(float)(n-miss)/n;
    cout<<"\nMiss ratio:"<<setprecision(2)<<(float)(miss)/n;
}
int main()
{
    cout<<"Enter the length of reference string:";
    cin>>n;
    cout<<"Enter the reference string:";
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    cout<<"Enter the no. of frame:";
    cin>>f;
    fifo();
}
/*
Enter the length of reference string:12
Enter the reference string:1 2 3 4 1 2 5 1 2 3 4 5
Enter the no. of frame:3

---------------
Page    Frame
---------------
1 ---> 1
2 ---> 1  2
3 ---> 1  2  3
4 ---> 4  2  3
1 ---> 4  1  3
2 ---> 4  1  2
5 ---> 5  1  2
1 --->
2 --->
3 ---> 5  3  2
4 ---> 5  3  4
5 --->

Hit ratio:0.25
Miss ratio:0.75
*/