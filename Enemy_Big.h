#ifndef ___Class_Big
#define ___Class_Big

#include "Enemy.h"

//Enemy_Bigを生成するクラス
class Big : public Enemy {
public:
	Big();
	~Big();

	void Update() {};
	void Update(const Player& player);
	void Draw() {};
	void Draw(const Player& player);
};

#endif