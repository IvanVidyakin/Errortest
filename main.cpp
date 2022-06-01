// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <iostream>
#include <fstream>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAX = 0;
int main(int argc, char** argv) {
	std::string name;
	std::cout << "Vvedite svoye imya" << std::endl;
	std::cin >> name;
	std::ofstream fin("service.txt");
	fin << name;
	fin.close();
	srand(time(NULL));
	int N, M, flagstandart;
	std::cin >> N;
	std::cin >> M;
	int **a = new int*[N];
	for(int i=0;i<N;i++)
	{
		a[i] = new int[M];
	}
	if(flagstandart==0)
	{
		std::cout << "Standartny rezhim programmy (from 0 to 1):" << std::endl;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				a[i][j]=(rand()%2);
			}
		}
	}
	else
	{
		std::cout << "Experimentalny rezhim programmy (from 0 to MAX):" << std::endl;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				a[i][j]=(rand()%MAX);
			}
		}	
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "------------" << std::endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			std::cout << *(*(a+i)+j) << " ";	
		}
		std::cout << std::endl;
	}
	std::cout << "-------------------" << std::endl;
	int flag=1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if((*(*(a+i)+j))==(*(*(a+i)+j+1)))
			{
				flag=0;
				break;
			}
		}
	}
	for(int i=1;i<N;i++)
	{
		delete []a[i];
	}
	if(flag==0)
	{
		std::cout << "Cheredovaniya net" << std::endl;
	}
	else
	{
		std::cout << "Cheredovaniye est" << std::endl;
	}
	std::ifstream bye("service.txt");
	name="";
	while(!bye.eof())
	{
		name+=bye.get();
	}
	std::cout << "Do svidaniya, " << name << "!";
	for(int i=1;i<N;i++)
	{
		delete []a[i];
	}
	return 0;
}