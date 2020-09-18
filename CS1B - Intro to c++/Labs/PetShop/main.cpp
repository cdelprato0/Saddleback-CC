
#include "PetShop.h"
#include "Birds.h"
#include "Fish.h"

int main()
{

	Fish *nemo;
	Birds *nigel;
	Pet * pet;

	PetShop omarsPetShop;

	nemo  = new Fish(false, "Nemo", 200.00, 5, 'M');
	nigel = new Birds(true, "Nigel", 10.00, 30, 'M');
	pet   = new Fish(false, "Dory", 15.00, 12, 'F');

	omarsPetShop.AddPet(nemo);
	omarsPetShop.AddPet(nigel);
	omarsPetShop.AddPet(pet);
	omarsPetShop.DisplayInventory();

	nemo->Speak();
	nigel->Speak();
	pet->Speak();

	return 0;
}
