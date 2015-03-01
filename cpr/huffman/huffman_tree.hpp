#include "node.hpp"
#include <set>
#include <fstream>
#include <queue>
#include <functional>


#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

namespace cpr
{
	namespace huffman
	{
		class HuffmanTree
		{
			
		public:
			using UniquePointer = cpr::huffman::Node::UniquePointer;

			template<typename Container>
			explicit HuffmanTree(Container && container)
				: root_(make_tree(std::move(container)))
			{	}

		private:
			UniquePointer root_;

			template<typename Container>
			UniquePointer make_tree(Container && container)
			{
				//using MinPriorityQueue = std::priority_queue < Node, std::vector<Node>, std::greater<Node> >;
				//auto queue = MinPriorityQueue();
				//for (auto && node : container)
				//	queue.push(node);

				//for (int _ = 1; _ != container.size(); ++_)
				//{
				//	auto node = Node();
				//	node.left_ = std::make_unique<Node>(std::move(queue.top()));
				//	queue.pop();
				//	node.right_ = std::make_unique<Node>(std::move(queue.top()));
				//	queue.pop();
				//	node.freq_ = node.left_->freq_ + node.right_->freq_;
				//	queue.push(node);
				//}

				//return std::make_unique<Node>(std::move(queue.top()));
				return std::make_unique<Node>();
			}
		};
	}
}

#endif // !HUFFMAN_HPP
