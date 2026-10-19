/*
===============================================================================

	LeetCode 2 - Somar Dois Numeros ( Add Two Numbers )

	-------------------------------------------------------------------
	ENUNCIADO ORIGINAL
	-------------------------------------------------------------------

	Voce recebe duas listas ligadas nao vazias representando dois
	numeros inteiros nao-negativos. Os digitos estao armazenados em
	ordem invertida, e cada um dos nos contem um unico digito. Some
	os dois numeros e retorne a soma como uma lista ligada.

	Voce pode assumir que os dois numeros nao contem nenhum zero a
	esquerda, exceto o proprio numero 0.

	Exemplo 1:

		Entrada: l1 = [2,4,3], l2 = [5,6,4]
		Saida: [7,0,8]
		Explicacao: 342 + 465 = 807.

	Exemplo 2:

		Entrada: l1 = [0], l2 = [0]
		Saida: [0]

	Exemplo 3:

		Entrada: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
		Saida: [8,9,9,9,0,0,0,1]
		Explicacao: 9999999 + 9999 = 10009998.

	Restricoes:

		O numero de nos em cada lista esta no intervalo [1, 100]
		0 <= Node.val <= 9
		E garantido que a lista representa um numero que nao tem
		zeros a esquerda

	-------------------------------------------------------------------
	A PARTIR DAQUI NAO FAZ PARTE DO ENUNCIADO ORIGINAL

	O texto abaixo e material de apoio com exemplos que podem nao
	cobrir tudo que o enunciado acima dita.
	-------------------------------------------------------------------

	POR ONDE COMECAR

	Escreva sua solucao dentro da funcao addTwoNumbers, mais abaixo
	neste arquivo. E a funcao exigida pelo LeetCode.

	O CABECALHO DA FUNCAO addTwoNumbers NAO PODE SER ALTERADO: nome,
	tipo de retorno e parametros devem permanecer exatamente como
	estao. A struct ListNode tambem e fornecida pelo LeetCode e nao
	deve ser alterada. O RESTO DO ARQUIVO PODE SER MODIFICADO a
	vontade: crie funcoes auxiliares, structs, variaveis globais ou
	o que mais precisar.

	AVISO SOBRE OS TESTES

	Os 10 testes deste arquivo NAO SAO EXAUSTIVOS. Passar em todos
	eles nao significa que a solucao esta correta. Para ser
	considerada correta, a solucao precisa ser submetida ao LeetCode
	e passar em TODOS os testes da plataforma.

	Voce pode ( e deve ) adicionar mais casos de teste no main para
	cobrir situacoes que os 10 daqui nao cobrem.

	OBSERVACOES SOBRE O FORMATO

	Os digitos estao em ORDEM INVERTIDA: o primeiro no e a unidade,
	o segundo e a dezena, e assim por diante. A lista [2,4,3]
	representa o numero 342. Isso e uma conveniencia, nao um
	obstaculo: a soma comeca justamente pelas unidades.

	As listas podem ter COMPRIMENTOS DIFERENTES ( ver exemplo 3 ) e
	a soma pode ter um digito A MAIS que a maior delas, quando sobra
	carry no fim.

	Os nos devolvidos devem ser alocados por voce; o LeetCode nao
	reaproveita os nos de entrada.

	c - '0' nao se aplica aqui: o campo val de cada no ja e um int
	de 0 a 9, nao um caractere.

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/*
	Struct fornecida pelo LeetCode.
*/
struct ListNode {
	int					val;
	struct ListNode *	next;
};

/*
====================
addTwoNumbers

	Assinatura exigida pelo LeetCode: NAO ALTERE o cabecalho abaixo
	( nome, tipo de retorno e parametros ). Funcoes auxiliares podem
	ser criadas livremente fora dela.

	Devolve uma nova lista ligada alocada com malloc.
====================
*/
struct ListNode *addTwoNumbers( struct ListNode *l1, struct ListNode *l2 ) {
/* >>> ESCREVA SUA SOLUCAO AQUI DENTRO <<< */

	struct ListNode* l3 = NULL;
	struct ListNode* nodeAtual = NULL;
	int carry = 0;
	
	while ( l1 != NULL || l2 != NULL || carry ) {

		int a = ( l1 != NULL ) ? l1->val : 0;
		int b = ( l2 != NULL ) ? l2->val : 0;
		int sum = a + b + carry;
		carry = 0;
		
		if ( sum > 9 ) {
			carry = 1;
			sum = sum - 10;
		}

		if ( l3 == NULL ) {
			l3 = (struct ListNode*) malloc ( sizeof ( struct ListNode ) );
			nodeAtual = l3;
		} else {
			nodeAtual->next = (struct ListNode*) malloc ( sizeof ( struct ListNode ) );
			nodeAtual = nodeAtual->next;
		}
		nodeAtual->val = sum;
		if ( l1 != NULL ) l1 = l1->next;
		if ( l2 != NULL ) l2 = l2->next;
	}

	nodeAtual->next = NULL;
	return l3;
}

/*
====================
CriarLista

	Monta uma lista ligada a partir de um array de digitos.
====================
*/
static struct ListNode *CriarLista( const int *digitos, int n ) {
	struct ListNode *	cabeca;
	struct ListNode *	cauda;
	struct ListNode *	novo;
	int					i;

	cabeca = NULL;
	cauda = NULL;
	for ( i = 0; i < n; i++ ) {
		novo = (struct ListNode*) malloc( sizeof( struct ListNode ) );
		novo->val = digitos[i];
		novo->next = NULL;
		if ( cabeca == NULL ) {
			cabeca = novo;
		} else {
			cauda->next = novo;
		}
		cauda = novo;
	}
	return cabeca;
}

/*
====================
LiberarLista
====================
*/
static void LiberarLista( struct ListNode *no ) {
	struct ListNode *	prox;

	while ( no != NULL ) {
		prox = no->next;
		free( no );
		no = prox;
	}
}

/*
====================
ImprimirLista
====================
*/
static void ImprimirLista( const struct ListNode *no ) {
	printf( "[" );
	while ( no != NULL ) {
		printf( "%d%s", no->val, no->next != NULL ? "," : "" );
		no = no->next;
	}
	printf( "]" );
}

/*
====================
ImprimirArray
====================
*/
static void ImprimirArray( const int *a, int n ) {
	int		i;

	printf( "[" );
	for ( i = 0; i < n; i++ ) {
		printf( "%d%s", a[i], i + 1 < n ? "," : "" );
	}
	printf( "]" );
}

/*
====================
ListaIgualArray

	Confere valor a valor e tambem o comprimento: sobrar ou faltar
	no conta como erro.
====================
*/
static int ListaIgualArray( const struct ListNode *no, const int *a, int n ) {
	int		i;

	i = 0;
	while ( no != NULL && i < n ) {
		if ( no->val != a[i] ) {
			return 0;
		}
		no = no->next;
		i++;
	}
	return ( no == NULL && i == n );
}

/*
====================
RodarTeste

	Compara o retorno de addTwoNumbers com o resultado esperado
	hard-coded.
====================
*/
static int RodarTeste( int num, const int *a1, int n1, const int *a2, int n2,
					   const int *esperado, int nEsp ) {
	struct ListNode *	l1;
	struct ListNode *	l2;
	struct ListNode *	res;
	int					ok;

	l1 = CriarLista( a1, n1 );
	l2 = CriarLista( a2, n2 );
	res = addTwoNumbers( l1, l2 );

	ok = ListaIgualArray( res, esperado, nEsp );

	printf( "Teste %2d: l1 = ", num );
	ImprimirArray( a1, n1 );
	printf( ", l2 = " );
	ImprimirArray( a2, n2 );
	printf( "\n  esperado = " );
	ImprimirArray( esperado, nEsp );
	printf( "\n  obtido   = " );
	ImprimirLista( res );
	printf( "  ->  %s\n\n", ok ? "OK" : "FALHOU" );

	LiberarLista( res );
	LiberarLista( l1 );
	LiberarLista( l2 );
	return ok;
}

/*
====================
main
====================
*/
int main( void ) {
	int		passou;

	/* Teste 1: exemplo 1 do enunciado - 342 + 465 = 807 */
	int		a1[] = { 2, 4, 3 };
	int		b1[] = { 5, 6, 4 };
	int		e1[] = { 7, 0, 8 };

	/* Teste 2: exemplo 2 do enunciado - zero mais zero */
	int		a2[] = { 0 };
	int		e2[] = { 0 };

	/* Teste 3: exemplo 3 do enunciado - comprimentos diferentes e  */
	/* carry ate o fim: 9999999 + 9999 = 10009998                   */
	int		a3[] = { 9, 9, 9, 9, 9, 9, 9 };
	int		b3[] = { 9, 9, 9, 9 };
	int		e3[] = { 8, 9, 9, 9, 0, 0, 0, 1 };

	/* Teste 4: carry criando um no NOVO no fim - 5 + 5 = 10 */
	int		a4[] = { 5 };
	int		e4[] = { 0, 1 };

	/* Teste 5: carry em cadeia - 99 + 1 = 100 */
	int		a5[] = { 9, 9 };
	int		b5[] = { 1 };
	int		e5[] = { 0, 0, 1 };

	/* Teste 6: lista curta somada a lista longa - 1 + 999 = 1000 */
	int		a6[] = { 1 };
	int		b6[] = { 9, 9, 9 };
	int		e6[] = { 0, 0, 0, 1 };

	/* Teste 7: somar zero preserva o numero - 342 + 0 = 342 */
	int		a7[] = { 2, 4, 3 };
	int		b7[] = { 0 };
	int		e7[] = { 2, 4, 3 };

	/* Teste 8: zero a direita no resultado nao deve ser removido */
	int		a8[] = { 1, 8 };
	int		b8[] = { 0 };
	int		e8[] = { 1, 8 };

	/* Teste 9: um digito com carry - 9 + 9 = 18 */
	int		a9[] = { 9 };
	int		e9[] = { 8, 1 };

	/* Teste 10: sem nenhum carry - 321 + 654 = 975 */
	int		a10[] = { 1, 2, 3 };
	int		b10[] = { 4, 5, 6 };
	int		e10[] = { 5, 7, 9 };

	passou = 0;
	passou += RodarTeste(  1, a1,  3, b1,  3, e1,  3 );
	passou += RodarTeste(  2, a2,  1, a2,  1, e2,  1 );
	passou += RodarTeste(  3, a3,  7, b3,  4, e3,  8 );
	passou += RodarTeste(  4, a4,  1, a4,  1, e4,  2 );
	passou += RodarTeste(  5, a5,  2, b5,  1, e5,  3 );
	passou += RodarTeste(  6, a6,  1, b6,  3, e6,  4 );
	passou += RodarTeste(  7, a7,  3, b7,  1, e7,  3 );
	passou += RodarTeste(  8, a8,  2, b8,  1, e8,  2 );
	passou += RodarTeste(  9, a9,  1, a9,  1, e9,  2 );
	passou += RodarTeste( 10, a10, 3, b10, 3, e10, 3 );

	/* Adicione aqui seus proprios casos de teste, no mesmo formato:
	   passou += RodarTeste( 11, arrayL1, tamL1, arrayL2, tamL2,
							 arrayEsperado, tamEsperado );
	   Lembre de ajustar o total impresso e a condicao do return. */

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	printf( "Lembrete: estes 10 testes NAO sao exaustivos. Submeta ao\n" );
	printf( "LeetCode e passe em todos os testes da plataforma.\n" );
	return passou == 10 ? 0 : 1;
}
