#include<bits/stdc++.h>
using namespace std;
int n,r,maximum[100][100],need[100][100],allcate[100][100],avail[100];

void bankers_algo()
{
    bool visit[n]={false};
    vector<int>ans;
    for(int k=0;k<n;k++)
    {
        for(int j,i=0;i<n;i++)
        {
            if(visit[i]==false)
            {
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>avail[j])
                        break;
                }
                if(j==r)
                {
                    for(int m=0;m<r;m++)
                        avail[m]+=allcate[i][m];
                    visit[i]=true;
                    ans.push_back(i+1);
                }
            }
        }
    }
    if((int)ans.size()<n)
    {
        cout<<"\nNO SAFE SQUENCE POSSIBLE.....\n DEADLOCK MAY OCCUR\n";
    }
    else
    {
        cout<<"\nPOSSIBLE SAFE SQUENCE: \n";
        for(auto i:ans)
        {
            cout<<"P"<<i<<"   ";
        }
    }
}

int main()
{
    cout<<"Enter the number of proccess:";
    cin>>n;
    cout<<"Enter the number of resource:";
    cin>>r;
    cout<<"Enter the avilable instances resource: ";
    for(int i=0;i<r;i++)
    {
        cin>>avail[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Proccess"<<i+1<<"\n";
        cout<<"Enter maximum requirement of resources: ";
        for(int j=0;j<r;j++)
        {
             cin>>maximum[i][j];
        }
        cout<<"Enter allocated instances of resources: ";
        for(int j=0;j<r;j++)
        {
             cin>>allcate[i][j];
             need[i][j]=maximum[i][j]-allcate[i][j];
        }   
    }
    bankers_algo();
}
/*
Enter the number of proccess:5
Enter the number of resource:3
Enter the avilable instances resource: 3 3 2
Proccess1
Enter maximum requirement of resources: 7 5 3
Enter allocated instances of resources: 0 1 0
Proccess2
Enter maximum requirement of resources: 3 2 2
Enter allocated instances of resources: 2 0 0
Proccess3
Enter maximum requirement of resources: 9 0 2
Enter allocated instances of resources: 3 0 2
Proccess4
Enter maximum requirement of resources: 2 2 2
Enter allocated instances of resources: 2 1 1
Proccess5
Enter maximum requirement of resources: 4 3 3
Enter allocated instances of resources: 0 0 2

POSSIBLE SAFE SQUENCE:
P2   P4   P5   P1   P3
*/