#include <cxxtest/TestSuite.h>

#include "DataTypes.hpp"

class TestC1 : public CxxTest::TestSuite 
{
  public:
    void setUp()
    {
    }
    void tearDown()
    {
    }

    void testConstructor1()
    {
      C1 stdfStr;
      TS_ASSERT_SAME_DATA(stdfStr.mData, " ", 1);
      TS_ASSERT_EQUALS(stdfStr.to_string(), " ");
      TS_ASSERT_EQUALS(stdfStr.storage(), 1u);
    }

    void testConstructor2()
    {
      C1 stdfStr = "";
      TS_ASSERT_SAME_DATA(stdfStr.mData, " ", 1);
      TS_ASSERT_EQUALS(stdfStr.to_string(), " ");
      TS_ASSERT_EQUALS(stdfStr.storage(), 1u);
    }

    void testConstructor3()
    {
      C1 stdfStr;
      TS_ASSERT_SAME_DATA(stdfStr.mData, " ", 1);
      TS_ASSERT_EQUALS(stdfStr.to_string(), " ");
      TS_ASSERT_EQUALS(stdfStr.storage(), 1u);
      stdfStr = "A";
      TS_ASSERT_SAME_DATA(stdfStr.mData, "A", 1);
      TS_ASSERT_EQUALS(stdfStr.to_string(), "A");
      TS_ASSERT_EQUALS(stdfStr.storage(), 1u);
    }

    void testConstructor4()
    {
      C1 stdfStr;
      TS_ASSERT_SAME_DATA(stdfStr.mData, " ", 1);
      TS_ASSERT_EQUALS(stdfStr.to_string(), " ");
      TS_ASSERT_EQUALS(stdfStr.storage(), 1u);
      stdfStr = 'A';
      TS_ASSERT_SAME_DATA(stdfStr.mData, "A", 1);
      TS_ASSERT_SAME_DATA(stdfStr.to_string().data(), "A", 1);
      TS_ASSERT_EQUALS(stdfStr.to_string(), "A");
      TS_ASSERT_EQUALS(stdfStr.storage(), 1u);
    }

    void testWriteRead1()
    {
      const char *filename = "TestC1.testWriteRead1.txt";

      C1 stdfStrIn;
      std::ofstream outfile(filename, std::ofstream::binary);
      stdfStrIn.write(outfile);
      outfile.close();

      C1 stdfStrOut;
      std::ifstream infile(filename, std::ifstream::binary);
      stdfStrOut.read(infile);
      outfile.close();

      TS_ASSERT_SAME_DATA(stdfStrIn.mData, stdfStrOut.mData, 1);
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), " ");
      TS_ASSERT_EQUALS(stdfStrIn.storage(), 1u);
      TS_ASSERT_EQUALS(stdfStrOut.to_string(), " ");
      TS_ASSERT_EQUALS(stdfStrOut.storage(), 1u);
    }

    void testWriteRead2()
    {
      const char *filename = "TestC1.testWriteRead2.txt";

      C1 stdfStrIn("A");
      std::ofstream outfile(filename, std::ofstream::binary);
      stdfStrIn.write(outfile);
      outfile.close();

      C1 stdfStrOut;
      std::ifstream infile(filename, std::ifstream::binary);
      stdfStrOut.read(infile);
      outfile.close();

      TS_ASSERT_SAME_DATA(stdfStrIn.mData, stdfStrOut.mData, 1);
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), "A");
      TS_ASSERT_EQUALS(stdfStrIn.storage(), 1u);
      TS_ASSERT_EQUALS(stdfStrOut.to_string(), "A");
      TS_ASSERT_EQUALS(stdfStrOut.storage(), 1u);
    }

    void testWriteRead3()
    {
      const char *filename = "TestC1.testWriteRead3.txt";

      C1 stdfStrIn('A');
      std::ofstream outfile(filename, std::ofstream::binary);
      stdfStrIn.write(outfile);
      outfile.close();

      C1 stdfStrOut;
      std::ifstream infile(filename, std::ifstream::binary);
      stdfStrOut.read(infile);
      outfile.close();

      TS_ASSERT_SAME_DATA(stdfStrIn.mData, stdfStrOut.mData, 1);
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), "A");
      TS_ASSERT_EQUALS(stdfStrIn.storage(), 1u);
      TS_ASSERT_EQUALS(stdfStrOut.to_string(), "A");
      TS_ASSERT_EQUALS(stdfStrOut.storage(), 1u);
    }

};
