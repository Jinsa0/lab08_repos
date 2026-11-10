#include "pch.h"
#include "CppUnitTest.h"
#include "../lab08_01_it/lab08_01_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
	TEST_CLASS(UnitTest81it)
	{
	public:
		TEST_METHOD(TestCount_Found)
		{
			const char* s = "BASIC programming in BASIC";
			// 'B'(2), 'A'(2), 'S'(2), 'I'(2), 'C'(2) -> разом 10
			Assert::AreEqual(10, Count(s));
		}

		TEST_METHOD(TestCount_None)
		{
			const char* s = "hello world 123";
			Assert::AreEqual(0, Count(s));
		}

		TEST_METHOD(TestChange_Single)
		{
			char s[100] = "Learn BASIC now";
			char* res = Change(s);
			Assert::AreEqual("Learn Delphi now", res);
			Assert::AreEqual("Learn Delphi now", s);
		}

		TEST_METHOD(TestChange_Multiple)
		{
			char s[100] = "BASIC and BASIC";
			char* res = Change(s);
			Assert::AreEqual("Delphi and Delphi", res);
			Assert::AreEqual("Delphi and Delphi", s);
		}

		TEST_METHOD(TestChange_NoMatch)
		{
			char s[100] = "C++ language";
			char* res = Change(s);
			Assert::AreEqual("C++ language", res);
			Assert::AreEqual("C++ language", s);
		}
	};
}