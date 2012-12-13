#pragma once

//�V�[�����N���X
//�S�V�[���N���X�̊��N���X�B���̃N���X��main()���N�����邱�Ƃŏ�ʂ��؂�ւ��B
class BaseScene{
public:
	BaseScene(){};
	virtual ~BaseScene(){};
	BaseScene* main();

protected:
	virtual void initialize(){};
	virtual void finalize(){};
	virtual void update(){};
	virtual void draw(){};
	void changeScene(BaseScene* next_scene);

private:
	int processLoop();
	BaseScene* next_scene;
	bool looping;	//���[�v���t���O
	static bool running;
};

//�V�[���Ǘ��N���X
//�V�[���̑J�ڂƎ��s���Ǘ�����N���X
class SceneManager{
	static bool running;
	static BaseScene* current_scene;

public:
	static void run(BaseScene* starter);
};