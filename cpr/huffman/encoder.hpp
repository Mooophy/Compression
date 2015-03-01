#include <algorithm>
#include "huffman.hpp"



#ifndef ENCODER_HPP
#define ENCODER_HPP

namespace cpr
{
	namespace huffman
	{
		class Encoder
		{
		public:
			explicit Encoder(std::vector<unsigned char> const& raw)
				: raw_(raw), frequencies_(find_frequencies(raw)), huff_tree_(frequencies_.cbegin(), frequencies_.cend())
			{	}

		private:
			const std::vector<unsigned char> raw_;
			const std::vector<Node<long>> frequencies_;
			const HuffmanTree<unsigned long> huff_tree_;

			
			std::vector<Node<long>> find_frequencies(std::vector<unsigned char> const& raw) const
			{
				std::vector<Node<unsigned long>> frequencies;
				for (auto ch : raw)
				{
					auto it = std::find_if(frequencies.begin(), frequencies.end(), [ch](Node<unsigned long> const& node){
						return node.character_ == ch;
					});

					if (it != frequencies.cend())
						++it->freq_;
					else
						frequencies.push_back(Node<unsigned long>(ch, 1));
				}

				return frequencies;
			}

			//std::vector<unsigned char> encode() const
			//{

			//}

			//
			// not tested yet 
			//
			unsigned char uchar_to_code(unsigned char uchar)const
			{
				unsigned char code = 0;
				using Lambda = std::function < void(unsigned char, const Node<unsigned long>*) >;
				Lambda search = [=, &search, &code](unsigned char first_part, const Node<unsigned long>* node)
				{
					if (!node)
						return;

					if (uchar == node->character_)
					{
						code = first_part;
						return;
					}
					else
					{
						search((first_part << 1) + 0, node->left_);
						search((first_part << 1) + 1, node->right_);
					}
				};

				search(0, this->huff_tree_.root());
				return code;
			}
		};
	}
}

#endif // !ENCODER_HPP
