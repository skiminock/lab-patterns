using namespace std;

// standart headers

#include <iostream>
#include <vector>

// custom headers

#include "Unit.h"

#include "Archer.h"
#include "Infantryman.h"
#include "Horseman.h"

#include "CompositeUnit.h"

#include "Army.h"
#include "Mediator.h"

#include "ConcreteArmy.h"
#include "ConcreteMediator.h"

CompositeUnit* createRomanLegion()
{
	CompositeUnit* romanLegion = new CompositeUnit;

	for (int i = 0; i<3000; ++i)
		romanLegion->addUnit(new Infantryman);

	for (int i = 0; i<1500; ++i)
		romanLegion->addUnit(new Archer);

	for (int i = 0; i<500; ++i)
		romanLegion->addUnit(new Horseman);

	return romanLegion;
}

CompositeUnit* createGreekLegion()
{
	CompositeUnit* greekLegion = new CompositeUnit;

	for (int i = 0; i<2000; ++i)
		greekLegion->addUnit(new Infantryman);

	for (int i = 0; i<1000; ++i)
		greekLegion->addUnit(new Archer);

	for (int i = 0; i<500; ++i)
		greekLegion->addUnit(new Horseman);

	return greekLegion;
}

int main()
{
	ConcreteMediator mediator;

	ConcreteArmy romanArmy("Roman army", &mediator);
	ConcreteArmy greekArmy("Greek army", &mediator);

	for (int i = 0; i < 4; ++i)
		(&romanArmy)->addUnit(createRomanLegion());

	for (int i = 0; i < 5; i++)
		(&greekArmy)->addUnit(createGreekLegion());

	cout << "Roman army damaging strength is " << (&romanArmy)->getStrength() << endl;
	cout << "Greek army damaging strength is " << (&greekArmy)->getStrength() << endl;

	mediator.SetArmy1(&romanArmy);
	mediator.SetArmy2(&greekArmy);

	romanArmy.Send("Are you ready to die, dirty hellens?");
	greekArmy.Send("Doing is better than saying, nasty legionnaires!");

	cout << "Press \"ENTER\" to exit";

	cin.get();

	(&romanArmy)->CompositeUnit::~CompositeUnit();
	(&greekArmy)->CompositeUnit::~CompositeUnit();

	return 0;
}
