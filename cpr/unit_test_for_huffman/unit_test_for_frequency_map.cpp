#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/frequency_map.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
    TEST_CLASS(unit_test_for_frequency_map)
    {
    public:

        TEST_METHOD(ctor)
        {
            std::vector<char> test_case{ 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c' };
            cpr::huffman::FrequencyMap<char, long> fmap(test_case);

            Assert::AreEqual(3u, fmap.size());
            Assert::AreEqual(4l, fmap.at('a'));
            Assert::AreEqual(3l, fmap.at('b'));
            Assert::AreEqual(1l, fmap.at('c'));
        }

        TEST_METHOD(str_case0)
        {
            std::vector<char> test_case{ 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'c' };
            cpr::huffman::FrequencyMap<char, long> fmap(test_case);
            std::string expect{ 'a', ':', 4, ',', 'b', ':', 3, ',', 'c', ':', 1, ',' };
            Assert::AreEqual(expect, fmap.str());
        }

        TEST_METHOD(str_case1)
        {
            std::string test_case;
            for (int i = 0; i != 0xabc; ++i)
                test_case += "ab";
            cpr::huffman::FrequencyMap<char, long> fmap(test_case);
            std::string expect{ 'a', ':', (char)0x0a, (char)0xbc, ',', 'b', ':', (char)0x0a, (char)0xbc, ',' };
            Assert::AreEqual(expect, fmap.str());
        }
    };
}