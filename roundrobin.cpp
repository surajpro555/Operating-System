/*4. Write a program to implement Round Robin. Calculate waiting time, turnaround time 
for each process. Calculate avg. waiting time, avg turnaround time*/
#include<bits/stdc++.h>
using namespace std;
int n,quantum_time=INT_MAX;
struct process
{
    int id,a,b,c,rem;
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
void roundrobin()
{
   sort();
   queue<int>q;
   q.push(0);
   int time=p[0].a,i,pointer=1,flag=0;
   while(!q.empty())
   {
      i=q.front();
      q.pop();
      if(p[i].rem==quantum_time)
      {
         time+=quantum_time;
         p[i].rem=0;
         p[i].c=time;
      }
      else if(p[i].rem<quantum_time)
      {
          time+=p[i].rem;
          p[i].rem=0;
          p[i].c=time;
      }else
      {
         time+=quantum_time;
         p[i].rem-=quantum_time;
         flag=1;
      }
        while(pointer<n and p[pointer].a<=time)
         {
             q.push(pointer++);
         }
         if(flag)
         q.push(i);
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
      p[i].rem=p[i].b;
   }   
   cout<<"Enter time slice of process:";
   cin>>quantum_time;
   roundrobin(); 
}
/*
Enter the number of process:5
Enter the arrival time of all process:0 1 2 3 4
Enter the burst time of all process:5 3 1 2 3
Enter time slice of process:2

Process Arrival Burst   Comp    Turn    Wait
1       0       5       13      13      8
2       1       3       12      11      8
3       2       1       5       3       2
4       3       2       9       6       4
5       4       3       14      10      7

Avg Trunaround time:8.6
Avg Waiting time:5.8

############################################

Enter the number of process:4
Enter the arrival time of all process:0 0 0 0
Enter the burst time of all process:53 17 68 24
Enter time slice of process:20

Process Arrival Burst   Comp    Turn    Wait
1       0       53      134     134     81
2       0       17      37      37      20
3       0       68      162     162     94
4       0       24      121     121     97

Avg Trunaround time:113.5
Avg Waiting time:73

#############################################

Enter the number of process:4
Enter the arrival time of all process:0 1 2 3
Enter the burst time of all process:8 4 9 5
Enter time slice of process:4

Process Arrival Burst   Comp    Turn    Wait
1       0       8       20      20      12
2       1       4       8       7       3
3       2       9       26      24      15
4       3       5       25      22      17

Avg Trunaround time:18.25
Avg Waiting time:11.75
*/