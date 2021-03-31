#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using namespace std;
vector<int> super_set;
void make_set(int i) {
    super_set[i] = i;
}
int find_id(int i) {
    while (i != super_set[i]) {
        i = super_set[i];
    }
    return i;
}
int parent(int i) {
    while (i != super_set[i]) {
        i = super_set[i];
    }
    return i;
}
void union_set(int u, int v) {
    int id1 = find_id(u);
    int id2 = find_id(v);
    if (id1 == id2) return;
    super_set[parent(v)] = id1;
}
double clustering(vector<int> x, vector<int> y, int k) {
    //write your code here
    /*
    * use kruskal alogorithm;
    * now we have n subset and each subset have one vertices and we want to reduce our subset in to k subset;
    * for that i will calculate the distance of each one of them from one another and sort the distance
    * increasing order and then  union the least distance sub-set up to we will reach the total k subets;
    */
    int n = x.size();
    std::vector<pair<double, pair<int, int>>> dist; //first store the distance and pair store the vertices
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (i == j) continue;
            double x_ = abs(x[i] - x[j]);
            double y_ = abs(y[i] - y[j]);
            double d = x_ * x_ + y_ * y_;
            d = pow(d, 0.5);
            dist.push_back({ d,{i,j} });
        }
    }
    super_set.resize(n);
    for (int i = 0;i < n;i++) {
        make_set(i);
    }
    sort(begin(dist), end(dist), [&](pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b)
        {return a.first < b.first; });
    int count = n;
    for (int i = 0;i < dist.size();i++) {
        if (n == k) break;
        pair<double, pair<int, int>> top = dist[i];
        pair<int, int> ver = top.second;
        int u = ver.first; int v = ver.second;
        if (find_id(u) == find_id(v)) continue;
        //union this;
        union_set(u, v);
        n--;
        /* int g = 0;
         for (auto it : super_set) {
             cout << g << " : " << it << " \n";
             g++;
          }
          cout << "now next part" << "\n";
          */

    }  double min_ = 100000.00;
    n = dist.size();
    for (int i = 0;i < n;i++) {

        pair<double, pair<int, int>> top = dist[i];
        pair<int, int> ver = top.second;
        double d = top.first;
        int u = ver.first; int v = ver.second;
        if (find_id(u) != find_id(v)) {
            min_ = min(min_, d);
        }

    }
    return min_;
}

int main() {
    size_t n;
    int k;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cin >> k;
    std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}