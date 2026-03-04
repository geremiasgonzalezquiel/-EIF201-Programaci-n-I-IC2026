
#include <iostream>
void showTemp(int* temp) {
	std::cout << "Temp desde funcion" << *temp << std::endl;
	*temp = 24;
}
int main()
{
	int temp = 35;
	int* pTemp = &temp;
	*pTemp = 36;
	temp = 40;

	std::cout << temp << std::endl;
	std::cout << *pTemp << std::endl;
	showTemp(&temp);
	std::cout << "desde el main" << temp << std::endl;
	std::cout << +pTemp << std::endl;
}