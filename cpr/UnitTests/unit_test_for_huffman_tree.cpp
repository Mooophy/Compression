#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/node.hpp"
#include "../huffman/huffman_tree.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests_for_huffman
{
	TEST_CLASS(unit_test_for_huffman_tree)
	{
	public:
		
		TEST_METHOD(test_ctor)
		{
			using N = cpr::huffman::Node;
			auto nodes = std::vector < cpr::huffman::Node > ();
			nodes.push_back(N('a', 42));
			auto htree = cpr::huffman::HuffmanTree(nodes);
		}
	};
}