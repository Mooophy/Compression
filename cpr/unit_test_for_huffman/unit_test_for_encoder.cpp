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
			Assert::AreEqual((unsigned)11, encoder.data.size());

			//test each character
			std::string content = "abcbbdeeead";
			auto it = content.cbegin();
			for (auto ch : encoder.data)
				Assert::AreEqual(ch, *it++);

			//test frequency_map
			Assert::AreEqual(5u, encoder.frequency_map.size());

			Assert::AreEqual(2l, encoder.frequency_map.at('a'));
			Assert::AreEqual(3l, encoder.frequency_map.at('b'));
			Assert::AreEqual(1l, encoder.frequency_map.at('c'));
			Assert::AreEqual(2l, encoder.frequency_map.at('d'));
			Assert::AreEqual(3l, encoder.frequency_map.at('e'));

		}

	};
}