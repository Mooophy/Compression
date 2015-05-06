#pragma once
#include <bitset>
#include <string>
#include <vector>

namespace cpr
{
    namespace huffman
    {
        class BitString
        {
        public:
            explicit BitString(std::string const& input) : data_( make_data(input) ){ }

            static auto char_to_bin(char ch) -> std::string
            {
                auto bs = std::string(8, 0);
                for (int i = 7; i != -1; --i)
                    bs[i] = (ch >> (7 - i)) & 0x1;
                return bs;
            }

            auto data() const -> std::string const&{ return data_; }
            auto str() const -> std::string
            {
                auto str = data_;
                for (auto& ch : str) ch += 48;
                return str;
            }

        private:
            std::string data_;
            auto make_data(std::string const& input) const -> std::string
            {
                auto data = std::string{};
                for (auto ch : input) data += char_to_bin(ch);
                return data;
            }
        };
    }
}