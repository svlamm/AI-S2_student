#include <iostream>
#include <vector>

struct Dog {
	int leeftijd = 1;
	int aantal_poten = 4;
};


// fusion is een functie die een const vector<T>& ontvangt en een T teruggeeft. Bedenk zelf wat je een leuke vorm van fusion vindt



template<typename T>
bool all_equal(const std::vector<T>& group_a, const std::vector<T>& group_b){
	if (group_a.size() != group_b.size()) {
		return false;
	}

	// Gebruik klassieke for loop voor het vergelijken van objecten op index

	return true;
}


int main() {
	Dog d1 = Dog(100, 4);
	Dog d2 = Dog(200, 1);
	Dog d3 = Dog(300, 16);
	std::vector<Dog> dogs = std::vector<Dog>{d1,d2,d3};
	std::vector<Dog> dogs2 = std::vector<Dog>{d1,d2,d3 };
	std::vector<Dog> dogs3 = std::vector<Dog>{d2,d2,d3 };

	Dog snoop_dog = fusion(dogs);
	std::cout << snoop_dog;

	std::cout << "dogs equal to dogs2: " << (all_equal(dogs, dogs2)) << std::endl;
	std::cout << "dogs equal to dogs3: " << (all_equal(dogs, dogs3)) << std::endl;

	Student s1 = Student(20, 180.5);
	Student s2 = Student(10, 280.5);
	Student s3 = Student(30, 100.5);

	std::vector<Student> students = std::vector<Student>{s1,s2,s3};
	std::vector<Student> students2 = std::vector<Student>{s1,s2,s3};
	std::vector<Student> students3 = std::vector<Student>{s2,s2,s3};

	Student mega_nerd = fusion(students);
	std::cout << mega_nerd;

	std::cout << "student equal to student2: " << (all_equal(students, students2)) << std::endl;
	std::cout << "student equal to student3: " << (all_equal(students, students3)) << std::endl;

	return 0;
}
