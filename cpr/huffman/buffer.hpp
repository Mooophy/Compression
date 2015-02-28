#include <list>


#ifndef BUFFER_HPP
#define BUFFER_HPP


namespace cpr
{
	namespace huffman
	{
		template<typename T>
		class Buffer 
		{
		public:
			Buffer()
				: bit_index_{ index_of_msb() }, data_{}
			{	}

			template<typename Iterator>
			Buffer(Iterator first, Iterator last)
				: bit_counter_{ index_of_msb() }, data_(first, last)
			{	}

			std::list<T> const& data() const
			{
				return data_;
			}

			unsigned pop_front_bit()
			{
				auto elem = data_.front();
				unsigned msb = (elem & (1 << bit_index_)) >> bit_index_;
				--bit_index_;
				if (bit_index_ < 0)
					data_.pop_front();
				return msb;
			}

		private:
			int bit_index_;
			std::list<T> data_;

			int index_of_msb() const
			{
				return sizeof(T) * 8 - 1;
			}
		};
	}
}


#endif // !BUFFER_HPP
