#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
void show(const std::vector<int> &v) 
{
    for (auto i : v)
    {
        std::cout << std::setw(4) << i << " ";
    }
    std::cout << "\n";
}
void insSort(std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
int main()
{
    std::vector<int> v(10, 0);
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);
    for (auto &i : v)
    {
        i = dist(rd);
    }
    show(v);
    insSort(v);
    show(v);
}
