#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node* CriarNode(int val){

    Node *Novo = (Node*)malloc(sizeof(Node));
    Novo->left = NULL;
    Novo->right = NULL;
    Novo->val = val;

    return Novo;
}

// Cria arvore pré determinada pra testar o exercicio
Node* CriarArvore(){

    Node* Cabeca = CriarNode(5);
    Cabeca->left = CriarNode(3);
    Cabeca->left->left = CriarNode(0);
    Cabeca->left->right = CriarNode(4);
    Cabeca->right = CriarNode(9);
    Cabeca->right->left = CriarNode(7);
    Cabeca->right->right = CriarNode(17);

    return Cabeca;
}

void FreeArvore(Node *raiz){

    if (raiz->left != NULL){
        FreeArvore(raiz->left);
    }
    if (raiz->right != NULL){
        FreeArvore(raiz->right);
    }
    free(raiz);

}

Node* searchBST(Node* root, int val) {
    
    if ( root->val == val ) {
        return root;
    }
    if ( root->left != NULL ) {
        Node* temp = searchBST(root->left, val);
        if ( temp != NULL) return temp;
    }
    if ( root->right != NULL ) {
        Node* temp = searchBST(root->right, val);
        if ( temp != NULL) return temp;
    }

    return NULL;
}

int main(){

    Node *Raiz = CriarArvore();
    
    Node *SubArv = searchBST(Raiz,7);

    if ( SubArv != NULL ) {
        printf("%d", SubArv->val);
    } else {
        printf("NULL");
    }

    FreeArvore(Raiz);

    return 0;
}