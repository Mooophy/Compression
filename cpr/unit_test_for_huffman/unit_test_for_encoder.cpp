#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/encoder.hpp"

#include <fstream>
#include <iterator>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
	TEST_CLASS(unit_test_for_encoder)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			cpr::huffman::Encoder<char, long, char> encoder("../test_cases/test_for_encoder.txt");

			//test each character in data
			Assert::AreEqual(21u, encoder.data.size());
			
			std::string content = "abbcccddddeeeeeffffff";
			auto it = content.cbegin();
			for (auto ch : encoder.data)
				Assert::AreEqual(ch, *it++);

			//test frequency_map part
			Assert::AreEqual(6u, encoder.frequency_map.size());

			Assert::AreEqual(1l, encoder.frequency_map.at('a'));
			Assert::AreEqual(2l, encoder.frequency_map.at('b'));
			Assert::AreEqual(3l, encoder.frequency_map.at('c'));
			Assert::AreEqual(4l, encoder.frequency_map.at('d'));
			Assert::AreEqual(5l, encoder.frequency_map.at('e'));
			Assert::AreEqual(6l, encoder.frequency_map.at('f'));

			//test huffman_tree part
			std::string str_expected = "[d,4][_,9][e,5][_,21][a,1][_,3][b,2][_,6][c,3][_,12][f,6]";
			Assert::AreEqual(str_expected, encoder.huffman_tree.to_string());

			//test code word dictionary part
			Assert::AreEqual(6u, encoder.code_dictionary.size());

			Assert::IsTrue(0x00 == encoder.code_dictionary.at('d'));	//d : 4 -->0b
			Assert::IsTrue(0x01 == encoder.code_dictionary.at('e'));	//e : 5 -->1b
			Assert::IsTrue(0x08 == encoder.code_dictionary.at('a'));	//a : 1 -->1000b
			Assert::IsTrue(0x09 == encoder.code_dictionary.at('b'));	//b : 2 -->1001b
			Assert::IsTrue(0x05 == encoder.code_dictionary.at('c'));	//c : 3 -->101b
			Assert::IsTrue(0x03 == encoder.code_dictionary.at('f'));	//f : 6 -->11b
		}

		TEST_METHOD(encode)
		{
			cpr::huffman::Encoder<char, long, char> encoder("../test_cases/test_for_encoder.txt");

			std::string expect = "100010011001101101101000011111111111111111";
			for (auto& ch : expect) ch -= 48; // <-- note this conversion

			Assert::AreEqual(expect, encoder.bit_string.str());
		}

		// abbcccddddeeeeeffffff							raw data
		//		-->
		// 100010011001101101101000011111111111111111		bit string encoded with huffman tree
		//		-->
		//	1000 1001	--	0x89
		//	1001 1011	--	0x9b
		//	0110 1000	--	0x68
		//	0111 1111	--	0x7f
		//	1111 1111	--	0xff
		//	11			--	0x03
		//		-->
		// [0x89][0x9b][0x68][0x7f][0xff]|[0x03]|[0x02]		final data using protocol (no FrequencyTable part in this version) : FrequencyTable|CompressedPart|Remainder|RemainderSize
		TEST_METHOD(write_case1)
		{
			cpr::huffman::Encoder<char, long, char> encoder("../test_cases/test_for_encoder.txt");
			encoder.write("../test_cases/test_for_encoder.cpr", '|');

			std::ifstream ifs("../test_cases/test_for_encoder.cpr", std::ios::binary);

			auto begin = std::istreambuf_iterator<char>(ifs);
			auto end = std::istreambuf_iterator<char>();
			std::vector<char> actual(begin, end);
			Assert::AreEqual(9u, actual.size());
			Assert::AreEqual((char)0x89, actual[0]);

			std::vector<char> expect{ (char)0x89, (char)0x9b, (char)0x68, (char)0x7f, (char)0xff, '|', (char)0x03, '|', (char)0x02 };
			for (unsigned idx = 0; idx != 9u; ++idx)
				Assert::AreEqual(expect[idx], actual[idx]);
		}

		TEST_METHOD(write_case2)
		{
			cpr::huffman::Encoder<char, long, char> encoder("../test_cases/shake.txt");
			encoder.write("../test_cases/shake.cpr", '|');
		}
	};
}