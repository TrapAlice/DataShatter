#include "GameStateInventory.hpp"
#include "Terminal.hpp"
#include "World.hpp"
#include "Character.hpp"
#include "Equipment.hpp"
#include "Item.hpp"
#include "GameStateViewItem.hpp"

PRIVATE_VARIABLES(State_Inventory){
	unsigned        itemPage;
	const vector<Item>* items;
};

State_Inventory::State_Inventory(Terminal& t, GameStateStack& s, World& w)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES()
{}

State_Inventory::~State_Inventory(){}

void State_Inventory::Render()
{
	Character& c = w.GetCharacter();
	t.Printx(0, "Inventory");
	m->items = &c.Items();
	for( unsigned x = 0; x < m->items->size(); ++x ){
		t.Printx(0, "[" << x+1 << "] - " <<(*m->items)[x].Name());
	}
	t.Printx(0, "");
	t.Printx(0, "[A] Back");
}

void State_Inventory::Update()
{
	unsigned key = t.Key();
	switch( key ){
		case 'a':
			s.pop();
			break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if( key-48 > m->items->size() ) return;
			s.push(NEW_STATE(ViewItem, (*m->items)[key-49]));
			break;
	}
}
