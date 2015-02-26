#include <set>
#include <fstream>

namespace cpr
{
	namespace huffman
	{
		template<typename Freq>	struct  C
		{
			unsigned char character_;
			Freq freq_;
			C* left_, right_;
		};

		template<typename Freq> class Set : public std::set<unsigned char>
		{

		};
	}
}