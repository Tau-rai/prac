#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
	char *dir;
	struct node *next;
} node_t;
void free_path_list(node_t *head);
node_t *build_path_list();

int main() {
	// Test the build_path_list function
	node_t *path_list = build_path_list();
	node_t *current = path_list;

	printf("PATH List:\n");
	while (current != NULL) {
		printf("%s\n", current->dir);
		current = current->next;
	}

	// Free the path_list to avoid memory leaks
	free_path_list(path_list);

	return 0;
}

// Define a function to free the list
void free_path_list(node_t *head) {
	while (head != NULL) {
		node_t *temp = head;
		head = head->next;
		free(temp->dir); // Free the memory allocated for dir
		free(temp);
	}
}
