#include <iostream>
#include <omp.h>
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}

};

void pDFS(TreeNode* root){
	stack <TreeNode*>s;
	s.push(root);
	while(!s.empty()){
		int ss=s.size();
		#pragma omp parallel for 
		for(int i=0;i<ss;i++){
		TreeNode* node;
		#pragma omp critical
		{node=s.top();
		cout<<node->val<<" ";
		s.pop();
		if(node->right) s.push(node->right);
		if(node->left) s.push(node->left);}
}
		
	}
}

int main(){
TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3); 
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);

cout<<"Parallel DFS";
pDFS(tree);
}