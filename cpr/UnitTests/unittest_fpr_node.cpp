#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/node.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests_for_huffman
{		
	TEST_CLASS(UnitTestForNode)
	{
	public:
		
		TEST_METHOD(test_ctor)
		{
			auto node = cpr::huffman::Node();

			Assert::IsNull(node.left_.get());
			Assert::IsNull(node.right_.get());
			Assert::AreEqual((uint8_t)0, node.character_);
			Assert::AreEqual((uint64_t)0, node.freq_);
		}

		TEST_METHOD(test_ctor_with_2_args)
		{
			auto node = cpr::huffman::Node('a', 42);
			Assert::IsNull(node.left_.get());
			Assert::IsNull(node.right_.get());
			Assert::AreEqual((uint8_t)'a', node.character_);
			Assert::AreEqual((uint64_t)42, node.freq_);

			node.left_ = std::make_unique<cpr::huffman::Node>('b', 41);
			node.right_ = std::make_unique<cpr::huffman::Node>('c', 99);
			Assert::IsNotNull(node.left_.get());
			Assert::IsNotNull(node.right_.get());
		}

		TEST_METHOD(test_move_ctor)
		{
			auto moved_from = cpr::huffman::Node('a', 42);
			moved_from.left_ = std::make_unique<cpr::huffman::Node>('b', 41);
			moved_from.right_ = std::make_unique<cpr::huffman::Node>('c', 99);
			auto moved_to = cpr::huffman::Node(std::move(moved_from));

			Assert::IsNull(moved_from.left_.get());
			Assert::IsNull(moved_from.right_.get());

			Assert::IsNotNull(moved_to.left_.get());
			Assert::AreEqual((uint8_t)'b', moved_to.left_->character_);
			Assert::AreEqual((uint64_t)41, moved_to.left_->freq_);

			Assert::IsNotNull(moved_to.right_.get());
			Assert::AreEqual((uint8_t)'c', moved_to.right_->character_);
			Assert::AreEqual((uint64_t)99, moved_to.right_->freq_);

			Assert::AreEqual((uint8_t)'a', moved_to.character_);
			Assert::AreEqual((uint64_t)42, moved_to.freq_);
		}
	};
}