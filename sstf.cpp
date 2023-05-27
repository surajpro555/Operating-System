#include <bits/stdc++.h>
using namespace std;

void sstf(vector<int> req, int n, int head)
{
    int stime = 0;
    n++;
    req.push_back(head);
    sort(req.begin(), req.end());
    int idx;
    for (int i = 0; i < req.size(); i++)
    {
        if (req[i] == head)
        {
            idx = i;
            break;
        }
    }
    cout << "\nSSTF POLICY:\n";
    while (req.size())
    {
        cout << "TRACK: " << head << "\n";
        if(req.size()==1)
        {
            stime += abs(req[0] - head);
            break;
        }
        if (idx > 0 and idx < req.size() - 1)
        {
            if (abs(req[idx - 1] - head) < abs(req[idx + 1] - head))
            {
                stime += abs(req[idx - 1] - head);
                head = req[idx - 1];
                idx--;
                req.erase(req.begin() + idx+1);
            }
            else
            {
                stime += abs(req[idx+1] - head);
                head = req[idx+1];
                req.erase(req.begin() + idx);
            }
        }
        else if (idx == 0)
        {
            stime += abs(req[idx+1] - head);
            head = req[idx+1];
            req.erase(req.begin()+idx);
        }
        else if (idx == req.size() - 1)
        {
            stime += abs(req[idx - 1] - head);
            head = req[idx - 1];
            idx--;
            req.erase(req.begin() + idx+1);
        }
    }
    cout << "\nTotal seek time:" << stime;
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
    sstf(req, n, head);
}
/*
Enter the number of request proccess:7
Enter head position:50
Enter the track of proccesses:82 170 43 140 24 16 190

SSTF POLICY:
TRACK: 50
TRACK: 43
TRACK: 24
TRACK: 16
TRACK: 82
TRACK: 140
TRACK: 170
TRACK: 190

Total seek time:208
*/