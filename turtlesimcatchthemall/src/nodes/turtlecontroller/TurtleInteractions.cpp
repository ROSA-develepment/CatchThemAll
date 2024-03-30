
#include "TurtleInteractions.h"


TurtleInteractions::TurtleInteractions(Node* parent)
    : _catchTurtleClient(parent, "catch_turtle")
    , _turtleSimPublisher(parent, "turtle1/cmd_vel")
    , _turtleSimSubscriber(parent)
    , _turtleSpawnSubscriber(parent)
    , _parent(parent)
{
    _turtleSimSubscriber.subscribe("turtle1/pose", [this](Pose::SharedPtr const& message) { callback(message); });
    _turtleSpawnSubscriber.subscribe("alive_turtles", [this](TurtleArray::SharedPtr const& message) { callback(message); });
    waitForTurtleArray();
}

void TurtleInteractions::sendMovement(Twist message)
{
    _turtleSimPublisher.send(message);
}

void TurtleInteractions::sendCatchTurtleRequest(Turtle const& cachedTurtle)
{
    _catchTurtleClient.setRequest(cachedTurtle);
    _catchTurtleClient.startWorkerThread();
}

Pose TurtleInteractions::getPosition()
{
    return _currentPosition;
}

TurtleArray TurtleInteractions::getTurtles()
{
    return _turtles;
}

void TurtleInteractions::callback(Pose::SharedPtr const& message)
{
    _currentPosition = *message;
}

void TurtleInteractions::callback(TurtleArray::SharedPtr const& message)
{
    _turtles = *message;
}

void TurtleInteractions::waitForTurtleArray()
{
    while (_turtles.turtles_array.empty())
    {
        rclcpp::spin_some(_parent);
    }
}
