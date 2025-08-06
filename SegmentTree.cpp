// time complexity - O(n * logn)

class Solution {
    //Building Tree - O(n)
    void build(int i, int l, int r, vector<int>& baskets,
               vector<int>& segmentTree) {
        if (l == r) {
            segmentTree[i] = baskets[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, baskets, segmentTree);
        build(2 * i + 2, mid + 1, r, baskets, segmentTree);
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
    }

    bool segmentTreeQuery(int i, int l, int r, vector<int>& segmentTree, int fruit) {
        if (segmentTree[i] < fruit) {
            return false;
        }
        if (l == r) {
            segmentTree[i] = -1;
            return true;
        }
        bool placed = false;
        int mid = (l + r) / 2;
        if (segmentTree[2 * i + 1] >= fruit) {
            placed = segmentTreeQuery(2 * i + 1, l, mid, segmentTree, fruit);
        } else {
            placed = segmentTreeQuery(2 * i + 2, mid + 1, r, segmentTree, fruit);
        }
        segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        return placed;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        // building the segmentTree
        vector<int> segmentTree(4 * n, -1);
        build(0, 0, n - 1, baskets, segmentTree);

        int unplaced = 0;
        for (int i = 0; i < n; ++i) {     //O(n)
            if (segmentTreeQuery(0, 0, n - 1, segmentTree, fruits[i]) == false) { // O(logn)
                unplaced++;
            }
        }
        return unplaced;
    }
};
