#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mm, int memsize, int total)
{
    cout << "\n\tMAIN MEMEORY\n";
    cout << "\t-----------------\n";
    for (int i = 0; i < (int)mm.size(); i++)
    {
        if (mm[i][1] == -1)
            cout << "Block" << i << "\t|\t\t|   " << mm[i][0] << " MB\n";
        else
            cout << "Block" << i << "\t|\t"<< "P" << mm[i][1] << "\t|   " << mm[i][0] << " MB\n";
        cout << "\t-----------------\n";
    }
    cout << "Block n"<< "\t|\t\t|   " << memsize - total << " MB\n";
    cout << "\t-----------------\n";
}

void MVT(int memsize)
{
    int t, external_fragment = 0, total = 0;
    vector<vector<int>> mm;
    cout << "Enter the number of procces you want to enter:";
    cin >> t;
    while (t--)
    {
        int p, id;
        cout << "\nEnter the procces id and size:";
        cin >> id >> p;
        total += p;
        if (total > memsize)
        {
            cout << "\nMemory is full....\n";
            break;
        }
        else
        {
            mm.push_back({p, id});
            print(mm, memsize, total);
        }
    }
    cout << "Enter the number of procces you want to swap:";
    cin >> t;
    while(t--)
    {
        int id,count=-1;
        cout << "\nEnter the procces id:";
        cin >> id;
        for(int i=0;i<(int)mm.size();i++)
        {
             if(mm[i][1]==id)
             {
                 count=i;
                 break;
             }
        }
        if(count==-1)
        {
           cout<<"Proccess not found.....";
        }
        else
        {
            external_fragment+=mm[count][0];
            mm[count][1]=-1;
           print(mm, memsize, total);
        }
    }
    cout << "\nTotal External fragmentation:" << external_fragment << " MB";
}

int main()
{
    int memsize;
    cout << "Enter the total size of main memory(MB):";
    cin >> memsize;
    MVT(memsize);
}
/*
Enter the total size of main memory(MB):20
Enter the number of procces you want to enter:3

Enter the procces id and size:1 2

        MAIN MEMEORY
        -----------------
Block0  |       P1      |   2 MB
        -----------------
Block n |               |   18 MB
        -----------------

Enter the procces id and size:2 5

        MAIN MEMEORY
        -----------------
Block0  |       P1      |   2 MB
        -----------------
Block1  |       P2      |   5 MB
        -----------------
Block n |               |   13 MB
        -----------------

Enter the procces id and size:3 3

        MAIN MEMEORY
        -----------------
Block0  |       P1      |   2 MB
        -----------------
Block1  |       P2      |   5 MB
        -----------------
Block2  |       P3      |   3 MB
        -----------------
Block n |               |   10 MB
        -----------------
Enter the number of procces you want to swap:2

Enter the procces id:2

        MAIN MEMEORY
        -----------------
Block0  |       P1      |   2 MB
        -----------------
Block1  |               |   5 MB
        -----------------
Block2  |       P3      |   3 MB
        -----------------
Block n |               |   10 MB
        -----------------

Enter the procces id:4
Proccess not found.....
Total External fragmentation:5 MB

*/