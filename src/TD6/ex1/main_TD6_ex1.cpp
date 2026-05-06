// #include <iostream>

// #include <node.hpp>

// void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
// {
//     if (node.right)
//     {
//         pretty_print_left_right(*node.right, prefix + (is_left ? "| " : " "), false);
//     }
//     std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
//     if (node.left)
//     {
//         pretty_print_left_right(*node.left, prefix + (is_left ? " " : "| "), true);
//     }
// }

// void pretty_print_left_right(Node const &node)
// {
//     pretty_print_left_right(node, "", true);
// }

// int main()
// {

//     pretty_print_left_right(*node)

//     //     Node *root{new Node{1, nullptr, nullptr}};
//     // root->left = {new Node{2, nullptr, nullptr}};
//     // root->right = {new Node{3, nullptr, nullptr}};

//     // root->left->left = {new Node{4, nullptr, nullptr}};

//     Node *node = create_node(10);

//     delete node;

//     delete root->left->left;
//     delete root->left;
//     delete root->right;
//     delete root;
// }