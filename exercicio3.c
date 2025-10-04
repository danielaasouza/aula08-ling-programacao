#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lerString(char s[]) {
    printf("Digite uma string: ");
    fgets(s, 100, stdin);   
    s[strcspn(s, "\n")] = 0; 
}

int contarCarac(const char s[]) {
    return strlen(s);
}

void inverter(char s[]) {
    int i=0, j=strlen(s)-1;
    while(i<j) {
        char tmp=s[i]; s[i]=s[j]; s[j]=tmp;
        i++; j--;
    }
}

void maiuscula(char s[]) {
    for(int i=0;s[i];i++) s[i]=toupper(s[i]);
}

void minuscula(char s[]) {
    for(int i=0;s[i];i++) s[i]=tolower(s[i]);
}

int contarPalavras(const char s[]) {
    int count=0, in_word=0;
    for(int i=0;s[i];i++) {
        if(!isspace(s[i]) && !in_word) {count++; in_word=1;}
        else if(isspace(s[i])) in_word=0;
    }
    return count;
}

int main() {
    char s[100];
    lerString(s);
    int op;
    do {
        printf("\n=== MANIPULADOR DE STRINGS ===\n");
        printf("1. Contar caracteres\n2. Inverter string\n3. Converter maiúscula\n4. Converter minúscula\n5. Contar palavras\n0. Sair\nOpção: ");
        scanf("%d", &op);
        getchar(); 
        switch(op) {
            case 1: printf("A string possui %d caracteres.\n", contarCarac(s)); 
            break;

            case 2: inverter(s); 
            printf("String invertida: %s\n", s); 
            break;

            case 3: maiuscula(s); 
            printf("String em maiúscula: %s\n", s); 
            break;

            case 4: minuscula(s); 
            printf("String em minúscula: %s\n", s);
            break;

            case 5: printf("Número de palavras: %d\n", contarPalavras(s)); 
            break;
        }
    } while(op != 0);
    
    return 0;
}

