#include <set>
#include <fstream>
#include <queue>
#include <functional>

#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

namespace cpr {namespace huffman{


template<typename Freq>
struct Node
{
    explicit Node()
        : character_{ 0 }, freq_{ 0 }, left_{ nullptr }, right_{ nullptr }
    {   }

    Node(Freq freq, unsigned char ch)
        : character_{ ch }, freq_{ freq }, left_{ nullptr }, right_{nullptr}
    {   }

    Node(Node const& other)
        : character_{ other.character_ }, freq_{ other.freq_ }, left_{ other.left_ }, right_{other.right_}
    {	}

    unsigned char character_;
    Freq freq_;
    Node* left_, *right_;
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



template<typename Iterator>
auto make_huffman_tree(Iterator first, Iterator last) -> decltype(*first)
{

    using Freq = decltype(first->freq_);
    using MinPriorityQueue = std::priority_queue<Node<Freq>, std::vector<Node<Freq>>, std::greater<Node<Freq>> > ;

//    auto size = last - first;
    auto size = std::distance(first, last);
    MinPriorityQueue queue;
    for(auto curr = first; curr != last; ++curr)
        queue.push(*curr);

    for(int _ = 1; _ != size; ++_)
    {
        Node<Freq> z;
        auto x = new Node<Freq>(queue.top());	queue.pop();
        auto y = new Node<Freq>(queue.top());	queue.pop();
        z.left_ = x;
        z.right_ = y;
        queue.push(z);
    }

    return queue.top();
}

//template<typename Freq>
//Node<Freq> make_huffman_tree(std::set<Node<Freq>> const& set)
//{
//    using MinPreorityQuee = std::priority_queue < Node<Freq>, std::vector<Node<Freq>>, std::greater<Node<Freq>> > ;
//    MinPreorityQuee queue;
//    for (auto const& node : set)
//        queue.push(node);

//    for (int _ = 1; _ != set.size(); ++_)
//    {
//        Node<Freq> z;
//        auto x = new Node<Freq>(queue.top());	queue.pop();
//        auto y = new Node<Freq>(queue.top());	queue.pop();
//        z.left_ = x, z.right_ = y;
//        z.freq_ = x->freq_ + y->freq_;
//        queue.push(z);
//    }

//    return queue.top();
//}

}}//namespace


#endif // HUFFMAN_HPP
