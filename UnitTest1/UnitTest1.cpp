#include "pch.h"
#include "CppUnitTest.h"
#include "../Alg3/bst.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		BST bst;

		TEST_METHOD(InitTest1)
		{
			bst.insert(1);
			Iterator* iter = bst.create_dft_iterator();
			Assert::IsTrue(iter->next() == 1);
		}

		TEST_METHOD(InitTest2)
		{
			try
			{
				bst.create_dft_iterator();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is empty");
			}
		}
		TEST_METHOD(InsertTest1)
		{
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) bst.insert(arr[i]);
			Iterator* iter = bst.create_bft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}

		TEST_METHOD(InsertTest2)
		{
			int arr[10] = { 7, 4, 1, 0, 3, 2, 6, 5, 9, 8 };
			for (int i = 0; i < 10; i++) bst.insert(arr[i]);
			Iterator* iter = bst.create_dft_iterator();
			for (int i = 0; i < 10; i++) Assert::IsTrue(arr[i] == iter->next());
		}

		TEST_METHOD(ContainsTest1)
		{
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) {
				bst.insert(arr[i]);
				Assert::IsTrue(bst.contains(arr[i]));
			}
		}

		TEST_METHOD(ContainsTest2)
		{
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) bst.insert(arr[i]);
			Assert::IsFalse(bst.contains(11));
		}

		TEST_METHOD(ContainsTest3)
		{
			try
			{
				bst.contains(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is empty");
			}
		}

		TEST_METHOD(RemoveTest1)
		{
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) bst.insert(arr[i]);
			bst.remove(1);
			Assert::IsFalse(bst.contains(1));
		}

		TEST_METHOD(RemoveTest2)
		{
			int arr[10] = { 7, 4, 9, 1, 6, 8, 0, 3, 5, 2 };
			for (int i = 0; i < 10; i++) bst.insert(arr[i]);
			try
			{
				bst.remove(11);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This element isn`t in tree");
			}
		}

		TEST_METHOD(RemoveTest3)
		{
			try
			{
				bst.remove(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "This tree is empty");
			}
		}

	};
}