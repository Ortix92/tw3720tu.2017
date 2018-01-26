#include <iostream>
#include <string>
#include <memory>

#include <typeinfo>

template<class dataType>
class Vector
{

public:
	dataType * data;
	std::size_t length;

	Vector() : data(nullptr), size(0) {};;

	// size constructor
	Vector(std::size_t size) : data(new dataType[size]), size(size) {};

	// copy constructor
	Vector(const Vector<dataType>& other) : Vector(other.size()) {
		this->length = other.size()
			for (auto i = 0; i < other.size(); i++) {
				data[i] = other.data[i];
			};
	};

	// initializer list
	Vector(std::initializer_list<dataType> lijstje) : Vector((int)lijstje.size())
	{
		std::uninitialized_copy(lijstje.begin(), lijstje.end(), data);
	};

	// Destructor
	~Vector() { delete[] data; length = 0; data = nullptr; };

	// Helper functions. Getters for size and data
	inline const std::size_t size() const { return length; }

	// Get data pointer (constant reference).    We could also make the data public
	inline const dataType& get(const std::size_t& i) const {
		return data[i];
	};
	// Get data pointer
	inline dataType& get(const std::size_t& i) {
		return data[i];
	};



	
	// Copy assignment leaves the argument intact.
	Vector<dataType>& operator=(const Vector<dataType>& other)
	{
		if (this != &other) {
			delete[] data;
			size = other.size();
			data = new dataType[size];
			for (std::size_t i = 0; i < size; i++) {
				data[i] = other.data[i];
			}
		}
		//std::cout << "Copy assign. " << std::endl;
		return *this;
	}

	// Move assignment deletes the input. 
	Vector<dataType>& operator=(Vector<dataType>&& other) {   //R VALUE INPUTS
		if (this != &other) {
			delete[] data;
			this->size = other.size();   //OR USE SWAP FUNCTIONS?
			this->data = other.data;
			other.data = nullptr;
			other.size = 0;
		}
		//std::cout << "Move assignment. Data from incoming is moved to current. Incoming data is deleted" << std::endl;
		return *this;
	};

}; // End of class


// ========  //


// Operators

	//pointwise sum taken from lectures
	template<typename T1, typename T2>
	auto operator+(const vector<T1>& v1,  const vector<T2>& v2)  {
		vector<typename std::common_type<T1, T2>::type>	addition(v1.size());  // <typename decltype(v1.get[0] + v2.get[0])> can also work
		if (v1.size() == v2.size()) {
			for (auto i = 0; i < v1.size(); i++)
				addition.get[i] = v1.get[i] + v2.get[i]; // add.get returns a mutable reference to addition data.
			return addition;
		} else
		{
			std::clog << "Vectors not of same length" << std::endl;
			return Vector<int>();
		};
	};

	/*
	//pointwise difference taken from lectures
	template<typename T1, typename T2>
	auto operator+(const vector<T1>& v1, 
				   const vector<T2>& v2) {
		vector<typename std::common_type<T1, T2>::type>	difference(v1.size());
		if (v1.size() == v2.size()) {
			for (auto i = 0; i < v1.size(); i++)
				difference.get[i] = v1.get[i] - v2.get[i]; // add.get returns a mutable reference to addition data.
			return difference;
		}
		else
		{

			std::clog << "Vectors not of same length" << std::endl;
			return Vector();
		};
	};

	//pointwise multiplication taken from lectures. Default is right side.
	template<typename T1, typename T2>
	auto operator+(const vector<T1>& v1, const T2& scalar) {
		vector<typename std::common_type<T1, T2>::type>	multiply(v1.size());
		for (auto i = 0; i < v1.size(); i++) {
			multiply.get[i] = v1.get[i] * scalar; // add.get returns a mutable reference to addition data.
		}
		return multiply;
	};

	// Enabling left multiplication
	template<typename T1, typename T2>
	auto operator+(const T1& scalar, const vector<T2>& v1) {

		return v1 * scalar;
	};

	// Dot product. Return type is auto
	template<typename T1, typename T2>
	T dot(const Vector<T1>& l, const Vector<T2>& r) {
		vector<typename std::common_type<T1, T2>::type>	dot(l.size())
			if (l.size() == r.size())
				for (auto i = 0; i < l.size(); i++) {
					dot.get[i] += l.get[i] * r.get[i];
				}
		return dot;
			else {
				std::clog << "Vectors not of same size" << std::endl;
				return Vector();

			};


	};

	*/

