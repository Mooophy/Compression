#include "node.hpp"
#include "frequency_map.hpp"
#include <map>
#include <fstream>
#include <queue>
#include <functional>
#include <string>


#ifndef HUFFMAN_TREE_HPP
#define HUFFMAN_TREE_HPP

namespace cpr
{
	namespace huffman
	{
		template<typename Char, typename Freq>
		class HuffmanTree
		{
		public:
			using SharedNode = typename Node<Char, Freq>::SharedNode;
			
			explicit HuffmanTree(FrequencyMap<Char, Freq> const& map)
				: root_{make_tree(map)}
			{}

			SharedNode root() const
			{
				return root_;
			}

			std::string to_string() const
			{
				std::string str;
				std::function<void(SharedNode)> inorder = [&](SharedNode node)
				{
					if (node)
					{
						inorder(node->left_);

						str.push_back('[');
						str.push_back(node->character_ == 0 ? '_' : node->character_);
						str.push_back(',');
						str += std::to_string(node->freq_);
						str.push_back(']');
						
						inorder(node->right_);
					}
				};

				inorder(root_);
				return str;
			}

		private:
			const SharedNode root_;

			// huffman coding algorithm 
			// based on a pseudocode on 16.3 CLRS 3rd.
			SharedNode make_tree(FrequencyMap<Char, Freq> const& map) const
			{
					auto greater = [](SharedNode lhs, SharedNode rhs){return lhs->freq_ > rhs->freq_; };
					using MinPriorityQueue = std::priority_queue < SharedNode, std::vector<SharedNode>, decltype(greater) > ;

					MinPriorityQueue queue(greater);
					for (auto const& pair : map)
						queue.push(make_new_node(pair.first, pair.second));
					
					for (int count = 1; count != map.size(); ++count)
					{
						auto merge = make_new_node<Char, Freq>();
						merge->left_ = make_new_node(*queue.top());
						queue.pop();
						merge->right_ = make_new_node(*queue.top());
						queue.pop();
						merge->freq_ = merge->left_->freq_ + merge->right_->freq_;
						queue.push(merge);
					}

					return queue.top();
			}
		};
	}
}

#endif // !HUFFMAN_TREE_HPP