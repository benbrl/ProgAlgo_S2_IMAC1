#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <queue>
#include <stack>

enum class Operator
{
  ADD,
  SUB,
  MUL,
  DIV,
  OPEN_PAREN,
  CLOSE_PAREN
};

enum class TokenType
{
  OPERATOR,
  OPERAND
};

struct Token
{
  TokenType type;
  float value;
  Operator op;
};

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

Token make_token(float value)
{
  Token mytoken{};
  mytoken.type = TokenType::OPERAND;
  mytoken.value = value;

  return mytoken;
}

Token make_token(Operator op)
{
  Token mytoken{};
  mytoken.type = TokenType::OPERATOR;
  mytoken.op = op;

  return mytoken;
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{

  std::vector<Token> mon_vecteur{};

  for (int i = 0; i < words.size(); i++)
  {
    if (is_floating(words[i]))
    {
      mon_vecteur.push_back(make_token(std::stof(words[i])));
    }
    else
    {
      if (words[i] == "+")
      {

        mon_vecteur.push_back(make_token(Operator::ADD));
      }
      else if (words[i] == "-")
      {
        mon_vecteur.push_back(make_token(Operator::SUB));
      }
      else if (words[i] == "*")
      {
        mon_vecteur.push_back(make_token(Operator::MUL));
      }
      else if (words[i] == "/")
      {
        mon_vecteur.push_back(make_token(Operator::DIV));
      }
    }
  }
  return mon_vecteur;
}

float npi_evaluate(std::vector<Token> const &tokens)
{

  std::stack<Token> stack;

  for (Token const &element : tokens)
  {

    if (element.type == TokenType::OPERAND)
    {
      stack.push(element);
    }
    else
    {

      if (stack.empty())
      {
        std::cout << "holalalalalalalala tu as tout cassé" << std::endl;
      }
      Token rightOperand{stack.top()};
      stack.pop();
      Token leftOperand{stack.top()};
      stack.pop();
      if (element.op == Operator::ADD)
      {
        stack.push(make_token(leftOperand.value + rightOperand.value));
      }
      else if (element.op == Operator::SUB)
      {
        stack.push(make_token(leftOperand.value - rightOperand.value));
      }
      else if (element.op == Operator::MUL)
      {
        stack.push(make_token(leftOperand.value * rightOperand.value));
      }
      else if (element.op == Operator::DIV)
      {
        stack.push(make_token(leftOperand.value / rightOperand.value));
      }
    }
  }
  std::cout << "resultat :" << std::endl;
  return stack.top().value;
}

int main()
{

  std::string expression{"2 12 + 5 +"};
  // std::cout << "votre expression :" << std::endl;
  // std::getline(std::cin, expression);

  std::vector<std::string> expression_split = split_string(expression);
  std::vector<Token> tokkkkkkkkkennnn = tokenize(expression_split);
  std::cout << "version split :" << std::endl;
  std::cout << npi_evaluate(tokkkkkkkkkennnn) << std::endl;
}