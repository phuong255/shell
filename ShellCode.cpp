#include<windows.h>

int main(int argc, char **argv) {
	char shellcode[] = {
	  0x31, 0xf6, 0x56, 0x64, 0x8b, 0x76, 0x30, 0x8b, 0x76, 0x0c, 0x8b, 0x76, 0x1c, 0x8b, 0x6e, 0x08, 0x8b, 0x36, 0x8b, 0x5d, 0x3c, 0x8b, 0x5c, 0x1d, 0x78, 0x01, 0xeb, 0x8b, 0x4b, 0x18, 0x67, 0xe3, 0xec, 0x8b, 0x7b, 0x20, 0x01, 0xef, 0x8b, 0x7c, 0x8f, 0xfc, 0x01, 0xef, 0x31, 0xc0, 0x99, 0x32, 0x17, 0x66, 0xc1, 0xca, 0x01, 0xae, 0x75, 0xf7, 0x66, 0x81, 0xfa, 0x2a, 0xb6, 0x74, 0x09, 0x66, 0x81, 0xfa, 0xaa, 0x1a, 0xe0, 0xdb, 0x75, 0xc5, 0x8b, 0x53, 0x24, 0x01, 0xea, 0x0f, 0xb7, 0x14, 0x4a, 0x8b, 0x7b, 0x1c, 0x01, 0xef, 0x03, 0x2c, 0x97, 0x85, 0xf6, 0x74, 0x12, 0x68, 0x33, 0x32, 0x20, 0x20, 0x68, 0x75, 0x73, 0x65, 0x72, 0x54, 0xff, 0xd5, 0x95, 0x31, 0xf6, 0xeb, 0xa3, 0x56, 0x68, 0x20, 0x21, 0x20, 0x20, 0x68, 0x43, 0x68, 0x61, 0x6f, 0x68, 0x58, 0x69, 0x6e, 0x20, 0x54, 0x87, 0x04, 0x24, 0x50, 0x50, 0x56, 0xff, 0xd5, 0xcc
	};

	void *exec = VirtualAlloc(0, sizeof shellcode, MEM_COMMIT, PAGE_READWRITE);
	memcpy(exec, shellcode, sizeof shellcode);
	((void(*)())exec)();
}

