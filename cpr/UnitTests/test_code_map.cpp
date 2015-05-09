#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/frequency_map.hpp"
#include "../huffman/make_huffman_tree.hpp"
#include "../huffman/code_map.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(test_code_map)
    {
    public:

        TEST_METHOD(code_map_ctor)
        {
            auto fmap_from_clrs = cpr::huffman::FrequencyMap{};
            fmap_from_clrs[(unsigned)'a'] = 45;
            fmap_from_clrs[(unsigned)'b'] = 13;
            fmap_from_clrs[(unsigned)'c'] = 12;
            fmap_from_clrs[(unsigned)'d'] = 16;
            fmap_from_clrs[(unsigned)'e'] = 9;
            fmap_from_clrs[(unsigned)'f'] = 5;
            auto root = cpr::huffman::make_huffman_tree(fmap_from_clrs);
            auto cmap = cpr::huffman::CodeMap(root);

            Assert::IsTrue(6 == cmap.size());
            Assert::AreEqual(0x00u, cmap.at(unsigned('a')));  //a : 0b
            Assert::AreEqual(0x04u, cmap.at(unsigned('c')));  //c : 100b
            Assert::AreEqual(0x05u, cmap.at(unsigned('b')));  //b : 101b
            Assert::AreEqual(0x0cu, cmap.at(unsigned('f')));  //f : 1100b
            Assert::AreEqual(0x0du, cmap.at(unsigned('e')));  //e : 1101b
            Assert::AreEqual(0x07u, cmap.at(unsigned('d')));  //d : 111b
        }

    };
}