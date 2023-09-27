#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <algorithm>
int search_val(std::vector<int>& vec, int val){
    for (size_t i=0; i<vec.size(); ++i){
        if (vec[i]==val){
            return i;
        }
    }
    return -1;
}
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    std::vector<int> vec(100, 0);
    std::generate(vec.begin(),vec.end(), [&](){return dist(gen);});
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i != 0 && i % 10 == 0)
        {
            std::cout << "\n";
        }
        std::cout << std::setw(4) << vec[i];
    }
    std::cout << "\n" << search_val(vec, 5) << "\n";
}