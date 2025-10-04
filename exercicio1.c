#include <stdio.h>

void exibirMenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Somar\n");
    printf("2. Subtrair\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("0. Sair\n");
    printf("Opção: ");
}

int obterOpcao() {
    int op;
    scanf("%d", &op);
    return op;
}

void obterNumeros(float *a, float *b) {
    printf("Digite o primeiro número: ");
    scanf("%f", a);
    printf("Digite o segundo número: ");
    scanf("%f", b);
}

float somar(float a, float b) { return a + b; }
float subtrair(float a, float b) { return a - b; }
float multiplicar(float a, float b) { return a * b; }
float dividir(float a, float b) {
    if(b == 0) {
        printf("Erro: divisão por zero!\n");
        return 0;
    }
    return a / b;
}

void exibir_resultado(float r) {
    printf("Resultado: %.2f\n", r);
}

int main() {
    int op;
    do {
        exibirMenu();
        op = obterOpcao();
        float a, b, r;
        switch(op) {
            case 1: obterNumeros(&a,&b); 
            r = somar(a,b); exibir_resultado(r); 
            break;

            case 2: obterNumeros(&a,&b); 
            r = subtrair(a,b); exibir_resultado(r); 
            break;

            case 3: obterNumeros(&a,&b); 
            r = multiplicar(a,b); exibir_resultado(r);
            break;

            case 4: obterNumeros(&a,&b); 
            r = dividir(a,b); exibir_resultado(r); 
            break;
        }
    } while(op != 0);

    return 0;
}
