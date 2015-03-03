#include <map>

#ifndef FREQUENCY_MAP_HPP
#define FREQUENCY_MAP_HPP


namespace cpr
{
	namespace huffman
	{
		// could be extended to read file directly, depending on later design.
		// could be extended to write file directly, depending on later design. 
		template<typename Char, typename Freq>
		class FrequencyMap : public std::map < Char, Freq >
		{
		public:
			template<typename Container>
			explicit FrequencyMap(Container const& container)
			{
				for (auto ch : container)
					if (this->find(ch) != this->end())
						++(*this)[ch];
					else
						(*this)[ch] = 1;
			}
		};
	}
}


#endif // !FREQUENCY_MAP_HPP
