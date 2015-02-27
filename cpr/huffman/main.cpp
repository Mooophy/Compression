#include <iostream>
#include "huffman.hpp"

int main()
{
	std::vector<char> raw_data{ 'a', 'a', 'a', 'a', 'b', 'b', 'c' };
	std::vector<cpr::huffman::Node<int>> C;
	for (auto ch : raw_data)
	{
		auto it = std::find_if(C.begin(), C.end(), [ch](cpr::huffman::Node<int> const& node){return node.character_ == ch; });
		if (it != C.cend())
			++it->freq_;
		else
			C.push_back(cpr::huffman::Node<int>(ch, 1));
	}
	std::cout << "size of Set C : " << C.size() << std::endl;

	cpr::huffman::HuffmanTree<int> huff_tree(C.cbegin(), C.cend());
	huff_tree.print();
	return 0;
}