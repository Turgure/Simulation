#include <DxLib.h>
#include "Keyboard.h"
#include "GameManager.h"

//----------------------------------------
//���[�v�ŕK���s������
//----------------------------------------
int ProcessLoop(){
	if(ProcessMessage() != 0)  return -1;	//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen() != 0) return -1;	//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	if(Keyboard::update() != 0) return -1;	//�L�[�̃A�b�v�f�[�g�������G���[�Ȃ�-1��Ԃ�
	return 0;
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	// �E�C���h�E���[�h�ɕύX
	ChangeWindowMode(true);
	if(DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;	//�������Ɨ���ʏ���


	Keyboard::initialize();
	GameManager manager;
	manager.create();
	
	while(!ProcessLoop() && !Keyboard::get(KEY_INPUT_ESCAPE)){
		manager.update();
		manager.draw();
		
		ScreenFlip();	//����ʂ�\��ʂɔ��f
	}

	WaitKey();
	DxLib_End();
	return 0;
}