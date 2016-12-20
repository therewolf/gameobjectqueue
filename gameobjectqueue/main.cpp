#include <iostream>

#include "Object.h"
#include "Entity.h"
#include "Queue.h"


int main(int argc, const char* argv[]) {

	Queue<Object*> updateQueue;
	Object* player = new Entity("player", 1);

	std::cout << player->getState() << std::endl;

	updateQueue.push(player);
	updateQueue.pop()->Update();

	std::cout << player->getState() << std::endl;

	delete player;
	system("PAUSE");
	return 0;
}
