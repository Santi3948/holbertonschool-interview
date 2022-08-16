#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the tree to traverse
 * Return: 1 if the tree it's perfect. otherwise, returns 0
 */

int binary_tree_is_perfect(const heap_t *tree)
{
	int k = 1;

	if (!tree)
		return (0);
	if (tree->left && tree->right)
	{
		if ((tree->left->left && tree->left->right) &&
		    (!tree->right->left && !tree->right->right))
			return (0);
		if ((!tree->left->left && !tree->left->right) &&
		    (tree->right->left && tree->right->right))
			return (0);
		k *= binary_tree_is_perfect(tree->left);
		k *= binary_tree_is_perfect(tree->right);
		return (k);
	}
	if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: the tree to traverse
 * Return: the height or null if !tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left += binary_tree_height(tree->left) + 1;
	if (tree->right)
		right += binary_tree_height(tree->right) + 1;


	if (left >= right)
		return (left);
	else
		return (right);
}
/**
 * change_root - function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heaps
 * Return: a pointer to the inserted node, or NULL on failure
 **/
 heap_t *change_root(heap_t **root)
 {
	heap_t *aux = NULL;
	heap_t *aux2 = NULL;
	heap_t *papa = NULL;
	heap_t *abuelo = NULL;

	printf("aaaaaaaaaaaaaa\n");
	if (root && *root)
	{
		printf("asassaaasasasasas\n");
		papa = (*root)->parent;
		if (papa)
		{
			abuelo = papa->parent;
			printf("viejaaaaa\n");
		}
		while (root && *root && papa)
		{
			printf("entro\n");
			aux2 = malloc(sizeof(heap_t));
			if (!aux2)
			{
				return (NULL);
			}
			aux2 = papa;
			if (abuelo)
			{
				if (abuelo->right == papa)
				{
					abuelo->right = (*root);
				}
				else if (abuelo->left == papa)
				{
					abuelo->left = (*root);
				}
				papa = abuelo;
				printf("bananannanana\n");
			}
			else
			{
				printf("%dwwwqqqqwww\n", papa->n);
				printf("kheleches\n");
				papa = NULL;
			}
			printf("aaaaasheeasda\n");
			aux2->parent = (*root);
			printf("vocemacaco\n");
			aux = malloc(sizeof(heap_t));
			if (!aux)
			{
				return (NULL);
			}
			aux->right = (*root)->right;
			aux->left = (*root)->left;
			printf("popopopopo\n");
			if(aux2->right == (*root))
			{
				(*root)->right = aux2;
				(*root)->left = aux2->left;
			}
			else {
				(*root)->left = aux2;
				(*root)->right = aux2->right;
			}
			printf("pappapapappapapa\n");
			aux2->right = aux->right;
			aux2->left = aux->left;
			printf("pipippipipipipippipipi\n");
			printf("%dzxzxzzx\n", (*root)->n);
			binary_tree_print((*root));
			printf("ioioioioioioioio\n");
		}
		printf("papopepo\n");
		return (NULL);
	}
	return (NULL);
 }
/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 **/
 heap_t *heap_insert(heap_t **root, int value)
 {
	if (!(*root))
	{
		*root = binary_tree_node(*root, value);
		printf("oaaaa\n");
		return (*root);
	}
	printf("jajajajjaja\n");
	if (!(*root)->left || binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if (!(*root)->left)
		{
			(*root)->left = binary_tree_node(*root, value);
			printf("hoalkease\n");
			return (change_root(&(*root)->left));
		}
		return (heap_insert(&(*root)->left, value));
	}
	else if (!(*root)->right)
	{
		(*root)->right = binary_tree_node(*root, value);
		return (change_root(&(*root)->right));
	}
	return (heap_insert(&(*root)->right, value));
 }