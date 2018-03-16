//////////////////////////////////////////////////////////////
/// Header
//////////////////////////////////////////////////////////////
#include "Console.h"

////////////////////////////////////////////////////////////
/// Convert a key value to key code
////////////////////////////////////////////////////////////
enum VirtualKeys VirtualKeyCode(int VirtualKey)
{
    switch (VirtualKey)
    {
        case 0x30 :         return VK_KEY_0;
        case 0x31 :         return VK_KEY_1;
        case 0x32 :         return VK_KEY_2;
        case 0x33 :         return VK_KEY_3;
        case 0x34 :         return VK_KEY_4;
        case 0x35 :         return VK_KEY_5;
        case 0x36 :         return VK_KEY_6;
        case 0x37 :         return VK_KEY_7;
        case 0x38 :         return VK_KEY_8;
        case 0x39 :         return VK_KEY_9;
		case 0x41 :       	return VK_KEY_A;
        case 0x42 :      	return VK_KEY_B;
        case 0x43 :         return VK_KEY_C;
        case 0x44 :       	return VK_KEY_D;
        case 0x45 :    		return VK_KEY_E;
        case 0x46 :    		return VK_KEY_F;
        case 0x47 :    		return VK_KEY_G;
        case 0x48 :    		return VK_KEY_H;
        case 0x49 :    		return VK_KEY_I;
        case 0x4A :         return VK_KEY_J;
        case 0x4B :         return VK_KEY_K;
        case 0x4C :         return VK_KEY_L;
        case 0x4D :         return VK_KEY_M;
        case 0x4E :         return VK_KEY_N;
        case 0x4F :         return VK_KEY_O;
        case 0x50 :         return VK_KEY_P;
        case 0x51 :         return VK_KEY_Q;
        case 0x52 :         return VK_KEY_R;
        case 0x53 :         return VK_KEY_S;
        case 0x54 :         return VK_KEY_T;
        case 0x55 :         return VK_KEY_U;
        case 0x56 :         return VK_KEY_V;
        case 0x57 :         return VK_KEY_W;
        case 0x58 :         return VK_KEY_X;
        case 0x59 :         return VK_KEY_Y;
		case 0x5A :         return VK_KEY_Z;
		case 0x1B :         return VK_ESCAPE;
		case 0x70 :         return VK_F1;
		case 0x79 :         return VK_F10;
		case 0x7A :         return VK_F11;
		case 0x7B :         return VK_F12;
		case 0x7C :         return VK_F13;
		case 0x7D :         return VK_F14;
		case 0x7E :         return VK_F15;	
		case 0x7F :         return VK_F16;
		case 0x80 :         return VK_F17;
		case 0x81 :         return VK_F18;
		case 0x82 :         return VK_F19;	
		case 0x71 :         return VK_F2;	
		case 0x83 :         return VK_F20;	
		case 0x84 :         return VK_F21;	
		case 0x85 :         return VK_F22;	
		case 0x86 :         return VK_F23;
		case 0x87 :         return VK_F24;	
		case 0x72 :         return VK_F3;	
		case 0x73 :         return VK_F4;	
		case 0x74 :         return VK_F5;	
		case 0x75 :         return VK_F6;	
		case 0x76 :         return VK_F7;	
		case 0x77 :         return VK_F8;	
		case 0x78 :         return VK_F9;
		case 0x0D :         return VK_RETURN;
		case 0x20 :         return VK_SPACE;
		case 0xFF :         return VK_ERROR;
    }
    
    return VK_ERROR;
}

//////////////////////////////////////////////////////////////
/// Process key value
//////////////////////////////////////////////////////////////
int ProcessKey(int keyValue)
{
	//	Convert key
    enum VirtualKeys keyPressed = VirtualKeyCode(keyValue);

    //	Actions
    switch (keyPressed)
    {
    	//	Exit key
    	case VK_ESCAPE:
    		return KEY_EXIT;

        //  Other key
    	default:
            break;
    }
    
    return KEY_NONE;
}