#ifndef ___Stage
#define ___Stage

#include "Define.h"

//ステージのmap情報
const int map_stage[STAGE_NUM][50][50] =
{
	{	//Menu画面のステージ
		{ 1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, A,  C, T, I, O, N,  2, G, A, M, E,  0, 0, 0, 0, 1 },

		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, S, T, A,  R, T, 0, 0, 0,  G, 2, B, U, T,  T, O, N, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },

		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, M, A, N,  U, A, L, 0, 0,  M, 2, B, U, T,  T, O, N, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 0,  0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1,  1, 1, 1, 1, 1 },
	},
	{	//Game画面のステージ
		{ 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 ,1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },

		{ 1,0,0,0,0, 0,0,0,0,0, 2,2,2,2,2, 2,2,2,0,0 ,0,0,0,2,2, 2,2,2,2,2, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,1,1,1,1, 1,1,1,1,1, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 1,1,1,1,1, 1,1,1,1,1 },

		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 2,2,2,2,2, 2,2,2,2,2 ,2,2,2,2,2, 2,2,2,2,2, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },

		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 2,2,2,2,2, 2,2,2,2,2, 0,0,0,0,0 ,0,0,0,0,0, 2,2,2,2,2, 2,2,2,2,2, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1 },
		{ 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 ,1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 },
	},
	{	//ボスのステージ
		{ 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 ,1,1,1,1,1, 1,1,1,1,1, 1,1,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,2,2,2,2, 2,2,2,2,2 ,2,2,2,0,0, 0,0,0,0,0, 0,0,1 },

		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,2, 2,2,2,2,2, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,2,2, 2,2,2,2,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },

		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,1,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },

		{ 1,1,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 1,1,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 ,0,0,0,0,0, 0,0,0,0,0, 0,0,1 },
		{ 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1 ,1,1,1,1,1, 1,1,1,1,1, 1,1,1 },
	},
};

#endif