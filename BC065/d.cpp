#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

class UnionFind {
    vector<int> par;
    vector<int> sizes;
public:
    UnionFind(int n) : par(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
       if (x == par[x]) return x;
       return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sizes[x] < sizes[y]) swap(x, y);
        par[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return sizes[find(x)];
    }
};

bool xord(pair< int, pair<int, int> > v1, pair< int, pair<int, int> >v2) {
    return v1.second.first < v2.second.first;
}
bool yord(pair< int, pair<int, int> > v1, pair< int, pair<int, int> >v2) {
    return v1.second.second < v2.second.second;
}

void solve(int n, vector< pair< int, pair<int, int> > > V) {
    vector< pair<int, pair <int, int> > > E;
    vector< pair<int, pair<int, int> > > V1 = V;
    vector< pair<int, pair<int, int> > > V2 = V;
    sort(V1.begin(), V1.end(), xord);
    sort(V2.begin(), V2.end(), yord);
    for (int i = 0; i < n-1; i++) {
        pair<int, pair <int, int> > tmp;
        tmp.first = V1[i+1].second.first - V1[i].second.first;
        tmp.second.first = V1[i].first;
        tmp.second.second = V1[i+1].first;
        E.push_back(tmp);
    }
    for (int i = 0; i < n-1; i++) {
        pair<int, pair <int, int> > tmp;
        tmp.first = V2[i+1].second.second - V2[i].second.second;
        tmp.second.first = V2[i].first;
        tmp.second.second = V2[i+1].first;
        E.push_back(tmp);
    }
    sort(E.begin(), E.end());
    int min_cost = 0;
    UnionFind uf(n);
    for (int i = 0; i < E.size(); i++) {
        if (!uf.same(E[i].second.first, E[i].second.second)) {
            min_cost += E[i].first;
            uf.unite(E[i].second.first, E[i].second.second);
        }
    }
    std::cout << min_cost << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n;

    gettimeofday(&start,NULL);

    std::cin >> n;
    vector< pair<int, pair<int, int> > > V(n);
    for (int i = 0; i < n; i++) {
        V[i].first = i;
        std::cin >> V[i].second.first >> V[i].second.second;
    }
    solve(n, V);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
