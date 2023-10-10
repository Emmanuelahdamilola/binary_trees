#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is a full binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is a full binary tree, 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	return (0);
}
