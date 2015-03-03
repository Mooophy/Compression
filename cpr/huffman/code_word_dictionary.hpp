#include "huffman_tree.hpp"


#ifndef CODE_WORD_DICTIONARY
#define CODE_WORD_DICTIONARY

namespace cpr
{
	namespace huffman
	{
		template<typename Char, typename Freq, typename CodeWord>
		class CodeWordDictionary : public std::map < Char, CodeWord >
		{
		public:
		private:

		};
	}
}

#endif // !CODE_WORD_DICTIONARY
