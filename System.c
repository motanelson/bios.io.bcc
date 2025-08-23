#include "System.h"
#include <string.h>



#define BLOCO_TAMANHO 4096

void Console_Clear() {
    for (int i = 0; i < 500; i++) {
        printf("\n");
    }
}
void Console_Beep() {
    printf("\a");
    fflush(stdout);  // Garante que o som é enviado imediatamente
}
char* Console_ReadLine() {
    char* buffer = malloc(BLOCO_TAMANHO);
    if (!buffer) return NULL;

    if (fgets(buffer, BLOCO_TAMANHO, stdin) == NULL) {
        free(buffer);
        return NULL;
    }

    // Remove newline se presente
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return buffer;
}
char Console_Read() {
    int c = getc(stdin);
    if (c == EOF) {
        return '\0';  // ou um valor especial, como -1, se quiseres
    }
    return (char)c;
}
char Console_ReadKey() {
    int c = getc(stdin);
    if (c == EOF) {
        return '\0';  // ou um valor especial, como -1, se quiseres
    }
    return (char)c;
}

void Console_WriteLine(const char* texto) {
    printf("%s\n", texto);
}
void Console_Write(const char* texto) {
    printf("%s", texto);
    fflush(stdout);
}

char* File_ReadAllText(const char* path) {
    FILE* f = fopen(path, "r");
    if (!f) {
        printf("Erro ao abrir o ficheiro: %s\n", path);
        return NULL;
    }

    size_t capacidade = BLOCO_TAMANHO;
    size_t tamanho = 0;
    char* buffer = malloc(capacidade);
    if (!buffer) {
        fclose(f);
        return NULL;
    }

    size_t lido;
    while ((lido = fread(buffer + tamanho, 1, BLOCO_TAMANHO, f)) > 0) {
        tamanho += lido;
        if (tamanho + BLOCO_TAMANHO > capacidade) {
            capacidade += BLOCO_TAMANHO;
            char* novo = realloc(buffer, capacidade);
            if (!novo) {
                free(buffer);
                fclose(f);
                return NULL;
            }
            buffer = novo;
        }
    }

    buffer[tamanho] = '\0';  // Terminar como string
    fclose(f);
    return buffer;
}

int File_WriteAllText(const char* path, const char* conteudo) {
    FILE* f = fopen(path, "w");
    if (!f) {
        printf("Erro ao criar o ficheiro: %s\n", path);
        return 0;
    }

    fputs(conteudo, f);
    fclose(f);
    return 1;
}
void Console_BackgroundColor(ConsoleColor color) {
    int n = 40 + (color % 8);  // ANSI base para background (cores normais)
    printf("\033[%dm", n);

    if (color >= 8) {
        printf("\033[1m"); // brilhante se for "High" color
    }

    fflush(stdout);  // aplica imediatamente
}
void Console_ForegroundColor(ConsoleColor color) {
    int n = 30 + (color % 8);  // ANSI base para background (cores normais)
    printf("\033[%dm", n);

    if (color >= 8) {
        printf("\033[1m"); // brilhante se for "High" color
    }

    fflush(stdout);  // aplica imediatamente
}
void Console_ResetColor() {
    
    printf("\033[37;40m");
    
    fflush(stdout);  // aplica imediatamente
}
void Console_SetCursorPosition(int x,int y) {
    printf("\033[%d;%dd", y,x);
    fflush(stdout);  // aplica imediatamente
}


