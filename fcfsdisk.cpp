#include<bits/stdc++.h>
using namespace std;

int main()
{
    int head,n;
    cout<<"Enter the number of request proccess:";
    cin>>n;
    cout<<"Enter head position:";
    cin>>head;
    int req[n];
    cout<<"Enter the track of proccesses:";
    for(int i=0;i<n;i++)
    {
       cin>>req[i];
    }
    int seek=0;
    cout<<"FCFS POLICY:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"STEP"<<i+1<<": "<<req[i]<<"\n";
        seek+=abs(head-req[i]);
        head=req[i];
    }
    cout<<"\nTotal seek time:"<<seek;
}
/*
Enter the number of request proccess:8
Enter head position:53
Enter the track of proccesses:98 183 37 122 14 124 65 67
FCFS POLICY:
STEP1: 98
STEP2: 183
STEP3: 37
STEP4: 122
STEP5: 14
STEP6: 124
STEP7: 65
STEP8: 67

Total seek time:640
*/