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

			std::string const& data() const
			{
				return data_;
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
