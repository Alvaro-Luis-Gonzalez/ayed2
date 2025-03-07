// AUTOR: Álvaro Luis González
// FECHA: 07/03/2025
// EMAIL: alu0101575582@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#include <iostream>
#include <cmath>

// pauta de estilo [41]: ficheros de cabecera agrupados y separados
#include "rational_t.hpp"

#include "vector_t.hpp"

#include "matrix_t.hpp"

using namespace std;

int main()
{
  rational_t a(1, 2), b(3);

  // FASE I
  cout << "a + b: ";
  (a+b).write();

  cout << "b - a: ";
  (b-a).write();

  cout << "a * b: ";
  (a*b).write();
  
  cout << "a / b: ";
  (a/b).write();
  
  cout << endl;
  
  // FASE II
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  
  cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << endl << endl;
  
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  
  cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << endl << endl;
  
  
  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  C.multiply(A, B);
  cout << "Multiplicación de matrices A y B: " << endl;
  C.write();

  // MODIFICACION PRACTICA

  matrix_t<double> D;
  D.read();
  cout << "Matriz D:" << endl;
  D.write();

  double sum_secondary = D.sum_secondary_diagonal(); 
  cout << "Suma de la diagonal secundaria de D: " << sum_secondary << endl; 


  /*MODIFICACIONES

  //Formar un vector nuevo con las posiciones pares
  vector_t<double> v1(5);
  v1.set_val(0, 1.1);
  v1.set_val(1, 2.2);
  v1.set_val(2, 3.3);
  v1.set_val(3, 4.4);
  v1.set_val(4, 5.5);

  cout << "Vector original: " << endl;
  v1.write();

  vector_t<double> v3 = v1.even_positions();

  cout << "Vector con posiciones pares: " << endl;
  v3.write();

  //Meter la diagonal principal de una matriz en un vector
  matrix_t<double> D(3, 3);
  A(1, 1) = 1.1;
  A(1, 2) = 1.2;
  A(1, 3) = 1.3;
  A(2, 1) = 2.1;
  A(2, 2) = 2.2;
  A(2, 3) = 2.3;
  A(3, 1) = 3.1;
  A(3, 2) = 3.2;
  A(3, 3) = 3.3;

  cout << "Matriz A: " << endl;
  A.write();

  vector_t<double> diagonal = A.get_main_diagonal();

  cout << "Diagonal principal de A: " << endl;
  diagonal.write();
  
  */

  return 0;
}