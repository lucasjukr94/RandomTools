#include <dirent.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    DIR *d;
    struct dirent *dir;
    string s = "";
	char dirpath[1000];
    
    std::cout << "Dir path:";
    std::cin >> dirpath;
    std::cout << dirpath;
    d = opendir(dirpath);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
        	string strdir(dir->d_name),strbrk(";\n");
        	s += strdir + strbrk;
            printf("%s;\n", dir->d_name);
        }
        closedir(d);
    }
    ofstream file;
	file.open ("arq.txt");
	file << s;
	file.close();
    return(0);
}
