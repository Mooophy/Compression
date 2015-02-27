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
		template<typename Freq>
		struct Node
		{
			Node()
				: character_{ 0 }, freq_{ 0 }, left_{ nullptr }, right_{ nullptr }
			{   }
			Node(char ch, Freq freq)
				: character_{ ch }, freq_{ freq }, left_{ nullptr }, right_{ nullptr }
			{   }
			Node(Node const& other)
				: character_{ other.character_ }, freq_{ other.freq_ }, left_{ other.left_ }, right_{ other.right_ }
			{	}

			char character_;
			Freq freq_;
			Node *left_, *right_;
		};

		template<typename Freq>
		inline bool operator > (Node<Freq> const& lhs, Node<Freq> const& rhs)
		{
			return lhs.freq_ > rhs.freq_;
		}
		template<typename Freq>
		inline bool operator < (Node<Freq> const& lhs, Node<Freq> const& rhs)
		{
			return lhs.freq_ < rhs.freq_;
		}
		template<typename Freq>
		inline std::ostream& operator<<(std::ostream& os, Node<Freq> const& node)
		{
			return os << "[" << node.character_ << "," << node.freq_ << "]";
		}



		template<typename Freq>
		class HuffmanTree
		{
			using MinPriorityQueue = std::priority_queue<Node<Freq>, std::vector<Node<Freq>>, std::less<Node<Freq>> >;
		public:
			template<typename Iterator>
			HuffmanTree(Iterator first, Iterator last)
				: root_{ make_tree(first, last) }
			{	}

			std::ostream& print() const
			{
				preorder(root_);
				return std::cout;
			}

		private:
			Node<Freq>* root_;

			void preorder(const Node<Freq>* node) const
			{
				if (node)
				{
					preorder(node->left_);
					std::cout << *node << std::endl;
					preorder(node->right_);
				}
			}

			template<typename Iterator>
			Node<Freq>* make_tree(Iterator first, Iterator last)
			{
				MinPriorityQueue queue;
				for (auto curr = first; curr != last; ++curr)
					queue.push(*curr);

				for (int _ = 1; _ != std::distance(first, last); ++_)
				{
					Node<Freq> z;
					auto x = new Node<Freq>(queue.top());	queue.pop();
					auto y = new Node<Freq>(queue.top());	queue.pop();
					z.left_ = x;
					z.right_ = y;
					z.freq_ = x->freq_ + y->freq_;
					queue.push(z);
				}

				return new Node<Freq>(queue.top());
			}
		};
	}
}


#endif // !HUFFMAN_HPP
