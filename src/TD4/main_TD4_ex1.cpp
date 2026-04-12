#include <iostream>
#include <numeric>

int main()
{
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), []()
                  { return std::rand() % 100; });

    for (auto const element : vec)
    {

        std::cout << element << ";";
    }
    std::cout << std::endl;

    std::cout << "valeur à trouver : " << std::endl;

    int find_number{};

    std::cin >> find_number;

    auto iterator_find = std::find(vec.begin(), vec.end(), find_number);

    if (iterator_find != vec.end())
    {
        std::cout << "le numero " << find_number << " a été trouvé à la " << distance(vec.begin(), iterator_find) << " eme place" << std::endl;
    }
    else

    {
        std::cout << "je n'ai pas trouvé le nombre dnas le tableau  " << std::endl;
    }
    auto iterator_count = std::count(vec.begin(), vec.end(), find_number);
    if (
        iterator_count >= 1)
    {

        std::cout << "le nombre apparait :" << iterator_count << "fois" << std::endl;
    }
    {
        std::cout << "le nombre n'apparait pas" << std::endl;
    }

    std::sort(vec.begin(), vec.end());

    std::cout << "le vecteur trié" << std::endl;
    for (auto const element : vec)
    {
        std::cout << element << ";";
    }
    std::cout << std::endl;

    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "la somme est : " << std::endl;
    std::cout << sum << std::endl;
}