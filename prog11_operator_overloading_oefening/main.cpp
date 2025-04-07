
#include <iostream>
#include <vector>


struct Dog {
	int leeftijd = 1;
	int aantal_poten = 4;
};

bool operator==(const Dog& lhs, const Dog &rhs)  {
	return (lhs.leeftijd == rhs.leeftijd && lhs.aantal_poten == rhs.aantal_poten);
}

Dog operator*(const Dog& lhs, const Dog& rhs)  {
}

std::ostream& operator<<(std::ostream& os, const Dog& rhs) {
	os << "This dog is " << rhs.leeftijd << " years old, and has " << rhs.aantal_poten << " legs." << std::endl;
	return os;
}



template<typename T>
bool all_equal(const std::vector<T>& group_a, const std::vector<T>& group_b){
	//kijk of de twee klassen dezelfde studenten hebben
	if (group_a.size() != group_b.size()) {
		return false;
	}

	// Compare corresponding elements in the two vectors
	return true;
}

// Schrijf een template functie die een lijst van objecten van type T ontvangt, en een object van type T teruggeeft
// De functie heet fusion, bedenk zelf wat "fusion" betekent, maar gebruik in ieder geval de binairy * operator

int main() {
	Dog d1 = Dog(100, 4);
	Dog d2 = Dog(200, 1);
	Dog d3 = Dog(300, 16);
	std::vector<Dog> dogs = std::vector<Dog>{d1,d2,d3};
	std::vector<Dog> dogs2 = std::vector<Dog>{d1,d2,d3 };
	std::vector<Dog> dogs3 = std::vector<Dog>{d2,d2,d3 };

	Dog snoop_dog = fusion(dogs);
	std::cout << snoop_dog;

	std::cout << "dogs equal to dogs2 should be 1: " << (all_equal(dogs, dogs2)) << std::endl;
	std::cout << "dogs equal to dogs3 should be 0: " << (all_equal(dogs, dogs3)) << std::endl;

	Student s1 = Student(20, 180.5);
	Student s2 = Student(10, 280.5);
	Student s3 = Student(30, 100.5);

	std::vector<Student> students = std::vector<Student>{s1,s2,s3};
	std::vector<Student> students2 = std::vector<Student>{s1,s2,s3};
	std::vector<Student> students3 = std::vector<Student>{s2,s2,s3};

	Student mega_nerd = fusion(students);
	std::cout << mega_nerd;

	std::cout << "student equal to student2 should be 1: " << (all_equal(students, students2)) << std::endl;
	std::cout << "student equal to student3 should be 0: " << (all_equal(students, students3)) << std::endl;

	return 0;
}
