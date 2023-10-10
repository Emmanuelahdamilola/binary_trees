#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of non-leaf nodes in a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The number of non-leaf nodes in the binary tree, 0 if the tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);
	if (tree->left || tree->right)
		nodes ++;
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	return (nodes);
}
