#include <iostream>
#include "node.hpp"

Node *create_node(int value)
{
    Node *noeud = new Node();
    noeud->value = value;

    return noeud;
}

void Node::insert(int new_value)
{

    if (new_value < value)
    {

        if (this->left == nullptr)
        {
            left = create_node(new_value);
        }
        else
        {
            left->insert(new_value);
        }
    }
    else
    {
        if (this->right == nullptr)
        {
            right = create_node(new_value);
        }
        else
        {
            right->insert(new_value);
        }
    }
}

// benoit le goat t'es super change pas
int Node::height() const
{

    int left_height{};
    int right_height{};

    left_height = (left != nullptr) ? left->height() : 0;
    right_height = (right != nullptr) ? right->height() : 0;

    // std::cout << left_height << " " << right_height << " " << this->value << std::endl;

    return (1 + std::max(left_height, right_height));
}

void Node::delete_children()
{

    if (this->left != nullptr)
    {
        this->left->delete_children();
        delete left;
        left = nullptr;
    }

    if (this->right != nullptr)
    {
        this->right->delete_children();
        delete right;
        right = nullptr;
    }
}

void Node::display_infix() const
{

    // if (is_leaf() != true)
    // {
    //     int left_value = left->value;
    //     std::cout << " value de left " << left_value << std::endl;
    //     left->display_infix();
    // }

    if (left != nullptr)
    {
     display_infix();
    };

    std::cout << this->value << std::endl;

    if (right != nullptr)
    {
    display_infix();
    };
}
