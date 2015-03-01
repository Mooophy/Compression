#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/huffman.hpp"
#include <sstream>

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

		TEST_METHOD(operator_greater_than)
		{
			auto lhs = cpr::huffman::Node<long>('a', 42);
			auto rhs = cpr::huffman::Node<long>('c', 41);
			Assert::IsTrue(lhs > rhs);
		}

		TEST_METHOD(operator_less_than)
		{
			auto lhs = cpr::huffman::Node<long>('a', 42);
			auto rhs = cpr::huffman::Node<long>('c', 41);
			Assert::IsTrue(rhs < lhs);
		}

		TEST_METHOD(operator_output)
		{
			std::stringstream stream;
			auto node = cpr::huffman::Node<long>('a', 10);
			stream << node;
			Assert::AreEqual("[a,10]", stream.str().c_str());
		}
	};
}