#include <iostream>
#include <string>


using namespace std;

class Food
{
public:

	Food() // Default constructor
	{
		volume = 0;
		calories = 0;
		vegetarian = true;
	}

	Food(float v, int c, bool d) // Sets Parameters
	{
		volume = v;
		calories = c;
		vegetarian = d;
	}

	Food(const Food &f) // Copy constructor
	{
		volume = f.volume;
		calories = f.calories;
		vegetarian = f.vegetarian;
	}

	bool operator == (const Food& a) {
		if ((volume == a.volume) && (calories == a.calories) && (vegetarian == a.vegetarian))
			return true;
		else
			return false;
	}

	float getVolume() // accessor for Volume
	{
		return volume;
	}
	float setVolume(float a) // mutator for Volume
	{
		volume = a;
		return volume;
	}

	int getCalories() // access for Calories
	{
		return calories;
	}
	int setCalories(int a) // mutator for Calories
	{
		calories = a;
		return calories;
	}

	bool getVegetarian() // access for Vegetarian
	{
		return vegetarian;
	}
	bool setVegetarian(bool a) // mutator for Vegetarian
	{
		vegetarian = a;
		return vegetarian;
	}

	void printItem()
	{
		cout << "I am ";
		if (vegetarian == true)
		{
			cout << "a ";
		}
		if(vegetarian == false)
		{
			cout << "not a ";
		}
		cout << "vegetarian Food, my volume is " << volume << " fl. Oz and I have " << calories << " calories";
	}

protected:
	int calories;
	bool vegetarian;

private:
	float volume;

};

class CandyWrapper {

private:
	float length;
	float width;
	string color;

	//Constructor
public:
	CandyWrapper(float length1 = 0, float width1 = 0, string color1 = "NA") {
		length = length1;
		width = width1;
		color = color1;
	}

	CandyWrapper(const CandyWrapper &a) {
		length = a.length;
		width = a.width;
		color = a.color;
	}

	//Accessor
	float getLength() {
		return length;
	}

	float getWidth() {
		return width;
	}

	string getColor() {
		return color;
	}

	//Modifier
	void setLength(float length2) {
		length = length2;
	}

	void setWidth(float width2) {
		width = width2;
	}

	void setColor(string color2) {
		color = color2;
	}

	//PrintFunction
	void PrintItem() {
		cout << "a length of " << length << "in, a width of " << width << " in and a " << color << " color" << endl;
	}

};

class Candy :public Food {

private:
	float sweetness;
	CandyWrapper candyWrap;
	string color;

	//Constructor
public:
	Candy() {
		sweetness = 0;
		color = "NA";
	}

	Candy(const Candy &a) {
		sweetness = a.sweetness;
		candyWrap = a.candyWrap;
		color = a.color;
	}

	bool operator == (const Candy& a) {
		if ((color == a.color) && (sweetness == a.sweetness))
			return true;
		else
			return false;
	}

	//Accessor
	float getSweetness() {
		return sweetness;
	}

	CandyWrapper getCandyWrap() {
		return candyWrap;
	}

	string getColor() {
		return color;
	}

	//Modifier
	void setSweetness(float s) {
		sweetness = s;
	}

	void setCandyWrap(CandyWrapper c) {
		candyWrap = c;
	}

	void setColor(string c) {
		color = c;
	}

	//PrintFunction
	void PrintItem() {
		cout << "I am ";
		if (vegetarian == true)
		{
			cout << "a ";
		}
		else
		{
			cout << "not a ";
		}
		cout << "vegetarian Candy, my volume is " << getVolume() << " fl. Oz, I have " << getCalories();
		cout << ", my sweetness level is " << sweetness << ", my color is " << color << " and my wrapper has ";
		candyWrap.PrintItem();
	}
};




int main()
{
	Food fd1 = Food(1, 200, true);
	Food fd2 = Food(fd1);
	Candy cd1;
	Candy cd2;

	CandyWrapper cw1 = CandyWrapper(1, 0.5, "red");
	CandyWrapper cw2 = CandyWrapper(0.5, 0.25, "blue");

	cd1.setVolume(0.05);
	cd1.setCalories(100);
	cd1.setVegetarian(true);
	cd1.setSweetness(0.7);
	cd1.setColor("pink");
	cd1.setCandyWrap(cw1);
	cd2 = cd1;
	cd2.setCandyWrap(cw2);

	if (fd1 == fd2)
		cout << "we are similar !!" << endl << endl;
	else
		cout << "we are different !!" << endl << endl;

	fd1.printItem();
	cout << endl;
	fd2.printItem();
	cout << endl;

	if (cd1 == cd2)
		cout << "we are similar !!" << endl << endl;
	else
		cout << "we are different !!" << endl << endl;

	cd1.printItem();
	cout << endl;
	cd2.printItem();
	cout << endl;
	system("pause");

	return 0;
}
