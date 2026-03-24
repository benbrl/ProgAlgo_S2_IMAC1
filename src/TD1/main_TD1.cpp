#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <queue>
#include <stack>

std::vector<std::string> split_string(std::string const &s)
{
  std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
  // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
  return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
  for (char caractere : s)
  {
    // std::cout << "- " << std::isdigit(caractere) << std::endl;
    return std::isdigit(caractere);
  }
}

float npi_evaluate(std::vector<std::string> const &tokens)
{

  std::stack<float> stack;

  for (std::string const &element : tokens)
  {

    std::cout << element << std::endl;
    if (is_floating(element))
    {
      // std::cout << " je suis un chiffre" << std::endl;
      stack.push(std::stof(element));
    }
    else
    {
      float rightOperand{stack.top()};
      stack.pop();
      float leftOperand{stack.top()};
      stack.pop();
      if (element == "+")
      {
        // std::cout << " je suis un operateur +" << std::endl;
        stack.push(leftOperand + rightOperand);
      }
      else if (element == "-")
      {
        // std::cout << " je suis un operateur -" << std::endl;
        stack.push(leftOperand - rightOperand);
      }
      else if (element == "*")
      {
        // std::cout << " je suis un operateur *" << std::endl;
        stack.push(leftOperand * rightOperand);
      }
      else if (element == "/")
      {
        // std::cout << " je suis un operateur /" << std::endl;
        stack.push(leftOperand / rightOperand);
      }
    }
  }
  std::cout << "resultat :" << std::endl;
  return stack.top();
}

int main()
{

  std::string expression;
  std::cout << "votre expression :" << std::endl;
  std::getline(std::cin, expression);

  std::vector<std::string> expression_split = split_string(expression);
  std::cout << "version split :" << std::endl;
  std::cout << npi_evaluate(expression_split) << std::endl;
}