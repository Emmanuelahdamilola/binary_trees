#include "binary_trees.h"
/**
 * tree_is_perfect - Checks if a binary tree is perfect.
 * A perfect binary tree has the same number of levels in the left and right
 * subtrees, and each node has either 0 or 2 children.
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: The height of the tree if it is perfect, 0 otherwise.
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree || (!tree->left && !tree->right))
		return (1);
	if (tree->left && tree->right)
	{
		left_height = tree_is_perfect(tree->left);
		right_height = tree_is_perfect(tree->right);
		if (left_height == right_height)
			return (1 + left_height);
	}

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root of the binary tree.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_is_perfect(tree) != 0);
}
