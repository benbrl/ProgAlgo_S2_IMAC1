#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const &vec) { return std::is_sorted(vec.begin(), vec.end()); }

void bubble_sort(std::vector<int> &vec)
{

    // ici je fais un boucle pour aller jusqu'au dernier chiffre de mon talleau - 1 car mon i commence à 0;

    for (size_t i = 0; i < vec.size(); i++)
    {
        for (size_t j = 0; j < vec.size() - i - 1; j++)
        {
            // std::cout << "mes deux elements" << std::endl;
            // std::cout << vec[i] << std::endl;
            // std::cout << vec[i + 1] << std::endl;

            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
                // std::cout << "mes deux elements dans l'ordre" << std::endl;
                // std::cout << vec[i] << std::endl;
                // std::cout << vec[i + 1] << std::endl;
            }
        }
    }
}

int main()
{
    std::vector<int> array{9, 2, 3, 4, 1, 5, 7, 11, 10, 12431, 132, 24, 35, 406, 35};

    bubble_sort(array);

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