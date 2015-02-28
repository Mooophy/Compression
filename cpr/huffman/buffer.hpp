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
				: curr_bit_index_{ msb_index() }, data_{}
			{	}

			template<typename Iterator>
			Buffer(Iterator first, Iterator last)
				: curr_bit_index_{ msb_index() }, data_(first, last)
			{	}

			std::list<T> const& data() const
			{
				return data_;
			}

			//
			//	make sure not empty before calling this method
			//
			unsigned pop_front_bit()
			{
				unsigned msb = (data_.front() & (0x1 << curr_bit_index_)) >> curr_bit_index_;

				if (--bit_index_ < 0)
					data_.pop_front();

				return msb;
			}

		private:
			int curr_bit_index_;
			std::list<T> data_;

			int msb_index() const
			{
				return sizeof(T) * 8 - 1;
			}
		};
	}
}


#endif // !BUFFER_HPP
