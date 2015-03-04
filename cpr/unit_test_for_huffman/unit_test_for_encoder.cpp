#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/encoder.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_test_for_huffman
{
	TEST_CLASS(unit_test_for_encoder)
	{
	public:
		
		TEST_METHOD(ctor)
		{
			cpr::huffman::Encoder<char, long, char> encoder("test_for_encoder.txt");

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
	};
}