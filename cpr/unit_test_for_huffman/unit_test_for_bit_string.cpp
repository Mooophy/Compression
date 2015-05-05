#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/bit_string.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
    TEST_CLASS(unit_test_for_bit_string)
    {
    public:

        TEST_METHOD(ctor)
        {
            cpr::huffman::BitString<char> bit_string;
        }

        TEST_METHOD(data)
        {
            cpr::huffman::BitString<char> bit_string;
            Assert::AreEqual(0u, bit_string.str().size());
        }

        TEST_METHOD(bit_length)
        {
            cpr::huffman::BitString<char> bit_string;

            Assert::AreEqual(1u, bit_string.bit_length(0x00));
            Assert::AreEqual(7u, bit_string.bit_length(0x7f));
            Assert::AreEqual(8u, bit_string.bit_length(-0x01));
            Assert::AreEqual(8u, bit_string.bit_length(-0x7f));
            Assert::AreEqual(8u, bit_string.bit_length(-0x80));
            Assert::AreNotEqual(8u, bit_string.bit_length((char)-0x81));
        }

        TEST_METHOD(push_back_bits)
        {
            // case 1
            cpr::huffman::BitString<char> bit_string;
            bit_string.push_back_bits(0);
            Assert::AreEqual((char)0, bit_string.str().front());

            bit_string.push_back_bits((char)0xff);
            std::string expected(1, 0);
            expected += std::string(8, 1);
            Assert::AreEqual(expected, bit_string.str());
            Assert::AreEqual(9u, bit_string.str().size());

            //case 2
            cpr::huffman::BitString<char> bs_for_testing_minus_number;
            bs_for_testing_minus_number.push_back_bits(char(-1));
            Assert::AreEqual(8u, bs_for_testing_minus_number.str().size());

            bs_for_testing_minus_number.push_back_bits(0);
            Assert::AreEqual(9u, bs_for_testing_minus_number.str().size());

            //case 3
            cpr::huffman::BitString<char> case3;
            case3.push_back_bits(0x07);
            std::string expected_for_case3(3, 1);
            Assert::AreEqual(expected_for_case3, case3.str());
        }

        // protocol :
        // FrequencyTable|CompressedPart|Remainder|RemainderSize

        TEST_METHOD(compress_case1)
        {
            cpr::huffman::BitString<char> bit_string;
            bit_string.push_back_bits((char)0);
            std::string compressed = bit_string.compress('|');

            //note the compressed part is empty
            Assert::AreEqual(4u, compressed.size());
            std::string exprected{ '|', 0, '|', 1 };
            Assert::AreEqual(exprected, compressed);
        }

        TEST_METHOD(compress_case2)
        {
            cpr::huffman::BitString<char> bit_string;
            bit_string.push_back_bits((char)0xff);
            std::string compressed = bit_string.compress('|');
            Assert::AreEqual(5u, compressed.size());

            std::string exprected{ (char)0xff, '|', 0, '|', 0 };
            Assert::AreEqual(exprected, compressed);
        }

        TEST_METHOD(compress_case3)
        {
            cpr::huffman::BitString<char> bit_string;
            bit_string.push_back_bits((char)0X00);
            bit_string.push_back_bits((char)0Xff);
            std::string compressed = bit_string.compress('|');

            Assert::AreEqual(5u, compressed.size());

            std::string exprected{ (char)0x7f, '|', 1, '|', 1 };
            Assert::AreEqual(exprected, compressed);
        }

        TEST_METHOD(compress_case4)
        {
            cpr::huffman::BitString<char> bit_string;
            bit_string.push_back_bits((char)0X00);
            bit_string.push_back_bits((char)0Xff);
            bit_string.push_back_bits((char)0Xff);
            std::string compressed = bit_string.compress('|');

            Assert::AreEqual(6u, compressed.size());

            std::string exprected{ (char)0x7f, (char)0xff, '|', 1, '|', 1 };
            Assert::AreEqual(exprected, compressed);
        }
    };
}