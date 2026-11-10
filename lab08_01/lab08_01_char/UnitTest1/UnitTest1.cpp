#include "pch.h"
#include "CppUnitTest.h"
#include "../lab08_01_char/lab08_01_char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:
		TEST_METHOD(TestCount_Found)
		{
			char s[100] = "BASIC programming in BASIC";
			Assert::AreEqual(10, Count(s));
		}

		TEST_METHOD(TestCount_None)
		{
			char s[100] = "hello world 123";
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