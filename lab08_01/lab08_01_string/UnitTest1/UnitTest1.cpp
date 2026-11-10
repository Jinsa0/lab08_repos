#include "pch.h"
#include "CppUnitTest.h"
#include "../lab08_01_string/lab08_01_string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81string
{
	TEST_CLASS(UnitTest81string)
	{
	public:
		TEST_METHOD(TestCount_Found)
		{
			string s = "BASIC programming in BASIC";
			Assert::AreEqual(10, Count(s));
		}

		TEST_METHOD(TestCount_None)
		{
			string s = "hello world 123";
			Assert::AreEqual(0, Count(s));
		}

		TEST_METHOD(TestChange_Single)
		{
			string s = "Learn BASIC now";
			string res = Change(s);
			Assert::AreEqual(string("Learn Delphi now"), res);
			Assert::AreEqual(string("Learn Delphi now"), s);
		}

		TEST_METHOD(TestChange_Multiple)
		{
			string s = "BASIC and BASIC";
			string res = Change(s);
			Assert::AreEqual(string("Delphi and Delphi"), res);
			Assert::AreEqual(string("Delphi and Delphi"), s);
		}

		TEST_METHOD(TestChange_NoMatch)
		{
			string s = "C++ language";
			string res = Change(s);
			Assert::AreEqual(string("C++ language"), res);
			Assert::AreEqual(string("C++ language"), s);
		}
	};
}