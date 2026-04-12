// #include <iostream>

// bool palindrome(std::string const &str)
// {
//     auto begin_it{str.begin()};
//     auto end_it{str.end()};
//     auto rbegin_it{str.rbegin()};
//     auto rend_it{str.rend()};

//     // auto begin_it{str.begin()};
//     // auto rbegin_it  {str.rbegin()};
//     // if (*begin_it != *rbegin_it)  // il manquait le * pour déréférencer rbegin_it
//     // {
//     //     return false;             // il manquait le ;
//     // }

//     while (*begin_it == *rbegin_it && begin_it != end_it && rbegin_it != rend_it)
//     {
//         begin_it++;
//         rbegin_it++;
//     }

//     return begin_it == end_it || rbegin_it == rend_it;
// }
// // equal compare les valeurs

// // on a aun tralbuea de valeur et

// bool sum_even(std::vector<int> const &vec)
// {
//     return std::accumulate(vec.begin(), vec.end(), 0, [](int const &acc, int const &value)

//                            {
//                                return acc + (value % 2 == 0 ? value : 0);

//                                bool sum_even(std::vector<int> const& vec)
// {
//     return std::accumulate(vec.begin(), vec.end(), 0, [](int const& acc, int const& value)
//     //     ^ faute de frappe : stfd             ^ virgule manquante avant la lambda
//     {
//         return acc + (value % 2 == 0 ? value : 0);
//         //                                        ^ ; manquant
//     });
//     // ^ parenthèse fermante de accumulate et ; manquants
// } });
// }

// // si on vuet des truc oridnere il faut utlsier acucmualitre et si on vuet des truc rnadom c'est reduce
// int main()
// {
// }