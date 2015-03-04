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

	};
}