#ifndef UNITTEST_HPP
#define UNITTEST_HPP

#include <functional>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <memory>

using Test = std::pair<std::string, std::function<void()>>;
struct UnitTest_t{
	int Failed = 0;
	int Total = 0;
	int CurrentFailed;
	int CurrentTotal;
	std::string CurrentTest;
	static std::unique_ptr<std::map<std::string, std::vector<Test>>> TestGroups;
	void AddTest(std::string const& group, Test test){
		if( !TestGroups ) TestGroups.reset(new std::map<std::string, std::vector<Test>>());
		TestGroups->insert(std::make_pair(group, std::vector<Test>{}));
		TestGroups->at(group).push_back(test);
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
	if(!(A)){     std::cerr << "TEST_CHECK FAILED: " << __FILE__ << ":" << __LINE__\
		                  << " -- !" << #A << std::endl;\
		UnitTest.Failed++; UnitTest.CurrentFailed++; }

#define TEST_REQUIRE(A) UnitTest.Total++; UnitTest.CurrentTotal++;\
	if(!(A)){     std::cerr << "TEST_REQUIRE FAILED: " << __FILE__ << ":" << __LINE__\
		                  << " -- !" << #A << std::endl\
						  << "Exiting Test " << UnitTest.CurrentTest << " early\n";\
		UnitTest.Failed++; UnitTest.CurrentFailed++;\
		TEST_END;\
		return;}

#define TEST(GROUP, TEST)\
	void Test_##TEST();\
	struct Test_Struct_##TEST{\
		Test_Struct_##TEST(){\
			UnitTest.AddTest(#GROUP, std::make_pair(#TEST, Test_##TEST));\
		}\
	};\
	Test_Struct_##TEST TEST##_t;\
	void Test_##TEST()

#define TEST_BEGIN(TEST)\
	UnitTest.CurrentTest   = TEST;\
	UnitTest.CurrentFailed = 0;\
	UnitTest.CurrentTotal  = 0;\

#define TEST_END\
	std::cout << "\r" << UnitTest.CurrentTest << " (" \
	          << UnitTest.CurrentTotal << "/" \
			  << UnitTest.CurrentTotal - UnitTest.CurrentFailed << "/" \
			  << UnitTest.CurrentFailed << ")" << std::endl;

#define TESTS_RUN\
	for( auto const& group : *UnitTest.TestGroups.get() ){\
		for( auto const& test : group.second ){\
			TEST_BEGIN(group.first + "-" + std::get<0>(test));\
			std::get<1>(test)();\
			TEST_END;\
		}\
	}

#define TEST_RESULTS_OVERALL \
	std::cout << "Total (" \
	          << UnitTest.Total << "/" \
			  << UnitTest.Total - UnitTest.Failed << "/" \
			  << UnitTest.Failed << ") " \
			  << ((!!UnitTest.Failed)? "FAILED" : "PASSED") << std::endl;\
    return (!!UnitTest.Failed);

#endif

