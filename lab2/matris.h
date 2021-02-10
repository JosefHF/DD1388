#include <vector>
#include <initializer_list>
template <class T>
class Matris {
   public:
      // constructors
      Matris();
      Matris(T x);
      Matris(T rows, T columns);
      Matris(const Matris<T>& m);
      Matris(std::initializer_list<T> list);
      ~Matris();

      //Operators
      T& operator()(const T& x, const T& y); // (x,y) operator
      const T& operator()(const T& x, const T& y) const; // const (x,y) operator

      Matris<T>& operator=(const Matris<T>& m); // = operator
      Matris<T> operator+(const Matris<T>& m); // + operator
      Matris<T> operator+(const T scalar);     // + operator
      Matris<T> operator-(const Matris<T>& m); // - operator
      Matris<T> operator-(const T scalar);     // - operator
      Matris<T> operator*(const Matris<T>& m); // * operator
      Matris<T> operator*(const T scalar);     // * operator

      void operator+=(const Matris<T>& m);
      void operator-=(const Matris<T>& m);
      void operator*=(const Matris<T>& m);

      friend std::ostream& operator<<(std::ostream& out, const Matris<T>& m) {
         out << "Rows: " << m.m_rows << " Columns: " << m.m_cols << std::endl;
         for(int i=0; i<m.m_rows; i++){
            for(int j=0; j<m.m_cols; j++){
               out << m.m_vec[m.m_cols*i+j] << " ";
            }
            out << "" << std::endl;
         } 
         return out;
      }

      friend std::istream& operator>>(std::istream& input, Matris<T>& m)
      {
         std::vector<T> v;
         T c;
         int rows = 0;
         int cols = 0;
         int total_num = 0;
         std::string line;

         while(std::getline(input,line)){
            std::stringstream ss(line);
            rows += 1;
            while(!ss.eof()){
               ss >> c;
               total_num += 1;
               while(ss.peek() != ' ' && ss.peek() != EOF){
                  ss >> c;
                  total_num += 1;
               }
               //std::cout << c << std::endl;
               v.push_back(c);
            }
         }

         cols = total_num/rows;
         if(cols * rows != total_num){
            std::cerr << "Bad dimensions" << std::endl;
            return input;
         }
         else{
            m.m_rows = rows;
            m.m_cols = cols;
            m.m_capacity = rows*cols;
            m.m_vec = new T[m.m_capacity];

            for(int i=0; i<m.m_capacity; i++){
               m.m_vec[i] = v[i];
            }
            return input;
         }
         
         

         //std::cout << rows << " " << total_num << " " << std::endl;
         return input;
      }

      //METHODS
      T getRows();
      T getCols();
      T getCapacity();
      void setValue(int x, int y, T c);
      void reset();
      Matris<T> identity(unsigned int);
      void insert_row(unsigned int row_number);
      void append_row(unsigned int row_number);
      void remove_row(unsigned int row_number);
      void remove_column(unsigned int column_number);
      void insert_column(unsigned int column_number);
      void append_column(unsigned int column_number);
      T* begin();
      T* end();

   private:
      T m_rows;
      T m_cols;
      T m_capacity;
      T * m_vec;
};