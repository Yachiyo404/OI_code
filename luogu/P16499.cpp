#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

namespace FastIO {
    char buf[1<<21], *p1=buf, *p2=buf;
    inline int getch (void) {
        return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
    }
    inline int read (void) {
        int x = 0, f = 1, ch = getch();
        while(!isdigit(ch)) {
            if(ch == '-') f = -f;
            ch = getch();
        }
        while(isdigit(ch)) {
            x = x * 10 + ch - '0';
            ch = getch();
        }
        return x * f;
    }
    char buf2[1<<21], buf3[25];
    int tp_l, buf2_l=-1;
    inline void flush (void) {
        fwrite (buf2, 1, buf2_l+1, stdout), buf2_l=-1;
    }
    inline void print (long long x, char ch=10) {
        if(buf2_l>(1<<20)) flush();
        if(x<0) buf2[++buf2_l]='-', x=-x;
        do buf3[++tp_l]=x%10+48;
        while(x/=10);
        do buf2[++buf2_l]=buf3[tp_l];
        while(--tp_l);
        buf2[++buf2_l] = ch;
    }
}
using FastIO::read;
using FastIO::print;

struct BIT {
    int n;
    vector<ll> tree;
    BIT(int sz) : n(sz), tree(sz + 1, -INF) {}
    void update(int idx, ll val) {
        while (idx <= n) {
            if (val > tree[idx]) tree[idx] = val;
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        ll res = -INF;
        while (idx > 0) {
            if (tree[idx] > res) res = tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int main(){
    int cid = read(), test = read();
    while (test--) {
        int n = read();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = read();

        if (n == 1) {
            print(0);
            continue;
        }

        // Coordinate compression
        vector<int> sorted(a);
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        // Replace a with 1-indexed ranks
        for (int i = 0; i < n; ++i)
            a[i] = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin() + 1;

        BIT bit1(m);       // prefix max of f[x] - orig[x]
        BIT bit2_rev(m);   // prefix max of f[x] + orig[x], reversed index for suffix query

        ll tag = 0;
        ll max_f_raw = -INF;

        int yesterday_twice_more = 0; // required by problem

        for (int i = 1; i < n; ++i) {
            int cur_rank = a[i];
            int prev_rank = a[i - 1];
            int cur_orig = sorted[cur_rank - 1];
            int prev_orig = sorted[prev_rank - 1];
            ll delta = abs((ll)cur_orig - prev_orig);

            // best = max(empty_raw, max_{x<=cur}(f[x]-x)+cur, max_{x>cur}(f[x]+x)-cur)
            ll best = 0; // empty_raw = 0

            ll q1 = bit1.query(cur_rank);
            if (q1 > -INF / 2) {
                ll cand = q1 + cur_orig;
                if (cand > best) best = cand;
            }

            ll q2 = bit2_rev.query(m - cur_rank);
            if (q2 > -INF / 2) {
                ll cand = q2 - cur_orig;
                if (cand > best) best = cand;
            }

            tag += delta;
            ll candidate = best - delta;
            if (candidate > max_f_raw) max_f_raw = candidate;

            // Update f_raw[prev] -> store g1 and g2 in BITs
            bit1.update(prev_rank, candidate - prev_orig);
            bit2_rev.update(m - prev_rank + 1, candidate + prev_orig);

            yesterday_twice_more = 1;
        }

        ll ans = tag + max(0LL, max_f_raw);
        if (yesterday_twice_more) {} // suppress unused warning
        print(ans);
    }
    FastIO::flush();
    return 0;
}
