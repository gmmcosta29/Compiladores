# Juc Compiler - Complete Compiler Implementation 

> Full-featured compiler for Juc, a simplified Java subset, implementing the complete compilation pipeline from lexical analysis to code generation

# Features
- **Lexical Analysis**: Custom tokenizer handling C language tokens
- **Syntax Analysis**: Recursive descent parser with error recovery
- **Semantic Analysis**: Type checking and symbol table management with scope handling

# Technical Stack

**Language**: C
**Build System**: Make
**Tools**: Flex (lexer), Bison/Yacc (parser generator)
**Build**: Standard Unix toolchain (gcc, make)

# Features Implemented

**Lexical Analysis**:
- Complete token recognition for Juc language
- Comment handling (// and /* */)
- Error recovery with detailed diagnostics
**Syntax Analysis**:
- LALR(1) grammar with conflict resolution
- Abstract Syntax Tree construction
**Semantic Analysis**:
- Multi-scope symbol table management
- Type inference and checking
- Method signature matching and overload resolution
