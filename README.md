Sistema de Gerenciamento de Alunos de Algoritmos e Programação II
=================================================================

![License](https://img.shields.io/github/license/rafaelescaleira/sistema_gerenciamento_alunos.svg)

  Sistema para gerenciamento de alunos da disciplina de Algoritmos e Programação II.

Descrição
---------

  Cada aluno da disciplina possui armazenadas as seguintes informações:
  
* Nome (cadeia de caracteres que não devem conter acentos e cedilhas); 
* RA (inteiro);
* Nota da primeira prova obrigatória (P1);
* Nota da segunda prova obrigatória (P2);
* Nota do trabalho prático (T); 
* Nota da prova optativa (PO);

  Todas as notas são representadas usando números em ponto flutuante. A média final MF é calculada de acordo com a seguinte fórmula:
  
`` MF = 0,35 * P1 * 0,35 * P2 + 0,3 * T ``

  A nota da prova optativa (PO) pode substituir a menor das notas de prova (P1 ou P2), caso seja maior que tal nota. O aluno cuja média final for maior ou igual a 6,0 será considerado aprovado, caso contrário, estará reprovado.
  Durante a execução do programa, é utilizada uma lista duplamente encadeada de alunos. Sua aplicação fornece um menu com as seguintes opções:
  
  1. Cadastrar um novo aluno: insere um novo aluno na lista contendo os dados fornecidos como entrada pelo usuário. O usuário deve fornecer dados para todos os campos do aluno (se a PO não tiver sido realizada, a nota zero deve ser informada);
  2. Buscar aluno: solicita ao usuário uma cadeia de caracteres e lista os nomes completos, a média final e a situação de todos os alunos cujos nomes casam (total ou parcialmente com a cadeia fornecida). A listagem mostra ao final uma
contagem do número de resultados encontrados;
  3. Ler arquivo com listagem de alunos: solicita ao usuário o nome de um arquivo de texto contendo os dados de alunos. Esse arquivo conterá os dados de, no máximo, um aluno por linha e, em cada linha, todos os dados do aluno deverão ser informados na mesma ordem descrita na descrição da estrutura que define um aluno. Se o aluno não fez PO, o arquivo deve conter a nota zero no local adequado. Ao final do cadastramento, mostra na tela uma contagem de quantos alunos foram cadastrados;
  4. Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabética: escreve um arquivo texto contendo os nomes e as médias finais dos alunos aprovados na disciplina, um aluno por linha. Os alunos constantes no arquivo resultante estão em ordem alfabética de nome. Ao final do arquivo, aparece a contagem de alunos aprovados. O nome do arquivo de saída é aprovados.txt;
  5. Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética: escreve um arquivo texto contendo os nomes e as médias finais dos alunos reprovados na disciplina, um aluno por linha. Os alunos constantes no arquivo resultante estão em ordem alfabética de nome. Ao final do arquivo, aparece a contagem de alunos reprovados. O nome do arquivo de saída é reprovados.txt;
  6. Fechar programa: encerra a execução do programa.

Execução
--------

  A execução do programa inicia mostrando o menu de opções. O usuário pode escolher a qualquer momento uma das opções e, baseado na escolha realizada, o sistema realiza a atividade pedida.
  Os cadastros de novos alunos, tanto individualmente quanto por arquivo, devem fornecer dados para todos os campos do aluno em questão.
  A busca mostra na tela os dados descritos na seção anterior, esperar o usuário digitar *ENTER* e, então, mostra o menu novamente.

Formato do Arquivo de Entrada
-----------------------------

  Os arquivos de entrada para as opções que envolvem leitura de arquivo possuem uma linha para cada aluno a ser cadastrado. Cada linha possui dados para todos os campos do tipo de aluno em questão. Os campos que devem ser considerados são apenas os descritos na descrição e na mesma ordem da descrição.

Formato do Arquivo de Saída
---------------------------

  Os arquivos de saída para as opções que envolvem escrita em arquivo devem pos- suir uma linha por aluno. Cada linha possui dados para todos os campos do tipo de aluno sendo considerado. Os campos que devem ser escritos são apenas os descritos na descrição e na mesma ordem da descrição. Ao final deve aparecer a linha com a contagem seguindo o formato:
`` Total: cont ``
na qual cont é o número de alunos aprovados ou reprovados, de acordo com a opção escolhida.

Especificações
--------------

* No momento de teste dos programas, os arquivos de entrada serão armazenados dentro da mesma pasta dos arquivos fonte, mesmo local onde os de saída serão criados.

Instruções para Compilação
--------------------------
Para compilar `` sistema_gerenciamento_alunos.c `` :

* `` ~$ gcc sistema_gerenciamento_alunos.c -Wall -std=c99 -pedantic -o sistema_gerenciamento_alunos ``

Instruções para Execução
------------------------
Para executar o arquivo já compilado com `` sistema_gerenciamento_alunos.c `` :

* `` ~$ ./sistema_gerenciamento_alunos ``

Execução do Programa
--------------------
![grab-landing-page](https://j.gifs.com/yrZQVz.gif)
