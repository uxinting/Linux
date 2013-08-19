#ifndef MEMENTO_H_
#define MEMENTO_H_
class PlayerMemento
{
private:
	int vit; //ÉúÃü
	int atk; //¹¥»÷
	int def; //·ÀÓù
public:
	PlayerMemento(int v, int a, int d) { vit = v; atk = a; def = d; }

	int GetVitality() { return vit; }
	void SetVitality(int vit) { this->vit = vit; }

	int GetAttack() { return atk; }
	void SetAttack(int atk) { this->atk = atk; }

	int GetDefense() { return def; }
	void SetDefense(int def) { this->def = def; }
};

class Player
{
public:
	//save player's state
	PlayerMemento* Save();

	//recovery player's state
	void Recovery(PlayerMemento*);

	void StateDisplay();
	void InitState();
	void Fight();
private:
	int vit;
	int atk;
	int def;
};

class PlayerCaretaker
{
private:
	PlayerMemento* memento;
public:
	PlayerMemento* GetPlayerMemento() { return memento; }
	void SetPlayerMemento(PlayerMemento* m) { memento = m; }
};

#endif