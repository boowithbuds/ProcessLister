#include <windows.h>//contains prototypes for Windows API
#include <tlhelp32.h>//includes ToolHelp32 which contains functions for working with processes, modules and heaps
#include <tchar.h>//TCHAR provides support for Unicode and ANSI character strings
#include <iostream>//standard lib for input && output
//+++++scritp by boowithbuds+++++++

int main() {//original 'allProcessSnapVariable' named as 'hProcessSnap'(IN) returned by CreateToolhelp32Snapshot && 'pe32' original named 'pe32', is the second variable needed by 'CreateToolhelp32Snapshot' FUNCT
  HANDLE allProcessSnapVariable;//Declares a handle variable named 'allProcessSnapVariable' to hold the process snapshot
  PROCESSENTRY32 pe32;//declares a 'PROCESSENTRY' structure(defined) variable(inout) named 'pe32' and original named 'pe32' to hold the process entry. This (inout)variable will get data from 'CreateToolHelp32Snapshot'

  allProcessSnapVariable = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);//This line creates a process snapshot using 'CreateToolHelp32Snapshot' functiong with the 'TH32CS_SNAPPROCESS' flag to specify that the snapshot should include all processes.
  
  if (allProcessSnapVariable == INVALID_HANDLE_VALUE) {
    std::cout << "Error obtaining process snapshot" << std::endl;
    return 1;
  }

  pe32.dwSize = sizeof(PROCESSENTRY32);//This line sets the size of the 'PROOCESSENTRY32' structure variable 'pe32'

  //Get the first entry
  if (!Process32First(allProcessSnapVariable, &pe32)) {//This block checks if the first process entry could be obtained using the 'Process32First' function and prints an error message if it could not.
    std::cout << "Error obtaining the first entry of the process" << std::endl;
    CloseHandle(allProcessSnapVariable);//This line closes the process snapshot handle.
    return 1;
  }

  do {
    std::wcout << "Process Name: " << pe32.szExeFile << std::endl;
  } while (Process32Next(allProcessSnapVariable, &pe32));

  CloseHandle(allProcessSnapVariable);//This line closes the process snapshot handle.
  
  system("pause");
  return 0;
}
