#include<bits/stdc++.h>
using namespace std;

/*
 * 离散化（坐标压缩）通用模板
 * 用法：
 *   Discrete<int> d;
 *   d.init(原始数组);
 *   int idx = d.id(x);    // 原值 → 压缩值（1-based）
 *   int v   = d.val(idx); // 压缩值 → 原值
 *   int m   = d.size();   // 不同值的个数
 * 复杂度：init O(n log n)，id O(log n)，val O(1)
 */

template<typename T>
struct Discrete {
    vector<T> raw;

    void init(const vector<T>& a) {
        raw = a;
        sort(raw.begin(), raw.end());
        raw.erase(unique(raw.begin(), raw.end()), raw.end());
    }

    int id(T x) {
        return lower_bound(raw.begin(), raw.end(), x) - raw.begin() + 1;
    }

    T val(int id) {
        return raw[id - 1];
    }

    int size() { return raw.size(); }
};
