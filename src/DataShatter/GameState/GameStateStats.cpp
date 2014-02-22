#include "GameStateStats.hpp"
#include "Terminal.hpp"
#include "World.hpp"
#include "Character.hpp"
#include "Equipment.hpp"
#include "Item.hpp"
#include "GameStateInventory.hpp"
#include "GameStateAbilities.hpp"
#include "Spec.hpp"

State_Stats::State_Stats(Terminal& t, GameStateStack&s, World& w)
	: iGameState(t,s,w)
{}

State_Stats::~State_Stats(){}

void State_Stats::Render()
{
	Character& c =  w.GetCharacter();
	t.Printx(0, "Character stats - " << c.GetSpec().Name() << "(" << c.GetSpec().Level()
		 << ")");
	t.Printx(0, "HP   : " << c.Hp() << "/" << c.MaxHp());
	t.Printx(0, "Mana : " << c.Mana() << "/" << c.MaxMana());
	t.Printx(0, "Heat : " << c.Heat());
	t.Printx(0, "");

	t.Printx(0, "Equipment:");
	Equipment& equipment = c.GetEquipment();
	auto right = equipment.Equipped(RIGHT_HAND);
	t.Printx(0, "Right Hand: " << ((right)? right->Name() : "empty"));
	auto left = equipment.Equipped(LEFT_HAND);
	t.Printx(0, "Left Hand : " << ((left)? left->Name() : "empty"));

	t.Printx(0, "[I] Inventory");
	t.Printx(0, "[K] Abilities");
	t.Printx(0, "");
	t.Printx(0, "[A] Back");
}

void State_Stats::Update()
{
	switch( t.Key() ){
		case 'a':
			s.pop();
			break;
		case 'i':
			s.push(NEW_STATE(Inventory));
			break;
		case 'k':
			s.push(NEW_STATE(Abilities));
			break;
	}
}
