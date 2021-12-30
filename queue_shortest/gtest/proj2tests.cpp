#include "gtest/gtest.h"
#include "LLQueue.hpp"
#include "proj2.hpp"
#include <string>
#include <iostream>


namespace{


// NOTE:  these are not intended as exhaustive tests.
	// This should get you started testing.
	// You should make your own additional tests for both queue
	// and for the social network question.
	// VERY IMPORTANT:  if your LLQueue is not templated, or if 
	//		it is not linked-list based, your score for this project
	//		will be zero.  Be sure your LLQueue compiles and runs 
	// 		with non-numeric data types. 

TEST(QueueTest, QueueTestFront1)
{
	LLQueue<int> a;
	a.enqueue(5);
	EXPECT_TRUE( a.front() == 5 );
}

TEST(QueueTest, QueueTestFrontString1)
{
	LLQueue<std::string> a;
	a.enqueue("asdf");
	EXPECT_TRUE( a.front() == "asdf" );
}

TEST(QueueTest, QueueTestFront2)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	EXPECT_TRUE( a.front() == 5 );
}


TEST(QueueTest, QueueTestFront3)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.dequeue();
	EXPECT_TRUE( a.front() == 3 );
}
TEST(QueueTest, SizeStartsAtZero)
{
	LLQueue<int> a;
	ASSERT_EQ(a.size(), 0);
}

TEST(QueueTest, SizeTests1)
{
	LLQueue<int> a;
	a.enqueue(1);
	ASSERT_EQ(a.size(), 1);
	a.enqueue(2);
	ASSERT_EQ(a.size(), 2);
	a.enqueue(3);
	ASSERT_EQ(a.size(), 3);

}

TEST(QueueTest, SizeTests2)
{
	LLQueue<int> a;
	a.enqueue(1);
	ASSERT_EQ(a.size(), 1);
	a.enqueue(2);
	ASSERT_EQ(a.size(), 2);
	a.enqueue(3);
	ASSERT_EQ(a.size(), 3);
	a.dequeue();
	ASSERT_EQ(a.size(), 2);
	a.dequeue();
	ASSERT_EQ(a.size(), 1);

}

TEST(QueueTest, IsEmpty1)
{
	LLQueue<int> a;
	ASSERT_TRUE(a.isEmpty());

}

TEST(QueueTest, IsEmpty2)
{
	LLQueue<int> a;
	a.enqueue(1);
	ASSERT_FALSE(a.isEmpty());

}

TEST(QueueTest, IsEmpty3)
{
	LLQueue<int> a;
	a.enqueue(1);
	a.dequeue();
	ASSERT_TRUE(a.isEmpty());

}

TEST(QueueTest, ExceptionThrowFront)
{
	LLQueue<int> a;
	ASSERT_THROW(a.front(), QueueEmptyException); 
	

}

TEST(QueueTest, ExceptionThrowDequeue)
{
	LLQueue<int> a;
	ASSERT_THROW(a.dequeue(), QueueEmptyException); 
	

}



TEST(QueueTest, SizeTests3)
{
	LLQueue<int> a;
	a.enqueue(1);
	ASSERT_EQ(a.size(), 1);
	a.enqueue(2);
	ASSERT_EQ(a.size(), 2);
	a.enqueue(3);
	ASSERT_EQ(a.size(), 3);
	a.dequeue();
	ASSERT_EQ(a.size(), 2);
	a.dequeue();
	ASSERT_EQ(a.size(), 1);
	a.dequeue();
	ASSERT_EQ(a.size(), 0);
	ASSERT_THROW(a.dequeue(), QueueEmptyException);
}

TEST(QueueTest, SizeTestsStrings4)
{
	LLQueue<std::string> a;
	a.enqueue("asdf");
	ASSERT_EQ(a.size(), 1);
	a.enqueue("asasdfdf");
	ASSERT_EQ(a.size(), 2);
	a.enqueue("as123df");
	ASSERT_EQ(a.size(), 3);
	LLQueue<std::string> b = a;
	a.dequeue();
	ASSERT_EQ(a.size(), 2);
	a.dequeue();
	ASSERT_EQ(a.size(), 1);
	a.dequeue();
	ASSERT_EQ(a.size(), 0);
	ASSERT_EQ(b.front(), "asdf");
}


TEST(QueueTest, CopyConstructor1)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(6);
	a.enqueue(7);
	a.enqueue(8);
	LLQueue<int> b = a;
	ASSERT_EQ(b.front(),a.front());
	a.dequeue();
	ASSERT_FALSE(b.front() == a.front());
	a.dequeue();
	ASSERT_EQ(b.front(), 5);
	ASSERT_EQ(b.size(), 4);

}

TEST(QueueTest, EqualsOperator)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(6);
	a.enqueue(7);
	a.enqueue(8);
	LLQueue<int> b;
	b.enqueue(1);
	b.enqueue(2);
	b.enqueue(3);
	a = b;
	ASSERT_EQ(a.size(), b.size());
	ASSERT_EQ(a.front(), b.front());
	ASSERT_EQ(a.front(), 1);
	b.dequeue();
	ASSERT_FALSE(b.front() == a.front());
	b.dequeue();
	ASSERT_EQ(a.front(), 1);
	ASSERT_EQ(a.size(), 3);

}

TEST(QueueTest, EqualsOperator1)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(6);
	a.enqueue(7);
	a.enqueue(8);
	LLQueue<int> b;
	b = a;
	ASSERT_EQ(a.size(), b.size());
	ASSERT_EQ(a.front(), b.front());
	a.dequeue();
	ASSERT_FALSE(b.front() == a.front());
	a.dequeue();
	ASSERT_EQ(b.front(), 5);
	ASSERT_EQ(b.size(), 4);

}

TEST(GraphTest, GraphTest1)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2}, {0,3}, {0,3}, {1,2}
	};
		std::vector<unsigned> pathLengths(4);
	std::vector<unsigned> numShortestPaths(4);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2};


	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}


TEST(GraphTest, GraphTest2)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5}, {0, 5}, {3, 4}
	};
	
	std::vector<unsigned> pathLengths(6);
	std::vector<unsigned> numShortestPaths(6);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1};
	
	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);
}

TEST(GraphTest, GraphTest3)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1, 2, 4}, {0,3}, {0,3}, {1,2,5, 7}, {0, 5, 6}, {3, 4}, {4, 7}, {3, 6},
	};
	
	std::vector<unsigned> pathLengths(8);
	std::vector<unsigned> numShortestPaths(8);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0, 1, 1, 2, 1, 2, 2, 3};
	std::vector<unsigned> expNumSP = {1, 1, 1, 2, 1, 1, 1, 3};


	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}
TEST(GraphTest, GraphTest4)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2,3},{0,4},{0,4},{0,4},{1,2,3},
	};
	
	std::vector<unsigned> pathLengths(5);
	std::vector<unsigned> numShortestPaths(5);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0,1,1,1,2};
	std::vector<unsigned> expNumSP = {1,1,1,1,3};
	

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}
TEST(GraphTest, GraphTest5)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2},{0,2},{0,1},
	};
	
	std::vector<unsigned> pathLengths(3);
	std::vector<unsigned> numShortestPaths(3);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0,1,1};
	std::vector<unsigned> expNumSP = {1,1,1};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}
TEST(GraphTest, GraphTest6)
{
	std::vector< std::vector<unsigned> > g1 = {
		{1,2,3,4,5}, {0,2}, {0,1,6}, {0,6}, {0,6}, {0,6}, {2,3,5,4}
	};
	
	std::vector<unsigned> pathLengths(7);
	std::vector<unsigned> numShortestPaths(7);
	
	countPaths(g1, 0, pathLengths, numShortestPaths);

	std::vector<unsigned> expPathLengths = {0,1,1,1,1,1,2};
	std::vector<unsigned> expNumSP = {1,1,1,1,1,1,4};

	EXPECT_TRUE(pathLengths == expPathLengths && expNumSP == numShortestPaths);

}
}
code 