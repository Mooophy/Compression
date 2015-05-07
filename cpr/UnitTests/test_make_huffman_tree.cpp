#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/make_huffman_tree.hpp"
#include "../huffman/bit_string.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(test_make_huffman_tree)
	{
	public:
		
		TEST_METHOD(make_huffman_tree_case_from_clrs)
		{
            auto fmap_from_clrs = cpr::huffman::FrequencyMap{};
            fmap_from_clrs[(unsigned)'a'] = 45;
            fmap_from_clrs[(unsigned)'b'] = 13;
            fmap_from_clrs[(unsigned)'c'] = 12;
            fmap_from_clrs[(unsigned)'d'] = 16;
            fmap_from_clrs[(unsigned)'e'] = 9;
            fmap_from_clrs[(unsigned)'f'] = 5;
            auto root = cpr::huffman::make_huffman_tree(fmap_from_clrs);

            Assert::AreEqual(100u, root->frequence);
            Assert::AreEqual(0u, root->value);
            Assert::AreEqual((unsigned)'a', root->left->value);
        }

	};
}