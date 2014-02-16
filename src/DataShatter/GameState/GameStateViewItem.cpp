#include "GameStateViewItem.hpp"
#include "Item.hpp"
#include "Terminal.hpp"
#include "World.hpp"
#include "ItemData.hpp"
#include "Character.hpp"

PRIVATE_VARIABLES(State_ViewItem){
	PrivateVariables(Item const& i)
		: item(i)
	{}
	Item const& item;
};

State_ViewItem::State_ViewItem(Terminal& t, GameStateStack& s, World& w, Item const& i)
	: iGameState(t,s,w)
	, INIT_PRIVATE_VARIABLES(i)
{
}

State_ViewItem::~State_ViewItem(){}

void State_ViewItem::Render()
{
	t.Printx(0, m->item.Name());
	t.Printx(0, m->item.Info());
	t.Printx(0, m->item.Type());
	t.Printx(0, m->item.Skill());
	t.Printx(0, m->item.Power());
	t.Printx(0, m->item.Durability() << "/" << m->item.MaxDurability());
	t.Printx(0, "");
	t.Printx(0, "[E] Equip");
	t.Printx(0, "[A] Back");
}

void State_ViewItem::Update()
{
	Character& c = w.GetCharacter();
	switch( t.Key() ){
		case 'a':
			s.pop();
			break;
		case 'e':
			c.Equip(m->item);
			break;
	}
}
