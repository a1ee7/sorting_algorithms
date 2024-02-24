#include <stdio.h>

/* Structure for a doubly linked list node */

typedef struct listint {
    int n;
    struct listint *prev;
    struct listint *next;
} listint_t;


/* insertion_sort_list - takes pointer
 * to a doubly linked list as input
 * @*list: the pointer
 */

void insertion_sort_list(listint_t **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL) {
        return;
    }

    listint_t *current = (*list)->next;

    while (current != NULL) {
        listint_t *temp = current->next; // Save the next node to be processed
        listint_t *check = current->prev; // Start checking from the previous node

        while (check != NULL && check->n > current->n) {
            check = check->prev;
        }

        if (check == NULL) {
            // If the current node is already in the correct position, move to the next node
            current = temp;
        } else {
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *list = current->next;
            }

            current->prev = check;
            current->next = check->next;

            if (check->next != NULL) {
                check->next->prev = current;
            }
            check->next = current;

            if (check == NULL) {
                *list = current;
            }

            // Print the list after each swap
            listint_t *print_node = *list;
            while (print_node != NULL) {
                printf("%d ", print_node->n);
                print_node = print_node->next;
            }
            printf("\n");

            current = temp; // Move to the next node
        }
    }
}

