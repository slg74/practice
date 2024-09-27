#include <stdio.h>
#include <stdint.h>

#define MEM_SIZE 0x100000000  // 4GB of memory
uint64_t registers[256];      // General-purpose registers
uint8_t memory[MEM_SIZE];     // Memory space
uint64_t PC = 0;              // Program counter

typedef enum {
    ADD = 0x20,  // ADD instruction opcode
    SUB = 0x21,  // Subtract
    MUL = 0x22,  // Multiply
    DIV = 0x23,  // Divide
    LDB = 0x80,  // Load byte
    STB = 0x90,  // Store byte
    JMP = 0xF0,  // Jump
} Opcode;

// Function to decode and execute a single instruction
void execute_instruction(uint32_t instruction) {
    uint8_t opcode = (instruction >> 24) & 0xFF;
    uint8_t ra = (instruction >> 16) & 0xFF;
    uint8_t rb = (instruction >> 8) & 0xFF;
    uint8_t rc = instruction & 0xFF;

    switch (opcode) {
        case ADD:
            registers[ra] = registers[rb] + registers[rc];
            break;
        case SUB:
            registers[ra] = registers[rb] - registers[rc];
            break;
        case MUL:
            registers[ra] = registers[rb] * registers[rc];
            break;
        case DIV:
            if (registers[rc] != 0) {
                registers[ra] = registers[rb] / registers[rc];
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        case LDB:
            registers[ra] = memory[registers[rb] + registers[rc]];
            break;
        case STB:
            memory[registers[rb] + registers[rc]] = registers[ra] & 0xFF;
            break;
        case JMP:
            PC = registers[ra];
            break;
        default:
            printf("Unknown opcode: 0x%02X\n", opcode);
            break;
    }
}

// Main loop for fetch-decode-execute cycle
void run() {
    while (1) {
        uint32_t instruction = (memory[PC] << 24) |
                               (memory[PC + 1] << 16) |
                               (memory[PC + 2] << 8) |
                               memory[PC + 3];
        PC += 4;
        execute_instruction(instruction);
    }
}

// Load binary program into memory
void load_program(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    fread(memory, sizeof(uint8_t), MEM_SIZE, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <program>\n", argv[0]);
        return 1;
    }

    load_program(argv[1]);

    // Set up some initial values in registers
    registers[1] = 10;
    registers[2] = 5;

    // Test ADD
    uint32_t add_instruction = (ADD << 24) | (3 << 16) | (1 << 8) | 2;
    execute_instruction(add_instruction);
    printf("ADD result: %llu\n", registers[3]);

    // Test SUB
    uint32_t sub_instruction = (SUB << 24) | (4 << 16) | (1 << 8) | 2;
    execute_instruction(sub_instruction);
    printf("SUB result: %llu\n", registers[4]);

    // Test MUL
    uint32_t mul_instruction = (MUL << 24) | (5 << 16) | (1 << 8) | 2;
    execute_instruction(mul_instruction);
    printf("MUL result: %llu\n", registers[5]);

    // Test DIV
    uint32_t div_instruction = (DIV << 24) | (6 << 16) | (1 << 8) | 2;
    execute_instruction(div_instruction);
    printf("DIV result: %llu\n", registers[6]);

    run();  // Start the emulation

    return 0;
}