#include "headers/ParserLR.hpp"

ParserLR::ParserLR(Lexer *lexer)
{
  this->lexer = lexer;
}

ParserLR::~ParserLR()
{
}

void ParserLR::loadSyms()
{
  /*********************************************
   * 4. Agregar todos los símbolos (N∪T) de G'*
   *********************************************/
  //No terminales
  grammar.addSymbol(0, Symbol(epsilon));
  grammar.addSymbol(1, Symbol(P_));
  grammar.addSymbol(2, Symbol(P));
  grammar.addSymbol(3, Symbol(D));
  grammar.addSymbol(4, Symbol(S));
  grammar.addSymbol(5, Symbol(X));
  grammar.addSymbol(6, Symbol(R));
  grammar.addSymbol(7, Symbol(L));
  grammar.addSymbol(8, Symbol(Y));
  grammar.addSymbol(9, Symbol(E));
  grammar.addSymbol(10, Symbol(T));
  grammar.addSymbol(11, Symbol(F));
  //terminales
  grammar.addSymbol(12, Symbol(t_eof));
  grammar.addSymbol(13, Symbol(i));
  grammar.addSymbol(14, Symbol(f));
  grammar.addSymbol(15, Symbol(d));
  grammar.addSymbol(16, Symbol(IF));
  grammar.addSymbol(17, Symbol(w));
  grammar.addSymbol(18, Symbol(e));
  grammar.addSymbol(19, Symbol(n));
  grammar.addSymbol(20, Symbol(COMA));
  grammar.addSymbol(21, Symbol(PYC));
  grammar.addSymbol(22, Symbol(LPAR)); // (
  grammar.addSymbol(23, Symbol(RPAR)); // )
  grammar.addSymbol(24, Symbol(LBRA)); // {
  grammar.addSymbol(25, Symbol(RBRA)); // }
  grammar.addSymbol(26, Symbol(MAS));
  grammar.addSymbol(27, Symbol(MENOS));
  grammar.addSymbol(28, Symbol(MUL));
  grammar.addSymbol(29, Symbol(DIV));
  grammar.addSymbol(30, Symbol(ASIG));
}

void ParserLR::loadProds()
{
  /************************************************
   * 5. Agregar todas las producciones (P) de G' *
   ************************************************/
  //P’→ P
  grammar.addProd(0, Production(1, {2}));
  //P → D S
  grammar.addProd(1, Production(2, {3,4}));
  //D→ D X
  grammar.addProd(2, Production(3, {3,5}));
  //D→ X
  grammar.addProd(3, Production(3, {5}));
  //X → R L ;
  grammar.addProd(4, Production(5, {6,7,21}));
  //R → i
  grammar.addProd(5, Production(6, {13}));
  //R → f
  grammar.addProd(6, Production(6, {14}));
  //L → L , d
  grammar.addProd(7, Production(7, {7,20,15}));
  //L → d
  grammar.addProd(8, Production(7, {15}));
  //S → S Y
  grammar.addProd(9, Production(4, {4,8}));
  //Y → d = E ;
  grammar.addProd(10, Production(8, {15,30,9,21}));
  //Y → if (E) { S } e { S }
  grammar.addProd(11, Production(8, {16,22,9,23,24,4,25,18,24,4,25}));
  //Y → w(E) { S }
  grammar.addProd(12, Production(8, {17,22,9,23,24,4,25}));
  //E → E + T
  grammar.addProd(13, Production(9, {9,26,10}));
  //E → E - T
  grammar.addProd(14, Production(9, {9,27,10}));
  //E → T
  grammar.addProd(15, Production(9, {10}));
  //T → T * F
  grammar.addProd(16, Production(10, {10,28,11}));
  //T → T / F
  grammar.addProd(17, Production(10, {10,29,11}));
  //T → F
  grammar.addProd(18, Production(10, {11}));
  //F → (E)
  grammar.addProd(19, Production(11, {22,9,23}));
  //F → d
  grammar.addProd(20, Production(11, {15}));
  //F → n
  grammar.addProd(21, Production(11, {19}));
}

void ParserLR::loadTable()
{
  /*************************************************
   **     6. Cargar la tabla de AS LR             **
   *************************************************/

  //ACTION[estado][term] = Action(tipo_accion, num_accion);
  //GOTO[estado][no-term] = estado
}

int ParserLR::parse()
{

  /**************************************************
   ** 7. Implementar el algoritmo de AS LR **
   **************************************************/

  //Auxiliares
  //stack<int> pila;
  //map<Token, Action>::iterator accion;
  //vector<int> body;
  //int X, head;
  
  return -1; //failure
}

void ParserLR::error(string msg)
{
  cout << msg << endl;
  exit(EXIT_FAILURE);
}

Token ParserLR::eat()
{
  return (Token)lexer->yylex();
}

void ParserLR::aceptar(string msg)
{
  cout << msg << endl;
}
