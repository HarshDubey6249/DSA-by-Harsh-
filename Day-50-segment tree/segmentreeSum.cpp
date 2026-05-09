#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

    void BuildTree(vector<int> &arr, int st, int end, int node)
    {

        if (st == end)
        {
            tree[node] = arr[st];
            return;
        }

        int mid = st + (end - st) / 2;
        BuildTree(arr, st, mid, 2 * node + 1);
        BuildTree(arr, mid + 1, end, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int rangeSum(int qi,int qj,int si,int sj,int node){

        if(qj<si||qi>sj){  //No overlap
                return 0;
        }

        if(si>=qi&& sj<=qj){
            return tree[node];
        }

        int mid=si+(sj-si)/2;

        return rangeSum(qi,qj,si,mid,2*node+1)+rangeSum(qi,qj,mid+1,sj,2*node+2);
    }

    void updateTree(int idx,int val,int st,int end,int node){

        if(st==end){
            tree[node]=val;
            return;
        }

        int mid=st+(end-st)/2;

        if(idx>=st&&idx<=mid){
            updateTree(idx,val,st,mid,2*node+1);//left

        }else{
            updateTree(idx,val,mid+1,end,2*node+2);//right
        }

        tree[node]=tree[2*node+1]+tree[2*node+2];

    }

public:
    SegmentTree(vector<int> &arr)
    {
         n = arr.size();
        tree.resize(4 * n);
        BuildTree(arr, 0, n - 1, 0);
    }

    void print()
    {
        for (int i = 0; i < tree.size() - 1; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
   
    int rangeQueries(int qi, int qj)
    {

       return rangeSum(qi, qj, 0, n - 1, 0);
    }

    int updateVal(int idx,int val){

        updateTree(idx,val,0,n-1,0);
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    SegmentTree st(arr);
    st.print();

    cout<<"-------------------------------\n";
    cout<<st.rangeQueries(0,3)<<endl;

    st.updateVal(1,3);
     st.print();
     cout<<endl;
     cout<<st.rangeQueries(0,3)<<endl;

    return 0;
}