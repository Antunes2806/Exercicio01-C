/*
 * Nome: Ana Julia Antunes Cardoso
 * RA: 0040962523038
 * Exercício 01 - Contagem de ocorrências de caractere em arquivo texto
 */

#include <stdio.h>

#define SUCESSO 0
#define ERRO_ARQUIVO -1

/*
 * Função:
 * Recebe o nome do arquivo e o caractere a ser pesquisado.
 * Retorna:
 * - Quantidade de ocorrências encontradas.
 * - ERRO_ARQUIVO caso o arquivo não possa ser aberto.
 */
int contarOcorrencias(const char *nomeArquivo, char caractere)
{
    FILE *arquivo;
    int contador = 0;
    int caractereLido;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        return ERRO_ARQUIVO;
    }

    while ((caractereLido = fgetc(arquivo)) != EOF)
    {
        if (caractereLido == caractere)
        {
            contador++;
        }
    }

    fclose(arquivo);

    return contador;
}

int main()
{
    char nomeArquivo[256];
    char caracterePesquisa;
    int resultado;

    printf("========================================\n");
    printf(" CONTADOR DE OCORRENCIAS EM ARQUIVO\n");
    printf("========================================\n\n");

    printf("Informe o nome do arquivo: ");
    scanf("%255s", nomeArquivo);

    printf("Informe o caractere para pesquisa: ");
    scanf(" %c", &caracterePesquisa);

    resultado = contarOcorrencias(nomeArquivo, caracterePesquisa);

    if (resultado == ERRO_ARQUIVO)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo '%s'.\n",
               nomeArquivo);
        return 1;
    }

    printf("\nResultado da pesquisa\n");
    printf("----------------------\n");
    printf("Caractere pesquisado : %c\n", caracterePesquisa);
    printf("Ocorrencias encontradas: %d\n", resultado);

    return SUCESSO;
}