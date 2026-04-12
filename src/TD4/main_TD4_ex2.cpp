
#include <iostream>

auto const is_space = [](char letter)
{ return letter == ' '; };

int main()
{

    std::string phrase{"bonjour les amis"};

    // std::cout << "votre phrase : " << std::endl;
    // std::cin >> phrase;

    // int nb_caracter{};
    // for (auto const element : phrase)
    // {

    //     if (is_space(element))
    //     {

    //         std::cout << element << " n'est pas un caractere" << std::endl;
    //         std::cout << "le nombre de caractere est : " << std::endl;
    //         std::cout << nb_caracter << std::endl;

    //         return 0;
    //     }
    //     else
    //     {
    //         std::cout << element << " est un caractere" << std::endl;
    //         nb_caracter++;
    //     }
    // }

    auto it = std::find(phrase.begin(), phrase.end(), is_space) {

    }
    // std::cout << nb_caracter << std::endl;
    // std::cout << "le nombre de caractere est : " << std::endl;
}