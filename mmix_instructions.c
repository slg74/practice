
#include <stdio.h>
#include <stdint.h>

int main() {
    // Sample MMIX program
    uint32_t program[] = {
        (ADD << 24) | (3 << 16) | (1 << 8) | 2,  // ADD $3, $1, $2
        (SUB << 24) | (4 << 16) | (3 << 8) | 2,  // SUB $4, $3, $2
        (MUL << 24) | (5 << 16) | (3 << 8) | 4,  // MUL $5, $3, $4
        (DIV << 24) | (6 << 16) | (5 << 8) | 2   // DIV $6, $5, $2
    };

    // Load the program into memory
    for (int i = 0; i < sizeof(program) / sizeof(uint32_t); i++) {
        memory[i * 4] = (program[i] >> 24) & 0xFF;
        memory[i * 4 + 1] = (program[i] >> 16) & 0xFF;
        memory[i * 4 + 2] = (program[i] >> 8) & 0xFF;
        memory[i * 4 + 3] = program[i] & 0xFF;
    }

    // Set initial values
    registers[1] = 10;
    registers[2] = 5;

    // Run the program
    PC = 0;
    for (int i = 0; i < sizeof(program) / sizeof(uint32_t); i++) {
        execute_instruction(program[i]);
    }

    // Print results
    printf("Result in $3: %llu\n", registers[3]);
    printf("Result in $4: %llu\n", registers[4]);
    printf("Result in $5: %llu\n", registers[5]);
    printf("Result in $6: %llu\n", registers[6]);

    return 0;
}