#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "frequency_map.hpp"
#include "huffman_tree.hpp"
#include "code_word_dictionary.hpp"
#include "bit_string.hpp"


#ifndef ENCODER_HPP
#define ENCODER_HPP


namespace cpr
{
	namespace huffman
	{
		template<typename Char, typename Freq, typename CodeWord>
		class Encoder
		{
		public:
			explicit Encoder(std::string path) : 
				data(read_file(path)), 
				frequency_map(data), 
				huffman_tree(frequency_map), 
				code_dictionary(huffman_tree),
				bit_string(encode_data_and_push_into_bit_string())
			{	}

			void write(std::string out_file) const
			{
				//
				// should convert bit string into a sequence of char first
				//

				//auto first = bit_string.str().cbegin();
				//auto last = bit_string.str().cend();
				//std::ofstream output(out_file, std::ios::binary);
				//auto destination = std::ostreambuf_iterator<Char>(output);

				//std::copy(first, last, destination);
			}

			//
			// data members, read only
			//
			const std::vector<Char> data;
			const FrequencyMap<Char, Freq> frequency_map;
			const HuffmanTree<Char, Freq> huffman_tree;
			const CodeWordDictionary<Char, Freq, CodeWord> code_dictionary;
			const BitString<Char> bit_string;

		private:
			std::vector<Char> read_file(std::string path)const
			{
				std::ifstream file(path, std::ios::binary);
				if (file.bad())
					throw std::logic_error("bad file");
				auto begin = std::istreambuf_iterator<Char>(file);
				auto end = std::istreambuf_iterator<Char>();
				return std::vector<Char>(begin, end);
			}

			BitString<Char> encode_data_and_push_into_bit_string()const
			{
				BitString<Char> encoded;
				for (auto ch : data)
					encoded.push_back_bits(code_dictionary.at(ch));
				return encoded;
			}
		};
	}
}


#endif // !ENCODER_HPP
