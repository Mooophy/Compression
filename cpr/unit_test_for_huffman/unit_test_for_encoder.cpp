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
			{
				std::ifstream file("test_for_encoder.txt");
				Assert::AreEqual(true, file.good());
			}
			cpr::huffman::Encoder<char, long, char> encoder("test_for_encoder.txt");
		}

	};
}