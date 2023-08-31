#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

struct task{
    int end_day;
    int value;
    bool operator<(const task& rhs) {
        return end_day == rhs.end_day ? value > rhs.value : end_day < rhs.end_day;
    }
};

struct people{
    int l, r, w;
    bool operator<(const people& rhs) {
        return l < rhs.l;
    }
};


int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<task> tasks(m);
    for (int i = 0; i < m; ++i) {
        cin >> tasks[i].end_day >> tasks[i].value;
    }

    vector<people> peoples(r);
    for (int i = 0; i < r; ++i) {
        cin >> peoples[i].l >> peoples[i].r >> peoples[i].w;
    } 

    sort(tasks.begin(), tasks.end());
    sort(peoples.begin(), peoples.end());

    priority_queue<int, vector<int>, greater<>> pq;
    int res = 0;
    int time = 0;
    int people_id = 0;
    int task_cnt = 0;
    for (int i = 0; i < m; ++i) {
        time = tasks[i].end_day;
        while (people_id < r && peoples[people_id].l <= time) {
            task_cnt += peoples[people_id].w;
            people_id++;
        }

        if (pq.size() < task_cnt) {
            res += tasks[i].value;
            pq.push(tasks[i].value);
        } else if (pq.top() < tasks[i].value) {
            res += tasks[i].value;
            pq.push(tasks[i].value);
            res -= pq.top();
            pq.pop();
        }
    }
    cout << res << endl;
    return 0;
}

/*
3 5 2
2 3
1 10
2 10
3 2
3 10
1 3 2
1 2 2

33
*/