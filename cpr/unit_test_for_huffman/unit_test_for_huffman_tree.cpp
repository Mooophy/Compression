#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/huffman_tree.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
	using FrequencyMap = cpr::huffman::FrequencyMap < unsigned char, unsigned long > ;
	using HuffmanTree = cpr::huffman::HuffmanTree < unsigned char, unsigned long > ;
	TEST_CLASS(unit_test_for_huffman_tree)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			std::vector<unsigned char> test_case{ 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c' };
			FrequencyMap fmap(test_case);
			HuffmanTree htree{ fmap };
		}

	};
}