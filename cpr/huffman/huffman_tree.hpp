#include "node.hpp"
#include <set>
#include <fstream>
#include <queue>
#include <functional>


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
			using SharedNode = Node<Char, Freq>::SharedNode;

			template<typename Container>
			explicit HuffmanTree(Container const& nodes)
				: root_{ make_tree(nodes) }
			{	}

		private:
			SharedNode root_;

			template<typename Container>
			SharedNode make_tree(Container const& nodes) const
			{
				auto greater = [](SharedNode lhs, SharedNode rhs){return lhs->freq_ > rhs->freq_; };
				using MinPriorityQueue = std::priority_queue < SharedNode, std::vector<SharedNode>>, decltype(greater) > ;

				MinPriorityQueue queue(greater);
				for (auto const& n : node)
					queue.push(make_new_node(n));

				for (int _ = 1; _ != container.size(); ++_)
				{
					auto z = make_new_node();
					z->left_ = make_new_node(queue.top());
					queue.pop();
					z->right_ = make_new_node(queue.top());
					queue.pop();
					z.freq_ = z.left_->freq_ + z.right_->freq_;
					queue.push(z);
				}
			}
		};
	}
}

#endif // !HUFFMAN_TREE_HPP