#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <cstdio>
#include <functional>
#include <vector>

struct UnitTest_t{
	 int Failed = 0;
	 int Total = 0;
	 int CurrentFailed;
	 int CurrentTotal;
	 char const* CurrentTest;
	 std::vector<std::function<void()>> Tests;
	 void AddTest(std::function<void()> test){
		Tests.push_back(test);
	}
};
extern UnitTest_t UnitTest;

#define TEST_EQ(A, B) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(A != B){ printf("TEST_EQ FAILED: %s:%d -- %s != %s\n",__FILE__, __LINE__, #A, #B);\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_NEQ(A, B) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(A == B){ printf("TEST_NEQ FAILED: %s:%d -- %s == %s\n",__FILE__, __LINE__, #A, #B);\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_CHECK(A) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(!A){ printf("TEST_CHECK FAILED: %s:%d -- !%s\n",__FILE__, __LINE__, #A);\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_REQUIRE(A) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(!A){ printf("TEST_REQUIRE FAILED: %s:%d -- !%s\n", __FILE__, __LINE__, #A);\
		UnitTest.Failed++; UnitTest.CurrentFailed++;\
		printf("Exiting Test %s early\n", UnitTest.CurrentTest);\
		TEST_END;\
		return;}

#define TEST_CLASS(CLASS)\
	CLASS##_Test();

#define TEST_LOAD(TEST)\
	UnitTest.AddTest(Test_##TEST);

#define TEST(TEST, ...)\
	struct Test_Struct_##TEST{\
		static void Test_##TEST(){\
			TEST_BEGIN(TEST);\
			__VA_ARGS__\
			TEST_END;\
		}\
		Test_Struct_##TEST(){\
			UnitTest.AddTest(Test_##TEST);\
		}\
	};\
	Test_Struct_##TEST TEST##_t;

#define TEST_BEGIN(TEST)\
	UnitTest.CurrentTest   = #TEST;\
	UnitTest.CurrentFailed = 0;\
	UnitTest.CurrentTotal  = 0;\
	printf("----- Beginning tests for %s -----\n", #TEST);

#define TEST_END\
	printf("----- Results for         %s -----\n", UnitTest.CurrentTest);\
	printf("\t Tested: %d\n", UnitTest.CurrentTotal);\
	printf("\t Passed: %d\n", UnitTest.CurrentTotal - UnitTest.CurrentFailed);\
	printf("\t Failed: %d\n\n", UnitTest.CurrentFailed);

#define TESTS_RUN\
	for( auto const& t : UnitTest.Tests ){\
		t();\
	}

#define TEST_RESULTS_OVERALL \
	printf("Total Tested: %d\n", UnitTest.Total);\
	printf("Total Passed: %d\n", UnitTest.Total - UnitTest.Failed);\
	printf("Total Failed: %d\n\n", UnitTest.Failed);

#endif

