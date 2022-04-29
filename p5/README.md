# [Compiladores 2022-1] Grupo 7009 
## Práctica 5 Repositorio base


### Estructura del directorio
```c++
p5
├── README.md
└── src //carpeta de código
    ├── prueba //archivo para I/O test
    ├── lib //carpeta para bibliotecas
    │   └── FlexLexer.h //archivo de cabecera para autograding (ignorar)
    ├── Makefile //archivo de reglas de compilación
    ├── main.cpp //contiene la función principal del programa
    ├── Production.cpp //archivo para la clase producción
    ├── lexer.ll //archivo de Flex para generación de `scanner`
    ├── Symbol.cpp //archivo para la clase de símbolo
    ├── Grammar.cpp //archivo para la clase de gramática
    ├── ParserLR.cpp //archivo para parser LR(0)
    └── headers //carpeta de archivos de código
        ├── Lexer.hpp //archivo de cabecera para el scanner
        ├── Symbol.h //archivo de cabecera de símbolo
        ├── Production.h //archivo de cabecera de producción
        ├── Symbols.hpp //archivo de cabecera definición de los conjuntos N y Σ
        ├── Grammar.h //archivo de cabecera de gramática
        └── ParserLR.hpp //archivo de cabecera del parser LR(0)

```

### Uso

#### Compilacion

```bash
$ cd src/
$ make
```

#### Ejecucion

```bash
$ ./comp prueba
```

#### Ejercicios
Para la gramática G = ( N, T, P, S), descrita por las siguientes producciones: 
> P = {
>> programa → declaraciones sentencias <br>
>> declaraciones → declaraciones declaracion | declaracion <br>
>> declaracion → tipo lista-var **;** <br>
>> tipo → **int** | **float** <br>
>> lista_var → lista_var **,** _**identificador**_ | _**identificador**_ <br>
>> sentencias → sentencias sentencia | sentencia <br>
>> sentencia → _**identificador**_ **=** expresion **;** | **if** **(** expresion **)** sentencias **else** sentencias | **while** **(** expresión **)** sentencias <br>
>> expresion → expresion **+** expresion | expresion **-** expresion | expresion __\*__ expresion | expresion **/** expresión | _**identificador**_ | **_numero_** <br>
>> expresion → **(** expresion **)** <br>
}


1. Determinar en un archivo Readme, en formato Markdown (.md) o LaTeX (.tex) - con su respectivo PDF, para este último - , los conjuntos _N_, _T_ y el símbolo inicial _S_.  (0.5 pts.) <br>
    a. Mostrar en el archivo el proceso para aumentar la gramática a _G'_. (0.25 pts.) <br>
    b. Mostrar en el archivo la construcción de la tabla de transiciones del autómata LR. (1 pt.) <br>
    c. Mostrar en el archivo la construcción de los conjuntos FIRST de la gramática _G_. (0.5 pts.) <br>
    d. Mostrar en el archivo la construcción de los conjuntos FOLLOW de la gramática _G_. (0.5 pts.)
2. Mostrar en el archivo la construcción de la tabla de análisis sintáctico LR (ACCION y GOTO). (1 pt.)
3. Sustituir el contenido del Analizador Léxico (lexer.ll) con el implementado en la segunda práctica. (0.5 pts.) (listo)
4. Definir en un comentario de _Symbols.hpp_ la gramática _G'_. (0.05 pts.) (listo)
5. Definir _T_ en un _**enum**_ de _Symbols.hpp_. (0.10 pts.) (listo)
6. Definir _N_ en un _**enum**_ de _Symbols.hpp_. (0.10 pts.) (listo)
7. Cargar  _N ∪ T_ en _ParserLR.cpp_. (0.25 pts.) 
8. Cargar _P'_ en _ParserLR.cpp_. (0.25 pts.)
9. Cargar la tabla de análisis sintáctico LR en _ParserLR.cpp_. (0.25 pts.)
10. Implementar el algoritmo de análisis sintáctico ascendente LR en _ParserLR.cpp_ de modo que el programa acepte el archivo _prueba_. (4.5 pts.)
---
#### Extras

11. Documentar el código. (0.25pts)
12. Proponer 4 archivos de prueba nuevos, 2 válidos y 2 inválidos. (0.25pts)
