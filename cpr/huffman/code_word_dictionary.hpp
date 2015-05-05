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
            using SharedNode = typename cpr::huffman::Node<Char, Freq>::SharedNode;
        public:
            explicit CodeWordDictionary(HuffmanTree<Char, Freq> const& huffman_tree)
            {
                fill_this_by_dfs(0, huffman_tree.root);
            }

        private:
            void fill_this_by_dfs(CodeWord path, SharedNode node)
            {
                if (!node)
                    return;

                if (node->character_ != 0)
                {
                    (*this)[node->character_] = path;
                }
                else
                {
                    fill_this_by_dfs((path << 1) + 0, node->left_);
                    fill_this_by_dfs((path << 1) + 1, node->right_);
                }
            }
        };
    }
}

#endif // !CODE_WORD_DICTIONARY
