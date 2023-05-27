#include <bits/stdc++.h>
using namespace std;

void clook(vector<int> req, int head)
{
    req.push_back(head);
    sort(req.begin(), req.end());
    int index, n = req.size();
    for (int i = 0; i < n; i++)
    {
        if (req[i] == head)
        {
            index = i;
            break;
        }
    }
    cout << "\n\tC-LOOK POLICY\n";
    cout << "------------------------------------\n";
    cout << "\tLEFT TO RIGHT\n";
    cout << "------------------------------------\n";
    for (int i = index; i < n; i++)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    for (int i = 0; i <index; i++)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "\nTotal seek time:" << (req[n - 1] - head + req[n-1]-req[0]+req[index-1] - req[0]) << endl;

    cout << "\n------------------------------------\n";
    cout << "\tRIGHT TO LEFT\n";
    cout << "------------------------------------\n";
    for (int i = index; i >= 0; i--)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    for (int i = n-1; i>index; i--)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "\nTotal seek time:" << (head - req[0] + req[n-1]-req[0]+req[n - 1] - req[index+1]);
}

int main()
{
    int head, n;
    cout << "Enter the number of request proccess:";
    cin >> n;
    cout << "Enter head position:";
    cin >> head;
    vector<int> req(n);
    cout << "Enter the track of proccesses:";
    for (int i = 0; i < n; i++)
    {
        cin >> req[i];
    }
    clook(req, head);
}
/*
Enter the number of request proccess:7
Enter head position:53
Enter the track of proccesses:98 183 40 122 10 124 65

        C-LOOK POLICY
------------------------------------
        LEFT TO RIGHT
------------------------------------
TRACK: 53
TRACK: 65
TRACK: 98
TRACK: 122
TRACK: 124
TRACK: 183
TRACK: 10
TRACK: 40

Total seek time:333

------------------------------------
        RIGHT TO LEFT
------------------------------------
TRACK: 53
TRACK: 40
TRACK: 10
TRACK: 183
TRACK: 124
TRACK: 122
TRACK: 98
TRACK: 65

Total seek time:334
Press any key to continue . .
*/