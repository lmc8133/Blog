#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void preOrder(TreeNode* r){  //递归前序遍历
    if(r){
        cout<<r->val<<" ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

void preOrder1(TreeNode* r){     //非递归前序遍历
    stack<TreeNode*>s;
    TreeNode* p=r;
    while(p||!s.empty()){
        while(p){
            cout<<p->val<<" ";
            s.push(p);
            p=p->left;
        }
        p=s.top();
        s.pop();
        p=p->right;
    }
}

void inOrder(TreeNode* r){  //递归中序遍历
    if(r){
        inOrder(r->left);
        cout<<r->val<<" ";
        inOrder(r->right);
    }
}

void inOrder1(TreeNode* r){     //非递归中序遍历
    stack<TreeNode*> s;
    TreeNode* p=r;
    while(p||!s.empty()){
        while(p){
            s.push(p);
            p=p->left;
        }
        p=s.top();
        s.pop();
        cout<<p->val<<" ";
        p=p->right;
    }
}

void postOrder(TreeNode* r){       //递归后序遍历
    if(r){
        postOrder(r->left);
        postOrder(r->right);
        cout<<r->val<<" ";
    }
}

void postOrder1(TreeNode* r){       //非递归后续遍历
    //思路1：当前节点p不存在左右孩子或左右孩子都已被访问过，则直接访问该节点。否则依次压入p的右孩子
    //和左孩子(确保出栈顺序是先左后右)
    stack<TreeNode*> s;
    TreeNode* cur, *pre=NULL;
    s.push(r);
    while(!s.empty()){
        cur=s.top();
        if((cur->left==NULL&&cur->right==NULL)||(pre!=NULL&&(pre==cur->left||pre==cur->right))){
            cout<<cur->val<<" ";
            s.pop();
            pre=cur;
        }
        else{
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
        }
    }
}

void postOrder2(TreeNode* r){
    //思路2:首先改写非递归前序遍历(根左右)为根右左，暂存结果，再将结果逆置，得到非递归后序遍历(左右根)
    vector<int>t;
    stack<TreeNode*>s;
    TreeNode*p=r;
    while(p||!s.empty()){
        while(p){
            t.push_back(p->val);
            s.push(p);
            p=p->right; //注意跟非递归前序遍历的区别
        }
        p=s.top();
        s.pop();
        p=p->left;  //注意跟非递归前序遍历的区别
    }
    reverse(t.begin(),t.end());
    for(int i=0,n=t.size(); i<n; ++i){
        cout<<t[i]<<" ";
    }
}

void postOrder3(TreeNode* r){
    //思路3：对当前节点p，将其入栈，然后依次沿着其左子树往下搜索并入栈直至为空，然后根据此时栈顶
    //节点判断，若栈顶节点右孩子为空或右孩子已访问过，则访问栈顶节点并弹栈；否则将栈顶节点右孩子入栈。
    //需要一个pre指针记录前一个访问的节点。
    stack<TreeNode*>s;
    TreeNode *cur=r, *pre=NULL;
    while(cur||!s.empty()){
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        if(cur->right==NULL||cur->right==pre){  //当前栈顶节点没有右孩子或右孩子访问过了
            s.pop();
            cout<<cur->val<<" ";
            pre=cur;
            cur=NULL;
        }
        else{   //否则右孩子入栈
            cur=cur->right;
        }
    }
}

int main(){
    TreeNode* r=new TreeNode(3);
    r->left=new TreeNode(5);
    r->right=new TreeNode(1);
    TreeNode* t;
    t=r->left;
    // t->left=new TreeNode(6);
    t->right=new TreeNode(2);
    t=r->right;
    t->left=new TreeNode(0);
    t->right=new TreeNode(8);
    cout<<"递归前序"<<endl;
    preOrder(r);
    cout<<endl;
    cout<<"非递归前序"<<endl;
    preOrder1(r);
    cout<<endl<<endl;
    cout<<"递归中序"<<endl;
    inOrder(r);
    cout<<endl;
    cout<<"非递归中序"<<endl;
    inOrder1(r);
    cout<<endl<<endl;
    cout<<"递归后序"<<endl;
    postOrder(r);
    cout<<endl;
    cout<<"非递归后序1"<<endl;
    postOrder1(r);
    cout<<endl;
    cout<<"非递归后序2"<<endl;
    postOrder2(r);
    cout<<endl;
    cout<<"非递归后序3"<<endl;
    postOrder3(r);
    cout<<endl;
}
