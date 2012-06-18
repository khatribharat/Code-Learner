// A generic class implementation of a Binary Tree.
#ifndef BINARYTREE_H
#define BINARYTREE_H

template<class T>
class TreeNode
{
	private:
		TreeNode* right;
		TreeNode* left;
		T value;	

	public:
		TreeNode();
		void setLeft(TreeNode *node);
		void setRight(TreeNode *node);
		TreeNode* getLeft();
		TreeNode* getRight();
		T getValue();
		void setValue(T val);
};



template <class nodeT, class retT>
class BinaryTree
{
	private:
		nodeT *root;
	public:
		nodeT* getRoot();
		void setRoot(nodeT *root);
		void traverseAndExec(nodeT *root, retT (*callBack)(nodeT *root));
};

#endif

