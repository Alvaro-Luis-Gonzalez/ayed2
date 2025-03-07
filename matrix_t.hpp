// AUTOR: Álvaro Luis González
// FECHA: 07/03/2025
// EMAIL: alu0101575582@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t
{
public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);

  vector_t<T> get_main_diagonal() const;
  T sum_secondary_diagonal() const;

  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};



template<class T>
matrix_t<T>::matrix_t(const int m, const int n)
{ 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
matrix_t<T>::~matrix_t()
{}



template<class T>
void
matrix_t<T>::resize(const int m, const int n)
{
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}



template<class T>
inline int
matrix_t<T>::get_m() const
{
  return m_;
}



template<class T>
inline int
matrix_t<T>::get_n() const
{
  return n_;
}



template<class T>
T&
matrix_t<T>::at(const int i, const int j)
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
T&
matrix_t<T>::operator()(const int i, const int j)
{
  return at(i, j);
}



template<class T>
const T&
matrix_t<T>::at(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}



template<class T>
const T&
matrix_t<T>::operator()(const int i, const int j) const
{
  return at(i, j);
}



template<class T>
void
matrix_t<T>::write(ostream& os) const
{ 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}



template<class T>
void
matrix_t<T>::read(istream& is)
{
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}


template<class T>
inline
int
matrix_t<T>::pos(const int i, const int j) const
{
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
template<class T>
void
matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B)
{
  assert(A.get_n() == B.get_m()); // Asegurar que las dimensiones son compatibles para la multiplicación

  const int m = A.get_m(); // Número de filas de la matriz resultante
  const int n = B.get_n(); // Número de columnas de la matriz resultante
  const int p = A.get_n(); // Número de columnas de A (o filas de B)

  resize(m, n); // Redimensionar la matriz actual para que tenga las dimensiones del resultado

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      T sum = T(); // Inicializar la suma para el elemento (i, j) con el valor por defecto de T
      for (int k = 1; k <= p; ++k) {
        sum = sum + (A(i, k) * B(k, j)); // Sumar los productos de los elementos correspondientes
      }
      at(i, j) = sum; // Asignar la suma al elemento (i, j) de la matriz resultante
    }
  }
}

template <class T>
vector_t<T>
matrix_t<T>::get_main_diagonal() const {
  assert(get_m() == get_n()); // Asegurar que la matriz es cuadrada

  vector_t<T> diagonal(get_m()); // Crear un vector del tamaño de la diagonal

  for (int i = 1; i <= get_m(); ++i) {
    diagonal[i - 1] = at(i, i); // Copiar los elementos de la diagonal al vector
  }

  return diagonal; // Devolver el vector con la diagonal principal
}

template<class T>
T
matrix_t<T>::sum_secondary_diagonal() const {
  T sum = T();
  for (int i = 1; i <= get_m(); ++i) {
    sum = sum + at(i, get_n() - i + 1);
  }
  return sum; // Devolver la suma
}
