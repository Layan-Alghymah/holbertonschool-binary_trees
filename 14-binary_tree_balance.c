#include "binary_trees.h"

/**
 * tree_height - measures the height of a subtree
 * @tree: pointer to the root of the subtree
 *
 * Return: height of the subtree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = (int)tree_height(tree->left);
	right = (int)tree_height(tree->right);

	return (left - right);
}
