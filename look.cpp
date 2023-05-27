#include <bits/stdc++.h>
using namespace std;

void look(vector<int> req, int head)
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
    cout << "\nLOOK POLICY:\n";
    cout << "------------------------------------\n";
    cout << "\tLEFT TO RIGHT\n";
    cout << "------------------------------------\n";
    for (int i = index; i < n; i++)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    for (int i = index - 1; i >= 0; i--)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "\nTotal seek time:" << (req[n - 1] - head + req[n - 1] - req[0]) << endl;

    cout << "\n------------------------------------\n";
    cout << "\tRIGHT TO LEFT\n";
    cout << "------------------------------------\n";
    for (int i = index; i >= 0; i--)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    for (int i = index + 1; i < n; i++)
    {
        cout << "TRACK: " << req[i] << "\n";
    }
    cout << "\nTotal seek time:" << (head - req[0] + req[n - 1] - req[0]);
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
    look(req, head);
}

/*
Enter the number of request proccess:8
Enter head position:53
Enter the track of proccesses:98 183 65 67 122 124 14 37

LOOK POLICY:
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
TRACK: 37
TRACK: 14

Total seek time:299

------------------------------------
        RIGHT TO LEFT
------------------------------------
TRACK: 53
TRACK: 37
TRACK: 14
TRACK: 65
TRACK: 67
TRACK: 98
TRACK: 122
TRACK: 124
TRACK: 183

Total seek time:208
*/