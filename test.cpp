#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 100005;
const int LOG = 20; // 因为 2^17 > 1e5

struct Edge {
    int u, v, w;
    bool used; // 是否为树边
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
vector<pair<int, int>> tree[N]; // 邻接表存MST: (to, weight)
int parent[N], depth[N];
int fa[N][LOG], mx1[N][LOG], mx2[N][LOG];
int n, m;

// ---------- 并查集 ----------
int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

// ---------- 合并最大和次大值 ----------
pair<int, int> combine(int a, int b, int c, int d) {
    // 将四者中最大的两个（严格区分）返回
    vector<int> v = {a, b, c, d};
    int maxv = -1, secv = -1;
    for (int x : v) {
        if (x > maxv) {
            secv = maxv;
            maxv = x;
        } else if (x < maxv && x > secv) {
            secv = x;
        }
    }
    return {maxv, secv};
}

// ---------- DFS 预处理 ----------
void dfs(int u, int f, int w) {
    fa[u][0] = f;
    mx1[u][0] = w;
    mx2[u][0] = -1; // 不存在次大边
    depth[u] = depth[f] + 1;

    for (int k = 1; k < LOG; k++) {
        int mid = fa[u][k-1];
        fa[u][k] = fa[mid][k-1];

        // 合并上半段和下半段的最大/次大
        auto res = combine(mx1[u][k-1], mx2[u][k-1], mx1[mid][k-1], mx2[mid][k-1]);
        mx1[u][k] = res.first;
        mx2[u][k] = res.second;
    }

    for (auto &e : tree[u]) {
        int v = e.first;
        if (v == f) continue;
        dfs(v, u, e.second);
    }
}

// ---------- 查询路径上的最大和严格次大 ----------
pair<int, int> query(int u, int v) {
    int maxv = -1, secv = -1;

    if (depth[u] < depth[v]) swap(u, v);

    // 1. 将 u 提升到与 v 同深度
    int diff = depth[u] - depth[v];
    for (int k = LOG - 1; k >= 0; k--) {
        if (diff & (1 << k)) {
            auto res = combine(maxv, secv, mx1[u][k], mx2[u][k]);
            maxv = res.first;
            secv = res.second;
            u = fa[u][k];
        }
    }

    if (u == v) return {maxv, secv};

    // 2. 同时向上跳
    for (int k = LOG - 1; k >= 0; k--) {
        if (fa[u][k] != fa[v][k]) {
            auto res = combine(maxv, secv, mx1[u][k], mx2[u][k]);
            maxv = res.first;
            secv = res.second;
            u = fa[u][k];

            res = combine(maxv, secv, mx1[v][k], mx2[v][k]);
            maxv = res.first;
            secv = res.second;
            v = fa[v][k];
        }
    }

    // 最后一步：跳到 LCA
    auto res = combine(maxv, secv, mx1[u][0], mx2[u][0]);
    maxv = res.first;
    secv = res.second;

    res = combine(maxv, secv, mx1[v][0], mx2[v][0]);
    maxv = res.first;
    secv = res.second;

    return {maxv, secv};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w, false});
    }

    // ---------- Kruskal 求 MST ----------
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) parent[i] = i;

    ll sum = 0;
    int cnt = 0;

    for (auto &e : edges) {
        int ru = find(e.u), rv = find(e.v);
        if (ru != rv) {
            parent[ru] = rv;
            e.used = true;
            sum += e.w;
            cnt++;

            tree[e.u].push_back({e.v, e.w});
            tree[e.v].push_back({e.u, e.w});
        }
        if (cnt == n - 1) break;
    }

    // ---------- 倍增预处理 ----------
    depth[1] = 0;
    dfs(1, 0, 0);

    // ---------- 枚举非树边，找最小替换 ----------
    ll ans = LLONG_MAX;

    for (auto &e : edges) {
        if (e.used) continue;

        auto res = query(e.u, e.v);
        int maxv = res.first;
        int secv = res.second;

        // 严格替换
        if (e.w > maxv) {
            ans = min(ans, sum - maxv + e.w);
        } else if (e.w == maxv && secv != -1 && e.w > secv) {
            // 最大值相等，必须用次大值替换
            ans = min(ans, sum - secv + e.w);
        }
    }

    cout << ans << endl;
    return 0;
}