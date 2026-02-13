#include "CImageManager.h"

CImageManager::CImageManager()
{
}

CImageManager::~CImageManager()
{
}

bool CImageManager::Load(HWND hWnd, HDC hScreenDC, HDC hMemDC, HDC hWorkDC, HDC hWorkDC2)
{
	struct ImgList
	{
		int listNo;		//enList列挙型を設定
		char path[256];	//ファイルの名前(パス付)
		char alias[32];	//エイリアス名
	};
	ImgList Img_List[]
	{ 
		{enImgList::Img_StageMain,"Data\\MapImage\\StageMain.bmp","MainStage"} ,
		{enImgList::Img_BuckGround1,"Data\\MapImage\\BackGround_1.bmp","BackGround_1"} ,
		{enImgList::Img_BuckGround2,"Data\\MapImage\\BackGround_1.bmp","BackGround_2"} ,
	};
	int Img_List_max = sizeof(Img_List) / sizeof(Img_List[0]);
	

	for (int i = 0;i < Img_List_max;++i) {
		m_upImg.push_back(std::make_unique<CImage>(hScreenDC, hMemDC, hWorkDC, hWorkDC2));
	}

	for (int i = 0;i <m_upImg.size();++i) {
		m_upImg[i].get()->LoadBmp(Img_List[i].path);
	}

	return true;
}

void CImageManager::Release()
{
}
