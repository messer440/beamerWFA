#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>

bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
   if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!

  return false;    // this is not a directory!
}

int main()
{
    std::string home = "C:\\Users\\";
	std::string programFiles64 = "C:\\Program Files (x86)\\";
	std::string programFiles = "C:\\Program Files\\";
	std::string miktex9="Miktex 2.9";
    std::string miktex8="Miktex 2.8";
    std::string username;

    int numbOfEnv = 4;
    int env[numbOfEnv];
	env[0] = putenv("programFiles64=C:\\Program Files (x86)");
	env[1] = putenv("programFiles=C:\\Program Files");
	env[2]= putenv("miktex9=Miktex 2.9");
	env[3] = putenv("miktex8=Miktex 2.8");

    std::string inst_path = std::string(home + getenv("username"));
	if (!dirExists(inst_path))
    {
        std::cout << "Nie poprawna sciezka do katalogu domowego.\n";
        std::cout << "Podaj nazwe swojego profilu na sciezce:\n";
        std::cout << "C:\\Users\\NAZWA\\" << std::endl;
        std::cin >>  username;
        std::string homeDir = std::string("username=") + username;
        int succ = putenv((char *)homeDir.c_str());
        if (succ != 0){
            std::cout << "Nie udalo sie podac sciezki instlacji. Przerywam!\n";
            std::cout << "Prosze zglosic blad pod adres: krzysztof.cach@ift.uni.wroc.pl";
        }
    }

	for (int i=0; i<numbOfEnv; i++)
    {
        if (env[i]!=0)
        {
            std::cout << "Nie mozna zainicjalizowac zmiennej srodowiskowej env" + i << std::endl;
            std::cout << "Prosze zglosic problem pod adres:" << std::endl;
            std::cout << "krzysztof.cach@ift.uni.wroc.pl\n\n" << std::endl;
            system("pause");
            return -1;
        }
    }

	if (dirExists(programFiles64)) {
		if (dirExists(programFiles64 + miktex9)) {
            std::cout << "Rozpoznanow wersje 64 bit Windowsa oraz Miktexa 2.9\n";
            system("pause");
			system("xcopy /Y /f /i /e \"%cd%\\texmf\\*\" \"C:\\Users\\%username%\\AppData\\Roaming\\Miktex\\2.9\\\"");
			system("cd %programFiles64%\\%miktex9%\\miktex\\bin\\");
			system("texhash.exe");
		}
		if (dirExists(programFiles64 + miktex8)) {
		    std::cout << "Rozpoznanow wersje 64 bit Windowsa oraz Miktexa 2.8\n";
		    system("pause");
		     system("xcopy /Y /f /i /e \"%cd%\\texmf\\*\" \"C:\\Users\\%username%\\AppData\\Roaming\\Miktex\\2.8\\\"");
			//system("xcopy /Y /f /i /e \"%cd%\\texmf\\*\" \"%programFiles64%\\%miktex8%\\\"");
			system("cd %programFiles64%\\%miktex8%\\miktex\\bin\\");
			//system("texhash.exe");
			system("initexmf.exe --verbose --update-fndb");
		}
	}

	else {
		if (dirExists(programFiles + miktex9)) {
            std::cout << "Rozpoznanow wersje 32 bit Windowsa oraz Miktexa 2.9\n";
            system("pause");
			system("xcopy /Y /f /i /e \"%cd%\\texmf\\*\" \"C:\\Users\\%username%\\AppData\\Roaming\\Miktex\\2.9\\\"");
			system("cd %programFiles%\\%miktex9%\\miktex\\bin\\");
			system("texhash.exe");
		}
		if (dirExists(programFiles + miktex8)) {
		    std::cout << "Rozpoznanow wersje 32 bit Windowsa oraz Miktexa 2.8\n";
		    system("pause");
		    system("xcopy /Y /f /i /e \"%cd%\\texmf\\*\" \"C:\\Users\\%username%\\AppData\\Roaming\\Miktex\\2.8\\\"");
			//system("xcopy /Y /f /i /e \"%cd%\\texmf\\*\" \"%programFiles%\\%miktex8%\\\"");
			system("cd %programFiles%\\%miktex8%\\miktex\\bin\\");
			system("initexmf.exe --verbose --update-fndb");
		}
	}

    std::cout << "\n\nZainstalowano tematy uniwersyteckie" << std::endl;
    std::cout << "Nazwy tematow: UWr_blue oraz UWr_white" << std::endl;
    std::cout << "Wszelkie uwagi prosze kierowac pod adres" << std::endl;
    std::cout << "krzysztof.cach@ift.uni.wroc.pl\n\n" << std::endl;
	system("pause");
	return 0;
}
