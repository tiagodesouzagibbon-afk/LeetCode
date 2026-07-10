#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* NextLargerNodes( struct ListNode* head, int* returnSize ) {
    
    int i = 1; // Tamanho de no minimo 1 (head)
    struct ListNode* currentNode = head;

    struct ListNode* nextNode = currentNode->next;
    while ( nextNode != NULL ) {
        nextNode = nextNode->next;
        i++; // Começa a somar a partir do Head -> next
    }

    int* answer = (int*)malloc(sizeof(int)*i);
    *returnSize = i;
    i = 0;

    while ( currentNode != NULL ) {

        nextNode = currentNode->next;

        answer[i] = 0;
        
        while ( nextNode != NULL ) {
            if ( nextNode->val > currentNode->val ) {
                answer[i] = nextNode->val;
                break;
            }
            nextNode = nextNode->next;
        }

        currentNode = currentNode->next;
        i++;
    }

    return answer;
}

void Insert( struct ListNode* head, int val ){

    struct ListNode* Prox = head;
    while ( Prox->next != NULL ) {
        Prox = Prox->next;
    }
    
    struct ListNode* New = (struct ListNode*)malloc(sizeof(struct ListNode));
    New->next = NULL;
    New->val = val;

    Prox->next = New;
}

void FreeList( struct ListNode* head ){

    struct ListNode* temp;
    head = head->next; // head não foi criada com malloc, não precisa usar free()

    while ( head != NULL ) {
        temp = head;
        head = head->next;
        free(temp);
    }

}

int main(){

    struct ListNode head;
    head.next = NULL;

    int testArr[] = {2,7,4,3,5};
    head.val = testArr[0];
    int tamanho = sizeof(testArr)/sizeof(int);

    for ( int i = 1; i < tamanho; i++ ) {
        Insert(&head, testArr[i]);
    }
    int returnSize;

    int* answer = NextLargerNodes( &head, &returnSize );

    printf("Output = [");
    for ( int i = 0; i < returnSize; i++ ) {
        printf("%d", answer[i]);
        if ( i != returnSize - 1 ) printf( "," );
    }
    printf("]");

    FreeList(&head);
    free(answer);
    return 0;
}