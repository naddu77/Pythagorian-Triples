// A sample standard C++20 program that prints
// the first N Pythagorean triples.
#include <iostream>
#include <ranges>
#include <format>

int main() 
{
	for (auto const& [x, y, z] : std::views::iota(1)
        | std::views::transform([](int z) {
            return std::views::iota(1, z + 1) 
                | std::views::transform([=](int x) {
                    return std::views::iota(x, z + 1) 
                        | std::views::transform([=](int y) {
                            return std::views::single(std::tuple{ x, y, z }) | std::views::take(x * x + y * y == z * z);
                        })
                        | std::views::join;
                })
                | std::views::join;
        })
        | std::views::join
        | std::views::take(20))
    {
        std::cout << std::format("({},{},{})\n", x, y, z);
    }
}
