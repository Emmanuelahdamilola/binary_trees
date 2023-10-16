#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor
 * of two nodes in a binary tree.
 * @first: First node.
 * @second: Second node.
 * Return: Pointer to the lowest common ancestor node,
 * or NULL if none is found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor;
    
	/* Check if either of the input nodes is NULL */
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	/* Check if the nodes are the same, in which
	 * case either can be returned as the ancestor
	 */
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	/* Initialize temporary pointers to traverse up
	 * the tree from both nodes
	 */
	ancestor = (binary_tree_t *)first;
	while (ancestor)
	{
		binary_tree_t *temp = (binary_tree_t *)second;
		while (temp)
		{
			if (ancestor == temp)
			{
				return ancestor; /* Common ancestor found */
			}
			temp = temp->parent;
		}
		ancestor = ancestor->parent;
	}

	return NULL;  /* No common ancestor found */
}

