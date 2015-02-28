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

			Buffer(std::initializer_list<T> li)
				: curr_bit_index_{ msb_index() }, data_(li)
			{	}

			template<typename Iterator>
			Buffer(Iterator first, Iterator last)
				: curr_bit_index_{ msb_index() }, data_(first, last)
			{	}

			void push_back(T const& val)
			{
				data_.push_back(val);
			}

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
				if (--curr_bit_index_ < 0)
				{
					data_.pop_front();
					curr_bit_index_ = msb_index();
				}
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
