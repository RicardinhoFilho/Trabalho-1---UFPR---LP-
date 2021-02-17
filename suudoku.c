/*  Trabalho 1 - Passos para resolver o sudoku
 *  Autor: Ricardo Pinto Giasson Filho
 *  GRR: 20204465
 *  Data: Janeiro 2021
 */
#include <stdio.h>
#define TAMANHO 9
void menu();
void desenha_sudoku();
void valoresAusentesLinha(int linha, int *vetor, int opcao);
void valoresAusentesColuna(int coluna, int *vetor, int opcao);
void valoresAusentesGrupo(int linha, int coluna, int *vetor, int opcao);
void ComparaVetores(int linha, int coluna, int opcao);

void menu()
{
    printf("\n\n                                 MENU\n\n\n");
    printf("1-Valores Ausentes nas Linhas		2-Valores Ausentes nas Colunas\n\n");
    printf("3-Valores Ausentes nos Grupos		4-Valores Possiveis nas Celulas\n\n");
    printf("5-Valores Impossiveis nas Celulas	6-Quantidade de valores possíveis por célula\n\n");
    printf("0-Sair\n\n\n");
}
int jogoInicial[9][9] = {{9, 4, 0, 1, 0, 2, 0, 5, 8},
                         {6, 0, 0, 0, 5, 0, 0, 0, 4},
                         {0, 0, 2, 4, 0, 3, 1, 0, 0},
                         {0, 2, 0, 0, 0, 0, 0, 6, 0},
                         {5, 0, 8, 0, 2, 0, 4, 0, 1},
                         {0, 6, 0, 0, 0, 0, 0, 8, 0},
                         {0, 0, 1, 6, 0, 8, 7, 0, 0},
                         {7, 0, 0, 0, 4, 0, 0, 0, 3},
                         {4, 3, 0, 5, 0, 9, 0, 1, 2}};
void desenha_sudoku()
{
    int i, j;
    printf("\n ----------------------------------\n");
    for (i = 0; i < 9; i++)
    {
        printf("|");
        for (j = 0; j < 9; j++)
        {
            printf(" %d ", jogoInicial[i][j]);
            if ((j + 1) % 3 == 0)
            {
                printf(" | ");
            }
        }

        if ((i + 1) % 3 == 0)
        {
            printf("\n ----------------------------------");
        }

        printf("\n");
    }
}

void valoresAusentesLinha(int linha, int *vetor, int opcao)
{
    int lin, col;
    for (lin = linha; lin < linha + 1; lin++)
    {
        for (col = 0; col < TAMANHO; col++)
        {

            if (jogoInicial[lin][col])
            {
                vetor[jogoInicial[lin][col] - 1] = 0;
            }
        }
    }
    if (opcao == 1)
    {

        for (int i = 0; i < TAMANHO; i++)
        {
            if (vetor[i] > 0)
            {
                printf(" %d \n", vetor[i]);
            }
        }
    }
}
void valoresAusentesColuna(int coluna, int *vetor, int opcao)
{
    int col, lin;
    for (col = coluna; col < coluna + 1; col++)
    {
        for (lin = 0; lin < TAMANHO; lin++)
        {
            if (jogoInicial[lin][coluna])
            {
                vetor[jogoInicial[lin][col] - 1] = 0;
            }
        }
    }
    if (opcao == 2)
    {
        for (int i = 0; i < TAMANHO; i++)
        {
            if (vetor[i] > 0)
            {
                printf(" %d \n", vetor[i]);
            }
        }
    }
}
void valoresAusentesGrupo(int linha, int coluna, int *vetor, int opcao)
{
    int lin, col;
    int aux_lin = ((int)(linha + 3) / 3) * 3;
    int aux_col = ((int)(coluna + 3) / 3) * 3;
    int aux_lin1 = (((int)(linha + 3) / 3) * 3) - 3;
    int aux_col1 = (((int)(coluna + 3) / 3) * 3) - 3;

    for (int i = coluna; i < coluna + 1; i++)
    {

        for (lin = aux_lin1; lin < aux_lin; lin++)
        {
            for (col = aux_col1; col < aux_col; col++)
            {
                if (jogoInicial[lin][col])
                {
                    vetor[(jogoInicial[lin][col]) - 1] = 0;
                }
            }
        }
    }
    if (opcao == 3)
    {
        for (int i = 0; i < TAMANHO; i++)
        {
            if (vetor[i] > 0)
            {
                printf(" %d \n", vetor[i]);
            }
        }
    }
}
void ComparaVetores(int linha, int coluna, int opcao)
{
    int vet_padrao[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (opcao == 4 || opcao == 5 || opcao == 6)
    {
        if (jogoInicial[linha][coluna] == 0)
        {
            int vet_imp[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            int lin, col;
            int cont = 0;
            int vet_linha[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            valoresAusentesLinha(1, vet_linha, opcao);
            int vet_coluna[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            valoresAusentesColuna(coluna, vet_coluna, opcao);
            int vet_grupo[TAMANHO] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            valoresAusentesGrupo(linha, coluna, vet_grupo, opcao);
            for (int i = 0; i < TAMANHO; i++)
            {
                if ((vet_linha[i] && vet_coluna[i] && vet_grupo[i] != 0))
                {
                    vet_imp[i] = 0;
                    cont++;
                }
                else
                {
                    vet_padrao[i] = 0;
                }
            }
            for (int i = 0; i < TAMANHO; i++)
            {
                if (vet_padrao[i] > 0 && opcao == 4)
                {
                    printf(" %d \n", vet_padrao[i]);
                }
                else if (vet_imp[i] > 0 && opcao == 5)
                {
                    printf(" %d \n", vet_imp[i]);
                }
            }
            if (opcao == 6)
            {
                printf("%d possibilidades!\n", cont);
            }
        }
        else
        {
            printf("Esta Célula já está preenchida");
        }
    }
    else if (opcao == 1)
    {
        valoresAusentesLinha(linha, vet_padrao, opcao);
    }
    else if (opcao == 2)
    {
        valoresAusentesColuna(coluna, vet_padrao, opcao);
    }
    else if (opcao == 3)
    {
        valoresAusentesGrupo(linha, coluna, vet_padrao, opcao);
    }
}
int main()
{
    desenha_sudoku();
    int opcao, linha, coluna;
    menu();
    //scanf("%d",&opcao);
    while (opcao != 0)
    {
        desenha_sudoku();
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("Defina a Linha X:");
            scanf("%d", &linha);
            printf("Valores Ausentes da Linha[%d]\n\n", linha);
            ComparaVetores(linha, 0, opcao);
            break;
        case 2:
            printf("Defina a Coluna Y:");
            scanf("%d", &coluna);
            printf("Valores Ausentes da Coluna[%d]\n\n", coluna);
            ComparaVetores(0, coluna, opcao);
            break;
        case 3:
            printf("Defina o Grupo Z:\n");
            scanf("%d", &linha);
            scanf("%d", &coluna);
            printf("Valores Ausentes do Grupo [%d][%d]\n\n", linha, coluna);
            ComparaVetores(linha, coluna, 3);
            break;
        case 4:
            printf("Defina a Célula[linha][coluna]:\n");
            scanf("%d", &linha);
            scanf("%d", &coluna);
            printf("Valores Possiveis da Célula [%d][%d]\n\n", linha, coluna);
            ComparaVetores(linha, coluna, opcao);
            break;
        case 5:
            printf("Defina a Célula [linha][coluna]:\n");
            scanf("%d", &linha);
            scanf("%d", &coluna);
            printf("Valores Impossíveis da Célula [%d][%d]\n\n", linha, coluna);
            ComparaVetores(linha, coluna, opcao);
            break;
        case 6:
            printf("Defina a Célula [linha][coluna]:\n");
            scanf("%d", &linha);
            scanf("%d", &coluna);
            printf("Número de Possibilidades da Célula [%d][%d]\n\n", linha, coluna);
            ComparaVetores(linha, coluna, opcao);
            break;
        default:
            printf("Opção Indisponível!");
            break;
        }
        menu();
        scanf("%d", &opcao);
    }
    return 0;
}