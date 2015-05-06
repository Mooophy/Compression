#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/bit_string.hpp"
#include "../huffman/frequency_map.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(test_frequency_map)
    {
    public:

        TEST_METHOD(frequency_map_len_1)
        {
            auto fa = cpr::huffman::BitString("fa");
            auto splited_data = fa.split_by_length(1);
            auto const fmap = cpr::huffman::FrequencyMap{ splited_data };

            Assert::AreEqual(2u, fmap.size());
            Assert::AreEqual(9u, fmap.at(0));
            Assert::AreEqual(7u, fmap.at(1));
        }

        TEST_METHOD(frequency_map_len_2)
        {
            auto fa = cpr::huffman::BitString("fa");
            auto splited_data = fa.split_by_length(2);
            auto const fmap = cpr::huffman::FrequencyMap{ splited_data };

            Assert::AreEqual(3u, fmap.size());
            Assert::AreEqual(1u, fmap.at(0));
            Assert::AreEqual(4u, fmap.at(1));
            Assert::AreEqual(3u, fmap.at(2));
        }

        TEST_METHOD(frequency_map_len_3)
        {
            auto fa = cpr::huffman::BitString("fa");
            auto splited_data = fa.split_by_length(3);
            auto const fmap = cpr::huffman::FrequencyMap{ splited_data };

            Assert::AreEqual(5u, fmap.size());
            Assert::AreEqual(1u, fmap.at(0));
            Assert::AreEqual(2u, fmap.at(1));
            Assert::AreEqual(1u, fmap.at(3));
            Assert::AreEqual(1u, fmap.at(4));
            Assert::AreEqual(1u, fmap.at(6));
        }

        TEST_METHOD(frequency_map_len_4)
        {
            auto fa = cpr::huffman::BitString("fa");
            auto splited_data = fa.split_by_length(4);
            auto const fmap = cpr::huffman::FrequencyMap{ splited_data };

            Assert::AreEqual(2u, fmap.size());
            Assert::AreEqual(1u, fmap.at(1));
            Assert::AreEqual(3u, fmap.at(6));
        }

        TEST_METHOD(frequency_map_len_5)
        {
            auto fa = cpr::huffman::BitString("fa");
            auto splited_data = fa.split_by_length(5);
            auto const fmap = cpr::huffman::FrequencyMap{ splited_data };

            Assert::AreEqual(4u, fmap.size());
            Assert::AreEqual(1u, fmap.at(0x01));
            Assert::AreEqual(1u, fmap.at(0x0c));
            Assert::AreEqual(1u, fmap.at(0x19));
            Assert::AreEqual(1u, fmap.at(0x10));
        }

        TEST_METHOD(frequency_map_len_0xa)
        {
            auto fa = cpr::huffman::BitString("fa");
            auto splited_data = fa.split_by_length(0xa);
            auto const fmap = cpr::huffman::FrequencyMap{ splited_data };

            Assert::AreEqual(2u, fmap.size());
            Assert::AreEqual(1u, fmap.at(0x199));
            Assert::AreEqual(1u, fmap.at(0x021));
        }

    };
}