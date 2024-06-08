#include <stdio.h>
#include <stdlib.h>
#include <winuser.h>
#include <windows.h>

#define true 1

int currentAmmo = 30, maxAmmo = 90;

void main() {
    while (true) {
        printf ("%d / %d", currentAmmo, maxAmmo);

        // shooting
        if (currentAmmo > 0 && currentAmmo <= 30) {
            if (GetKeyState(VK_LBUTTON) & 0x8000) {
                currentAmmo -= 1;
                PlaySound("C:\\xx", NULL, SND_ASYNC); // replace xx with your weapon firing sound
                Sleep(50); // this is your "rpm". set it to what you like
                if (currentAmmo <= 0) 
                    currentAmmo = 0;
            }
        } 
        // reload
        if (currentAmmo >= 0 && currentAmmo < 30) {
            if (maxAmmo > 0 && maxAmmo <= 90) {
                if (GetKeyState(0x52) & 0x8000) {
                    PlaySound("C:\\xx", NULL, SND_ASYNC); // replace xx with your weapon reload sound
                    Sleep (2000);
                    while (currentAmmo < 30 && maxAmmo > 0) {
                        currentAmmo += 1;
                        maxAmmo -= 1;
                        if (maxAmmo == 0) 
                            continue;
                    }
                    if (maxAmmo <=0 || maxAmmo >= 90) 
                        maxAmmo = 0;
                }
            }
        }

        // dry fire sound
        if (currentAmmo == 0 || maxAmmo == 0) {
            if (GetKeyState(VK_LBUTTON) & 0x8000) {
                PlaySound("c:\\xx", NULL, SND_ASYNC); // replace xx with your weapon dry fire sound
            }
        }

        system("cls");
    }
}
