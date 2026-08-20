#include "binary_trees.h"

/**
 * tree_depth - gets the depth of the leftmost leaf
 * @tree: pointer to the root node
 *
 * Return: depth of the leftmost leaf
 */
size_t tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	return (depth);
}

/**
 * check_perfect - checks if a tree is perfect
 * @tree: pointer to the current node
 * @depth: expected leaf depth
 * @level: current level
 *
 * Return: 1 if perfect, otherwise 0
 */
int check_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_perfect(tree->left, depth, level + 1) &&
		check_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = tree_depth(tree);

	return (check_perfect(tree, depth, 0));
}
