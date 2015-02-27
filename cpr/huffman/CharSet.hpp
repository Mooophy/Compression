#include <set>
#include <fstream>
#include <queue>
#include <functional>

namespace cpr
{
	namespace huffman
	{
		template<typename Freq>
		struct  Node
		{
			Node()
				: character_{ 0 }, freq_{ 0 }, left_{ nullptr }, right_{ nullptr }
			{	}

			Node(Node<Freq> const& other)
				: character_{ other.character_ }, freq_{ other.freq_ }, left_{ other.left_ }, right_{other.right_}
			{	}

			unsigned char character_;
			Freq freq_;
			Node* left_, right_;
		};

		template<typename Freq>
		inline bool operator > (Node<Freq> const& lhs, Node<Freq> const& rhs)
		{
			return lhs.freq_ > rhs.freq_;
		}




		template<typename Freq> 
		class Set : public std::set<Node<Freq>>
		{

		};

		template<typename Freq>
		Node<Freq> make_huffman_tree(Set<Node<Freq>> const& set)
		{
			using MinPreorityQuee = std::priority_queue < Node<Freq>, std::vector<Node<Freq>>, std::greater<Node<Freq>> > ;
			MinPreorityQuee queue;
			for (auto const& node : set)
				queue.push(node);

			for (int _ = 1; _ != set.size(); ++_)
			{
				Node<Freq> node;
			}
		}
	}
}