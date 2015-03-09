#include <map>
#include <deque>

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
					if (this->find(ch) != this->end())
						++(*this)[ch];
					else
						(*this)[ch] = 1;
			}

			//format : symbol:frequency,
			//say :
			//		a:1304,b:89,c:990,
			std::string str()const
			{
				std::string str;
				for (auto pair : *this)
				{
					str.push_back(pair.first);
					str.push_back(':');
					str += frequency_to_string(pair.second);
					str.push_back(',');
				}
				return str;
			}

		private:
			std::string frequency_to_string(Freq freq) const
			{
				std::deque < char > dq;
				for (/* */; freq > 0; freq >>= 8)
					dq.push_front(freq & 0xff);
				return std::string(dq.begin(), dq.end());
			}
		};
	}
}


#endif // !FREQUENCY_MAP_HPP
