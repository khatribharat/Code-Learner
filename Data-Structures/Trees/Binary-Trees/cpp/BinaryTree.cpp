#include "BinaryTree.hpp"
#include <cstring>

template <class T>
TreeNode<T>::TreeNode()
{
	this->right = NULL;
	this->left  = NULL;  
}




template <class T>
void
TreeNode<T>::setLeft(TreeNode *node)
{
	this->left = node;
}

template <class T>
void
TreeNode<T>::setRight(TreeNode *node)
{
	this->right = node;
}

template <class T>
TreeNode<T>*
TreeNode<T>::getLeft()
{
	return this->left;
}

template <class T>
TreeNode<T>*
TreeNode<T>::getRight()
{
	return this->right;
}

template <class T>
T
TreeNode<T>::getValue()
{
	return this->value;
}


template <class T>
void
TreeNode<T>::setValue(T val)
{
	this->value = val;
}

template <class nodeT, class retT>
nodeT*
BinaryTree<nodeT, retT>::getRoot()
{
	return (this->root);
}

template <class nodeT, class retT>
void
BinaryTree<nodeT, retT>::setRoot(nodeT* root)
{
	this->root = root;
}

template <class nodeT, class retT>
void 
BinaryTree<nodeT, retT>::traverseAndExec(nodeT* root, retT (*callBack)(nodeT* root))
{
	// Preorder Traversal
	if ( root == NULL )
		return;
	
	callBack(root);
	traverseAndExec(root->getLeft(), callBack);
	traverseAndExec(root->getRight(), callBack);		
}

// Template instantiations required by the compiler to instantiate and compile  the templates against specific arguments
// The compiler doesn't remember what it compiled in different files; hence if it does not see the template definition and
// declaration in the same file; it would not compile the template for that particular argument.

/*** This does not work 

TreeNode<int> nodes[7];
BinaryTree < TreeNode<int>, void> tree;

 **** This does not work ***/


template class TreeNode<int>;
template class BinaryTree <TreeNode<int>, void>;
