#include <cxxtest/TestSuite.h>
#include "matris.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void testConstructors( void )
  {
  	//DEFUALT
    Matris<int> m1;
    TS_ASSERT(m1.getCapacity() == 0);
    TS_ASSERT(m1.getRows() == 0);
    TS_ASSERT(m1.getCols() == 0);

    //Square
    Matris<int> m2(3);
  	TS_ASSERT(m2.getCapacity() == 9);
  	TS_ASSERT(m2.getCols() == 3);
  	TS_ASSERT(m2.getRows() == 3);
  	TS_ASSERT(m2(1,1) == 0);

  	//(rows, cols)
  	Matris<int> m3(3,2);
  	TS_ASSERT(m3.getCapacity() == 6);
  	TS_ASSERT(m3.getCols() == 2);
  	TS_ASSERT(m3.getRows() == 3);

  	//copy
  	m3(1,1) = 3;
  	Matris<int> m4(m3);
  	TS_ASSERT(m4(1,1) == 3);
  	TS_ASSERT(m4.getCapacity() == 6);
  	TS_ASSERT(m4.getCols() == 2);
  	TS_ASSERT(m4.getRows() == 3);

  	//initializerlist NEED TO BE SQUARE MATRIX
  	Matris<int> m5 = {1,2,3,4,5,6,7,8,9};

  	TS_ASSERT(m5(1,0)==4);
  	TS_ASSERT(m5.getCapacity() == 9);
  	TS_ASSERT(m5.getRows() == 3);
  	TS_ASSERT(m5.getCols() == 3);

  }
  void testIndexingOperator( void )
  {
  	Matris<int> m5 = {1,2,3,4,5,6,7,8,9};

  	TS_ASSERT(m5(2,2) == 9);
  }
  void testAssignmentOperator( void )
  {
  	Matris<int> m1 = {1,2,3,4,5,6,7,8,9};
  	Matris<int> m2 = m1;

  	TS_ASSERT(m2(1,1) == m1(1,1));
  }
  void testIstream( void )
  {
  	Matris<int> m;
  	std::istringstream ss("123\n456"); // Create istringstream
    ss >> m;

    std::cout << m;
    TS_ASSERT(m(0,0) == 1);
    TS_ASSERT(m.getCapacity() == 6);
    TS_ASSERT(m.getRows() == 2);
    TS_ASSERT(m.getCols() == 3);
  }
};