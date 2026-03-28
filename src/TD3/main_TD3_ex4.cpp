#include <iostream>
#include <vector>
#include <algorithm>

int search(const std::vector<int> &array, int nb_search, int left, int right)
{

    // debug
    //  std::cout << nb_search << std::endl;
    //  std::cout << left << std::endl;
    //  std::cout << right << std::endl;

    int middle = (left + right) / 2;
    // std::cout << middle << std::endl;

    int terme = array[middle];
    // std::cout << terme << std::endl;

    if (terme == nb_search)
    {
        return middle;
    }
    else if (terme < nb_search)
    {
        if (middle == left)
        {
            return -1;
        }

        return search(array, nb_search, middle + 1, right);
    }
    else if (terme > nb_search)
    {
        if (middle == right)
        {
            return -1;
        }

        return search(array, nb_search, left, middle - 1);
    }
    else
    {
        return -1;
    }
}

int remap_seach(std::vector<int> &array, int nb_search)
{
    return search(array, nb_search, 0, array.size() - 1);
}

int main()
{
    // std::vector<int> array{1, 2, 2, 3, 4, 8, 12};

    // std::vector<int> array{1, 2, 3, 3, 6, 14, 12, 15};
    // std::vector<int> array{2, 2, 3, 4, 5, 8, 12, 15, 16};
    // std::vector<int> array{5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8, 9};

    // int nb_search = 8;
    // int nb_search = 15;
    // int nb_search = 16;
    // int nb_search = 6;
    int nb_search = 10;

    int result = remap_seach(array, nb_search);

    if (result != -1)
    {
        std::cout << nb_search << " trouvé en position " << result << std::endl;
    }
    else
    {
        std::cout << nb_search << " non trouvé" << std::endl;
    }
}