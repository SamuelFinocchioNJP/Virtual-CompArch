#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H

#include <stdint.h>

const uint16_t INSTRUCTION_PUSH = 0x0001;
const uint16_t INSTRUCTION_POP = 0x0002;
const uint16_t INSTRUCTION_ADD = 0x0003;
const uint16_t INSTRUCTION_SUB = 0x0004;
const uint16_t INSTRUCTION_MUL = 0x0005;
const uint16_t INSTRUCTION_DIV = 0x0006;
const uint16_t INSTRUCTION_MOD = 0x0007;
const uint16_t INSTRUCTION_MOVE = 0x000A;

#endif // INSTRUCTION_SET_H
