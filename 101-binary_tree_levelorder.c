#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree.
 * @tree: Tree to measure.
 * Return: Height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((left > right) ? left : right);
	}
}

/**
 * binary_tree_depth - Calculate the depth of a node from the root.
 * @tree: Node to calculate depth for.
 * Return: 0 if it is the root, or the depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Creates a linked list node to store
 * a node at a specific depth.
 * @head: Pointer to the head of the linked list.
 * @tree: Node to store.
 * @level: Depth of the node to store.
 * Return: Nothing.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *newnode, *auxnode;

	newnode = malloc(sizeof(link_t));
	if (newnode == NULL)
	{
		return;
	}
	newnode->n = level;
	newnode->node = tree;
	if (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
	}
	else
	{
		auxnode = *head;
		while (auxnode->next != NULL)
		{
			auxnode = auxnode->next;
		}
		newnode->next = NULL;
		auxnode->next = newnode;
	}
}

/**
 * recursion - Traverses the entire tree and store
 * each node in linked_node function.
 * @head: Pointer to the head of the linked list.
 * @tree: Node to check.
 * Return: Nothing; it affects the pointer.
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Prints the nodes in a level-order traversal.
 * @tree: Root node.
 * @func: Function to apply to each node.
 * Return: Nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *auxnode;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			auxnode = head;
			while (auxnode != NULL)
			{
				if (count == auxnode->n)
				{
					func(auxnode->node->n);
				}
				auxnode = auxnode->next;
			}
			count++;
		}
		while (head != NULL)
		{
			auxnode = head;
			head = head->next;
			free(auxnode);
		}
	}
}

