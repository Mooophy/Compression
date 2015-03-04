#include <string>


#ifndef BIT_STRING_HPP
#define BIT_STRING_HPP


namespace cpr
{
	namespace huffman
	{
		template<typename Char>
		class BitString
		{
		public:
			BitString()
				: data_{}
			{	}

			std::string const& str() const
			{
				return data_;
			}
			
			void push_back_bits(Char bits)
			{
				if (0 == bit_length(bits))
				{
					data_.push_back(bits);
				}
				else
				{
					for (int pos = bit_length(bits) - 1; pos >= 0; --pos)
					{
						char curr_bit = ((bits & (1 << pos)) >> pos);
						data_.push_back(curr_bit);
					}
				}
			}

			unsigned bit_length(Char ch) const
			{
				if (ch < 0)
					return sizeof (ch) * 8; 
				if (ch == 0)
					return 1;

				unsigned count = 0;
				for (; ch > 0; ch >>= 1) ++count;
				return count;
			}

		private:
			std::string data_;
		};
	}
}


#endif // !BIT_STRING_HPP
