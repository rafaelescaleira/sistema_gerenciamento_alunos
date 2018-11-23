/* * * * * * * * * * * * * * * * * * * * * * * * *
 *                                               *
 * Nome : Rafael Escaleira Ferreira dos Santos.  *
 * Universidade Federal do Mato Grosso do Sul    *
 * Disciplina : Algoritmo e Programação 2	 *
 *                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHAR 100

/* Descrição
 *
 * O trabalho prático de nossa disciplina consiste na implementação de um sistema para gerenciamento 
 * de alunos da disciplina de Algoritmos e Programação II. Cada aluno da disciplina possui armazenadas 
 * as seguintes informações:
 *
 * 	• Nome (cadeia de caracteres que não devem conter acentos e cedilhas);
 * 	• RA (inteiro);
 * 	• Nota da primeira prova obrigatória (P1);
 * 	• Nota da segunda prova obrigatória (P2);
 * 	• Nota do trabalho prático (T);
 * 	• Nota da prova optativa (PO).
 *
 * Todas as notas devem ser representadas usando números em ponto flutuante. A média final MF é
 * calculada de acordo com a seguinte fórmula:
 * 
 * 	• MF = 0,35 * P1 * 0,35 * P2 + 0,3 * T,
 *
 * lembrando que a nota da prova optativa (PO) pode substituir a menor das notas de prova (P1 ou P2),
 * caso seja maior que tal nota. O aluno cuja média final for maior ou igual a 6,0 será considerado aprovado,
 * caso contrário, estará reprovado.
 *
 */

typedef struct _aluno {
	
	char nome [MAX_CHAR];	// Nome (cadeia de caracteres que não devem conter acentos e cedilhas);
	long int ra;			// RA (inteiro);
	double p1;				// Nota da primeira prova obrigatória (P1);
	double p2;				// Nota da segunda prova obrigatória (P2);
	double nota_trabalho;	// Nota do trabalho prático (T);
	double po;				// Nota da prova optativa (PO);

	double media_final;		// MF = 0,35 * P1 * 0,35 * P2 + 0,3 * T;
	bool aprovado;

} tipo_aluno;

/* Estrutura para Lista Duplamente Encadeada */

typedef struct elemento_celula {

	tipo_aluno aluno;
	struct elemento_celula * anterior;
	struct elemento_celula * posterior;

} tipo_elemento_celula;

typedef struct celula {

   int tamanho;
   int aprovados;
   int reprovados;
   struct elemento_celula * inicio;
   struct elemento_celula * fim;

} tipo_celula;

/* 1. Cadastrar um novo aluno:
 *
 * Insere um novo aluno na lista contendo os dados for- necidos como entrada pelo usuário. 
 * O usuário deve fornecer dados para todos os campos do aluno (se a PO não tiver sido realizada,
 * a nota zero deve ser infor- mada);
 *
 */

void cadastrar_um_novo_aluno (tipo_celula * lista_alunos);

/* 2. Buscar aluno:
 * 
 * solicita ao usuário uma cadeia de caracteres e lista os nomes com- pletos, a média final
 * e a situação de todos os alunos cujos nomes casam (total ou parcialmente com a cadeia fornecida).
 * A listagem deve mostrar ao final uma contagem do número de resultados encontrados;
 *
 */

void buscar_aluno (tipo_celula * lista_alunos, char aluno[MAX_CHAR]);

/* 3. Ler arquivo com listagem de alunos:
 *
 * Solicita ao usuário o nome de um arquivo de texto contendo os dados de alunos. 
 * Esse arquivo conterá os dados de, no máximo, um aluno por linha e, em cada linha,
 * todos os dados do aluno deverão ser informados na mesma ordem descrita na descrição
 * da estrutura que define um aluno. Se o aluno não fez PO, o arquivo deve conter a
 * nota zero no local adequado. Ao final do cadastramento, deve-se mostrar na tela uma
 * contagem de quantos alunos foram cadastrados;
 *
 */

void ler_arquivo_com_listagem_de_alunos (tipo_celula * lista_alunos);

/* 4. Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética:
 * 
 * Escreve um arquivo texto contendo os nomes e as médias finais dos alunos
 * aprovados na disciplina, um aluno por linha. Os alunos constantes no arquivo
 * resultante devem estar em ordem alfabética de nome. Ao final do arquivo,
 * deve aparecer a contagem de alunos aprovados. O nome do arquivo de saída
 * deve ser aprovados.txt;
 *
 */

void gerar_arquivo_com_dados_dos_alunos_aprovados (tipo_celula * lista_alunos);

/* 5. Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética:
 * 
 * Escreve um arquivo texto contendo os nomes e as médias finais dos alunos
 * reprovados na disciplina, um aluno por linha. Os alunos constantes no
 * arquivo resultante devem estar em ordem alfabética de nome. Ao final
 * do arquivo, deve aparecer a contagem de alunos reprovados. O nome do
 * arquivo de saída deve ser reprovados.txt;
 *
 */

void gerar_arquivo_com_dados_dos_alunos_reprovados (tipo_celula * lista_alunos);

/* Estrutura Lista Duplamente Encadeada
 *
 * 1. Construção;
 * 2. Inserção em Lista Vazia;
 * 3. Inserção no Início;
 *
 */

tipo_celula * constroi_lista_duplamente_encadeada ();
void insere_lista_vazia_duplamente_encadeada (tipo_celula * lista_alunos, tipo_aluno aluno);
void insere_lista_inicio_duplamente_encadeada (tipo_celula * lista_alunos, tipo_aluno aluno);

/* Criar menu de opções */

int constroi_menu_operacao ();

int main (int argc, char const * argv[]) {

	int operacao;
	char busca_cadeia[MAX_CHAR];
	tipo_celula * lista_alunos;

	lista_alunos = constroi_lista_duplamente_encadeada ();

	while (1) {

		operacao = constroi_menu_operacao ();

		switch (operacao) {

			// 1. Cadastrar um novo aluno
			case 1:

			cadastrar_um_novo_aluno (lista_alunos);
			printf("\n\033[32m *\033[0m Aluno cadastrado com sucesso.\n");

			break;

			// 2. Buscar aluno
			case 2:

			printf (" Informe o nome que deseja buscar: ");
			setbuf (stdin, NULL);
			scanf ("%[^\n]", busca_cadeia);
			printf("\n");
			buscar_aluno (lista_alunos, busca_cadeia);

			break;

			// 3. Ler arquivo com listagem de alunos
			case 3:

			ler_arquivo_com_listagem_de_alunos (lista_alunos);

			break;

			// 4. Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética
			case 4:

			gerar_arquivo_com_dados_dos_alunos_aprovados (lista_alunos);
			printf("\033[32m *\033[0m Arquivo gerado com sucesso.\n");

			break;

			// 5. Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética:
			case 5:

			gerar_arquivo_com_dados_dos_alunos_reprovados (lista_alunos);
			printf("\033[32m *\033[0m Arquivo gerado com sucesso.\n");

			break;

			case 6:

			printf ("\033[31m *\033[0m Execução do programa encerrada.\n\n");

			return 0;

			break;

			default:

			printf ("\033[31m *\033[0m Informe uma operação válida.\n");

			break;

		}

	}
	
	return 0;
	
}

void cadastrar_um_novo_aluno (tipo_celula * lista_alunos) {

	tipo_aluno aluno;

	printf (" Nome: ");
	setbuf (stdin, NULL);
	scanf ("%[^\n]", aluno.nome);

	printf (" RA: ");
	scanf ("%ld", &aluno.ra);

	printf (" Nota P1: ");
	scanf ("%lf", &aluno.p1);

	printf (" Nota P2: ");
	scanf ("%lf", &aluno.p2);

	printf (" Nota do trabalho: ");
	scanf ("%lf", &aluno.nota_trabalho);

	printf (" Nota PO: ");
	scanf ("%lf", &aluno.po);

	aluno.p1 < aluno.p2 ? (aluno.p1 = aluno.po > aluno.p1 ? aluno.po : aluno.p1) : (aluno.p2 = aluno.po > aluno.p2 ? aluno.po : aluno.p2);

	aluno.media_final = (0.35 * aluno.p1) + (0.35 * aluno.p2) + (0.30 * aluno.nota_trabalho);
	aluno.aprovado = aluno.media_final >= 6.0 ? true : false;

	lista_alunos -> tamanho == 0 ? insere_lista_vazia_duplamente_encadeada (lista_alunos, aluno) : insere_lista_inicio_duplamente_encadeada (lista_alunos, aluno);

}

void buscar_aluno (tipo_celula * lista_alunos, char aluno[MAX_CHAR]) {

	int alunos_encontrados, m, n, cont, i, j, k;
	char nome_auxiliar[MAX_CHAR];
	tipo_elemento_celula * percorre;

	alunos_encontrados = 0;
	percorre = lista_alunos -> inicio;
	m = strlen (aluno);

    while (percorre != NULL) {

    	strcpy (nome_auxiliar, percorre -> aluno.nome);
    	n = strlen (nome_auxiliar);

    	if (m <= n) {

    		for (i = 0; i < n; i ++) {

    			cont = 1;

    			for (j = 0, k = i; j < m && k < n; j ++, k ++) {

    				if (nome_auxiliar[k] != aluno[j]) {

    					cont = 0;

    				}

    			}

    			if (cont == 1) {

    				alunos_encontrados ++;
    				percorre -> aluno.media_final >= 6.0 ? (printf (" %s \033[34m%.2lf\033[0m\n", nome_auxiliar, percorre -> aluno.media_final)) : (printf (" %s \033[31m%.2lf\033[0m\n", nome_auxiliar, percorre -> aluno.media_final));
    				i = n;

    			}

    		}

    	}

    	strcpy (nome_auxiliar, "");

    	percorre = percorre -> posterior;

    }

    printf ("\n Total de alunos encontrados: %d\n", alunos_encontrados);

}

void ler_arquivo_com_listagem_de_alunos (tipo_celula * lista_alunos) {

	FILE * arquivo_entrada;
	char * nome_arquivo_entrada, nome_aluno[MAX_CHAR];
	int quantidade_alunos_cadastrados;
	tipo_aluno aluno;

	nome_arquivo_entrada = (char *) malloc (MAX_CHAR * sizeof (char));
	
	printf (" Informe o nome do arquivo (Exemplo: arquivo.text): ");
	setbuf (stdin, NULL);
	scanf ("%[^\n]", nome_arquivo_entrada);

	free (nome_arquivo_entrada);

	arquivo_entrada = fopen (nome_arquivo_entrada, "r");

	if (arquivo_entrada == NULL) {

		printf("\n\033[31m *\033[0m Arquivo vazio.\n");

		return ;

	}

	quantidade_alunos_cadastrados = 0;

	while (fscanf (arquivo_entrada, "%[A-Z a-z]", nome_aluno) != EOF) {

		fscanf (arquivo_entrada, "%ld", &aluno.ra); 
		fscanf (arquivo_entrada, "%lf", &aluno.p1); 
		fscanf (arquivo_entrada, "%lf", &aluno.p2); 
		fscanf (arquivo_entrada, "%lf", &aluno.nota_trabalho);
		fscanf (arquivo_entrada, "%lf\n", &aluno.po);

		strcpy (aluno.nome, nome_aluno);

		aluno.p1 < aluno.p2 ? (aluno.p1 = aluno.po > aluno.p1 ? aluno.po : aluno.p1) : (aluno.p2 = aluno.po > aluno.p2 ? aluno.po : aluno.p2);

		aluno.media_final = (0.35 * aluno.p1) + (0.35 * aluno.p2) + (0.30 * aluno.nota_trabalho);
		aluno.aprovado = aluno.media_final >= 6.0 ? true : false;

		lista_alunos -> tamanho == 0 ? insere_lista_vazia_duplamente_encadeada (lista_alunos, aluno) : insere_lista_inicio_duplamente_encadeada (lista_alunos, aluno);
		quantidade_alunos_cadastrados = quantidade_alunos_cadastrados + 1;

	}

	fclose (arquivo_entrada);

	printf("\n Total de alunos cadastrados: %d\n", quantidade_alunos_cadastrados);

}

void ordenacao_insercao (tipo_aluno * v, int n) {

	int i, j;
	tipo_aluno aluno;

	for (i = 1; i < n; i ++){

		aluno = v[i];

		for (j = i - 1; j >= 0 && strcmp (v[j].nome, aluno.nome) > 0; j --)
			v[j + 1] = v[j];

		v[j + 1] = aluno;

	}

}

void gerar_arquivo_com_dados_dos_alunos_aprovados (tipo_celula * lista_alunos) {

	FILE * arquivo_saida;
	int i;
	tipo_elemento_celula * percorre;
	tipo_aluno * aluno;

	aluno = (tipo_aluno *) malloc (lista_alunos -> aprovados * sizeof (tipo_aluno));

	arquivo_saida = fopen ("aprovados.txt", "w");

    percorre = lista_alunos -> inicio;
    i = 0;

    while (percorre != NULL) {

    	if (percorre -> aluno.aprovado == true) {

    		strcpy (aluno[i].nome, percorre -> aluno.nome);
    		aluno[i].media_final = percorre -> aluno.media_final;
    		i = i + 1;

    	}

    	percorre = percorre -> posterior;

    }

    ordenacao_insercao (aluno, lista_alunos -> aprovados);

    for (i = 0; i < lista_alunos -> aprovados; i ++) {

    	fprintf (arquivo_saida, "%s %.2lf\n", aluno[i].nome, aluno[i].media_final);

    }

    fprintf (arquivo_saida, "Total: %d", lista_alunos -> aprovados);
    fclose (arquivo_saida);
    free (aluno);

}

void gerar_arquivo_com_dados_dos_alunos_reprovados (tipo_celula * lista_alunos) {

	FILE * arquivo_saida;
	int i;
	tipo_elemento_celula * percorre;
	tipo_aluno * aluno;

	aluno = (tipo_aluno *) malloc (lista_alunos -> reprovados * sizeof (tipo_aluno));

	arquivo_saida = fopen ("reprovados.txt", "w");

    percorre = lista_alunos -> inicio;
    i = 0;

    while (percorre != NULL) {

    	if (percorre -> aluno.aprovado == false) {

    		strcpy (aluno[i].nome, percorre -> aluno.nome);
    		aluno[i].media_final = percorre -> aluno.media_final;
    		i = i + 1;

    	}

    	percorre = percorre -> posterior;

    }

    ordenacao_insercao (aluno, lista_alunos -> reprovados);

    for (i = 0; i < lista_alunos -> reprovados; i ++) {

    	fprintf (arquivo_saida, "%s %.2lf\n", aluno[i].nome, aluno[i].media_final);

    }

    fprintf (arquivo_saida, "Total: %d", lista_alunos -> reprovados);
    fclose (arquivo_saida);
    free (aluno);

}

int constroi_menu_operacao () {

	int operacao;

	printf ("\n\t\033[31m Algoritmos e Programação II\033[0m\n\n");

	printf ("\033[31m 1.\033[0m Cadastrar um novo aluno;\n");
	printf ("\033[31m 2.\033[0m Buscar aluno;\n");
	printf ("\033[31m 3.\033[0m Ler arquivo com listagem de alunos;\n");
	printf ("\033[31m 4.\033[0m Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética;\n");
	printf ("\033[31m 5.\033[0m Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética;\n");
	printf ("\033[31m 6.\033[0m Fechar programa;\n\n");

	printf (" Informe o número da operação desejada: \033[31m");
	scanf ("%d", &operacao);
	printf ("\033[0m\n");

	return operacao;

}

tipo_celula * constroi_lista_duplamente_encadeada () {

	tipo_celula * lista_alunos;

	lista_alunos = (tipo_celula *) malloc (sizeof (tipo_celula));
	lista_alunos -> inicio = NULL;
	lista_alunos -> fim = NULL;
	lista_alunos -> tamanho = 0;
	lista_alunos -> aprovados = 0;
	lista_alunos -> reprovados = 0;

	return lista_alunos;

}

void insere_lista_vazia_duplamente_encadeada (tipo_celula * lista_alunos, tipo_aluno aluno) {

	tipo_elemento_celula * novo_aluno;

	novo_aluno = (tipo_elemento_celula *) malloc (sizeof (tipo_elemento_celula));
    novo_aluno -> aluno = aluno;

    novo_aluno -> aluno.aprovado == true ? (lista_alunos -> aprovados ++) : (lista_alunos -> reprovados ++);

    novo_aluno -> anterior = lista_alunos -> inicio;
    novo_aluno -> posterior = lista_alunos -> fim;
    lista_alunos -> inicio = novo_aluno;
    lista_alunos -> fim = novo_aluno;
    lista_alunos -> tamanho = lista_alunos -> tamanho + 1;


}

void insere_lista_inicio_duplamente_encadeada (tipo_celula * lista_alunos, tipo_aluno aluno) {

	tipo_elemento_celula * novo_aluno;

    novo_aluno = (tipo_elemento_celula *) malloc (sizeof (tipo_elemento_celula));
    novo_aluno -> aluno = aluno;

    novo_aluno -> aluno.aprovado == true ? (lista_alunos -> aprovados ++) : (lista_alunos -> reprovados ++);

    novo_aluno -> anterior = NULL;
    novo_aluno -> posterior = lista_alunos -> inicio;
    lista_alunos -> inicio -> anterior = novo_aluno;
    lista_alunos -> inicio = novo_aluno;
    lista_alunos -> tamanho = lista_alunos -> tamanho + 1;

}
