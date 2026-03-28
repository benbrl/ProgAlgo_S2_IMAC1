#include <vector>
#include <cstdlib>
#include <algorithm>
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

// bubble sort
void bubble_sort(std::vector<int> &vec)
{

    // ici je fais un boucle pour aller jusqu'au dernier chiffre de mon talleau - 1 car mon i commence à 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Merge Sort
void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right)
{
    std::vector<int> vecTempLeft(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> vecTempRight(vec.begin() + middle + 1, vec.begin() + right + 1);
    size_t i = 0;
    size_t j = 0;
    for (size_t k = left; k <= right; k++)
    {
        if (i >= vecTempLeft.size())
        {
            vec[k] = vecTempRight[j];
            j++;
        }
        else if (j >= vecTempRight.size())
        {
            vec[k] = vecTempLeft[i];
            i++;
        }
        else if (vecTempLeft[i] <= vecTempRight[j])
        {
            vec[k] = vecTempLeft[i];
            i++;
        }
        else
        {
            vec[k] = vecTempRight[j];
            j++;
        }
    }
}

void merge_sort(std::vector<int> &vec, size_t const left, size_t const right)
{
    size_t middle = (left + right) / 2;
    size_t tableau_1_left = left;
    size_t tableau_1_right = middle;
    size_t tableau_2_left = middle + 1;
    size_t tableau_2_right = right;

    if (left != right)
    {
        merge_sort(vec, tableau_1_left, tableau_1_right);
        merge_sort(vec, tableau_2_left, tableau_2_right);
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<int> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

int main()

{

    std::vector<int> array = generate_random_vector(10000, 10000);
    {

        std::vector<int> array_bubble = array;
        ScopedTimer timer("Buble Sort ");
        bubble_sort(array_bubble);
    }
    {
        std::vector<int> array_merge = array;
        ScopedTimer timer("Merge Sort ");
        merge_sort(array_merge);
    }
    {
        std::vector<int> array_cpp = array;
        ScopedTimer timer("Sort cpp ");
        std::sort(array_cpp.begin(), array_cpp.end());
    }
}
