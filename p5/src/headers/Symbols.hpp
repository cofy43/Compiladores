#ifndef __SYMBOLS_HPP__
#define __SYMBOLS_HPP__


/** 
 * 1. Definir en un comentario la gramática G'(N, T, P', S) aumentada de G(N, T, P, S) 
 * N = {P', P, D, X, R, L, S, Y, E, T, F}
 * T = {i, f, ;, ',', d, =, if, '(', ')', '{', '}', e, w, +, -, *, /, d, n}
 * P'= {
 *      P’ → P
 *      P→D S
 *      D→ D X | X
 *      X→ R L ;
 *      R →i | f 
 *      L→ L , d | d
 *      S→ S Y
 *      Y → d = E ; | if (E) { S } e { S } | w(E) { S }
 *      E→E+ T | E - T | T
 *      T → T * F | T / F | F
 *      F → (E) | d | n
 * }
 * S = P'
 */


/**
 * 2. Determinar la enumeración para el conjunto T
 */
enum Token { t_eof, i, f , d , IF , w ,
    e , n , COMA , PYC , LPAR , RPAR , LBRA , 
    RBRA , MAS , MENOS , MUL , DIV , ASIG};
/*
enum Token { t_eof, INT = 'int',
  f = 'float',
  d = 'identificador',
  IF = 'if',
  w = 'while',
  e = 'else',
  n = 'numero',
  COMA = ',',
  PYC = ';',
  LPAR = '(',
  RPAR = ')',
  LBRA = '{',
  RBRA = '}',
  MAS = '+',
  MENOS = '-',
  MUL = '*',
  DIV = '/',
  ASIG = '='};
*/

/**
 * 3. Determinar la enumeración para el conjunto N
 */
enum NoTerm { epsilon, P_, P, D, X, R, L, S, Y, E, T, F};
/** 
 * P' = programa'
 * P = programa
 * D = delclaración
 * S = sentencias
 * X = declaración
 * R = tipo
 * L = lista-var
 * Y = sentencia
 * E = expresión
 * T = termino
 * F = factor
*/
 
#endif // !__SYMBOLS_HPP__
