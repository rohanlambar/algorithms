#include <bits/stdc++.h>
using namespace std;
void build(int node, vector<int> &tree, vector<int> &nums, int start, int end)
{
    if (start == end)
    {
        tree[node] = nums[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, tree, nums, start, mid);
    build(2 * node + 1, tree, nums, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, vector<int> &tree, vector<int> &nums, int start, int end, int L, int R)
{
    if (end < L || start > R)
        return 0;
    if (L <= start && end <= R)
        return tree[node];
    int mid = start + (end - start) / 2;
    return query(2 * node, tree, nums, start, mid, L, R) + query(2 * node + 1, tree, nums, mid + 1, end, L, R);
}
void update(int node, vector<int> &tree, vector<int> &nums, int index, int start, int end)
{
    if (start == end)
    {
        tree[node] = nums[index];
        return;
    }
    int mid = start + (end - start) / 2;
    if (mid >= index)
        update(2 * node, tree, nums, index, start, mid);
    else
        update(2 * node + 1, tree, nums, index, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int main()
{
    vector<int> nums = {2, 3, 5, 6, 7, 8};
    vector<int> tree(4 * nums.size());
    build(1, tree, nums, 0, nums.size() - 1);
    int i = 0;
    for (auto el : tree)
        cout << i++ << " " << el << endl;
    cout << "answer is 31 == " << query(1, tree, nums, 0, nums.size() - 1, 0, 5) << endl;
    nums[2] = 4;
    update(1, tree, nums, 2, 0, nums.size() - 1);

    cout << "after update answer is 30 == " << query(1, tree, nums, 0, nums.size() - 1, 0, 5) << endl;
    return 0;
}