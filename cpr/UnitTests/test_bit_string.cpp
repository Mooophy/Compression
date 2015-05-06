#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/bit_string.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(test_bit_string)
	{
	public:
		
        TEST_METHOD(char_to_bitstring)
		{
            Assert::AreEqual(std::string(8, 0), cpr::huffman::BitString::char_to_bin('\0'));

            auto expect_a = std::string{ 0, 1, 1, 0, 0, 0, 0, 1 };//0x61
            Assert::AreEqual(expect_a, cpr::huffman::BitString::char_to_bin('a'));

            auto expect_Z = std::string{ 0, 1, 0, 1, 1, 0, 1, 0 };//0x5a
            Assert::AreEqual(expect_Z, cpr::huffman::BitString::char_to_bin('Z'));
		}

        TEST_METHOD(bit_string_ctor)
        {
            auto foo = cpr::huffman::BitString("f");
        }

        TEST_METHOD(bit_string_data)
        {
            auto foo = cpr::huffman::BitString("f");
            auto f = std::string{ 0, 1, 1, 0, 0, 1, 1, 0 };
            Assert::AreEqual(f, foo.data());
        }

        TEST_METHOD(bit_string_str)
        {
            auto foo = cpr::huffman::BitString("f");
            auto expect = std::string("01100110");
            Assert::AreEqual(expect, foo.str());
        }

	};
}