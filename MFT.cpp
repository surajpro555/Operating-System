#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &mm)
{
    cout << "\n\tMAIN MEMEORY\n";
    cout << "\t-----------------\n";
    for (int i = 0; i < (int)mm.size(); i++)
    {
        if (mm[i][1] == -1)
            cout << "Block" << i << "\t|\t\t|   " << mm[i][0] << " MB\n";
        else
            cout << "Block" << i << "\t|\t"
                 << "P" << mm[i][1] << "\t|   " << mm[i][0] << " MB\n";
        cout << "\t-----------------\n";
    }
}

void equal_partion(int memsize)
{
    int bsize, t, x = 0, internal_fragment = 0;
    cout << "Enter the size of block(MB):";
    cin >> bsize;
    int part = memsize / bsize;
    vector<vector<int>> mm(part, {bsize, -1});
    print(mm);
    cout << "Enter the number of procces you want to enter:";
    cin >> t;
    while (t--)
    {
        int p, id;
        cout << "\nEnter the procces id and size:";
        cin >> id >> p;
        if (p > bsize)
        {
            cout << "\nProccess is Lager than Block size......\n";
        }
        else if (x >= part)
        {
            cout << "ALL Blocks are filled.....\nWait......\n";
        }
        else
        {
            mm[x++][1] = id;
            internal_fragment += bsize - p;
            print(mm);
        }
    }
    cout << "\nTotal Internal fragmentation:" << internal_fragment << " MB";
}

void unequal_partion()
{
    int t, internal_fragment = 0, part;
    cout << "Enter the total no. of partitions:";
    cin >> part;
    vector<vector<int>> mm(part, vector<int>(3));
    cout << "Enter the size of blocks(in sorted order)(MB):";
    for (int i = 0; i < part; i++)
    {
         cin >> mm[i][0];
         mm[i][1] = -1;
         mm[i][2] = 1;
    }
    print(mm);
    cout << "Enter the number of procces you want to enter:";
    cin >> t;
    while (t--)
    {
        int p, id;
        cout << "\nEnter the procces id and size:";
        cin >> id >> p;
        if (p > mm[part - 1][0])
        {
            cout << "\nProccess is Lager than Largest Block size......\n";
        }
        else
        {
            int i = 0;
            for (i = 0; i < part; i++)
            {
                if (mm[i][2]  && p <= mm[i][0])
                {
                    mm[i][1] = id;
                    mm[i][2]=0;
                    internal_fragment += mm[i][0] - p;
                    print(mm);
                    break;
                }
            }
            if (i == part)
            {
                cout << "No blocks are available.....\nWait......\n";
            }
        }
    }
    cout << "\nTotal Internal fragmentation:" << internal_fragment << " MB";
}

int main()
{
    int memsize, ch;
    cout << "Enter the total size of main memory(MB):";
    cin >> memsize;
    cout << "\n1.EQUAL PARTITIONS\n2.UNEQUAL PARTITIONS\nEnter the choice:";
    cin >> ch;
    switch (ch)
    {
    case 1:
        equal_partion(memsize);
        break;
    case 2:
        unequal_partion();
        break;
    default:
        cout << "\nINVALID OPTION....";
        break;
    }
}
/*
Enter the total size of main memory(MB):20

1.EQUAL PARTITIONS
2.UNEQUAL PARTITIONS
Enter the choice:1
Enter the size of block(MB):4

        MAIN MEMEORY
        -----------------
Block0  |               |   4 MB
        -----------------
Block1  |               |   4 MB
        -----------------
Block2  |               |   4 MB
        -----------------
Block3  |               |   4 MB
        -----------------
Block4  |               |   4 MB
        -----------------
Enter the number of procces you want to enter:3

Enter the procces id and size:1 3

        MAIN MEMEORY
        -----------------
Block0  |       P1      |   4 MB
        -----------------
Block1  |               |   4 MB
        -----------------
Block2  |               |   4 MB
        -----------------
Block3  |               |   4 MB
        -----------------
Block4  |               |   4 MB
        -----------------

Enter the procces id and size:2 1

        MAIN MEMEORY
        -----------------
Block0  |       P1      |   4 MB
        -----------------
Block1  |       P2      |   4 MB
        -----------------
Block2  |               |   4 MB
        -----------------
Block3  |               |   4 MB
        -----------------
Block4  |               |   4 MB
        -----------------

Enter the procces id and size:3 5

Proccess is Lager than Block size......

Total Internal fragmentation:4 MB

######################## CASE 2 ###############################

Enter the total size of main memory(MB):20

1.EQUAL PARTITIONS
2.UNEQUAL PARTITIONS
Enter the choice:2
Enter the total no. of partitions:6
Enter the size of blocks(in sorted order)(MB):1 2 3 4 5 5

        MAIN MEMEORY
        -----------------
Block0  |               |   1 MB
        -----------------
Block1  |               |   2 MB
        -----------------
Block2  |               |   3 MB
        -----------------
Block3  |               |   4 MB
        -----------------
Block4  |               |   5 MB
        -----------------
Block5  |               |   5 MB
        -----------------
Enter the number of procces you want to enter:3

Enter the procces id and size:1 3

        MAIN MEMEORY
        -----------------
Block0  |               |   1 MB
        -----------------
Block1  |               |   2 MB
        -----------------
Block2  |       P1      |   3 MB
        -----------------
Block3  |               |   4 MB
        -----------------
Block4  |               |   5 MB
        -----------------
Block5  |               |   5 MB
        -----------------

Enter the procces id and size:2 5

        MAIN MEMEORY
        -----------------
Block0  |               |   1 MB
        -----------------
Block1  |               |   2 MB
        -----------------
Block2  |       P1      |   3 MB
        -----------------
Block3  |               |   4 MB
        -----------------
Block4  |       P2      |   5 MB
        -----------------
Block5  |               |   5 MB
        -----------------

Enter the procces id and size:3 3

        MAIN MEMEORY
        -----------------
Block0  |               |   1 MB
        -----------------
Block1  |               |   2 MB
        -----------------
Block2  |       P1      |   3 MB
        -----------------
Block3  |       P3      |   4 MB
        -----------------
Block4  |       P2      |   5 MB
        -----------------
Block5  |               |   5 MB
        -----------------

Total Internal fragmentation:1 MB

*/