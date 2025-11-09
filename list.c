#include "list.h"
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9 

List init_list(void) {
    return NULL;
}

int is_empty(List L) {
    return (L == NULL);
}

Node* create_node(double val) {
    Node *p = (Node*) malloc(sizeof(Node));
    if (!p) {
        perror("malloc");
        return NULL;
    }
    p->value = val;
    p->count = 1;
    p->next = NULL;
    return p;
}

void display_list(List L) {
    if (is_empty(L)) {
        printf("List is empty.\n");
        return;
    }
    Node *p = L;
    printf("List contents:\n");
    while (p) {
        printf("Value = %.6g  |  Count = %d\n", p->value, p->count);
        p = p->next;
    }
}

int count_element(List L) {
    int sum = 0;
    Node *p = L;
    while (p) {
        sum += p->count;
        p = p->next;
    }
    return sum;
}
int is_in(List L, double x) {
    Node *p = L;
    while (p) {
        if (fabs(p->value - x) < EPS) return p->count;
        p = p->next;
    }
    return 0;
}


List add_element(List L, double y) {
    if (L == NULL) {
       
        return create_node(y);
    }

    Node *p = L;
    Node *prev = NULL;
    while (p) {
        if (fabs(p->value - y) < EPS) {
            p->count += 1;
            return L;
        }
        prev = p;
        p = p->next;
    }
    
    Node *newn = create_node(y);
    if (prev) prev->next = newn;
    return L;
}

List remove_element(List L, double z) {
    Node *p = L;
    Node *prev = NULL;
    while (p) {
        if (fabs(p->value - z) < EPS) {
            if (p->count > 1) {
                p->count -= 1;
            } else {
                if (prev == NULL) {
                    List newHead = p->next;
                    free(p);
                    return newHead;
                } else {
                    prev->next = p->next;
                    free(p);
                }
            }
            return L;
        }
        prev = p;
        p = p->next;
    }
  
    return L;
}