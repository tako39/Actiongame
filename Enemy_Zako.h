#ifndef ___Class_Zako
#define ___Class_Zako

#include "Enemy.h"

//Enemy_Zakoを生成するクラス
class Zako : public Enemy {
public:
	Zako();
	~Zako();

	void Update() {};
	void Update(const Player& player);
	void Draw() {};
	void Draw(const Player& player);
};

#endif