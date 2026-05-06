#pragma once

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    bool is_leaf() const

    {
        return (left == nullptr && right == nullptr);
    }

    void insert(int new_value);

    int height() const;

    void delete_children();

    void display_infix() const;
};

Node *create_node(int value);