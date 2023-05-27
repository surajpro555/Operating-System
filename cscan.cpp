#include <bits/stdc++.h>
using namespace std;

void scan(vector<int> req, int head, int tracks)
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
    cout << "\nC-SCAN POLICY:\n";
    cout << "------------------------------------\n";
    cout << "\tLEFT TO RIGHT\n";
    cout << "------------------------------------\n";
    for (int i = index; i < n; i++)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "TRACK: " << tracks << "\n";
    cout << "TRACK: " << 0 << "\n";
    for (int i = 0; i < index; i++)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "\nTotal seek time:" << (tracks - head + tracks + req[index - 1]) << endl;

    cout << "\n------------------------------------\n";
    cout << "\tRIGHT TO LEFT\n";
    cout << "------------------------------------\n";
    for (int i = index; i >= 0; i--)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "TRACK: " << 0 << "\n";
    cout << "TRACK: " << tracks << "\n";
    for (int i = n - 1; i > index; i--)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "\nTotal seek time:" << (head + tracks + tracks-req[index + 1]);
}

int main()
{
    int head, n, tracks;
    cout << "Enter the total number of tracks:";
    cin >> tracks;
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
    scan(req, head, tracks - 1);
}
/*
Enter the total number of tracks:200
Enter the number of request proccess:8
Enter head position:53
Enter the track of proccesses:98 41 14 65 67 122 124 183

C-SCAN POLICY:
------------------------------------
        LEFT TO RIGHT
------------------------------------
TRACK: 53
TRACK: 65
TRACK: 67
TRACK: 98
TRACK: 122
TRACK: 124
TRACK: 183
TRACK: 199
TRACK: 0
TRACK: 14
TRACK: 41

Total seek time:386

------------------------------------
        RIGHT TO LEFT
------------------------------------
TRACK: 53
TRACK: 41
TRACK: 14
TRACK: 0
TRACK: 199
TRACK: 183
TRACK: 124
TRACK: 122
TRACK: 98
TRACK: 67
TRACK: 65

Total seek time:386
*/