#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <iostream>
//+++++scritp by boowithbuds+++++++

int main() {
  HANDLE allProcessSnapVariable;
  PROCESSENTRY32 pe32;

  allProcessSnapVariable = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  
  if (allProcessSnapVariable == INVALID_HANDLE_VALUE) {
    std::cout << "Error obtaining process snapshot" << std::endl;
    return 1;
  }

  pe32.dwSize = sizeof(PROCESSENTRY32);
 
  if (!Process32First(allProcessSnapVariable, &pe32)) {
    std::cout << "Error obtaining the first entry of the process" << std::endl;
    CloseHandle(allProcessSnapVariable);
    return 1;
  }

  do {
    std::wcout << "Process Name: " << pe32.szExeFile << std::endl;
  } while (Process32Next(allProcessSnapVariable, &pe32));

  CloseHandle(allProcessSnapVariable);
  
  system("pause");
  return 0;
}