#include <DxLib.h>
#include "BaseScene.h"
#include "Keyboard.h"

bool BaseScene::running;

BaseScene* BaseScene::main(){
	if(running) return nullptr;	//1�x�Ɏ��s�ł���V�[����1��
	running = true;
	next_scene = nullptr;

	//���[�v�O����
	initialize();
	looping = true;
	
	//���C�����[�v
	while(looping){
		if(processLoop()){
			running = false;
			return nullptr;
		}
		update();
		draw();
		ScreenFlip();	//����ʂ�\��ʂɔ��f
	}

	//���[�v�㏈��
	finalize();
	running = false;

	return next_scene;
}

void BaseScene::changeScene(BaseScene* next_scene){
	this->next_scene = next_scene;
	looping = false;
}

int BaseScene::processLoop(){
	if(ProcessMessage() != 0)  return -1;	//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen() != 0) return -1;	//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	if(Keyboard::update() != 0) return -1;	//�L�[�̃A�b�v�f�[�g�������G���[�Ȃ�-1��Ԃ�
	return 0;
}


bool SceneManager::running = false;
BaseScene* SceneManager::current_scene;

void SceneManager::run(BaseScene* starter){
	if(running || !starter) return;
	running = true;

	current_scene = starter;
	BaseScene* next_scene = nullptr;
	//���C�����[�v�J�n
	do{
		next_scene = current_scene->main();
	}while(next_scene = current_scene);

	delete current_scene;
	running = false;
}