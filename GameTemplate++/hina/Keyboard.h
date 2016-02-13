#ifndef KEYBOARD_DEF
#define KEYBOARD_DEF

#define KEYINPUT(input) (Keyboard::GetInstance()->GetKeyInput(input))

class Keyboard{
private:
	int Key[256];
	Keyboard(){}; //シングルトン記述

public :
	void Update();
	int GetKeyInput(int KeyCode);

	static Keyboard* GetInstance(){
		static Keyboard instance;
		return &instance;
	}
};

#endif