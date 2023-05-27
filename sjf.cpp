/*2. Write a program to implement SJF (with arrival time=0 for all) Calculate waiting 
time, turnaround time for each process. Calculate avg. waiting time, avg turnaround 
time*/
#include<bits/stdc++.h>
using namespace std;
int n;
struct process
{
    int id,a,b,c;
}p[100];

void sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].b>p[j].b)
            {
                swap(p[i],p[j]);
            }
        }
    }
}
void sjf()
{
   sort(); 
   int time=0;
   for(int i=0;i<n;i++)
   {
       p[i].c=p[i].b+time;
       time=p[i].c;
   }
   float turn=0,wait=0;
   cout<<"\nProcess\tArrival\tBurst\tComp\tTurn\tWait\n";
   for(int i=0;i<n;i++)
   {
      cout<<p[i].id+1<<"\t"<<p[i].a<<"\t"<<p[i].b<<"\t"<<p[i].c<<"\t"<<p[i].c-p[i].a<<"\t"<<p[i].c-p[i].a-p[i].b<<"\n";
      turn+=p[i].c-p[i].a;
      wait+=p[i].c-p[i].a-p[i].b;
   }
   cout<<"\n"<<"Avg Trunaround time:"<<turn/n<<"\n"<<"Avg Waiting time:"<<wait/n;  
}
int main()
{
   cout<<"Enter the number of process:";
   cin>>n;
   cout<<"Enter the arrival time of all process:";
   for(int i=0;i<n;i++)
   {
      cin>>p[i].a;
      p[i].id=i;
   } 
   cout<<"Enter the burst time of all process:";
   for(int i=0;i<n;i++)
   {
      cin>>p[i].b;
   }   
   sjf(); 
}
/*
Enter the number of process:4
Enter the arrival time of all process:0 0 0 0
Enter the burst time of all process:7 4 1 4

Process Arrival Burst   Comp    Turn    Wait
3       0       1       1       1       0
2       0       4       5       5       1
4       0       4       9       9       5
1       0       7       16      16      9

Avg Trunaround time:7.75
Avg Waiting time:3.75
*/