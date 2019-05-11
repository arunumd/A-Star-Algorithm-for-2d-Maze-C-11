//
// Created by arunk on 04/27/2019.
//

#ifndef ENPM809Y_PROJECT_5_A_STAR_H
#define ENPM809Y_PROJECT_5_A_STAR_H

#include <iostream>
#include <utility>
#include <array>
#include <map>

struct ListInfo {
    double cost_g = 0;
    double cost_h = -10;
    double total_cost = -10;
    std::pair<int, int> node{std::make_pair(-100, -100)};
    std::pair<int, int> parent{std::make_pair(-100, -100)};
};

class Maze {       // First
public:            //012345  // Second
    Maze() : grid_{{"S#####",//0
                    ".....#",//1
                    "#.####",//2
                    "#.#G.#",//3
                    "...#.#",//4
                    "##...#"}},//5
             start_{std::make_pair(0, 0)}, goal_{std::make_pair(3, 3)} {}

    ~Maze() = default;

    void Spawn(std::array<std::string, 6> board) const;

    const std::pair<int, int> Scan() const;

    // Four functions to make four moves

    std::pair<int, int> North(std::pair<int, int> node) const;

    std::pair<int, int> East(std::pair<int, int> node) const;

    std::pair<int, int> West(std::pair<int, int> node) const;

    std::pair<int, int> South(std::pair<int, int> node) const;

    const int TakeDecision1(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                            const std::pair<int, int> &parent_node);

    const int TakeDecision2(const std::pair<int, int> &new_node, const double &cost_g, ListInfo &info,
                            const std::pair<int, int> &parent_node);

    int Action();

    const double CalculateDistance(std::pair<int, int> current_node) const;

    bool IsNotObstacle(std::pair<int, int> node) const;

    bool IsWithinRegion(std::pair<int, int> node) const;

    void PlotTrajectory();


private:
    const std::array<std::string, 6> grid_;
    const std::pair<int, int> start_, goal_;
    std::multimap<double, ListInfo> priority_list_;
    std::map<std::pair<int, int>, ListInfo> open_list_, closed_list_;
};

#endif //ENPM809Y_PROJECT_5_A_STAR_H
