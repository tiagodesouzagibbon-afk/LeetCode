#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/*
=====================================================================================================================

        Funções do teste

=====================================================================================================================
*/

struct ListNode* CreateNode ( int val ) {

    struct ListNode* NewNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    NewNode->next = NULL;
    NewNode->val = val;

    return NewNode;
}

struct ListNode* CreateList ( int* arr, int size ) {

    int i;
    struct ListNode* head = CreateNode ( arr[0] );
    struct ListNode* last = head;

    for ( i = 1; i < size; i++ ) {
        last->next = CreateNode ( arr[i] );
        last = last->next;
    }

    return head;
}

void FreeList ( struct ListNode* n ) {
    if ( n->next != NULL ) FreeList ( n->next );
    free ( n );
}

int CompListaArray ( struct ListNode* head, int* arr ) {

    int i = 0;
    while ( head != NULL ) {
        if ( head->val != arr[i] ) {
            return 0;
        }
        i++;
        head = head->next;
    }

    return 1;
}

/*
=====================================================================================================================

        Funções do LeetCode

=====================================================================================================================
*/
int CompStruct ( const void *a, const void *b ) {
    struct ListNode* N1 = *(struct ListNode**)a;
    struct ListNode* N2 = *(struct ListNode**)b;

    return N1->val - N2->val;
}

struct ListNode* sortList(struct ListNode* head) {
    if ( head == NULL ) return NULL;

    int size = 0;
    struct ListNode* temp = head;
    while ( temp != NULL ) {
        temp = temp->next;
        size++;
    }

    temp = head;
    struct ListNode* arr[size];
    int i = 0;
    while ( temp != NULL ) {
        arr[i] = temp;
        temp = temp->next;
        i++;
    }

    qsort( arr, size, sizeof(struct ListNode*), CompStruct );

    head = arr[0];
    struct ListNode* last = head;
    for ( i = 1; i < size; i++ ) {
        last->next = arr[i];
        last = last->next;
    }
    last->next = NULL;

    return head;
}

int main() {

    int t1[4] = {4,2,1,3};
    int r1[4] = {1,2,3,4};
    int t2[5] = {-1,5,3,4,0};
    int r2[5] = {-1,0,3,4,5};
    
    int correto = 0;

    struct ListNode* head = CreateList ( t1, 4 );
    head = sortList( head );
    correto += CompListaArray ( head, r1 );
    FreeList(head);

    head = CreateList ( t2, 5 );
    head = sortList( head );
    correto += CompListaArray ( head, r2 );
    FreeList(head);

    correto += ( sortList ( NULL ) == NULL ); // terceiro testcase do leetcode

    printf("%d/3 testes corretos.", correto);

    return 0;
}