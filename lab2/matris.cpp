#include <iostream>
#include <ostream>
#include <sstream>
#include <initializer_list>
#include "matris.h"

//DEFAULT
template <class T>
Matris<T>::Matris(){
	m_rows = 0;
	m_cols = 0;
	m_capacity = 0;
	m_vec = new T[0];
}

template <class T>
Matris<T>::Matris(T dim){
	m_rows = dim;
	m_cols = dim;
	m_capacity = dim*dim;
	m_vec = new T[dim*dim];

	for(int i=0; i<m_capacity; i++){
		m_vec[i] = 0;
	}
}
template <class T>
Matris<T>::Matris(T rows, T cols){
	m_rows = rows;
	m_cols =cols;
	m_capacity = rows*cols;
	m_vec = new T[rows*cols];
}
//COPY
template <class T> 
Matris<T>::Matris(const Matris<T>& m){
    m_rows = m.m_rows;
    m_cols = m.m_cols;
    m_capacity = m.m_capacity;
    m_vec = new T[m_capacity];
    for(int i=0; i<m_capacity; i++){
    	m_vec[i] = m.m_vec[i];
    }
}
template<class T>  
   Matris<T>::Matris(std::initializer_list<T> list)
   {
      if (list.size() >= 0) {
 
        long double sr = sqrt(list.size());
        if(sr * sr == list.size())
        {
         m_rows = sr;
         m_cols = sr;
         m_capacity = list.size();
         m_vec = new T[m_capacity];
         int i = 0;
         for(T e : list){
            m_vec[i] = e;
            i++;
         }
        }
      }
      else{
         throw std::out_of_range ("Out of range");
      }
   }
template <class T> 
Matris<T>::~Matris(){
	delete[] m_vec;
	//std::cout << "destructor called" << std::endl;
}

// ######################## Operators #########################
template<class T>  
   T& Matris<T>::operator()(const T& row, const T& col)
   {
      return m_vec[m_cols * row + col];
   }
template<class T>  
   const T& Matris<T>::operator()(const T& row,const T& col) const
   {
      return m_vec[m_cols * row + col];
   }

template<class T>  
   Matris<T>& Matris<T>::operator=(const Matris<T>& m)
   {
      if (&m == this){
          return *this;
      }
      m_cols = m.m_cols;
      m_rows = m.m_rows;
      m_capacity = m.m_capacity;
      m_vec = new T[m_capacity];
      for(int i=0; i<m_rows; i++)
      {
         for(int j=0; j<m_cols; j++)
         {
            m_vec[m_cols*i+j] = m.m_vec[m_cols*i+j]; 
         }
      }
      return *this;
   }
template<class T>  
   Matris<T>& Matris<T>::operator+(const Matris<T>& m)
   {
      if(m_cols != m.m_cols || m_rows != m.m_rows){
         std::cerr << "We cannot add two matrices that have different dimensions" << std::endl;
      }
      else{
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] + m.m_vec[m_cols*i+j];
            }
         }
      }
      return *this;
   }

template<class T>  
   Matris<T>& Matris<T>::operator+(const T scalar)
   {
      for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] + scalar;
            }
         }
      return *this;
   }

template<class T>  
   Matris<T>& Matris<T>::operator-(const Matris<T>& m)
   {
      if(m_cols != m.m_cols || m_rows != m.m_rows){
         std::cerr << "We cannot add two matrices that have different dimensions" << std::endl;
      }
      else{
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] - m.m_vec[m_cols*i+j];
            }
         }
      }
      return *this;
   }
template<class T>  
   Matris<T>& Matris<T>::operator-(const T scalar)
   {
      for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] - scalar;
            }
         }
      return *this;
   }
template<class T>  
   Matris<T>& Matris<T>::operator*(const Matris<T>& m)
   {
    	if(m_rows == m.m_cols && m_cols == m.m_rows){
	      	Matris<T> temp(m_rows,m.m_cols);
	      	for (int i = 0; i < m_rows; i++){
	        	for (int j = 0; j < m_cols; ++j){
	            	for (int k = 0; k < m_cols; ++k){
	                	temp.m_vec[i * m.m_cols + j] += m_vec[i * m_cols + k] * m.m_vec[j + k * m_cols];
	            	}               
	        	}
	    	}
	        *this = std::move(temp);
	      	return *this;
      	}
      	else{
        	std::cerr << "We cannot add two matrices that have different dimensions" << std::endl;
        	exit(-1);
      }
   }
template<class T>  
   Matris<T>& Matris<T>::operator*(const T scalar)
   {
      for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] * scalar;
            }
         }
      return *this;
   }
template<class T>  
   void Matris<T>::operator+=(const Matris<T>& m)
   {
      if(m_cols != m.m_cols || m_rows != m.m_rows){
         std::cerr << "We cannot add two matrices that have different dimensions" << std::endl;
      }
      else{
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] + m.m_vec[m_cols*i+j];
            }
         }
      }
   }
template<class T>  
   void Matris<T>::operator-=(const Matris<T>& m)
   {
      if(m_cols != m.m_cols || m_rows != m.m_rows){
         std::cerr << "We cannot add two matrices that have different dimensions" << std::endl;
      }
      else{
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               m_vec[m_cols*i+j] = m_vec[m_cols*i+j] - m.m_vec[m_cols*i+j];
            }
         }
      }
   }
   template<class T>  
   void Matris<T>::operator*=(const Matris<T>& m)
   {
      if(m_rows == m.m_cols && m_cols == m.m_rows){
      	*this = *this * m;
      }
      else{
         std::cerr << "We cannot add two matrices that have different dimensions" << std::endl;
         exit(-1);
      }
   }

template<class T>  
   Matris<T> Matris<T>::identity(unsigned int a)
   {
      Matris<T> temp(a);
      for(int i=0; i<a; i++){
         for(int j=0; j<a; j++){
            if(i == j){
               temp.m_vec[a*i+j] = 1;
            }
            else{
               temp.m_vec[a*i+j] = 0;
            }
         }
      }
      return temp;
   }
template<class T>  
   void Matris<T>::insert_row(unsigned int row_number)
   {
      if(row_number > m_rows || row_number < 0){
         std::cerr << "Cannot insert at this row" << std::endl;
         return;
      }
      else{
         T * vec = new T[m_capacity + m_cols]; 
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols; j++){
               if(i == row_number){
                  vec[m_cols*i + j] = 0;
               }
               else if(i < row_number){
                  vec[m_cols*i+j] = m_vec[m_cols*i+j];
               }
               else{
                  vec[m_cols*(i+1) + j] = m_vec[m_cols*i + j];
               }
            }
         }
         m_capacity = m_capacity + m_cols;
         m_rows += 1;
         m_vec = vec;
      }
   }
template<class T>  
   void Matris<T>::append_row(unsigned int row_number)
   {
      if(row_number >= m_rows || row_number < 0){
         std::cerr << "Cannot insert after this row" << std::endl;
         return;
      }
      else{

         T * vec = new T[m_capacity + m_cols];
         for(int i=0; i<m_rows+1; i++){
            for(int j=0; j<m_cols; j++){
               //std::cout << "i" << i << " j" << j << " row_number" << row_number << std::endl;
               if(i == row_number + 1){
                  vec[m_cols*i + j] = 0;
               }
               else if(i <= row_number+1){
                  vec[m_cols*i+j] = m_vec[m_cols*i+j];
               }
               else{

                  vec[m_cols*i + j] = m_vec[m_cols*(i-1) + j];
               }
            }
         }
         if(row_number == m_rows && row_number != 0){
            for(int i=0; i<m_cols; i++){
               vec[m_cols*m_rows + i] = 0;
            }
         }
         m_capacity = m_capacity + m_cols;
         m_rows += 1;
         m_vec = vec;
      }
   }
template<class T>  
   void Matris<T>::remove_row(unsigned int row_number)
   {
      if(row_number >= m_rows || row_number < 0){
         std::cerr << "Cannot remove the this row" << std::endl;
         return;
      }
      else{

         T * vec = new T[m_capacity - m_cols];
         for(int i=0; i<m_rows-1; i++){
            for(int j=0; j<m_cols; j++){
               std::cout << "i" << i << " j" << j << " row_number" << row_number << std::endl;
               if(i < row_number){
                  vec[m_cols*i + j] = m_vec[m_cols*i+j];
               }
               else{
                  //std::cout << m_vec[m_cols*(i+1) * j];
                  vec[m_cols*i +j] = m_vec[m_cols*(i+1) + j];
               }
            }
         }
         m_capacity = m_capacity - m_cols;
         m_rows -= 1;
         m_vec = vec;
      }
   }
template<class T>  
   void Matris<T>::insert_column(unsigned int column_number)
   {
      if(column_number >= m_cols || column_number < 0){
         std::cerr << "Cannot insert column before the given column number" << std::endl;
         return;
      }
      else{
         T * vec = new T[m_rows*(m_cols+1)];
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols+1; j++){
               if(j < column_number){
                  vec[(m_cols+1)*i + j] = m_vec[m_cols*i + j];
               }
               else if(j == column_number){
                  vec[(m_cols+1)*i + j] = 0;
               }
               else{
                  vec[(m_cols+1)*i + j] = m_vec[m_cols*i + j-1]; 
               }
            }
         }
         m_capacity = m_rows*(m_cols+1);
         m_cols += 1;
         m_vec = vec;
      }
   }
template<class T>  
   void Matris<T>::append_column(unsigned int column_number)
   {
      if(column_number >= m_cols || column_number < 0){
         std::cerr << "Cannot insert column before the given column number" << std::endl;
         return;
      }
      else{
         T * vec = new T[m_rows*(m_cols+1)];
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols+1; j++){
               if(j <= column_number){
                  vec[(m_cols+1)*i + j] = m_vec[m_cols*i + j];
               }
               else if(j == column_number+1){
                  vec[(m_cols+1)*i + j] = 0;
               }
               else{
                  vec[(m_cols+1)*i + j] = m_vec[m_cols*i + j-1]; 
               }
            }
         }
         m_capacity = m_rows*(m_cols+1);
         m_cols += 1;
         m_vec = vec;
      }
   }

template<class T>  
   void Matris<T>::remove_column(unsigned int column_number)
   {
      if(column_number >= m_cols || column_number < 0){
         std::cerr << "Cannot remove the this column" << std::endl;
         return;
      }
      else{

         T * vec = new T[m_rows*(m_cols-1)];
         for(int i=0; i<m_rows; i++){
            for(int j=0; j<m_cols-1; j++){
               if(j>=column_number){
                  vec[(m_cols-1)*i + j] = m_vec[m_cols*i + (j+1)];
               }
               else{
                  vec[(m_cols-1)*i + j] = m_vec[m_cols*i + j];
               }
            }
         }
         m_capacity = m_rows*(m_cols-1);
         m_cols -= 1;
         m_vec = vec;
      }
   }

template<class T>  
   T* Matris<T>::begin()
   {
      return &m_vec[0];
   }
template<class T>  
   T* Matris<T>::end()
   {
      return &m_vec[m_capacity-1];
   }

template<class T>
   T Matris<T>::getCapacity(){
      return m_capacity;
   }
template<class T>
   void Matris<T>::setValue(int x, int y, T z){
      m_vec[m_cols*x + y] = z;
   }
template<class T>
   T Matris<T>::getRows()
   {
      return m_rows;
   }
template<class T>
   T Matris<T>::getCols()
   {
      return m_cols;
   }
template<class T>
   void Matris<T>::reset()
   {
      m_cols = T();
      m_rows = T();
      * m_vec = T();
   }

int main(int argc, char * argv[]) {
	//Constructors
		//Matris<int> m;
		//Matris<int> m(20);
		//Matris<int> m(5,5);
		//Matris<int> x(m);
		//Matris<int> m = {1,2,3,4};
	//Operators
		//std::cout << m(1,1) << std::endl;


	//tests
	//Matris<int> m(2);
	//m(0,0) = 1;
	//m(0,1) = 2;
	//m(1,0) = 3;
	//m(1,1) = 4;
	//m *= m;
	//std::cout << m;
	//m.remove_column(0);
	//std::cout<< m;

	//std::istringstream ss("1 2 5 4\n12 3 4 5"); // Create istringstream
    //ss >> m;

    std::cout << m << std::endl;
}