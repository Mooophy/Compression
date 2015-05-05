#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/huffman_tree.hpp"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
    using FrequencyMap = cpr::huffman::FrequencyMap < char, long > ;
    using HuffmanTree = cpr::huffman::HuffmanTree < char, long > ;
    TEST_CLASS(unit_test_for_huffman_tree)
    {
    public:

        TEST_METHOD(ctor)
        {
            //case 1 made up on my own
            std::vector<char> test_case{ 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c' };
            FrequencyMap fmap(test_case);
            HuffmanTree htree{ fmap };
            Assert::IsNotNull(htree.root.get());


            //case 2 based on 16.3 clrs 
            auto empty_case = std::vector<char>();
            FrequencyMap fmap_from_clrs(empty_case);
            fmap_from_clrs['a'] = 45;
            fmap_from_clrs['b'] = 13;
            fmap_from_clrs['c'] = 12;
            fmap_from_clrs['d'] = 16;
            fmap_from_clrs['e'] = 9;
            fmap_from_clrs['f'] = 5;
            HuffmanTree htree_from_clrs{ fmap_from_clrs };

            Assert::AreEqual(100l, htree_from_clrs.root->freq_);
            Assert::AreEqual((char)0, htree_from_clrs.root->character_);
            Assert::AreEqual((char)'a', htree_from_clrs.root->left_->character_);

            //! the rest is tested below using method "to_string".
        }

        TEST_METHOD(to_string)
        {
            auto empty_case = std::vector<char>();
            FrequencyMap fmap_from_clrs(empty_case);
            fmap_from_clrs['a'] = 45;
            fmap_from_clrs['b'] = 13;
            fmap_from_clrs['c'] = 12;
            fmap_from_clrs['d'] = 16;
            fmap_from_clrs['e'] = 9;
            fmap_from_clrs['f'] = 5;
            HuffmanTree htree_from_clrs{ fmap_from_clrs };

            std::string expected = "[a,45][_,100][c,12][_,25][b,13][_,55][f,5][_,14][e,9][_,30][d,16]";
            Assert::AreEqual(expected, htree_from_clrs.to_string());
        }
    };
}