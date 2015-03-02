#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/node.hpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
	using Node = cpr::huffman::Node <unsigned char, unsigned long > ;

	TEST_CLASS(UnitTestForNode)
	{
	public:
		
		TEST_METHOD(test_default_ctor)
		{
			Node node;

			Assert::AreEqual((unsigned char)0, node.character_);
			Assert::AreEqual(0ul, node.freq_);
			Assert::IsNull(node.left_.get());
			Assert::IsNull(node.right_.get());
		}

		TEST_METHOD(test_ctor_with_2_args)
		{
			Node node{'a', 42ul};

			Assert::AreEqual((unsigned char)'a', node.character_);
			Assert::AreEqual(42ul, node.freq_);
			Assert::IsNull(node.left_.get());
			Assert::IsNull(node.right_.get());
		}

		TEST_METHOD(test_is_leaf)
		{
			Node node;
			Assert::IsTrue(node.is_leaf());
		}

		TEST_METHOD(test_make_new_node_without_args)
		{
			auto pointer = cpr::huffman::make_new_node<unsigned char, unsigned long>();

			Assert::AreEqual((unsigned char)0, pointer->character_);
			Assert::AreEqual(0ul, pointer->freq_);
			Assert::IsNull(pointer->left_.get());
			Assert::IsNull(pointer->right_.get());
		}

		TEST_METHOD(test_make_new_node_with_2_args)
		{
			auto pointer = cpr::huffman::make_new_node<unsigned char, unsigned long>('a', 42ul);

			Assert::AreEqual((unsigned char)'a', pointer->character_);
			Assert::AreEqual(42ul, pointer->freq_);
			Assert::IsNull(pointer->left_.get());
			Assert::IsNull(pointer->right_.get());
		}

		TEST_METHOD(test_for_shared_pointer)
		{
			auto pointer = cpr::huffman::make_new_node<unsigned char, unsigned long>('a', 42ul);
			auto p2 = pointer;
			auto p3 = p2;
		}

		TEST_METHOD(operator_greater_than)
		{
			// note there is a type conversion here:
			auto lhs = Node('a', 42);
			auto rhs = Node('c', 41);
			Assert::IsTrue(lhs > rhs);
		}

		TEST_METHOD(operator_less_than)
		{
			// note there is a type conversion here:
			auto lhs = Node('a', 42);
			auto rhs = Node('c', 41);
			Assert::IsTrue(rhs < lhs);
		}

		TEST_METHOD(operator_output)
		{
			std::stringstream stream;
			// note there is a type conversion here:
			auto node = Node('a', 10);
			stream << node;
			Assert::AreEqual("[a,10]", stream.str().c_str());
		}
	};
}