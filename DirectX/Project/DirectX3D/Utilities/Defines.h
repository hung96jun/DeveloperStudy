#pragma once

//#define WIN_WIDTH 1920
//#define WIN_HEIGHT 1080
#define WIN_WIDTH 1700
#define WIN_HEIGHT 1000
//#define WIN_WIDTH 1280
//#define WIN_HEIGHT 720

#define MAX_LIGHT 10
#define MAX_BONE 1024
#define MAX_FRAME 1024
#define MAX_INSTANCE 128

#define CENTER_X (WIN_WIDTH * 0.5f)
#define CENTER_Y (WIN_HEIGHT * 0.5f)

#define DEVICE GameInstance::GetDevice()->GetDevice()
#define DC GameInstance::GetDevice()->GetDeviceContext()

#define KEY_DOWN(k) GameInstance::GetKeyboard()->Down(k)
#define KEY_UP(k) GameInstance::GetKeyboard()->Up(k)
#define KEY_PRESS(k) GameInstance::GetKeyboard()->Press(k)


#define GMAE_MODE 0
#define	ANIM_MODE 0

#define DEBUG 0