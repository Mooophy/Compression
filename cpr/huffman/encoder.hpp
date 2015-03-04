#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "frequency_map.hpp"


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
			explicit Encoder(std::string path)
				: data(read_file(path)), frequency_map(data)
			{	}
		
			const std::vector<Char> data;
			const FrequencyMap<Char, Freq> frequency_map;
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
		};
	}
}


#endif // !ENCODER_HPP
