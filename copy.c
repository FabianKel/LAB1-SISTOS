#include <stdio.h>
#include <stdlib.h>

void copy_file(const char *source, const char *destination) {
    	FILE *src = fopen(source, "rb");
    	if (!src) {
        	perror("Error al abrir el archivo de origen");
        	exit(EXIT_FAILURE);
    	}

	FILE *dest = fopen(destination, "wb");
    	if (!dest) {
        	perror("Error al abrir el archivo de destino");
        	fclose(src);
        	exit(EXIT_FAILURE);
    	}

    	char buffer[4096];
    	size_t bytes;
    	while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        	fwrite(buffer, 1, bytes, dest);
    	}
	fclose(src);
    	fclose(dest);
    	printf("Archivo copiado exitosamente! :D\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Ejecucion: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        return EXIT_FAILURE;
    }

    copy_file(argv[1], argv[2]);
    return EXIT_SUCCESS;
}