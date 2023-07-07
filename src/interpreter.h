#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

extern EMSCRIPTEN_KEEPALIVE void brainfuck(char *instr_ptr, char *input);