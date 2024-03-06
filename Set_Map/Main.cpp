#include<iostream>
#include<set>
#include<map>
#include<unordered_map> // неотсортированная версия (для типов данных, для которых неариализуемы стандартные методы сортировки, например, объекты класса животных)
#include<vector>
#include<string>
#include<random>

void DemoBase() {
	std::vector<int>initialData;
	initialData.reserve(10); // резервируем память под 1000 элементов, чтобы потом не тратить времня на перевыделение памяти
	// Подключаем генератор случайных чисел
	std::random_device rd; // Источник иистинно случайных чисел\
	Энтропия операционной системы (дынные вольтажа) - истинно случайная последовательность, которая не предугадываемая\
	Функция time масимально истащаемая по энтропии функция, когда случайные числа могут идти одинаковыми
	std::mt19937 provider(rd()); // provider - это генератор псевдослучайных чисел - аналог сишного rand(), только не нужно создавать формулу, как в rand()\
	rd() - зерно генерации числа
	std::uniform_int_distribution<int> distributor(10, 99); // Доставщик чисел (Случайные числа от 100 до 900), причёсывает числа до нужного диапазона\
	Из distributor будем забирать случайное число в заданном диапазоне. По сути distributor - это фукнтор
	for (int i = initialData.size(); i < initialData.capacity(); ++i) { // метод capacity() стандартной коллекции возвращает максимальную вместимость\
		метод .size() возвращает последний заполненный элемент коллекции
		initialData.push_back(distributor(provider)); // Заполняем массив
	}
	// Задача - Сколько уникальных элементов в коллекции???
	std::vector<int> uniqueData; // Создаём новую коллекцию для уникальных чисел
	for (auto& element : initialData) {
		bool flag{ true };
		for (auto& uElement : uniqueData) {
			if (element == uElement) {
				flag = false;
				break; // Прерываем вложенный цикл
			}			
		}	
		if (flag) {
			uniqueData.push_back(element);
		}
	}
	std::cout << "All elements: " << initialData.size() << '\n';
	for (auto& i : initialData)
		std::cout << i << ' ';
	std::cout << "\nUnique elements: " << uniqueData.size() << '\n';
	for (auto& i : uniqueData)
		std::cout << i << ' ';
}

class A {
public:
	// Можно перегружать оператор () не в пространстве имён std, а здесь
	/*bool operator<(const A& other)const {
		return bool();
	}*/
};

namespace std { 
	template<>
	struct less<A> {
		bool operator()(const A& a, const A& b)const {
			return bool();
		}
	}; 
	// перегрузка свойства типа по признаку сравниваемости, таким образо мы можем научить работать с нашим типом стандартную библиотеку языка не нагружать\
	функционал класса наследуемыми элементами
}

struct MyStruct { 
	std::string id; // Номер договора / паспорта
	std::string name;
	std::string patrinomyc;
	std::string surename;
};

int main() {
	//DemoBase();
	std::set<A> obj;
	obj.insert(A()); // Чтобы не было ошибки, в простр.имён перегружаем оператор ()
	A z, x;
	obj.contains(z); // Чтобы не было ошибки надо стандарт языка поставить не менее 20 (Правая кнопка мыши по наименованию проекта -> Свойства -> Стандарт языка С++)

	// Если мы создаём map, нам надо два параметра
	std::map<std::string, MyStruct> dictionary;
	std::vector<MyStruct> data{ // коллекция с разными данными
		{"q123r15","jack","vitalievich","London"},
		{"q123r11", "jack", "vitalievich", "Eddison"},
		{"q123r12", "Tom", "vitalievich", "frolov"},
		{"q123r13", "jack", "sergeevich", "Enstien"},
		{"q123r14", "jack", "vitalievich", "frolov"},
		{"q123r15","jack","vitalievich","Pitt"},
	};
	for (int i = 0; i < data.size(); ++i) {
		if (!dictionary.contains(data[i].id)) { // contains проверяет, есть ли совпадение ключа (необходимая проверка при использовании [])
			dictionary.insert({ data[i].id,data[i] }); // {} для того, чтобы показать компилятору, что данные являются парой (это требование метода insert)
			// Размер mapa будет не 6, а 5, т.к. у нас id = q123r15 одинаковый для 2-ух элементов
		}
		else {
			std::cout << "didn't insert data:\n" << data[i].id << '\n' << data[i].name << '\n' << data[i].patrinomyc << '\n' << data[i].surename \
				<< '\n' << "this data already has:\n" << dictionary[data[i].id].id << '\n' << dictionary[data[i].id].name << '\n' << \
				dictionary[data[i].id].patrinomyc << '\n' << dictionary[data[i].id].surename << '\n';
		}
	}
	dictionary.at("fhasjklhfdlj"); // Метод at() выдаст ошибку, если такого ключа не существует

	return 0;
}