#ifndef _CONSOLE_H
#define _CONSOLE_H

//////////////////////////////////////////////////////////////
///	Includes
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
///	Defines
//////////////////////////////////////////////////////////////
#define KEY_NONE 0x00
#define KEY_EXIT 0x01

//////////////////////////////////////////////////////////////
/// Enum key values
//////////////////////////////////////////////////////////////
enum VirtualKeys
{
	VK_KEY_0	= 0x30,
	VK_KEY_1	= 0x31,
	VK_KEY_2	= 0x32,
	VK_KEY_3	= 0x33,
	VK_KEY_4	= 0x34,
	VK_KEY_5	= 0x35,
	VK_KEY_6	= 0x36,
	VK_KEY_7	= 0x37,
	VK_KEY_8	= 0x38,
	VK_KEY_9	= 0x39,
	VK_KEY_A	= 0x41,
	VK_KEY_B	= 0x42,
	VK_KEY_C	= 0x43,
	VK_KEY_D	= 0x44,
	VK_KEY_E	= 0x45,
	VK_KEY_F	= 0x46,
	VK_KEY_G	= 0x47,
	VK_KEY_H	= 0x48,
	VK_KEY_I	= 0x49,
	VK_KEY_J	= 0x4A,
	VK_KEY_K	= 0x4B,
	VK_KEY_L	= 0x4C,
	VK_KEY_M	= 0x4D,
	VK_KEY_N	= 0x4E,
	VK_KEY_O	= 0x4F,
	VK_KEY_P	= 0x50,
	VK_KEY_Q	= 0x51,
	VK_KEY_R	= 0x52,
	VK_KEY_S	= 0x53,
	VK_KEY_T	= 0x54,
	VK_KEY_U	= 0x55,
	VK_KEY_V	= 0x56,
	VK_KEY_W	= 0x57,
	VK_KEY_X	= 0x58,
	VK_KEY_Y	= 0x59,
	VK_KEY_Z	= 0x5A,
	VK_ESCAPE	= 0x1B,
	VK_F1		= 0x70,	
	VK_F10		= 0x79,	
	VK_F11		= 0x7A,	
	VK_F12		= 0x7B,	
	VK_F13		= 0x7C,	
	VK_F14		= 0x7D,	
	VK_F15		= 0x7E,	
	VK_F16		= 0x7F,	
	VK_F17		= 0x80,	
	VK_F18		= 0x81,	
	VK_F19		= 0x82,	
	VK_F2		= 0x71,	
	VK_F20		= 0x83,	
	VK_F21		= 0x84,	
	VK_F22		= 0x85,	
	VK_F23		= 0x86,	
	VK_F24		= 0x87,	
	VK_F3		= 0x72,	
	VK_F4		= 0x73,	
	VK_F5		= 0x74,	
	VK_F6		= 0x75,	
	VK_F7		= 0x76,	
	VK_F8		= 0x77,	
	VK_F9		= 0x78,
	VK_RETURN	= 0x0D,
	VK_SPACE	= 0x20,
	VK_ERROR   = 0xFF
};

////////////////////////////////////////////////////////////
/// Convert a key value to key code
////////////////////////////////////////////////////////////
enum VirtualKeys VirtualKeyCode(int VirtualKey);

//////////////////////////////////////////////////////////////
/// Process key value
//////////////////////////////////////////////////////////////
int ProcessKey(int keyValue);

#endif