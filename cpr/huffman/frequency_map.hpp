#include <map>

#ifndef FREQUENCY_MAP_HPP
#define FREQUENCY_MAP_HPP


namespace cpr
{
	namespace huffman
	{
		template<typename Char, typename Freq>
		class FrequencyMap : public std::map < Char, Freq >
		{
		public:
			template<typename Container>
			explicit FrequencyMap(Container const& container)
			{
				for (auto ch : container)
				{
					auto it = this->find(ch);
					if (it != container.cend())
						++(*this)[ch];
					else
						(*this)[ch] = 1;
				}
			}
		};
	}
}


#endif // !FREQUENCY_MAP_HPP
