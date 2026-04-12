#include <iostream>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

// POSITION DIRECTION et operateur
enum Direction
{
    Haut,
    Droite,
    Gauche,
    Bas,

};

struct Position
{
    int x;
    int y;
};

namespace std
{
    template <>
    struct hash<Position>
    {
        std::size_t operator()(const Position &pos) const
        {
            return std::hash<int>()(pos.x) ^ std::hash<int>()(pos.y);
        }
    };
}

struct WalkResult
{
    Position final_position;
    size_t steps_taken;
    std::unordered_set<Position> visited_positions;
    bool is_loop;
};

const std::unordered_map<Direction, Position> direction_to_position = {
    {Haut, {0, -1}},
    {Droite, {1, 0}},
    {Bas, {0, 1}},
    {Gauche, {-1, 0}}

};

bool operator==(Position const &position1, Position const &position2)
{
    return position1.x == position2.x && position1.y == position2.y;
}

std::ostream &operator<<(std::ostream &os, Position const &current_position)
{
    return os << "(" << current_position.x << ";" << current_position.y << ")";
}

Position &operator+=(Position &position1, Position const &position2)
{
    position1.x += position2.x;
    position1.y += position2.y;

    return position1;
}

Position operator+(Position const &position, Direction const &direction)
{
    Position const &direction_remap = direction_to_position.at(direction);

    return Position{position.x + direction_remap.x, position.y + direction_remap.y};
}

Position operator+=(Position &position, Direction const &direction)
{
    Position const &direction_remap = direction_to_position.at(direction);
    position.x += direction_remap.x;
    position.y += direction_remap.y;
    return position;
}

// GARDE et operateur

struct GuardState
{
    Position guard_position;
    Direction guard_direction;
};

namespace std
{
    template <>
    struct hash<GuardState>
    {
        std::size_t operator()(const GuardState &etat) const
        {
            return std::hash<Position>()(etat.guard_position) ^ std::hash<int>()(static_cast<int>(etat.guard_direction));
        }
    };
}

bool operator==(GuardState const &guard_position1, GuardState const &guard_position2)
{
    return guard_position1.guard_position == guard_position2.guard_position && guard_position1.guard_direction == guard_position2.guard_direction;
}

Direction turn_right(Direction direction)
{
    Direction new_direction{};

    switch (direction)
    {
    case Direction::Bas:
        new_direction = Direction::Gauche;
        break;
    case Direction::Haut:
        new_direction = Direction::Droite;
        break;
    case Direction::Gauche:
        new_direction = Direction::Haut;
        break;
    case Direction::Droite:
        new_direction = Direction::Bas;
        break;
    default:
        new_direction = direction;
        break;
    }

    return new_direction;
}

struct Input_Structure
{
    Position initial_position{};
    Direction initial_direction{};

    std::vector<Position> position_obstacle{};

    int width_map{};
    int height_map{};
};

Input_Structure parse_input(std::istream &input_stream)
{

    Input_Structure resultat{};
    int y = 0;
    for (std::string line{}; std::getline(input_stream, line, '\n') and line != "";)
    {
        int x = 0;
        for (char colonne : line)
        {

            std::cout << colonne;
            if (colonne == '#')
            {
                resultat.position_obstacle.push_back(Position{x, y});
            }
            else if (colonne == '<')
            {
                resultat.initial_direction = Direction::Gauche;
                resultat.initial_position = Position{x, y};
            }
            else if (colonne == '>')
            {
                resultat.initial_direction = Direction::Droite;
                resultat.initial_position = Position{x, y};
            }
            else if (colonne == '^')
            {
                resultat.initial_direction = Direction::Haut;
                resultat.initial_position = Position{x, y};
            }
            else if (colonne == 'v')
            {
                resultat.initial_direction = Direction::Bas;
                resultat.initial_position = Position{x, y};
            }
            x++;
        }
        y++;

        resultat.width_map = x;
        resultat.height_map = y;
        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    // debug
    for (auto number : resultat.position_obstacle)
    {
        std::cout << number << std::endl;
    }
    std::cout << "------------------------" << std::endl;

    std::cout << "width : " << resultat.width_map << " height : " << resultat.height_map << std::endl;

    std::cout << "------------------------" << std::endl;

    return resultat;
}

WalkResult walk(Position garde_position, Direction initial_direction, std::vector<Position> const &obstacles, int height_map, int width_map)
{

    WalkResult resultat{};

    size_t steps_taken = 0;
    std::unordered_set<Position> visited_positions;
    Direction current_direction = initial_direction;

    std::unordered_set<GuardState> boucle;

    while (garde_position.x >= 0 && garde_position.x < width_map &&
           garde_position.y >= 0 && garde_position.y < height_map)
    {
        Position next = garde_position + current_direction;
        GuardState direction_and_position{garde_position, current_direction};

        std::cout << "------------------------" << std::endl;
        // debug
        for (GuardState const &coordonnee : boucle)
        {
            std::cout << coordonnee.guard_position << " et direction:" << coordonnee.guard_direction << std::endl;
        }
        std::cout << "------------------------" << std::endl;

        if (boucle.count(direction_and_position) > 0)
        {
            resultat.is_loop = true;

            std::cout << "oups ! on ets dans une boucle " << std::endl;
            return resultat;
        }
        else
        {
            boucle.insert(direction_and_position);
        }

        bool is_obstacle = false;

        for (Position const &obstacle : obstacles)
        {
            if (next.x == obstacle.x && next.y == obstacle.y)
            {
                is_obstacle = true;
                break;
            }
        }

        if (is_obstacle)
        {

            current_direction = turn_right(current_direction);
        }
        else
        {
            resultat.visited_positions.insert(garde_position);

            garde_position = next;

            resultat.steps_taken++;
        }
    }

    std::cout << "en dehors de la carte" << std::endl;

    resultat.final_position = garde_position;
    return resultat;
}

int main()
{

    // Position initial_position = {2, 3};
    // Direction dir = Direction::Haut;
    // std::cout << "position :" << initial_position << std::endl;
    // std::cout << "direction : " << dir << std::endl;
    // Position newPos{initial_position + dir}; // newPos devient (2, 2)
    // std::cout << "ma nouvelle position : " << newPos << std::endl;
    // newPos += dir; // newPos devient (2, 1)

    // std::cout << newPos << std::endl;

    std::ifstream file("../../src/TD5/map.txt");
    // std::ifstream file("../../src/TD5/input_guard_patrol.txt");
    // std::ifstream file("../../src/TD5/map_obstacle.txt");

    
    Input_Structure input = parse_input(file);

    WalkResult resultat = walk(input.initial_position, input.initial_direction, input.position_obstacle, input.height_map, input.width_map);
    // debug

    std::cout << "le nombre de pas est de : " << resultat.steps_taken << std::endl;
    std::cout << "positions visitées : " << resultat.visited_positions.size() << std::endl;

    int boucle_loop = 0;

    for (Position const &position : resultat.visited_positions)
    {
        std::vector<Position> obstacles_temporaire = input.position_obstacle;
        obstacles_temporaire.push_back(position);

        WalkResult test = walk(input.initial_position, input.initial_direction, obstacles_temporaire, input.height_map, input.width_map);

        if (test.is_loop)
        {
            boucle_loop++;
        }
    }

    std::cout << "nombre de boucles : " << boucle_loop << std::endl;
}