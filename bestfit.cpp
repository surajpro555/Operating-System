/*6. Write programs to simulate the Best Fit Memory Allocation Technique*/
#include<iostream>
using namespace std;
int p[100][4],n;

void print()
{
    cout<<"Sr No.\tMemory\tStatus\tProcces\n";
   for(int i=0;i<n;i++)
   {
      cout<<p[i][0]<<"\t"<<p[i][1]<<"\t"<<p[i][2]<<"\t"<<p[i][3]<<"\n";
   }
}

void bestfit()
{
    int id,size,i=0;
    cout<<"\nEnter the procces id and it's size:";
    cin>>id>>size;
    int best=10000,index=-1;
    for(i=0;i<n;i++)
    {
        if(size<=p[i][1] && p[i][2] && best>p[i][1])
        {
            best=p[i][1];
            index=i;
        }
    }
    if(index==-1)
    {
        cout<<"Proccess must wait......\n";
    }
    else{
         p[index][2]=0;
         p[index][3]=id;
         print();
    }
}

int main()
{
    cout<<"Enter the no of blocks:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        p[i][0]=i+1;
        cout<<"\nEnter the size of block"<<i+1<<":";
        cin>>p[i][1];
        cout<<"Is free(1)/Not free(0):";
        cin>>p[i][2];
        if(p[i][2]==0)
        {
        cout<<"Allocated proccess id:";
        cin>>p[i][3];
        }
        else{
            p[i][3]=-1;
        }
    }
   print();
   int t;
   cout<<"\nEnter the no. of waiting proccess:";
   cin>>t;
   while(t--)
   {
      bestfit();
   }
}
/*
Enter the no of blocks:4

Enter the size of block1:100
Is free(1)/Not free(0):1

Enter the size of block2:200
Is free(1)/Not free(0):0
Allocated proccess id:1

Enter the size of block3:300
Is free(1)/Not free(0):1

Enter the size of block4:400
Is free(1)/Not free(0):0
Allocated proccess id:2
Sr No.  Memory  Status  Procces
1       100     1       -1
2       200     0       1
3       300     1       -1
4       400     0       2

Enter the no. of waiting proccess:2

Enter the procces id and it's size:3 305
Proccess must wait......

Enter the procces id and it's size:4 150
Sr No.  Memory  Status  Procces
1       100     1       -1
2       200     0       1
3       300     0       4
4       400     0       2

*/