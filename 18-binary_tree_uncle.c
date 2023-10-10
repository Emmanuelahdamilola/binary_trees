#include "binary_trees.h"

binary_tree_t *sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: Node to find the uncle for.
 *
 * Return: Pointer to the uncle node, or NULL if there is no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);
	return (sibling(node->parent));
}

/**
 * sibling - Gets the sibling node of a given node.
 * @node: Node to find the sibling for.
 *
 * Return: Pointer to the sibling of the node,
 * or NULL if there is no sibling.
 */
binary_tree_t *sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
