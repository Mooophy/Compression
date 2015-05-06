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

        TEST_METHOD(bit_string_bin_to_unsigned)
        {
            auto _0x03 = std::string{ 0, 1, 1 };
            Assert::AreEqual(0x03u, cpr::huffman::BitString::bin_to_unsigned(_0x03));

            auto _0x29 = std::string{ 0, 0, 1, 0, 1, 0, 0, 1 };
            Assert::AreEqual(0x29u, cpr::huffman::BitString::bin_to_unsigned(_0x29));
        }

        TEST_METHOD(bit_string_split_by_length_1)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(1);
            auto exp = std::vector < unsigned > {0, 1, 1, 0, 0, 1, 1, 0};

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_2)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(2);
            auto exp = std::vector < unsigned > {1, 2, 1, 2};

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_3)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(3);
            auto exp = std::vector < unsigned > {3, 1, 2};

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_4)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(4);
            auto exp = std::vector < unsigned > { 6, 6 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_5)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(5);
            auto exp = std::vector < unsigned > { 0xc, 0x6 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_6)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(6);
            auto exp = std::vector < unsigned > { 0x19, 0x02 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_7)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(7);
            auto exp = std::vector < unsigned > { 0x33, 0x00 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_8)
        {
            auto foo = cpr::huffman::BitString("f");
            auto act = foo.split_by_length(8);
            auto exp = std::vector < unsigned > { 0x66 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_9)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(9);
            auto exp = std::vector < unsigned > { 0xcc, 0x61 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_0xa)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(0xa);
            auto exp = std::vector < unsigned > { 0x199, 0x21 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_0xb)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(0xb);
            auto exp = std::vector < unsigned > { 0x333, 0x01 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_0xd)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(0xd);
            auto exp = std::vector < unsigned > { 0xccc, 0x01 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_0xe)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(0xe);
            auto exp = std::vector < unsigned > { 0x1998, 0x01 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_0xf)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(0xf);
            auto exp = std::vector < unsigned > { 0x3330, 0x01 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

        TEST_METHOD(bit_string_split_by_length_0x10)
        {
            auto foo = cpr::huffman::BitString("fa");
            auto act = foo.split_by_length(0x10);
            auto exp = std::vector < unsigned > { 0x6661 };

            for (int i = 0; i != exp.size(); ++i)
                Assert::AreEqual(exp[i], act[i]);
        }

    };
}