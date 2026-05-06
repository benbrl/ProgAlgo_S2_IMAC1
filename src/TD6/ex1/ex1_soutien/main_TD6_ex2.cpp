#include <iostream>
#include "node.hpp"

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "| " : " "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? " " : "| "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}

int main()
{

    Node *mon_premier_node = create_node(50);
    mon_premier_node->insert(3);
    mon_premier_node->insert(4);
    mon_premier_node->insert(332);
    mon_premier_node->insert(403);
    mon_premier_node->insert(10);
    mon_premier_node->insert(14);
    mon_premier_node->insert(12);
    mon_premier_node->insert(34);

    std::cout << " mon premier node hauteur : " << mon_premier_node->height() << std::endl;
    pretty_print_left_right(*mon_premier_node);

    mon_premier_node->display_infix();

    // mon_premier_node->delete_children();
    // std::cout << " ------- Mon novueau arbre -----" << std::endl;

    // pretty_print_left_right(*mon_premier_node);
}