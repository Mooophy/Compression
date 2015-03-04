#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stdexcept>


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
				: data_( read_data(path) )
			{	}
		private:
			std::vector<Char> data_;

			std::vector<Char> read_data(std::string path)const
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
