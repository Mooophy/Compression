#include "stdafx.h"
#include "CppUnitTest.h"
#include "../huffman/frequency_map.hpp"
#include "../huffman/make_huffman_tree.hpp"
#include "../huffman/code_map.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(test_code_map)
	{
	public:
		
		TEST_METHOD(code_map_ctor)
		{
            auto fmap_from_clrs = cpr::huffman::FrequencyMap{};
            fmap_from_clrs[(unsigned)'a'] = 45;
            fmap_from_clrs[(unsigned)'b'] = 13;
            fmap_from_clrs[(unsigned)'c'] = 12;
            fmap_from_clrs[(unsigned)'d'] = 16;
            fmap_from_clrs[(unsigned)'e'] = 9;
            fmap_from_clrs[(unsigned)'f'] = 5;
            auto root = cpr::huffman::make_huffman_tree(fmap_from_clrs);
		}

	};
}