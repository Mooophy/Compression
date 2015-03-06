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

			// protocol :
			// FrequencyTable|CompressedPart|Remainder|RemainderSize
			std::string compress(Char delimiter) const
			{
				std::string compressed_data;
				auto curr = data_.cbegin();

				//for compressed part
				while (data_.cend() - curr >= sizeof(Char))
				{
					Char ch = 0;
					auto peek = curr;
					for (; peek != curr + sizeof(Char); ++peek)
						ch = (ch << 1) + *peek;
					compressed_data.push_back(ch);

					curr = peek;
				}

				compressed_data.push_back(delimiter);

				//for remainder part and remainder size
				Char remainder = 0;
				for (auto peek = curr; peek != data_.cend(); ++peek)
					remainder = (remainder << 1) + *peek;
				compressed_data.push_back(remainder);
				compressed_data.push_back(delimiter);
				compressed_data.push_back(data_.cend() - curr);//remainder part

				return compressed_data;
			}

		private:
			std::string data_;
		};
	}
}


#endif // !BIT_STRING_HPP
