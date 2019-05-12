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

class Maze {       // First    012345678901234567890123456789012345
public:            //0123456789111111111122222222223333333333444444  // Second
    Maze() : grid_{{"##############################################",//0
                    "#              #                             #",//1
                    "#  ##########  #############  #######  ####  #",//2
                    "#           #                 #        #     #",//3
                    "#  #######  #############  ###################",//4
                    "#  #     #  #           #  #                 #",//5
                    "# S#  #  #  #  #  #######  #  #############  #",//6
                    "#  #  #  #  #  #  #     #  #  #  #        #  #",//7
                    "#  #  ####  #  ##########  #  #  ####  #  #  #",//8
                    "#  #     #  #              #           #  #  #",//9
                    "#  ####  #  ################  #############  #",//10
                    "#     #  #                    #              #",//11
                    "####  #  ######################  ##########  #",//12
                    "#  #  #                    #     #     #  #  #",//13
                    "#  #  ####  #############  #  ####  #  #  #  #",//14
                    "#  #  #     #     #     #  #  #     #     #  #",//15
                    "#  #  #  #######  ####  #  #  #  ##########  #",//16
                    "#     #  #              #  #  #             G#",//17
                    "####  #  #  ##########  #  #  #  #############",//18
                    "#  #  #  #  #  #        #  #  #  #           #",//19
                    "#  #  #  #  #  #######  #  #  #  #  #######  #",//20
                    "#  #  #  #  #  #     #  #  #  #  #  #     #  #",//21
                    "#  #  #  #  #  #######  #  #  #  #  #  #  #  #",//22
                    "#  #  #  #  #           #  #  #  #  #  #  #  #",//23
                    "#  #  #  #  #############  #  #  #  ####  #  #",//24
                    "#     #  #                 #  #  #        #  #",//25
                    "#  ####  #  ################  #  #######  #  #",//26
                    "#  #     #  #        #        #     #     #  #",//27
                    "#  ####  #  #######  #  ##########  #######  #",//28
                    "#        #           #  #                    #",//29
                    "######################  ######################"}},//30
             start_{std::make_pair(2, 6)}, goal_{std::make_pair(44, 17)} {}

    ~Maze() = default;

    void Spawn(std::array<std::string, 31> board) const;

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
    const std::array<std::string, 31> grid_;
    const std::pair<int, int> start_, goal_;
    std::multimap<double, ListInfo> priority_list_;
    std::map<std::pair<int, int>, ListInfo> open_list_, closed_list_;
};

#endif //ENPM809Y_PROJECT_5_A_STAR_H
