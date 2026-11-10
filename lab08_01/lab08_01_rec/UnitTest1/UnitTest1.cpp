#include "pch.h"
#include "CppUnitTest.h"
#include "../lab08_01_rec/lab08_01_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
	TEST_CLASS(UnitTest81rec)
	{
	public:
		TEST_METHOD(TestCount_Found)
		{
			const char* s = "BASIC programming in BASIC";
			Assert::AreEqual(10, Count(s, 0));
		}

		TEST_METHOD(TestCount_None)
		{
			const char* s = "hello world 123";
			Assert::AreEqual(0, Count(s, 0));
		}

		TEST_METHOD(TestChange_Single)
		{
			char src[100] = "Learn BASIC now";
			char dest[150];
			dest[0] = '\0';
			char* res = Change(dest, src, dest, 0);
			Assert::AreEqual("Learn Delphi now", res);
			Assert::AreEqual("Learn Delphi now", dest);
		}

		TEST_METHOD(TestChange_Multiple)
		{
			char src[100] = "BASIC and BASIC";
			char dest[150];
			dest[0] = '\0';
			char* res = Change(dest, src, dest, 0);
			Assert::AreEqual("Delphi and Delphi", res);
			Assert::AreEqual("Delphi and Delphi", dest);
		}

		TEST_METHOD(TestChange_NoMatch)
		{
			char src[100] = "C++ language";
			char dest[150];
			dest[0] = '\0';
			char* res = Change(dest, src, dest, 0);
			Assert::AreEqual("C++ language", res);
			Assert::AreEqual("C++ language", dest);
		}
	};
}