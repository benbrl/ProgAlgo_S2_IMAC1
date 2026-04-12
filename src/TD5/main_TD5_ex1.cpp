#include <iostream>

// petit 1)
size_t folding_string_hash(std::string const &s, size_t max)
{

    size_t hash{0};
    for (size_t i{0}; i < s.size(); i++)
    {
        hash += s[i];

        // debug
        // std::cout << "la sommes est : " << hash << std::endl;
        hash %= max;
    }

    std::cout << hash << std::endl;

    // for (char const &c : s)
    // {
    //     hash + c;
    // }

    // hash %= max;
    return hash;
}

// petit 2)
size_t folding_string_ordered_hash(std::string const &s, size_t max)
{
    size_t hash{0};
    for (size_t i{0}; i < s.size(); i++)
    {
        hash += s[i] * (i + 1);
        hash %= max;
    }

    return hash;
}

// petit 3)
// on vuet le module sur le hash la valeur la plus grande, celle qui croit le plus
//  size_t polynomial_rolling_hash(std::string const &s, size_t p, size_t m)
//  {
//  }

int main()
{

    std::string chaine_caracteres{};
    size_t max{1024};

    std::cout << "Entrez une chaine de caracteres : " << std::endl;

    // recuperer toute la ligne meme les espaces (avec le ciin ça ne fonctionnais pas)
    std::getline(std::cin, chaine_caracteres);

    // size_t result = folding_string_hash(chaine_caracteres, max);

    size_t result = folding_string_ordered_hash(chaine_caracteres, max);
    std::cout << "le resultat est : " << result << std::endl;
}
