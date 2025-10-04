#include <stdio.h>

#define Alunos 5
#define Disciplinas 4

void inserirNotas(float notas[][Disciplinas]) {
    for(int i=0;i<Alunos;i++) {
        printf("Aluno %d:\n", i+1);
        for(int j=0;j<Disciplinas;j++) {
            printf(" Disciplina %d: ", j+1);
            scanf("%f", &notas[i][j]);
        }
    }
}

void exibirNotas(const float notas[][Disciplinas]) {
    for(int i=0;i<Alunos;i++) {
        printf("Aluno %d: ", i+1);
        for(int j=0;j<Disciplinas;j++) printf("%.1f ", notas[i][j]);
        printf("\n");
    }
}

float calcMediaAluno(const float notas[][Disciplinas], int aluno) {
    float soma=0;
    for(int j=0;j<Disciplinas;j++) soma += notas[aluno][j];
    return soma/Disciplinas;
}

float calcMediaDisciplina(const float notas[][Disciplinas], int d) {
    float soma=0;
    for(int i=0;i<Alunos;i++) soma += notas[i][d];
    return soma/Alunos;
}

void exibirRelFinal(const float notas[][Disciplinas]) {
    for(int i=0;i<Alunos;i++) {
        float m = calcMediaAluno(notas,i);
        printf("Aluno %d - Média: %.2f - %s\n", i+1, m, (m>=6.0?"Aprovado":"Reprovado"));
    }
    for(int d=0;d<Disciplinas;d++) {
        printf("Disciplina %d - Média: %.2f\n", d+1, calcMediaDisciplina(notas,d));
    }
}

int main() {
    float notas[Alunos][Disciplinas];
    int op;
    do {
        printf("\n=== SISTEMA DE GESTÃO DE NOTAS ===\n");
        printf("1. Inserir notas\n2. Exibir notas\n3. Calcular médias por aluno\n4. Calcular médias por disciplina\n5. Relatório final\n0. Sair\nOpção: ");
        scanf("%d", &op);
        switch(op) {
            case 1: inserirNotas(notas); 
            break;

            case 2: exibirNotas(notas);
            break;

            case 3: for(int i=0;i<Alunos;i++) 
            printf("Aluno %d - Média: %.2f\n", i+1, calcMediaAluno(notas,i)); 
            break;

            case 4: for(int d=0;d<Disciplinas;d++) 
            printf("Disciplina %d - Média: %.2f\n", d+1, calcMediaDisciplina(notas,d)); 
            break;

            case 5: exibirRelFinal(notas); 
            break;
        }
    } while(op != 0);

    return 0;
}

