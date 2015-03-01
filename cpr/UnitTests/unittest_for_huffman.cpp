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
			Assert::AreEqual((unsigned char)0, node.character_);
			Assert::IsNull(node.left_);
			Assert::IsNull(node.right_);
		}
	};
}