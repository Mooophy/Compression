#pragma once
#include <string>
#include <vector>
#include <bitset>

namespace cpr
{
    namespace huffman
    {
        class BitString
        {
        public:
            explicit BitString(std::string const& input) 
                : data_{ make_data(input) }
            { }

            explicit BitString(std::vector<unsigned> const& unsigneds)
                : data_{ make_data(unsigneds) }
            { }

            static auto unsigned_to_bitstring_without_leading_zeros(unsigned num) -> std::string
            {
                auto len = bit_len(num);
                auto bs = std::string(len, '\0');
                for (int i = 0; i != len; ++i)
                    bs[i] = (num & (0x1 << (len - 1 - i))) ? 1 : 0;
                return bs;
            }

            static auto char_to_bin(char ch) -> std::string
            {
                auto bs = std::string(8, 0);
                for (int i = 7; i != -1; --i)
                    bs[i] = (ch >> (7 - i)) & 0x1;
                return bs;
            }

            static auto bin_to_unsigned(std::string const& str) -> unsigned
            {
                auto ret = unsigned(0);
                for (int i = str.size() - 1; i != -1; --i)
                    ret |= ((str[i] & 0x1) << (str.size() - 1 - i));
                return ret;
            }

            template<typename Integral>
            static auto bit_len(Integral num) -> std::size_t
            {
                if (num < 0) return sizeof(Integral) * 8;
                if (num == 0)return 1;

                unsigned len = 0;
                for (; num > 0; num >>= 1) ++len;
                return len;
            }

            auto data() const -> std::string const&
            { 
                return data_; 
            }

            auto str() const -> std::string
            {
                auto str = data_;
                for (auto& ch : str) ch += 48;
                return str;
            }

            auto split_by_length(unsigned len) const -> std::vector < unsigned >
            {
                static const unsigned max_len = 8 * sizeof(unsigned);
                if (len > max_len) 
                    throw std::exception{ "too many bits" };

                auto ret = std::vector < unsigned > {};
                auto pos = unsigned(0);
                for (; data_.size() - pos > len; pos += len)
                    ret.push_back(bin_to_unsigned(data_.substr(pos, len)));
                ret.push_back(bin_to_unsigned(data_.substr(pos)));

                return ret;
            }

            //auto to_chars() const -> std::vector < char >
            //{
            //    static const unsigned len = 8 * sizeof(char);
            //    auto chars = std::vector < char > {};
            //    auto pos = std::size_t(0);
            //    for (; data_.size() - pos >= len; pos += len)
            //        chars.
            //}

        private:
            std::string data_;
            auto make_data(std::string const& input) const -> std::string
            {
                auto data = std::string{};
                for (auto ch : input) 
                    data += char_to_bin(ch);
                return data;
            }

            auto make_data(std::vector<unsigned> const& unsigneds) const -> std::string
            {
                auto data = std::string{};
                for (auto num : unsigneds)
                    data += unsigned_to_bitstring_without_leading_zeros(num);
                return data;
            }
        };
    }
}