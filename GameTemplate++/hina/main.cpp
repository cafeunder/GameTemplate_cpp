#include <DxLib.h>
#include "main.h"
#include "Keyboard.h"

//================================
//|                              |
//| ���H����v���O���~���O���D�� |
//|                              |
//================================

//********************************************************
//* �g�p : DX���C�u����.net                              *
//* http://homepage2.nifty.com/natupaji/DxLib/index.html *
//* DX Library Copyright (C) 2001-2015 Takumi Yamada.    *
//********************************************************


//�t���X�N���[�����[�h����߂�ꍇ�͈ȉ����R�����g�A�E�g����
//#define FULL_SCREEN
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//���C���֐�
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
#ifdef FULL_SCREEN
	ChangeWindowMode(FALSE);	//�t���X�N���[�����[�h��
#else
	ChangeWindowMode(TRUE);
#endif
	
	if(DxLib_Init() == -1){		//DX���C�u�����̏�����
		ErrorExit("DX���C�u�����̏������Ɏ��s���܂����B");
	}
	SetDrawScreen(DX_SCREEN_BACK);	//�_�u���o�b�t�@�̂��߂̃Z�b�^

	while(true){
		if(!LoopStart()) break;	//����������
		Keyboard::GetInstance()->Update();
		if(KEYINPUT(KEY_INPUT_ESCAPE) == 1) break;

		//�����ɏ���������
	}

	DxLib_End();
	return 0;
}



//���[�v����������
bool LoopStart(){
	if(ScreenFlip() == -1) return false;			//����ʏ���
	if(ProcessMessage() == -1) return false;		//Windows�ւ̃V�X�e������
	if(ClearDrawScreen() == -1) return false;	//��ʂ̏�����

	return true;
}

//�G���[�I��
void ErrorExit(const char* message){
	MessageBox(NULL, message, "�G���[", MB_OK);

	DxLib_End();
	exit(1);
}