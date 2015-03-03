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
			//case 1 made up on my own
			std::vector<unsigned char> test_case{ 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c' };
			FrequencyMap fmap(test_case);
			HuffmanTree htree{ fmap };
			Assert::IsNotNull(htree.root().get());

			
			//case 2 based on 16.3 clrs 
			auto empty_case = std::vector<unsigned char>();
			FrequencyMap fmap_from_clrs(empty_case);
			fmap_from_clrs['a'] = 45;
			fmap_from_clrs['b'] = 13;
			fmap_from_clrs['c'] = 12;
			fmap_from_clrs['d'] = 16;
			fmap_from_clrs['e'] = 9;
			fmap_from_clrs['f'] = 5;
			HuffmanTree htree_from_clrs{ fmap_from_clrs };

			Assert::AreEqual(100ul, htree_from_clrs.root()->freq_);
			Assert::AreEqual((unsigned char)0, htree_from_clrs.root()->character_);
			Assert::AreEqual((unsigned char)'a', htree_from_clrs.root()->left_->character_);

			// more test needed , but for now clrs is unavailable 
		}
	};
}