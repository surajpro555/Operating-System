/*1. Write a program to implement FCFS (with arrival time=0 for all) Calculate waiting 
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
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].a>p[j].a)
            {
                swap(p[i],p[j]);
            }
        }
    }
}
void fcfs()
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
      cout<<p[i].id<<"\t"<<p[i].a<<"\t"<<p[i].b<<"\t"<<p[i].c<<"\t"<<p[i].c-p[i].a<<"\t"<<p[i].c-p[i].a-p[i].b<<"\n";
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
   fcfs(); 
}
/*
Enter the number of process:3
Enter the arrival time of all process:0 0 0
Enter the burst time of all process:24 3 3

Process Arrival Burst   Comp    Turn    Wait
0       0       24      24      24      0
1       0       3       27      27      24
2       0       3       30      30      27

Avg Trunaround time:27
Avg Waiting time:17

##########################################

Enter the number of process:4
Enter the arrival time of all process:2 3 0 5
Enter the burst time of all process:4 7 5 6

Process Arrival Burst   Comp    Turn    Wait
2       0       5       5       5       0
0       2       4       9       7       3
1       3       7       16      13      6
3       5       6       22      17      11

Avg Trunaround time:10.5
Avg Waiting time:5
*/