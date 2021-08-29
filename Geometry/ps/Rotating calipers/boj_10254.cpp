#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pt {
    long long x, y;
    bool operator < (const pt & b) const {
        return x < b.x || x == b.x && y < b.y;
    }
    pt operator - (const pt & b) const {
        return {x - b.x, y - b.y};
    }
};

long long dist(pt & a, pt & b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}
long long cross(pt const& a, pt const& b, pt const& c) {
    return (a.x - b.x) * (b.y - c.y) + (b.x - c.x) * (b.y - a.y);
}
long long cross(pt const& a, pt const& b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pt> p(n);
        for(pt & i : p) cin >> i.x >> i.y;

        sort(p.begin(), p.end());
        stable_sort(p.begin() + 1, p.end(), [&](const pt & a, const pt & b) {
            return cross(p[0], a, b) > 0;
        });

        vector<pt> h;
        for(pt & i : p) {
            while(h.size() > 1 && cross(h[h.size() - 2], h[h.size() - 1], i) <= 0){h.pop_back();}
            h.push_back(i);
        }
        n = h.size();
        auto next = [n](int i) {return (i + 1) % n;};
        
        int left = 0, right = 0;
        for(int i =0; i<n; ++i) {
            if (h[left].x > h[i].x) left = i;
            if (h[right].x < h[i].x) right = i;
        }
        long long ans = dist(h[left], h[right]), a = left, b = right;
        //pt line = {0, 1};
        for(int i =0; i<n; ++i) {
            if (cross(h[next(left)] - h[left], h[right] - h[next(right)]) > 0) {
                //line = h[left] - h[next(left)];
                left = next(left);
            } else {
                //line = h[next(right)] - h[right];
                right = next(right);
            }
            auto d = dist(h[left], h[right]);
            if (ans < d) {
                ans = d;
                a = left;
                b = right;
            }
        }
        cout << h[a].x << ' ' << h[a].y << ' ' << h[b].x << ' ' << h[b].y << '\n';
    } 
}
