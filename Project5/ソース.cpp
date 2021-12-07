#include <iostream>
#include <string> //������
#include <vector> //���I�z��
#include <fstream> // �O���t�@�C���̏�������
#include <istream> // �ǂݍ��ݗp
#include <sstream> // ������̑���


struct student {
	int id; 
	std::string name; 
	int age;
	int gender;
};

std::vector<student> member{
	{1,"�c��",19,0},
	{2,"���",18,1},
	{3,"����",20,0}
};

//���ʗp�z��
std::string gender[3] = { "�j��","����","���̑�" };

//�ꗗ�\��
void listView() {

	for (int i = 0; i < member.size(); i++) {
		std::cout
			<< member[i].id << ":"
			<< member[i].name << "\t"
			<< member[i].age << "��\t"
			<< gender[member[i].gender] << "\n";
	}
}
//�ǉ�
void listAdd() {
	int id; 
	std::string name;
	int age; 
	int gender;

	std::cout << "�w�Дԍ��F";
	std::cin >> id;

	std::cout << "�����F";
	std::cin >> name;

	std::cout << "�N��F";
	std::cin >> age;

	std::cout << "����(0:�j�� 1:���� 2:���̑�)�F";
	std::cin >> gender;

	member.push_back({ id , name , age , gender });

	std::cout << "�o�^����\n";

}

//�폜
void listDel() {}
//�ҏW
void listChange() {}


std::vector<std::string> split(std::string input, char delimiter)
{
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}

//�Ǎ� load
void load() {
	std::string fileName = "data.txt";
	std::ifstream ifs(fileName);

	if (!ifs) {
		std::cout << "�t�@�C�����J���܂���";
	}
	else {
		member.clear();
		std::string line;
		while (getline(ifs, line)) {
			std::cout << "---------------\n\n" << line << "\n";

			std::vector<std::string> strvec = split(line, ',');

			member.push_back({
					std::atoi(strvec[0].c_str()),// id
					strvec[1], //���O
					std::atoi(strvec[2].c_str()),// age
					std::atoi(strvec[3].c_str()),// gender
				});
		}
	}
}

//�ۑ� save
void save() {
	std::string fileName = "data.txt"; //�ۑ��t�@�C����
	std::ofstream ofs(fileName);

	if (!ofs) {
		std::cout << "�t�@�C�����J���܂���ł����B";
	}
	else {
		
		for (int i = 0; i < member.size(); i++) {
			ofs
				<< member[i].id << ","
				<< member[i].name << ","
				<< member[i].age << ","
				<< member[i].gender << "\n";
		}
		std::cout << "�ۑ�����";
	}
}

int main() {
	std::cout << "����V�X�e��\n";
	int selector = 0;

	while (selector != 9) {
		std::cout << "0:�ꗗ�\��  1:�ǉ��@2:�폜�@3:�ҏW�@4:�Ǎ��@5:�ۑ��@9:�I���F";
		std::cin >> selector;
		system("cls");
		switch (selector)
		{
		case 0: listView(); break;
		case 1: listAdd(); break;
		case 2: listDel(); break;
		case 3: listChange(); break;
		case 4: load(); break;
		case 5: save(); break;
		case 9:  break;
		default: std::cout << "���ڂ��L��܂���\n";  break;
		}
	}


	system("pause");
	return 0;
}