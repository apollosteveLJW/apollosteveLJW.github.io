#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n):val(n),left(nullptr),right(nullptr){};
};

TreeNode* build(const vector<int>& nums, int s, int e) {
    if(nums.size() == 0) return nullptr;
    TreeNode* root = new TreeNode(nums[s]);
    if(s == e) {
        return root;
    }
    int count = 0, k = 0;
    int index[2];
    for(int i = s + 1; i <= e; ++i) {
        if(nums[i] == nums[s]) {
            index[k] = i;
            k++;
            count++;
        }
    }
    if(count == 1) {
        root->right = build(nums, s+1, index[0] -1);
    } else {
        root->left = build(nums, s + 1, index[0] - 1);
        root->right = build(nums, index[0] + 1, index[1] - 1);
    }
    return root;

}
int main() {
    vector<int> test({3, 1});
    int n = test.size();
    TreeNode* root = build(test, 0, n-1);
    return 0;
}