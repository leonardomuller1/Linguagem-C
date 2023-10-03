#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
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
} __attribute__((packed)) BMPHeader;

int main()
{
    char inputFilename[256];
    char outputFilenameGrayScale[256];
    char outputFilenameRGB[256];

    FILE *inputFile, *outputFileGrayScale, *outputFileRGB;

    printf("Digite o nome do arquivo BMP de entrada: ");
    fgets(inputFilename, sizeof(inputFilename), stdin);
    inputFilename[strcspn(inputFilename, "\n")] = '\0';

    strcpy(outputFilenameGrayScale, inputFilename);
    strcpy(outputFilenameRGB, inputFilename);
    strcat(inputFilename, ".bmp");
    strcat(outputFilenameGrayScale, "_gs.bmp");
    strcat(outputFilenameRGB, "_rgb.bmp");

    inputFile = fopen(inputFilename, "rb");
    outputFileGrayScale = fopen(outputFilenameGrayScale, "wb");
    outputFileRGB = fopen(outputFilenameRGB, "wb");

    if (inputFile == NULL)
    {
        printf("Erro ao abrir o arquivo BMP de entrada.\n");
        return 1;
    }

    BMPHeader header;

    if (fread(&header, sizeof(BMPHeader), 1, inputFile) != 1)
    {
        printf("Erro ao ler o cabeçalho BMP de entrada.\n");
        fclose(inputFile);
        return 1;
    }

    if (header.type != 0x4D42)
    {
        printf("O arquivo de entrada não é um BMP válido.\n");
        fclose(inputFile);
        return 1;
    }

    fwrite(&header, sizeof(BMPHeader), 1, outputFileGrayScale);
    fwrite(&header, sizeof(BMPHeader), 1, outputFileRGB);
    int rowSize = ((header.width_px * 3 + 3) / 4) * 4;
    int paddingSize = rowSize - (header.width_px * 3);

    char pixelData[3];

    for (int i = 0; i < header.height_px; i++)
    {
        for (int j = 0; j < header.width_px; j++)
        {
            if (fread(pixelData, 1, 3, inputFile) != 3)
            {
                printf("Erro na leitura dos dados da imagem.\n");
                fclose(inputFile);
                return 1;
            }

            // Inverta as cores RGB para a imagem RGB
            char red = pixelData[2];
            char green = pixelData[1];
            char blue = pixelData[0];

            char grayValue = (0.299 * red + 0.587 * green + 0.114 * blue);
            grayValue = 255 - grayValue;

            pixelData[0] = grayValue;
            pixelData[1] = grayValue;
            pixelData[2] = grayValue;

            fwrite(pixelData, 1, 3, outputFileGrayScale);

            pixelData[0] = red;
            pixelData[1] = green;
            pixelData[2] = blue;

            fwrite(pixelData, 1, 3, outputFileRGB);
        }

        // Pule qualquer byte de preenchimento na linha
        if (paddingSize > 0)
        {
            fread(0, 1, paddingSize,  inputFile);
            fwrite(0, 1, paddingSize, outputFileGrayScale);
            fwrite(0, 1, paddingSize, outputFileRGB);
        }
    }

    fclose(inputFile);
    fclose(outputFileGrayScale);
    fclose(outputFileRGB);

    printf("Manipulacao de cores concluida com sucesso. Os arquivos BMP de saida foram criados.\n");

    return 0;
}
