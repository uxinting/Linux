#include "memento.h"
#include <iostream>
using namespace std;

PlayerMemento* Player::Save() {
	return new PlayerMemento(vit, atk, def);
}

void Player::Recovery(PlayerMemento* m) {
	vit = m->GetVitality();
	atk = m->GetAttack();
	def = m->GetDefense();
}

void Player::InitState() {
	vit = 100;
	atk = 100;
	def = 100;
	this->StateDisplay();
}

void Player::StateDisplay() {
	cout<< "Vitality: " << vit << " Attack: " << atk << " Defense: " << def << endl;
}

void Player::Fight() {
	vit = atk = def = 0;
}