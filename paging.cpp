/*13. Write a program to simulate Paging technique*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int prosize,pagesize,physize;
    cout<<"Enter the process size(KB):";
    cin>>prosize;
    cout<<"Enter the page size(B):";
    cin>>pagesize;
    cout<<"Enter the physical size(KB):";
    cin>>physize;
    int pageno=(prosize*1024)/pagesize;
    int pageno_bit=floor(log2(pageno))+1;
    int pagesize_bit=floor(log2(pagesize))+1;
    int physize_bit=floor(log2(physize*1024))+1;
    int logic_bit=pageno_bit+pagesize_bit;
    int frameno_bit=physize_bit-pagesize_bit;
    cout<<"\nTotal no of frames:"<<pow(2,frameno_bit)<<endl;
    cout<<"Total no of enteries:"<<pageno<<endl;
    cout<<"Number of bits physical address:"<<physize_bit<<endl;
    cout<<"Number of bits in logical address:"<<logic_bit<<endl;
    
    int filled;
    cout<<"Enter the no. of enteries:";
    cin>>filled;
    int page_table[pageno][2];
    for(int i=0;i<(int)pageno;i++)
    {
        page_table[i][0]=-1;
        page_table[i][1]=0;
    }
    for(int i=0;i<filled;i++)
    {
       int pno;
       cout<<"Enter the page no.:";
       cin>>pno;
       cout<<"Enter the frame on:";
       cin>>page_table[pno][0];
       cout<<"page is avilable or not in MM:";
       cin>>page_table[pno][1];
    }
    string s;
    cout<<"Enter the logical address:";
    cin>>s;
    int pno=stoi(s.substr(0,pageno_bit));
    if(page_table[pno][1]==1)
    {
        cout<<"Pagr Hit...."<<"\nPage is present in frame no:"<<page_table[pno][0]<<endl;

    }else{
        cout<<"Page Fault..."<<endl;
    }
    return 0;
}
/*
Enter the process size(KB):8
Enter the page size(B):32
Enter the physical size(KB):2048

Total no of frames:65536
Total no of enteries:256
Number of bits physical address:22
Number of bits in logical address:15
Enter the no. of enteries:4
Enter the page no.:0
Enter the frame on:-1
page is avilable or not in MM:0
Enter the page no.:1
Enter the frame on:4
page is avilable or not in MM:1
Enter the page no.:2
Enter the frame on:6
page is avilable or not in MM:1
Enter the page no.:255
Enter the frame on:-1
page is avilable or not in MM:0
Enter the logical address:000000000000011
Page Fault...
*/