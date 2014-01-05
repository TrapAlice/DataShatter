#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <functional>
#include <vector>
#include <iostream>
#include <string>

struct UnitTest_t{
	 int Failed = 0;
	 int Total = 0;
	 int CurrentFailed;
	 int CurrentTotal;
	 std::string CurrentTest;
	 std::vector<std::function<void()>> Tests;
	 void AddTest(std::function<void()> test){
		Tests.push_back(test);
	}
};
extern UnitTest_t UnitTest;

#define TEST_EQ(A, B) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(A != B){ std::cerr << "TEST_EQ FAILED: " << __FILE__ << ":" << __LINE__\
		                  << " -- " << #A << " != " << #B << std::endl\
	                      << "\t" << #A << " == " << A  << std::endl;\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_NEQ(A, B) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(A == B){ std::cerr << "TEST_NEQ FAILED: " << __FILE__ << ":" << __LINE__\
		                  << " -- " << #A << " == " << #B << std::endl\
	                      << "\t" << #A << " != " << A  << std::endl;\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_CHECK(A) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(!A){     std::cerr << "TEST_CHECK FAILED: " << __FILE__ << ":" << __LINE__\
		                  << " -- !" << #A << std::endl;\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_REQUIRE(A) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(!A){     std::cerr << "TEST_REQUIRE FAILED: " << __FILE__ << ":" << __LINE__\
		                  << " -- !" << #A << std::endl\
						  << "Exiting Test " << UnitTest.CurrentTest << " early\n";\
		UnitTest.Failed++; UnitTest.CurrentFailed++;\
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
	std::cout << "----- Beginning tests for " << #TEST << " -----\n"

#define TEST_END\
	std::cout << "----- Results for         " << UnitTest.CurrentTest <<" -----\n"\
	          << "\tTested: " << UnitTest.CurrentTotal << std::endl\
			  << "\tPassed: " << UnitTest.CurrentTotal - UnitTest.CurrentFailed << std::endl\
			  << "\tFailed: " << UnitTest.CurrentFailed << std::endl << std::endl;

#define TESTS_RUN\
	for( auto const& t : UnitTest.Tests ){\
		t();\
	}

#define TEST_RESULTS_OVERALL \
	std::cout << "Total Tested: " << UnitTest.Total << std::endl\
	          << "Total Passed: " << UnitTest.Total - UnitTest.Failed << std::endl\
			  << "Total Failed: " << UnitTest.Failed << std::endl << std::endl;

#endif

