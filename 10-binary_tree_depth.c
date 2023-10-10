#include "binary_trees.h"

/**
 * binary_tree_depth - Computes the depth of a node in a binary tree.
 * @tree: Pointer to the node for which to calculate the depth.
 *
 * Return: The depth of the node, 0 if the node is NULL or at the root.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth += 1 + binary_tree_depth(tree->parent);
	return (depth);
}
