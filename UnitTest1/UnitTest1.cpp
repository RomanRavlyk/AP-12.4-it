#include "pch.h"
#include "CppUnitTest.h"
#include "..//AP 12.4 it/AP 12.4 it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* list = nullptr;
			insert(list, 10);
			Assert::AreEqual(10, list->info);
		}
	};
}
