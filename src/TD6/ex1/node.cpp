// #include <iostream>
// #include "node.hpp"

// Node *create_node(int value)
// {
//     Node *noeud{new Node};
//     noeud->value = value;
//     return noeud;


//     std::unique_
// }

// struct Node
// {
//     int value;
//     Node *left{nullptr};
//     Node *right{nullptr};

//     bool is_leaf() const // le const est opour dire que je ne modifieriais pas moi meme
//     {
//         return left == nullptr && right == nullptr;
//     }

//     void Node::insert(int value)
//     {
//         if (value < this->value)
//         {
//             if (left == nullptr)
//             {
//                 left = create_node(value);
//             }
//             else
//             {
//                 left->insert(value);
//             }
//         }
//         else
//         {
//             if (right == nullptr)
//             {
//                 right = create_node(value);
//             }
//             else
//             {
//                 right->insert(value);
//             }
//         }
//     }

//     int Node::height() const
//     {
//         int leftHeight{0};
//         int rightHeight{0};

//         if (left != nullptr)
//         {
//             leftHeight = left->height();
//         }

//         // if (right != nullptr)
//         // {
//         //     rightHeight = right->height();
//         // }

//         int const rightHeight = right != nullptr ? right->height : 0;

//         return 1 + std::max(leftHeight, rightHeight);
//     }
// };

// void Node::delete_children()
// {


//     // if(left != nullptdr) {
//     //     left-> delete_childen();
//     //     delete left;
//     //     left = nullptr
//     // }
//     // delete left;
//     // delete right;
//     // left = nullptdr;
//     // right = nullptdr;




// }