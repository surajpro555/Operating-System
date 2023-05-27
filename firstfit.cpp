/*5. Write a program to simulate the First Fit Memory Allocation Technique.*/
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

void firstfit()
{
    int id,size,i=0;
    cout<<"\nEnter the procces id and it's size:";
    cin>>id>>size;
    for(i=0;i<n;i++)
    {
        if(size<=p[i][1] && p[i][2])
        {
            p[i][2]=0;
            p[i][3]=id;
            break;
        }
    }
    if(i==n)
    {
        cout<<"Proccess must wait......\n";
    }
    else{
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
      firstfit();
   }
}
/*
Enter the no of blocks:8

Enter the size of block1:100
Is free(1)/Not free(0):0
Allocated proccess id:1

Enter the size of block2:300
Is free(1)/Not free(0):1

Enter the size of block3:40
Is free(1)/Not free(0):0
Allocated proccess id:2

Enter the size of block4:50
Is free(1)/Not free(0):1

Enter the size of block5:150
Is free(1)/Not free(0):0
Allocated proccess id:3

Enter the size of block6:240
Is free(1)/Not free(0):1

Enter the size of block7:200
Is free(1)/Not free(0):0
Allocated proccess id:4

Enter the size of block8:400
Is free(1)/Not free(0):1
Sr No.  Memory  Status  Procces
1       100     0       1
2       300     1       -1
3       40      0       2
4       50      1       -1
5       150     0       3
6       240     1       -1
7       200     0       4
8       400     1       -1

Enter the no. of waiting proccess:2

Enter the procces id and it's size:5 200
Sr No.  Memory  Status  Procces
1       100     0       1
2       300     0       5
3       40      0       2
4       50      1       -1
5       150     0       3
6       240     1       -1
7       200     0       4
8       400     1       -1

Enter the procces id and it's size:6
500
Proccess must wait......

*/