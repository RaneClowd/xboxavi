#include <stdio.h>

FILE* file;
unsigned int bytesRemainingInFile;

void readNumBytesIntoBuffer(int numBytes, void* buffer) {
  size_t lenRead = fread(buffer, sizeof(char), numBytes, file);
  if (lenRead != numBytes) {
    printf("ERROR: %d bytes read when %d were expected\n", (int)lenRead, numBytes);
    exit(1);
  }
  bytesRemainingInFile -= numBytes;
}

void readInt(void* buffer) {
  readNumBytesIntoBuffer(4, buffer);
}

void printFourCC(char* fourCC) {
  printf("%c%c%c%c", fourCC[0], fourCC[1], fourCC[2], fourCC[3]);
}

void readFourCC(void* buffer) {
  readNumBytesIntoBuffer(4, buffer);
}

int readRiffHeader() {
  char riffHeader[4];
  readFourCC(riffHeader);
  int isRiff = riffHeader[0] == 'R' && riffHeader[1] == 'I' &&
               riffHeader[2] == 'F' && riffHeader[3] == 'F';

  if (isRiff) {
    printf("Riff header found: ");

    unsigned int fileSize;
    readInt(&fileSize);
    bytesRemainingInFile = fileSize;
    printf("File size is %d, ", fileSize);

    char fileType[4];
    readFourCC(fileType);
    printf("File type is ");
    printFourCC(fileType);
    printf(".\n");

    return 1;
  } else {
    printf("No riff found\n");
    return 0;
  }
}

int readDataElement() {
  char fourCC[4];
  unsigned int size;

  readFourCC(fourCC);
  readInt(&size);

  printf("Next Chunk '");
  printFourCC(fourCC);
  printf("' has a size of %d", size);
  printf("\n");

  bytesRemainingInFile -= size;
  return size;
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    file = fopen(argv[1], "r");

    if (file != NULL) {
      if (readRiffHeader()) {
        int size = readDataElement();
        while (bytesRemainingInFile > 0 && size > 0) {
          fseek(file, size, SEEK_CUR);

          size = readDataElement();
        }
      }

      printf("%d bytes unread\n", bytesRemainingInFile);
      fclose(file);
    } else {
      printf("ERROR: file could not be found.\n");
    }
  } else {
    printf("Use program with only the file to check as a parameter.\n");
  }
}
