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
			using std::map < Char, CodeWord >::map;
			using SharedNode = typename cpr::huffman::Node<Char, Freq>::SharedNode;
		public:
			explicit CodeWordDictionary(HuffmanTree<Char, Freq> const& htree)
				: map()
			{
				std::function<void(CodeWord, SharedNode)> 
					fill_dic_by_dfs = [=this](CodeWord path, SharedNode node)
				{
					if (node)
					{
						if (node->character_ != 0)
						{
							(*this)[node->character_] = path;
							return;
						}
						else
						{
							fill_dic_by_dfs(path << 1 + 0, node->left_);
							fill_dic_by_dfs(path << 1 + 1, node->right_);
						}
					}

					fill_dic_by_dfs(0, htree.root());
				}
			}
		};
	}
}

#endif // !CODE_WORD_DICTIONARY
