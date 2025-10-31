#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[50];
    char estado[30];
    char codigo[8];
    unsigned long int populacao;3 - PIB (bilhões)\n");
    if (excluir_for != 4) printf("  4 - Pontos Turísticos\n");
    if (excluir_for != 5) printf("  5 - Densidade Demográfica\n");
    if (excluir_for != 6) printf("  6 - PIB per Capita\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &opc);
    if (opc < 1 || opc > 6 || opc == excluir_for) return 0;
    return opc;
}
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

void calcular_derived(Carta *c) {
    c->densidade = (c->area > 0) ? (float)c->populacao / c->area : 0;
    c->pib_per_capita = (c->populacao > 0) ? (c->pib * 1000000000.0f) / (float)c->populacao : 0;
}

void print_humanized_ulong(unsigned long int num) {
    if (num >= 1000000000UL)
        printf("%lu.%03lu.%03lu.%03lu", num/1000000000UL, (num/1000000UL)%1000, (num/1000UL)%1000, num%1000);
    else if (num >= 1000000UL)
        printf("%lu.%03lu.%03lu", num/1000000UL, (num/1000UL)%1000, num%1000);
    else if (num >= 1000UL)
        printf("%lu.%03lu", num/1000UL, num%1000);
    else
        printf("%lu", num);
}

int mostrar_menu(int excluir_for) {
    int opc = 0;
    printf("\nEscolha um atributo para comparar:\n");
    if (excluir_for != 1) printf("  1 - População\n");
    if (excluir_for != 2) printf("  2 - Área (km²)\n");
    if (excluir_for != 3) printf("  

float obter_valor(const Carta *c, int atributo) {
    switch (atributo) {
        case 1: return (float)c->populacao;
        case 2: return c->area;
        case 3: return c->pib;
        case 4: return (float)c->pontos_turisticos;
        case 5: return c->densidade;
        case 6: return c->pib_per_capita;
        default: return 0.0f;
    }
}

const char* nome_atributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área (km²)";
        case 3: return "PIB (bilhões)";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica (hab/km²)";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    srand(time(NULL));

    Carta paises[20] = {
        {"Brasil", "América do Sul", "BR01", 214000000UL, 8516000.0f, 2089.0f, 30},
        {"Japão", "Ásia", "JP01", 125800000UL, 377975.0f, 4230.0f, 20},
        {"Estados Unidos", "América do Norte", "US01", 331000000UL, 9834000.0f, 25000.0f, 40},
        {"China", "Ásia", "CN01", 1410000000UL, 9597000.0f, 17700.0f, 25},
        {"Índia", "Ásia", "IN01", 1393000000UL, 3287000.0f, 3170.0f, 15},
        {"Alemanha", "Europa", "DE01", 83000000UL, 357000.0f, 4200.0f, 22},
        {"Reino Unido", "Europa", "UK01", 67000000UL, 243000.0f, 3800.0f, 25},
        {"França", "Europa", "FR01", 65000000UL, 551000.0f, 3700.0f, 27},
        {"Itália", "Europa", "IT01", 59000000UL, 301000.0f, 3300.0f, 30},
        {"Canadá", "América do Norte", "CA01", 39000000UL, 9985000.0f, 2200.0f, 18},
        {"Austrália", "Oceania", "AU01", 26000000UL, 7692000.0f, 1800.0f, 15},
        {"Rússia", "Europa/Ásia", "RU01", 144000000UL, 17098200.0f, 1700.0f, 10},
        {"Espanha", "Europa", "ES01", 47000000UL, 505000.0f, 1600.0f, 35},
        {"Argentina", "América do Sul", "AR01", 46000000UL, 2780000.0f, 640.0f, 20},
        {"México", "América do Norte", "MX01", 126000000UL, 1964000.0f, 1600.0f, 25},
        {"Coreia do Sul", "Ásia", "KR01", 52000000UL, 100210.0f, 1800.0f, 20},
        {"África do Sul", "África", "ZA01", 60000000UL, 1219000.0f, 420.0f, 12},
        {"Egito", "África", "EG01", 110000000UL, 1002000.0f, 480.0f, 18},
        {"Portugal", "Europa", "PT01", 10300000UL, 92212.0f, 270.0f, 25},
        {"Suíça", "Europa", "CH01", 8700000UL, 41285.0f, 820.0f, 15}
    };

    for(int i=0;i<20;i++) calcular_derived(&paises[i]);

    printf("=============================================\n");
    printf("     SUPER TRUNFO - PLAYER vs CPU\n");
    printf("=============================================\n\n");

    printf("Lista de países disponíveis:\n");
    for(int i=0;i<20;i++) printf("%2d - %s\n", i+1, paises[i].nome);

    int escolha;
    printf("\nEscolha o número da sua carta: ");
    scanf("%d", &escolha);
    if(escolha <1 || escolha>20){
        printf("Seleção inválida. Saindo...\n");
        return 0;
    }

    Carta jogador = paises[escolha-1];
    int indice_cpu;
    do {
        indice_cpu = rand()%20;
    } while(indice_cpu == (escolha-1));
    Carta cpu = paises[indice_cpu];

    printf("\nSua carta: %s\nCarta da CPU: %s\n", jogador.nome, cpu.nome);

    // Jogador escolhe atributo
    int attr_jogador=0;
    while((attr_jogador = mostrar_menu(0))==0) printf("Opção inválida.\n");

    // CPU escolhe estrategicamente
    int attr_cpu=0;
    float max_dif = -1.0f;
    for(int i=1;i<=6;i++){
        if(i == attr_jogador) continue;
        float v_cpu = obter_valor(&cpu, i);
        float v_jog = obter_valor(&jogador, i);
        float dif;
        if(i==5) dif = v_jog - v_cpu; // menor vence
        else dif = v_cpu - v_jog;     // maior vence
        if(dif > max_dif){
            max_dif = dif;
            attr_cpu = i;
        }
    }

    printf("Você escolheu: %s\n", nome_atributo(attr_jogador));
    printf("CPU escolheu: %s\n", nome_atributo(attr_cpu));

    // Valores
    float v_j = obter_valor(&jogador, attr_jogador);
    float v_c = obter_valor(&cpu, attr_cpu);

    int vence_j = (attr_jogador==5)?(v_j<v_c):(v_j>v_c);
    int vence_c = (attr_cpu==5)?(v_c<v_j):(v_c>v_j);

    printf("\n=============================================\n");
    printf("             RESULTADO DA RODADA\n");
    printf("=============================================\n");

    // Atributo jogador
    printf("\n%s:\n  %s = ", nome_atributo(attr_jogador), jogador.nome);
    if(attr_jogador==1) print_humanized_ulong((unsigned long int)v_j);
    else printf("%.2f", v_j);

    printf("\n  %s = ", cpu.nome);
    if(attr_jogador==1) print_humanized_ulong((unsigned long int)v_c);
    else printf("%.2f", v_c);

    printf("\nResultado: %s venceu\n", vence_j?jogador.nome:cpu.nome);

    // Atributo CPU
    printf("\n%s:\n  %s = ", nome_atributo(attr_cpu), cpu.nome);
    if(attr_cpu==1) print_humanized_ulong((unsigned long int)v_c);
    else printf("%.2f", v_c);

    printf("\n  %s = ", jogador.nome);
    if(attr_cpu==1) print_humanized_ulong((unsigned long int)v_j);
    else printf("%.2f", v_j);

    printf("\nResultado: %s venceu\n", vence_c?cpu.nome:jogador.nome);

    // Soma
    float soma_j = (attr_jogador==5?1/v_j:v_j) + (attr_cpu==5?1/v_j:v_j);
    float soma_c = (attr_cpu==5?1/v_c:v_c) + (attr_jogador==5?1/v_c:v_c);

    printf("\nSoma dos atributos (considerando densidade invertida para poder):\n");
    printf("  %s = %.2f\n  %s = %.2f\n", jogador.nome, soma_j, cpu.nome, soma_c);

    if(soma_j > soma_c) printf("\n🏆 Vencedor final: %s!\n", jogador.nome);
    else if(soma_c > soma_j) printf("\n🏆 Vencedor final: %s!\n", cpu.nome);
    else printf("\n🤝 Empate!\n");

    printf("=============================================\n");
    printf("Fim da comparação. Obrigado por jogar!\n");
    printf("=============================================\n");

    return 0;
}
