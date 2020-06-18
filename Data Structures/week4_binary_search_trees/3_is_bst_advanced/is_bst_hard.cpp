#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool searchTree(vector<Node> tree,int root)
{
	if (root == -1) return true;

	int left = tree[root].left;
	int right = tree[root].right;

	if (tree[left].key == tree[root].key)
		return false;

	return searchTree(tree,left)&&searchTree(tree,right);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if (tree.size()<2) return true;
  vector<int> ino;
  stack<Node> st;
  int root = 0;
  bool done = false;
  while(!done)
  {
      if (root != -1)
      {
          st.push(tree[root]);
          root = tree[root].left;
      }
      else
      {
          if (!st.empty())
          {
              ino.push_back(st.top().key);
              root = st.top().right;
              st.pop();
          }
          else
            done = true;
      }
  }

  if (!searchTree(tree,0))
  	return false;

  for(int i=1;i<ino.size();i++)
    if (ino[i] < ino[i-1])
      return false;

  return true;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
