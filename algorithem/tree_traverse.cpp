#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/**
 * create a binary tree
 * @method createTree
 * @date   2017-12-10T17:09:36+080
 * @author Baboon
 * @param  root                    root node
 */
void createTree(TreeNode* &root){
  cout<<"input node:"<<endl;
  int temp;
  cin>>temp;
  if(temp>=10000){
    root = NULL;
    return;
  }
  else{
    root = new TreeNode(temp);
    createTree(root->left);
    createTree(root->right);
  }
}
/**
 * pre order traverse tree
 * @method preOrder
 * @date   2017-12-10T17:24:17+080
 * @author Baboon
 * @param  root                    [description]
 */
void preOrder(TreeNode* root){

  if(!root)return;
  cout<<root->val<<endl;
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(TreeNode* root){
  if(!root)return;
  inOrder(root->left);
  cout<<root->val<<endl;
  inOrder(root->right);
}

void postOrder(TreeNode* root){

  if(!root)return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->val<<endl;
}

void preOrderNonRecursive(TreeNode* root){
  if(!root) return;
  stack<TreeNode*> nodeStack;
  TreeNode* cur = root;
  nodeStack.push(root);
  while(!nodeStack.empty()){
    cur = nodeStack.top();
    cout<<cur->val<<endl;
    nodeStack.pop();
    if(cur->right){
      nodeStack.push(cur->right);
    }
    if(cur->left){
      nodeStack.push(cur->left);
    }
  }
}

void inOrderNonRecursive(TreeNode* root){
  if(!root) return;
  stack<TreeNode*> nodeStack;
  TreeNode* cur = root;
  nodeStack.push(cur);
  cur = cur->left;
  while(cur || !nodeStack.empty()){
    while(cur){
      nodeStack.push(cur);
      cur = cur->left;
    }

    cur = nodeStack.top();
    cout<<cur->val<<endl;
    nodeStack.pop();
    cur = cur->right;

  }
}

void postOrderNonRecursive(TreeNode* root){
  if(!root) return;
  stack<TreeNode*> nodeStack;
  TreeNode* cur = root;
  nodeStack.push(root);
  TreeNode* pre = NULL;
  while(!nodeStack.empty()){
    cur = nodeStack.top();
    if(((!cur->left) &&(!cur->right)) ||
    (pre &&( (cur->left==pre) || (cur->right==pre) ))){//2个判断原则
        cout<<cur->val<<endl;
        nodeStack.pop();
        pre = cur;// record last visited node
    }
    else{
        if(cur->right){
            nodeStack.push(cur->right);
        }
        if(cur->left){
            nodeStack.push(cur->left);
        }
    }
  }
}

int main(){

freopen("input.txt","r",stdin);
TreeNode* root;
createTree(root);
cout<<"pre order:"<<endl;
preOrder(root);
cout<<"in order:"<<endl;
inOrder(root);
cout<<"post order:"<<endl;
postOrder(root);
cout<<"pre order non recursive:"<<endl;
preOrderNonRecursive(root);
cout<<"in order non recursive:"<<endl;
inOrderNonRecursive(root);
cout<<"post order non recursive:"<<endl;
postOrderNonRecursive(root);
cout<<(5/(2.0));


}
