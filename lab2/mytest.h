#include <cxxtest/TestSuite.h>
#include "matris.cpp"

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  // void testConstructors( void )
  // {
  // 	//DEFUALT
  //   Matris<int> m1;
  //   TS_ASSERT(m1.getCapacity() == 0);
  //   TS_ASSERT(m1.getRows() == 0);
  //   TS_ASSERT(m1.getCols() == 0);

  //   //Square
  //   Matris<int> m2(3);
  // 	TS_ASSERT(m2.getCapacity() == 9);
  // 	TS_ASSERT(m2.getCols() == 3);
  // 	TS_ASSERT(m2.getRows() == 3);
  // 	TS_ASSERT(m2(1,1) == 0);

  // 	//(rows, cols)
  // 	Matris<int> m3(3,2);
  // 	TS_ASSERT(m3.getCapacity() == 6);
  // 	TS_ASSERT(m3.getCols() == 2);
  // 	TS_ASSERT(m3.getRows() == 3);

  // 	//copy
  // 	m3(1,1) = 3;
  // 	Matris<int> m4(m3);
  // 	TS_ASSERT(m4(1,1) == 3);
  // 	TS_ASSERT(m4.getCapacity() == 6);
  // 	TS_ASSERT(m4.getCols() == 2);
  // 	TS_ASSERT(m4.getRows() == 3);

  // 	//initializerlist NEED TO BE SQUARE MATRIX
  // 	Matris<int> m5 = {1,2,3,4,5,6,7,8,9};

  // 	TS_ASSERT(m5(1,0)==4);
  // 	TS_ASSERT(m5.getCapacity() == 9);
  // 	TS_ASSERT(m5.getRows() == 3);
  // 	TS_ASSERT(m5.getCols() == 3);

  // }
  // void testIndexingOperator( void )
  // {
  // 	Matris<int> m5 = {1,2,3,4,5,6,7,8,9};

  // 	TS_ASSERT(m5(2,2) == 9);
  // }
  void testAssignmentOperator( void )
  {
  	Matris<int> m1 = {1,2,3,4,5,6,7,8,9};
  	Matris<int> m2 = m1;

  	TS_ASSERT(m2(1,1) == m1(1,1));
    TS_ASSERT(m2.getCapacity() == m1.getCapacity());

    m1 = m1;
    TS_ASSERT(m1.getCapacity() == m2.getCapacity());
  }

  void testAddition ( void ){
    Matris<int> m1 = {1,2,3,4,5,6,7,8,9};
    Matris<int> m2 = {2,4,6,8,10,12,14,16,18};
    Matris<int> m3;

    m3 = m1 + m2;

    TS_ASSERT(m3(0,0) == 3);
    TS_ASSERT(m1(0,0) == 1);
    TS_ASSERT(m2(0,0) == 2);

    m1 += m1;

    TS_ASSERT(m1(0,0) == 2);

    m1 = m1 + 1;

    TS_ASSERT(m1(0,0) == 3);
  }

  void testSubtraction ( void ){
    Matris<int> m1 = {1,2,3,4,5,6,7,8,9};
    Matris<int> m2 = {2,4,6,8,10,12,14,16,18};
    Matris<int> m3;

    m3 = m1 - m2;

    TS_ASSERT(m3(0,0) == -1);
    TS_ASSERT(m1(0,0) == 1);
    TS_ASSERT(m2(0,0) == 2);

    m1 -= m1;

    TS_ASSERT(m1(0,0) == 0);

    m1 = m1 + 1;

    TS_ASSERT(m1(0,0) == 1);

  }

  void testMultiplication ( void ) {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {2,4,6,8};
    Matris<int> m3;
    m3 = m1 * m2;

    TS_ASSERT(m3(0,0) == 14);
    TS_ASSERT(m1(0,0) == 1);
    TS_ASSERT(m2(0,0) == 2);

    m1 *= m1;
    TS_ASSERT(m1(0,0) == 7);

    m2 = m1 * 2;

    TS_ASSERT(m2(0,0) == 14);
    TS_ASSERT(m1(0,0) == 7);
  }
  void testIstream( void )
  {
  	Matris<int> m;
  	std::istringstream ss("1 2 3\n4 5 6"); // Create istringstream
    ss >> m;
    TS_ASSERT(m(0,0) == 1);
    TS_ASSERT(m.getCapacity() == 6);
    TS_ASSERT(m.getRows() == 2);
    TS_ASSERT(m.getCols() == 3);
  }
  void testGetRows( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {2,4,6,8,4,5,2,3,4};
    Matris<int> m3;
    Matris<int> m4(10);
    Matris<int> m5(3,4);

    TS_ASSERT(m1.getRows() == 2);
    TS_ASSERT(m2.getRows() == 3);
    TS_ASSERT(m3.getRows() == 0);
    TS_ASSERT(m4.getRows() == 10);
    TS_ASSERT(m5.getRows() == 3);
  }
  void testGetCols( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {2,4,6,8,4,5,2,3,4};
    Matris<int> m3;
    Matris<int> m4(10);
    Matris<int> m5(3,4);

    TS_ASSERT(m1.getCols() == 2);
    TS_ASSERT(m2.getCols() == 3);
    TS_ASSERT(m3.getCols() == 0);
    TS_ASSERT(m4.getCols() == 10);
    TS_ASSERT(m5.getCols() == 4);
  }
  void testSetValue( void )
  {
    Matris<int> m1 = {1,2,3,4};

    m1.setValue(0,0,10);
    TS_ASSERT(m1(0,0) == 10);
    TS_ASSERT(m1(0,1) == 2);
    TS_ASSERT(m1(1,0) == 3);
    TS_ASSERT(m1(1,1) == 4);
  }
  void testReset( void )
  {
    Matris<int> m1 = {1,2,3,4};
    m1.reset();

    TS_ASSERT(m1.getCols() == 0);
    TS_ASSERT(m1.getRows() == 0);
    TS_ASSERT(m1.getCapacity() == 0);
  }
  void testIdentity( void )
  {
    Matris<int> m1 = {1,2,3,4};

    Matris<int> m2 = m1.identity(2);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(0,1) == 0);
    TS_ASSERT(m2(1,0) == 0);
    TS_ASSERT(m2(1,1) == 1);
  }
  void testInsertRow( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {1,2,3,4};
    m1.insert_row(0);
    m2.insert_row(1);

    TS_ASSERT(m1(0,0) == 0);
    TS_ASSERT(m1(0,1) == 0);
    TS_ASSERT(m1(1,0) == 1);
    TS_ASSERT(m1(1,1) == 2);
    TS_ASSERT(m1(2,0) == 3);
    TS_ASSERT(m1(2,1) == 4);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(0,1) == 2);
    TS_ASSERT(m2(1,0) == 0);
    TS_ASSERT(m2(1,1) == 0);
    TS_ASSERT(m2(2,0) == 3);
    TS_ASSERT(m2(2,1) == 4);

    TS_ASSERT_THROWS_ANYTHING(m2.insert_row(-1));
    TS_ASSERT_THROWS_ANYTHING(m2.insert_row(4));
  }

  void testAppendRow( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {1,2,3,4};
    m1.append_row(0);
    m2.append_row(1);

    TS_ASSERT(m1(0,0) == 1);
    TS_ASSERT(m1(0,1) == 2);
    TS_ASSERT(m1(1,0) == 0);
    TS_ASSERT(m1(1,1) == 0);
    TS_ASSERT(m1(2,0) == 3);
    TS_ASSERT(m1(2,1) == 4);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(0,1) == 2);
    TS_ASSERT(m2(1,0) == 3);
    TS_ASSERT(m2(1,1) == 4);
    TS_ASSERT(m2(2,0) == 0);
    TS_ASSERT(m2(2,1) == 0);

    TS_ASSERT(m1.getCapacity() == 6);
    TS_ASSERT(m2.getCapacity() == 6);

    TS_ASSERT_THROWS_ANYTHING(m2.append_row(-1));
    TS_ASSERT_THROWS_ANYTHING(m2.append_row(4));
  }
  void testRemoveRow( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {1,2,3,4};
    m1.remove_row(0);
    m2.remove_row(1);

    TS_ASSERT(m1(0,0) == 3);
    TS_ASSERT(m1(0,1) == 4);
    TS_ASSERT(m1.getCapacity() == 2);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(0,1) == 2);
    TS_ASSERT(m2.getCapacity() == 2);

    TS_ASSERT_THROWS_ANYTHING(m2.remove_row(-1));
    TS_ASSERT_THROWS_ANYTHING(m2.remove_row(2));
  }
  void testInsertCol( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {1,2,3,4};
    m1.insert_column(0);
    m2.insert_column(1);

    TS_ASSERT(m1(0,0) == 0);
    TS_ASSERT(m1(0,1) == 1);
    TS_ASSERT(m1(0,2) == 2);
    TS_ASSERT(m1(1,0) == 0);
    TS_ASSERT(m1(1,1) == 3);
    TS_ASSERT(m1(1,2) == 4);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(0,1) == 0);
    TS_ASSERT(m2(0,2) == 2);
    TS_ASSERT(m2(1,0) == 3);
    TS_ASSERT(m2(1,1) == 0);
    TS_ASSERT(m2(1,2) == 4);

    TS_ASSERT_THROWS_ANYTHING(m2.insert_column(-1));
    TS_ASSERT_THROWS_ANYTHING(m2.insert_column(4));
  }

  void testAppendCol( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {1,2,3,4};
    m1.append_column(0);
    m2.append_column(1);

    TS_ASSERT(m1(0,0) == 1);
    TS_ASSERT(m1(0,1) == 0);
    TS_ASSERT(m1(0,2) == 2);
    TS_ASSERT(m1(1,0) == 3);
    TS_ASSERT(m1(1,1) == 0);
    TS_ASSERT(m1(1,2) == 4);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(0,1) == 2);
    TS_ASSERT(m2(0,2) == 0);
    TS_ASSERT(m2(1,0) == 3);
    TS_ASSERT(m2(1,1) == 4);
    TS_ASSERT(m2(1,2) == 0);

    TS_ASSERT(m1.getCapacity() == 6);
    TS_ASSERT(m2.getCapacity() == 6);

    TS_ASSERT_THROWS_ANYTHING(m2.append_column(-1));
    TS_ASSERT_THROWS_ANYTHING(m2.append_column(4));
  }
  void testRemoveCol( void )
  {
    Matris<int> m1 = {1,2,3,4};
    Matris<int> m2 = {1,2,3,4};
    m1.remove_column(0);
    m2.remove_column(1);

    TS_ASSERT(m1(0,0) == 2);
    TS_ASSERT(m1(1,0) == 4);

    TS_ASSERT(m2(0,0) == 1);
    TS_ASSERT(m2(1,0) == 3);

    TS_ASSERT(m1.getCapacity() == 2);
    TS_ASSERT(m2.getCapacity() == 2);

    TS_ASSERT_THROWS_ANYTHING(m2.remove_column(-1));
    TS_ASSERT_THROWS_ANYTHING(m2.remove_column(2));
  }
  void testBegin( void )
  {
    Matris<int> m1 = {1,2,3,4};
    TS_ASSERT(*m1.begin() == 1);
  }
  void testEnd( void )
  {
    Matris<int> m1 = {1,2,3,4};
    TS_ASSERT(*m1.end() == 4);
  }
};