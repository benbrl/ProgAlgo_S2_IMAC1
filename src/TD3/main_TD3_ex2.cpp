#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const &vec) { return std::is_sorted(vec.begin(), vec.end()); }

void merge_sort_merge(std::vector<int> &vec, size_t const left, size_t const middle, size_t const right)
{

    std::vector<int> vecTempLeft(vec.begin() + left, vec.begin() + middle + 1);

    // debug
    // std::cout << "vecTempLeft entier : " << std::endl;
    //  for (size_t i = 0; i < vecTempLeft.size(); i++)
    //  {
    //      std::cout << vecTempLeft[i] << ";";
    //  }
    //  std::cout << std::endl;

    std::vector<int> vecTempRight(vec.begin() + middle + 1, vec.begin() + right + 1);

    // debug
    // std::cout << "vecTempRight entier : " << std::endl;
    // for (size_t j = 0; j < vecTempRight.size(); j++)
    // {
    //     std::cout << vecTempRight[j] << ";";
    // }
    // std::cout << std::endl;

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

    // petit debug

    // std::cout << "gauche : " << std::endl;
    // std::cout << left << std::endl;
    // std::cout << "droite : " << std::endl;
    // std::cout << right << std::endl;

    // std::cout << "moyenne : " << std::endl;
    // std::cout << middle << std::endl;
    size_t middle = (left + right) / 2;

    // reasignation
    size_t tableau_1_left = left;
    size_t tableau_1_right = middle;

    size_t tableau_2_left = middle + 1;
    size_t tableau_2_right = right;

    if (left != right)
    {
        std::cout << "Divise de :" << left << " a " << right << "et milieu=" << middle << std::endl;
        merge_sort(vec, tableau_1_left, tableau_1_right);
        merge_sort(vec, tableau_2_left, tableau_2_right);
        std::cout << "Merge de " << left << " a  " << middle << " et de " << middle + 1 << " a " << right << std::endl;
        merge_sort_merge(vec, left, middle, right);
    }
}

void merge_sort(std::vector<int> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

int main()
{
    std::vector<int> array{9, 2, 3, 4, 1, 5, 7, 11, 10, 12431, 132, 24, 34, 406, 35};

    merge_sort(array);

    // petit verifiation du tableau
    std::cout << "Verificiation de la taille de mon tableau :" << std::endl;
    for (size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << ";";
    }
    std::cout << std::endl;

    if (is_sorted(array))
    {
        std::cout << "Le tableau est trié" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trié" << std::endl;
    }
}
