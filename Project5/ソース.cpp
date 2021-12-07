#include <iostream>
#include <string> //文字列
#include <vector> //動的配列
#include <fstream> // 外部ファイルの書き込み
#include <istream> // 読み込み用
#include <sstream> // 文字列の操作


struct student {
	int id; 
	std::string name; 
	int age;
	int gender;
};

std::vector<student> member{
	{1,"田中",19,0},
	{2,"鈴木",18,1},
	{3,"佐藤",20,0}
};

//性別用配列
std::string gender[3] = { "男性","女性","その他" };

//一覧表示
void listView() {

	for (int i = 0; i < member.size(); i++) {
		std::cout
			<< member[i].id << ":"
			<< member[i].name << "\t"
			<< member[i].age << "才\t"
			<< gender[member[i].gender] << "\n";
	}
}
//追加
void listAdd() {
	int id; 
	std::string name;
	int age; 
	int gender;

	std::cout << "学籍番号：";
	std::cin >> id;

	std::cout << "氏名：";
	std::cin >> name;

	std::cout << "年齢：";
	std::cin >> age;

	std::cout << "性別(0:男性 1:女性 2:その他)：";
	std::cin >> gender;

	member.push_back({ id , name , age , gender });

	std::cout << "登録完了\n";

}

//削除
void listDel() {}
//編集
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

//読込 load
void load() {
	std::string fileName = "data.txt";
	std::ifstream ifs(fileName);

	if (!ifs) {
		std::cout << "ファイルが開けません";
	}
	else {
		member.clear();
		std::string line;
		while (getline(ifs, line)) {
			std::cout << "---------------\n\n" << line << "\n";

			std::vector<std::string> strvec = split(line, ',');

			member.push_back({
					std::atoi(strvec[0].c_str()),// id
					strvec[1], //名前
					std::atoi(strvec[2].c_str()),// age
					std::atoi(strvec[3].c_str()),// gender
				});
		}
	}
}

//保存 save
void save() {
	std::string fileName = "data.txt"; //保存ファイル名
	std::ofstream ofs(fileName);

	if (!ofs) {
		std::cout << "ファイルが開けませんでした。";
	}
	else {
		
		for (int i = 0; i < member.size(); i++) {
			ofs
				<< member[i].id << ","
				<< member[i].name << ","
				<< member[i].age << ","
				<< member[i].gender << "\n";
		}
		std::cout << "保存完了";
	}
}

int main() {
	std::cout << "名簿システム\n";
	int selector = 0;

	while (selector != 9) {
		std::cout << "0:一覧表示  1:追加　2:削除　3:編集　4:読込　5:保存　9:終了：";
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
		default: std::cout << "項目が有りません\n";  break;
		}
	}


	system("pause");
	return 0;
}