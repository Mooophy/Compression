#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/huffman.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(TestNode)
	{
	public:
		
		TEST_METHOD(default_ctor)
		{
			auto node = cpr::huffman::Node<long>();
			Assert::AreEqual((unsigned char)0, node.character_);
			Assert::AreEqual(0L, node.freq_);
			Assert::IsNull(node.left_);
			Assert::IsNull(node.right_);
		}

		TEST_METHOD(ctor_with_2_args)
		{
			auto node = cpr::huffman::Node<long>('a', 10);
			Assert::AreEqual((unsigned char)'a', node.character_);
			Assert::AreEqual(10L, node.freq_);
			Assert::IsNull(node.left_);
			Assert::IsNull(node.right_);
		}

		TEST_METHOD(copy_ctor)
		{
			auto node = cpr::huffman::Node<long>('a', 10);
			auto copy = cpr::huffman::Node<long>(node);
			Assert::AreEqual((unsigned char)'a', copy.character_);
			Assert::AreEqual(10L, copy.freq_);
			Assert::IsNull(copy.left_);
			Assert::IsNull(copy.right_);
		}

		TEST_METHOD(is_leaf)
		{
			auto node = cpr::huffman::Node<long>('a', 10);
			Assert::IsTrue(node.is_leaf());
		}
	};
}