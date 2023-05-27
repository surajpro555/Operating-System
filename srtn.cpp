#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct process
{
  int b;
  int a;
  int id;
  int complition;
}p[100];

int n;
bool visit[100]={0};
multimap<int,int>m;

void input()
{
  printf("Enter the arrival time:");    
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i].a); 
    visit[p[i].a]=1; 
    p[i].id=i+1;
  }
  printf("Enter the burst time:");   
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i].b);    
  }
}
void sort()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i].a>p[j].a)
            {
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
}
void srtn()
{ 
  int comp=0,i=0;
  m.insert({p[i].b,i});
  i++;
  while(!m.empty())
  {
     comp++;
     auto it=m.begin();
     int min=it->first,index=it->second;
     m.erase(it);
     if(min==1)
        p[index].complition=comp;
     else
        m.insert({min-1,index});
     if(i<n&&visit[comp])
     {
        m.insert({p[i].b,i});
        i++;
     }
  }
}
void gantt()
{
    float turn=0,wait=0;
    printf("\n\n-----------------------------------------------\n");
    printf("Process\tArival\tBurst\tcomp\tWait\tTurn\n");
    printf("--------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].a,p[i].b,p[i].complition,p[i].complition-p[i].a-p[i].b,p[i].complition-p[i].a);
        turn +=p[i].complition-p[i].a;
        wait +=p[i].complition-p[i].a-p[i].b;
    }
    printf("\nAvg Turnaround time:%.3f",turn/n);
    printf("\nAvg Waiting time:%.3f",wait/n);
}
int main()
{
    printf("Enter number of proccess:");
    scanf("%d",&n);
    input();
    sort();
    srtn();
    gantt();
}