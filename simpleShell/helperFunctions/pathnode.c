#include "main.h"

typedef struct node {
    char *dir;
    struct node *next;
} node_t;

node_t *build_path_list() {
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");
    node_t *head = NULL;
    while (dir != NULL) {
        node_t *new_node = malloc(sizeof(node_t));
        
	if (new_node == NULL)
	{
		perror("Error: Failed to allocate memory");
		exit(1);
	}

	new_node->dir = malloc(_strlen(dir) + 1);

	if (new_node->dir == NULL)
	{
		perror("Error: Failed to allocated memory");
		exit(1);
	}

        _strcpy(new_node->dir, dir);

	new_node->next = head;
        head = new_node;
        dir = strtok(NULL, ":");
    }
    return head;
}
