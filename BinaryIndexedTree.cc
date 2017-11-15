#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<vector>
#include<cassert>
#include<cstring>
#include<iostream>
#include<algorithm>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define len(a) ((int) (a).size())

using namespace std;

typedef long long int64;
typedef long double ld;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;

// Index must be 1 - based
struct BinaryIndexedTree {
        int N;
        vector<int> Tree;

        BinaryIndexedTree(int N) : Tree(N + 1, 0), N(N) {};

        void update(int idx, int value) {
                while ( idx <= N) {
                        Tree[idx] += value;
                        idx += idx & (-idx);
                }
        }

        int query(int idx) {
                int res = 0;
                while (idx > 0) {
                        res += Tree[idx];
                        idx -= idx & (-idx);
                }
                return res;
        }

        // Inclusive query
        int range_query(int from, int to) {
                return query(to) - query(from - 1);
        }
};

int main() {
        BinaryIndexedTree bit(5);

        bit.update(1, 1);
        bit.update(2, 3);

        assert(bit.query(0) == 0);
        assert(bit.query(1) == 1);
        assert(bit.query(2) == 4);
        assert(bit.query(5) == 4);
        assert(bit.range_query(2, 4) == 3);

        bit.update(2, -3);
        assert(bit.range_query(2, 4) == 0);

        bit.update(2, 1);
        bit.update(4, 4);
        assert(bit.query(4) == 6);
        assert(bit.range_query(3, 3) == 0);
        assert(bit.range_query(2, 2) == 1);
        assert(bit.range_query(2, 3) == 1);
        assert(bit.range_query(2, 4) == 5);
}

