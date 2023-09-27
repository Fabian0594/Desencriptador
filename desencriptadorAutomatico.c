#include <stdio.h>

int main() {
    FILE *file, *output_file;
    char filename[] = "desplazaAuto.txt";
    char output_filename[] = "output.txt";
    char c;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo %s\n", filename);
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("No se pudo crear el archivo %s\n", output_filename);
        return 1;
    }

    for (i = 1; i <= 256; i++) {
        while ((c = fgetc(file)) != EOF) {
            fputc(c - i, output_file);
        }
        rewind(file);
        fprintf(output_file, " - Contador: %d\n", i);
    }

    fclose(file);
    fclose(output_file);
    return 0;
}
