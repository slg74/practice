#include <stdio.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define CHUNK_SIZE 8192

void calculate_file_md5(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    MD5_CTX md5Context;
    MD5_Init(&md5Context);

    unsigned char chunk[CHUNK_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(chunk, 1, CHUNK_SIZE, file) > 0) {
        MD5_Update(&md5Context, chunk, bytesRead);
    }

    unsigned char result[MD5_DIGEST_LENGTH];
    MD5_Final(result, &md5Context);

    printf("MD5 hash of %s: ", filename);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    calculate_file_md5(argv[1]); 
    return 0;
}