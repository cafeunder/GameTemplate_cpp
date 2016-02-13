#include <DxLib.h>
#include "Keyboard.h"

void Keyboard::Update(){
	char temp[256];
	GetHitKeyStateAll(temp);

	for(int i = 0; i < 256; i++){ 
		if( temp[i] != 0 ){
			Key[i]++;
		} else {
			Key[i] = 0;
		}
	}
}

int Keyboard::GetKeyInput(int KeyCode){
	return Key[KeyCode];
}