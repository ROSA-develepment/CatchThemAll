
#ifndef ROS_SPAWNTURTLECLIENT_H
#define ROS_SPAWNTURTLECLIENT_H

#include "interfaces/msg/turtle.hpp"

#include <rosa/client/Client.h>
#include <rosa/node/Node.h>

#include "turtlesim/srv/spawn.hpp"

using Turtle = interfaces::msg::Turtle;
using Spawn = turtlesim::srv::Spawn;

class SpawnTurtleClient : public Client<Spawn>
{
public:
    SpawnTurtleClient(Node* node, std::string const& serviceName);

    void setRequest(Turtle const& turtleToSpawn);

private:
    void sendRequest() override;
};


#endif //ROS_SPAWNTURTLECLIENT_H
