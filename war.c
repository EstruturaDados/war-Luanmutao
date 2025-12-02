#include <stdio.h>
#include <string.h>

// Definindo uma constante para o número fixo de territórios
#define MAX_TERRITORIOS 5

/**
 * @brief Estrutura que representa um Território no jogo WAR.
 * * Conceitos: struct, Vetor estático.
 * nome: Nome completo do território.
 * cor: Cor do exército que o ocupa.
 * tropas: Quantidade de unidades militares.
 */
struct Territorio {
    // Tamanho: 30 (máx 29 caracteres + '\0')
    char nome[30]; 
    // Tamanho: 10 (máx 9 caracteres + '\0')
    char cor[10];  
    int tropas;
};

// Função principal do programa
int main() {
    // Declaração do Vetor Estático de Structs
    // Armazena 5 elementos do tipo Territorio.
    struct Territorio mapa[MAX_TERRITORIOS];
    
    // Variável de controle para os laços (índice)
    int i;
    
    printf("================================================\n");
    printf("  ⚔️ DESAFIO WAR ESTRUTURADO - NÍVEL NOVATO ⚔️\n");
    printf("================================================\n");
    printf("Início do Cadastro de %d Territórios.\n\n", MAX_TERRITORIOS);

    // 1. Leitura de Dados (Cadastro)
    // Utiliza um laço 'for' para preencher os dados dos 5 territórios.
    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- TERRITÓRIO %d de %d ---\n", i + 1, MAX_TERRITORIOS);

        // A. Leitura do NOME (Utilizando fgets para nomes com espaços)
        printf("Digite o NOME do Território (max 29 chars): ");
        // fgets lê a linha inteira, incluindo o '\n' final.
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        // strcspn remove o '\n' que o fgets adiciona ao final da string.
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = 0; 

        // B. Leitura da COR (Utilizando fgets)
        printf("Digite a COR do Exército (max 9 chars): ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = 0;

        // C. Leitura do NÚMERO DE TROPAS (Utilizando scanf)
        printf("Digite o Número de TROPAS: ");
        scanf("%d", &mapa[i].tropas);
        
        // Limpar o buffer do teclado (stdin) após o scanf. 
        // Isso é crucial para que o próximo 'fgets' funcione corretamente.
        while (getchar() != '\n');
        
        printf("\n");
    }

    // ---
    
    // 2. Impressão Organizada dos Dados (Saída)
    // Exibe o estado atual do mapa.
    printf("================================================\n");
    printf("         ESTADO ATUAL DO MAPA (Territórios)\n");
    printf("================================================\n");

    for (i = 0; i < MAX_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome:   %s\n", mapa[i].nome);
        printf("  Cor:    %s\n", mapa[i].cor);
        printf("  Tropas: %d\n", mapa[i].tropas);
        
        if (i < MAX_TERRITORIOS - 1) {
            printf("--------------------------------\n");
        }
    }
    
    printf("================================================\n");
    
    return 0; // Fim do programa.
}