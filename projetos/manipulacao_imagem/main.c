#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint16_t  type;             // Magic identifier: 0x4d42
    uint32_t  size;             // File size in bytes
    uint16_t  reserved1;        // Not used
    uint16_t  reserved2;        // Not used
    uint32_t  offset;           // Offset to image data in bytes from the beginning of the file (54 bytes)
    uint32_t  dib_header_size;  // DIB Header size in bytes (40 bytes)
    int32_t   width_px;         // Width of the image
    int32_t   height_px;        // Height of image
    uint16_t  num_planes;       // Number of color planes
    uint16_t  bits_per_pixel;   // Bits per pixel
    uint32_t  compression;      // Compression type
    uint32_t  image_size_bytes; // Image size in bytes
    int32_t   x_resolution_ppm; // Pixels per meter
    int32_t   y_resolution_ppm; // Pixels per meter
    uint32_t  num_colors;       // Number of colors
    uint32_t  important_colors; // Important colors
} __attribute__((packed)) BMPHeader;;

int main() {
    char inputFilename[256];  // Nome do arquivo de entrada
    char outputFilename[256]; // Nome do arquivo de saída

    printf("Digite o nome do arquivo BMP de entrada (por exemplo, 'minhafoto'): ");
    scanf("%s", inputFilename);

    // Adicione a extensão .bmp ao nome do arquivo de entrada
    char fullInputFilename[256];
    snprintf(fullInputFilename, sizeof(fullInputFilename), "%s.bmp", inputFilename);

    printf("Digite o nome do arquivo BMP de saída (por exemplo, 'saida'): ");
    scanf("%s", outputFilename);

    // Adicione a extensão .bmp ao nome do arquivo de saída
    char fullOutputFilename[256];
    snprintf(fullOutputFilename, sizeof(fullOutputFilename), "%s.bmp", outputFilename);

    FILE *inputFile = fopen(fullInputFilename, "rb");
    FILE *outputFile = fopen(fullOutputFilename, "wb");

    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo BMP de entrada.\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo BMP de saída.\n");
        fclose(inputFile);
        return 1;
    }

    BMPHeader header;

    if (fread(&header, sizeof(BMPHeader), 1, inputFile) != 1) {
        printf("Erro ao ler o cabeçalho BMP de entrada.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Verifique o campo 'type' para garantir que seja um arquivo BMP válido.
    if (header.type != 0x4D42) {
        printf("O arquivo de entrada não é um BMP válido.\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    // Escreva o cabeçalho BMP no arquivo de saída
    fwrite(&header, sizeof(BMPHeader), 1, outputFile);

    // Determine o número de bytes de dados de imagem por linha
    int rowSize = (header.width_px * (header.bits_per_pixel / 8));

    // Ajuste o tamanho da linha para ser múltiplo de 4 bytes (requisito BMP)
    if (rowSize % 4 != 0) {
        rowSize += (4 - (rowSize % 4));
    }

    char pixelData[3]; // Para armazenar os dados do pixel lido (BGR)

    for (int i = 0; i < header.height_px; i++) {
        for (int j = 0; j < rowSize; j += 3) { // Processa três bytes por vez (BGR)
            if (fread(pixelData, 1, 3, inputFile) != 3) {
                printf("Erro na leitura dos dados da imagem.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }

            // Mantenha apenas a componente azul e zere as componentes vermelha e verde
            pixelData[0] = 0; // Azul
            pixelData[1] = 0; // Vermelho
            pixelData[2] = 0; // Verde

            // Escreva o pixel modificado no arquivo de saída
            fwrite(pixelData, 1, 3, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Manipulação de cores concluída com sucesso. O arquivo BMP de saída foi criado.\n");

    return 0;
}
