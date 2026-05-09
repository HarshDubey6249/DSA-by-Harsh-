#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{

    vector<int> tree;
    int n;

    void buildTree(vector<int> arr, int st, int end, int node)
    {
        if (st == end)
        {
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end - st) / 2;
        buildTree(arr, st, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int maxQuery(int qi, int qj, int si, int sj, int node)
    {

        if (qi > sj || qj < si)
        {
            return INT16_MIN;
        }
        if (si >= qi && sj <= qj)
        {
            return tree[node];
        }
        int mid = si + (sj - si) / 2;

        int left = maxQuery(qi, qj, si, mid, 2 * node + 1);
        int right = maxQuery(qi, qj, mid + 1, sj, 2 * node + 2);

        return max(left, right);
    }

    void updateTree(int idx, int val, int st, int end, int node)
    {

        if (st == end)
        {
            tree[node] = val;
            return;
        }

        int mid = st + (end - st) / 2;

        if (idx >= st && idx <= mid)
        {
            updateTree(idx, val, st, mid, 2 * node + 1); // left
        }
        else
        {
            updateTree(idx, val, mid + 1, end, 2 * node + 2); // right
        }

        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(vector<int> arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }
    void print()
    {
        for (int i = 0; i < tree.size() - 1; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj)
    {

        return maxQuery(qi, qj, 0, n - 1, 0);
    }

    void updateVal(int idx, int val)
    {

        updateTree(idx, val, 0, n - 1, 0);
    }
};
int main()
{
    vector<int> arr = {6, 8, -1, 2, 17, 1, 3, 2, 4};
    SegmentTree st(arr);

    st.print();
    cout << st.rangeQuery(2, 5) << endl;

    st.updateVal(4,16);
     cout << st.rangeQuery(2, 5) << endl;
     
    st.print();
    return 0;
}