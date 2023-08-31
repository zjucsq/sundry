#include <bits/stdc++.h>
using namespace std;

int main()
{
    int C, N;
    cin >> C >> N;
    // {id, out_num}
    deque<pair<int, int>> order_queue;
    // return_queue[real_id]: has_return?
    int next_return = 0;
    vector<bool> return_queue;
    // id --> out num
    unordered_map<int, int> cnt;
    // id --> real_id
    unordered_map<int, int> id2real, real2id;
    int cur_id = 0;
    int cur_size = C;
    int cur_has = C;
    
    function<int(int, int, bool)> out = [&](int a, int b, bool first) {
        cnt[a] = b;
        int res = 0;
        if (b > cur_size) {
            if (cur_has == cur_size) {
                cur_size = b;
                cur_has = 0;
                id2real[a] = cur_id;
                real2id[cur_id] = a;
                cur_id++;
                return_queue.push_back(false);
                res = cur_size;
            } else {
                if (first)
                    order_queue.push_back({a, b});
                res = 0;
            }
        } else {
            if (cur_has >= b) {
                cur_has -= b;
                id2real[a] = cur_id;
                real2id[cur_id] = a;
                cur_id++;
                return_queue.push_back(false);
                res = b;
            } else {
                if (first)
                    order_queue.push_back({a, b});
                res = 0;
            }
        }
        return res;
    };
    
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a >= 0) {
            cout << out(a, b, true) << endl;
        } else {
            int r_id = id2real[b];
            return_queue[r_id] = true;
            while (next_return < return_queue.size() && return_queue[next_return]) {
                cur_has += cnt[real2id[next_return]];
                // cout << "// " << real2id[next_return] << " returns += " << cnt[real2id[next_return]] << ' ' << cur_has << endl;
                next_return++;
            }
            int res = 0;
            while (!order_queue.empty()) {
                auto tmp = order_queue.front();
                a = tmp.first;
                b = tmp.second;
                int res_one_order = out(a, b, false);
                if (res_one_order > 0) {
                    res += res_one_order;
                    order_queue.pop_front();
                } else {
                    break;
                }
            }
            cout << res << endl;
        }
    }
    
    return 0;
}

/*
10 11
0 3
1 2
2 4
-1 0
-1 2
3 100
4 5
-1 1
-1 3
5 9
6 13


*/


#include <bits/stdc++.h>
using namespace std;

struct img {
    int w, s;
    bool operator<(const img& lhs) {
        return w * w * lhs.s < lhs.w * lhs.w * s;
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    vector<img> imgs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &imgs[i].w, &imgs[i].s);
    }
    sort(imgs.begin(), imgs.end());
    
    int remain_size = 1024 * 1024;
    int used_id = 0;
    double res = 0;
    while (remain_size >= 64 && used_id < n) {
        int scale = 1;
        int cur_w = imgs[used_id].w;
        double cur_s = imgs[used_id].s;
        while (cur_w * cur_w > remain_size && cur_w >= 8) {
            cur_w /= 2;
            scale *= 2;
        }
        remain_size -= cur_w * cur_w;
        res += cur_s / scale / scale;
        // cout << remain_size << ' ' << res << endl;
        ++used_id;
    }
    printf("%.02lf", res);
    
    return 0;
}

/*
给你n张正方形的图片，每张图片分数为s，边长w为2的幂次
给你一张1024*1024的画布，希望能把这些图片放进去
可以缩放图片，缩放后边长必须保持大于8且为2的倍数，分数就变为s*(新面积/旧面积)
问最大得分是多少

1<=n<=1000
8<=w<=512
0<s<100

5
512 5
512 10
512 15
512 20
128 10
56.25

4
256 20
256 20
256 25
128 20
85.00
*/