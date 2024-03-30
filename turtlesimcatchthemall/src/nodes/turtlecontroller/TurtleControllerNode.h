
#ifndef TURTLESIM_CATCH_THEM_ALL_TURTLECONTROLLERNODE_H
#define TURTLESIM_CATCH_THEM_ALL_TURTLECONTROLLERNODE_H

#include "TurtleInteractions.h"
#include "TurtleMoveCenter.h"

#include "interfaces/msg/turtle.hpp"
#include "interfaces/msg/turtle_array.hpp"

#include "rosa/node/Node.h"
#include "rosa/timer/Timer.h"


using Turtle = interfaces::msg::Turtle;
using TurtleArray = interfaces::msg::TurtleArray;

class TurtleControllerNode : public Node
{
    enum class CatchOrder
    {
        Spawn,
        Closest
    };

public:
    TurtleControllerNode();

private:
    void controlLoop();
    void setTarget();
    void defineCatchOrder(std::string const& order);

    TurtleInteractions _interactions;
    TurtleMoveCenter _moveCenter;
    Timer _controlLoopTimer;

    Turtle _target;
    TurtleArray _turtles;
    CatchOrder _order;
};

#endif //TURTLESIM_CATCH_THEM_ALL_TURTLECONTROLLERNODE_H
