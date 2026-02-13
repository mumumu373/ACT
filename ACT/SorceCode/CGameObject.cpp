#include "CGameObject.h"

//ゲームオブジェで実体を作っておく
CGameObject::CGameObject()
	: m_pImg(nullptr)
	, m_Position(0.0,0.0)
	, m_Framesplit(0,0,0,0)
{
}
