#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/code_word_dictionary.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
    using FrequencyMap = cpr::huffman::FrequencyMap < char, long > ;
    using HuffmanTree = cpr::huffman::HuffmanTree < char, long > ;
    using CodeWordDictionary = cpr::huffman::CodeWordDictionary < char, long, char > ;

    TEST_CLASS(unit_test_for_code_word_dictionary)
    {
    public:

        TEST_METHOD(ctor)
        {
            //setup huffman tree for testing code word dictionary
            auto empty_case = std::vector<char>();
            FrequencyMap fmap_from_clrs(empty_case);
            fmap_from_clrs['a'] = 45;
            fmap_from_clrs['b'] = 13;
            fmap_from_clrs['c'] = 12;
            fmap_from_clrs['d'] = 16;
            fmap_from_clrs['e'] = 9;
            fmap_from_clrs['f'] = 5;
            HuffmanTree htree_from_clrs{ fmap_from_clrs };


            //test ctor
            const CodeWordDictionary dic{ htree_from_clrs };
            Assert::IsTrue(6 == dic.size());
            Assert::IsTrue(0x00 == dic.at('a'));	//a : 0b
            Assert::IsTrue(0x04 == dic.at('c'));	//c : 100b
            Assert::IsTrue(0x05 == dic.at('b'));	//b : 101b
            Assert::IsTrue(0x0c == dic.at('f'));	//f : 1100b
            Assert::IsTrue(0x0d == dic.at('e'));	//e : 1101b
            Assert::IsTrue(0x07 == dic.at('d'));	//d : 111b
        }
    };
}